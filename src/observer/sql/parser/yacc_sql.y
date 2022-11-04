
%{

#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.tab.h"
#include "sql/parser/lex.yy.h"
// #include "common/log/log.h" // 包含C++中的头文件

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ParserContext {
  Query * ssql;
  size_t select_length;
  size_t condition_length;
  size_t from_length;
  size_t value_length;
  size_t insert_length;
  int nullable;
  Value values[MAX_NUM];
  Inserts_more inserts_more[MAX_NUM];
  Condition conditions[MAX_NUM];
  CompOp comp;
  char id[MAX_NUM];
  struct ParserContext * sub_context;
} ParserContext;

//获取子串
char *substr(const char *s,int n1,int n2)/*从s中提取下标为n1~n2的字符组成一个新字符串，然后返回这个新串的首地址*/
{
  char *sp = malloc(sizeof(char) * (n2 - n1 + 2));
  int i, j = 0;
  for (i = n1; i <= n2; i++) {
    sp[j++] = s[i];
  }
  sp[j] = 0;
  return sp;
}

void yyerror(yyscan_t scanner, const char *str)
{
  ParserContext *context = (ParserContext *)(yyget_extra(scanner));
  query_reset(context->ssql);
  context->ssql->flag = SCF_ERROR;
  context->condition_length = 0;
  context->from_length = 0;
  context->select_length = 0;
  context->value_length = 0;
  context->insert_length = 0;
  context->nullable = 0;
  context->ssql->sstr.insertion.inserts_more_num = 0;
  printf("parse sql failed. error=%s", str);
}

ParserContext *get_context(yyscan_t scanner)
{
  return (ParserContext *)yyget_extra(scanner);
}

#define CONTEXT get_context(scanner)
#define GET_SUB_CONTEXT CONTEXT->sub_context

%}

%define api.pure full
%lex-param { yyscan_t scanner }
%parse-param { void *scanner }

//标识tokens
%token  SEMICOLON
        CREATE
        DROP
        TABLE
        TABLES
		UNIQUE
        INDEX
        SELECT
        DESC
        SHOW
        SYNC
        INSERT
        DELETE
        UPDATE
        LBRACE
        RBRACE
        COMMA
        TRX_BEGIN
        TRX_COMMIT
        TRX_ROLLBACK
        INT_T
        STRING_T
        FLOAT_T
        DATE_T
        HELP
        EXIT
        DOT //QUOTE
        INTO
        VALUES
        FROM
        WHERE
        AND
        SET
		INNER
		JOIN
        ON
		NOT
		NULL__ // 避免和C中的NULL冲突
		NULLABLE
        LOAD
        DATA
        INFILE
        EQ
        LT
        GT
        LE
        GE
        NE
		IS
        LIKE
        MAX
        MIN
        SUM
        COUNT
        AVG
        ORDER
        GROUP
        BY
        ASC
        HAVING

%union {
  struct _Attr *attr;
  struct _Condition *condition1;
  struct _Value *value1;
  char *string;
  int number;
  float floats;
	char *position;
}

%token <number> NUMBER
%token <floats> FLOAT 
%token <string> ID
%token <string> PATH
%token <string> SSS
%token <string> STAR
%token <string> STRING_V
//非终结符

%type <number> type;
%type <condition1> condition;
%type <value1> value;
%type <number> number;

%%

commands:		//commands or sqls. parser starts here.
    /* empty */
    | commands command
    ;

command:
	  select  
	| insert
	| update
	| delete
	| create_table
	| drop_table
	| show_tables
	| show_indexes
	| desc_table
	| create_index	
	| drop_index
	| sync
	| begin
	| commit
	| rollback
	| load_data
	| help
	| exit
    ;

exit:			
    EXIT SEMICOLON {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    };

help:
    HELP SEMICOLON {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    };

sync:
    SYNC SEMICOLON {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
    ;

begin:
    TRX_BEGIN SEMICOLON {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
    ;

commit:
    TRX_COMMIT SEMICOLON {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
    ;

rollback:
    TRX_ROLLBACK SEMICOLON {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
    ;

drop_table:		/*drop table 语句的语法解析树*/
    DROP TABLE ID SEMICOLON {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, $3);
    };

show_tables:
    SHOW TABLES SEMICOLON {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
    ;
show_indexes:
	SHOW INDEX FROM ID SEMICOLON {
	  CONTEXT->ssql->flag = SCF_SHOW_INDEXES;
	  create_show_index(&CONTEXT->ssql->sstr.show_index, $4);
	}	
	;

desc_table:
    DESC ID SEMICOLON {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, $2);
    }
    ;

create_index:		/*create index 语句的语法解析树*/
    CREATE INDEX ID ON ID LBRACE ID index_attr_list RBRACE SEMICOLON 
		{
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, $7);
			create_index_init(&CONTEXT->ssql->sstr.create_index, $3, $5, DEFAULT_INDEX);
		}
	| CREATE UNIQUE INDEX ID ON ID LBRACE ID index_attr_list RBRACE SEMICOLON
        {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
            create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, $8);
            create_index_init(&CONTEXT->ssql->sstr.create_index, $4, $6, UNIQUE_INDEX);
        }
    ;
    ;

index_attr_list:
    /* empty */
    | COMMA ID index_attr_list {
            create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, $2);
        }
    ;

drop_index:			/*drop index 语句的语法解析树*/
    DROP INDEX ID  SEMICOLON 
		{
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, $3);
		}
    ;
create_table:		/*create table 语句的语法解析树*/
    CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON 
		{
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, $3);
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
    ;
attr_def_list:
    /* empty */
    | COMMA attr_def attr_def_list {    }
    ;
    
attr_def:
    ID_get type LBRACE number RBRACE is_null
		{
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, $2, $4, CONTEXT->nullable);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;
			CONTEXT->value_length++;
		}
    |ID_get type is_null
		{
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, $2, 4, CONTEXT->nullable);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}
    ;
number:
		NUMBER {$$ = $1;}
		;
type:
	INT_T { $$=INTS; }
       | STRING_T { $$=CHARS; }
       | FLOAT_T { $$=FLOATS; }
       | DATE_T { $$=DATES; }
       ;
is_null: 
	/* empty */{
		CONTEXT->nullable = 0;
	}
	| NOT NULL__{
		CONTEXT->nullable = 0;
	}
	| NULLABLE {
		CONTEXT->nullable = 1;
	}
	;
ID_get:
	ID 
	{
		char *temp=$1; 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
	;

	
insert:				/*insert   语句的语法解析树*/
    INSERT INTO ID VALUES LBRACE insert_vaule value_list RBRACE value_tuple SEMICOLON 
		{
			// CONTEXT->values[CONTEXT->value_length++] = *$6;

			CONTEXT->ssql->flag=SCF_INSERT;//"insert";
			// CONTEXT->ssql->sstr.insertion.relation_name = $3;
			// CONTEXT->ssql->sstr.insertion.value_num = CONTEXT->value_length;
			// for(i = 0; i < CONTEXT->value_length; i++){
			// 	CONTEXT->ssql->sstr.insertion.values[i] = CONTEXT->values[i];
      // }
			inserts_init(&CONTEXT->ssql->sstr.insertion, $3, CONTEXT->inserts_more, CONTEXT->insert_length);

      //临时变量清零
      // CONTEXT->value_length=0;
	  inserts_more_destroy(CONTEXT->inserts_more, &CONTEXT->insert_length);
    }

value_tuple:
	/* empty */
	| COMMA LBRACE insert_vaule value_list RBRACE value_tuple {

	  }
	;

value_list:
    /* empty */
	{
		inserts_more_init(&CONTEXT->inserts_more[CONTEXT->insert_length].value_num, &CONTEXT->insert_length);
	}
    | COMMA insert_vaule value_list  { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
    ;
insert_vaule:
    NUMBER{	
		// 匹配时insert规则时，保存在CONTEXT->inserts_more->values中
  		value_init_integer(&CONTEXT->inserts_more[CONTEXT->insert_length].values[CONTEXT->inserts_more[CONTEXT->insert_length].value_num++], $1);
		// 匹配Conditon规则时，values需要保存在CONTEXT->values中,使用下面的value规则
		}
    |FLOAT{
  		value_init_float(&CONTEXT->inserts_more[CONTEXT->insert_length].values[CONTEXT->inserts_more[CONTEXT->insert_length].value_num++], $1);
		}
    |SSS {
			$1 = substr($1,1,strlen($1)-2);
  		value_init_string(&CONTEXT->inserts_more[CONTEXT->insert_length].values[CONTEXT->inserts_more[CONTEXT->insert_length].value_num++], $1);
		}
    |NULL__ {
		value_init_null(&CONTEXT->inserts_more[CONTEXT->insert_length].values[CONTEXT->inserts_more[CONTEXT->insert_length].value_num++]);
	};
value:
    NUMBER{	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], $1);
		}
    |FLOAT{
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], $1);
		}
    |SSS {
			$1 = substr($1,1,strlen($1)-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], $1);
		}
	| LBRACE sub_select RBRACE{
		value_init_query(&CONTEXT->values[CONTEXT->value_length++], GET_SUB_CONTEXT->ssql);
		// 赋值后将子句清空
		memset(GET_SUB_CONTEXT->ssql, 0, sizeof(*GET_SUB_CONTEXT->ssql));
	}
    ;
	|NULL__ {
		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
	}
	;
    
delete:		/*  delete 语句的语法解析树*/
    DELETE FROM ID where SEMICOLON 
		{
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, $3);
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
    ;
update:			/*  update 语句的语法解析树*/
    UPDATE ID update_list where SEMICOLON
		{
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, $2, CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
    ;
update_list:
    SET ID EQ value set_list{
		SetValue set_value;
		set_value_init(&set_value, $2, &CONTEXT->values[--CONTEXT->value_length]);
		update_append_value_list(&CONTEXT->ssql->sstr.update, &set_value);
	}
	;

set_list:
    /* empty */
	| COMMA ID EQ value set_list{
		SetValue set_value;
		set_value_init(&set_value, $2, &CONTEXT->values[--CONTEXT->value_length]);
		update_append_value_list(&CONTEXT->ssql->sstr.update, &set_value);
	}
	;

sub_select:
    SELECT sub_select_attr FROM ID sub_rel_list sub_where{
		// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
		selects_append_relation(&GET_SUB_CONTEXT->ssql->sstr.selection, $4);
		selects_append_conditions(&GET_SUB_CONTEXT->ssql->sstr.selection, GET_SUB_CONTEXT->conditions, GET_SUB_CONTEXT->condition_length);
		GET_SUB_CONTEXT->ssql->flag=SCF_SELECT;//"select";
		// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;
		//临时变量清零
		GET_SUB_CONTEXT->condition_length=0;
		GET_SUB_CONTEXT->from_length=0;
		GET_SUB_CONTEXT->select_length=0;
		GET_SUB_CONTEXT->value_length = 0;
	}
	;
sub_select_attr:
    STAR sub_attr_list{  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
		}
    | ID sub_attr_list {
			RelAttr attr;
			relation_attr_init(&attr, NULL, $1);
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
		}
  	| ID DOT ID sub_attr_list {
			RelAttr attr;
			relation_attr_init(&attr, $1, $3);
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
		}
	| ID DOT STAR sub_attr_list {
			RelAttr attr;
			relation_attr_init(&attr, $1, "*");
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
	| sub_agg_func sub_attr_list{
	}
    ;
sub_attr_list:
    /* empty */
    | COMMA ID sub_attr_list {
			RelAttr attr;
			relation_attr_init(&attr, NULL, $2);
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
	| COMMA ID DOT STAR sub_attr_list {
			RelAttr attr;
			relation_attr_init(&attr, $2, "*");
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
    | COMMA ID DOT ID sub_attr_list {
			RelAttr attr;
			relation_attr_init(&attr, $2, $4);
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
	| COMMA sub_agg_func sub_attr_list
  	;

sub_agg_func:
	MAX LBRACE ID RBRACE {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, $3, AGG_MAX);
	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
	| MAX LBRACE ID DOT ID RBRACE {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, $3, $5, AGG_MAX);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
	| MIN LBRACE ID RBRACE {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, $3, AGG_MIN);
	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
	| MIN LBRACE ID DOT ID RBRACE {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, $3, $5, AGG_MIN);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
       	| SUM LBRACE ID RBRACE {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, $3, AGG_SUM);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
       	| SUM LBRACE ID DOT ID RBRACE {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, $3, $5, AGG_SUM);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
       	| COUNT LBRACE NUMBER RBRACE {
       	  RelAttr attr;
       	  char *str = malloc(10 * sizeof(char));
       	  snprintf(str, 10, "%d", $3);
       	  aggregation_attr_init(&attr, NULL, str, AGG_COUNT);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
       	| COUNT LBRACE STAR RBRACE {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, "*", AGG_COUNT);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
       	| COUNT LBRACE ID RBRACE {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, $3, AGG_COUNT);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
	| AVG LBRACE ID RBRACE {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, $3, AGG_AVG);
	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
	| AVG LBRACE ID DOT ID RBRACE {
	  RelAttr attr;
	  aggregation_attr_init(&attr, $3, $5, AGG_AVG);
	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
	;

sub_rel_list:
    /* empty */
    | COMMA ID sub_rel_list {	
			selects_append_relation(&GET_SUB_CONTEXT->ssql->sstr.selection, $2);
		  }
    ;
select:				/*  select 语句的语法解析树*/
    SELECT select_attr FROM ID rel_list where order_by group_by having SEMICOLON
		{
			// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			selects_append_relation(&CONTEXT->ssql->sstr.selection, $4);

			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);

			CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;

			//临时变量清零
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
	| SELECT select_attr FROM ID rel_list inner where order_by group_by having SEMICOLON
		{
			selects_append_relation(&CONTEXT->ssql->sstr.selection, $4);
			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);

			CONTEXT->ssql->flag=SCF_SELECT;
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
	;

select_attr:
    STAR attr_list{  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
    | ID attr_list {
			RelAttr attr;
			relation_attr_init(&attr, NULL, $1);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
  	| ID DOT ID attr_list {
			RelAttr attr;
			relation_attr_init(&attr, $1, $3);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
	| ID DOT STAR attr_list {
			RelAttr attr;
			relation_attr_init(&attr, $1, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
//	| agg_func attr_list
	| MAX LBRACE ID RBRACE attr_list {
          RelAttr attr;
          aggregation_attr_init(&attr, NULL, $3, AGG_MAX);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
        | MAX LBRACE ID DOT ID RBRACE attr_list {
           RelAttr attr;
           aggregation_attr_init(&attr, $3, $5, AGG_MAX);
           selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
         }
        | MIN LBRACE ID RBRACE attr_list {
          RelAttr attr;
          aggregation_attr_init(&attr, NULL, $3, AGG_MIN);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
        | MIN LBRACE ID DOT ID RBRACE attr_list {
          RelAttr attr;
          aggregation_attr_init(&attr, $3, $5, AGG_MIN);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
        | SUM LBRACE ID RBRACE attr_list {
          RelAttr attr;
          aggregation_attr_init(&attr, NULL, $3, AGG_SUM);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
        | SUM LBRACE ID DOT ID RBRACE attr_list {
          RelAttr attr;
          aggregation_attr_init(&attr, $3, $5, AGG_SUM);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
        | COUNT LBRACE NUMBER RBRACE attr_list {
          RelAttr attr;
          char *str = malloc(10 * sizeof(char));
          snprintf(str, 10, "%d", $3);
          aggregation_attr_init(&attr, NULL, str, AGG_COUNT);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
        | COUNT LBRACE STAR RBRACE attr_list {
          RelAttr attr;
          aggregation_attr_init(&attr, NULL, "*", AGG_COUNT);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
        | COUNT LBRACE ID RBRACE attr_list {
          RelAttr attr;
          aggregation_attr_init(&attr, NULL, $3, AGG_COUNT);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
        | AVG LBRACE ID RBRACE attr_list {
          RelAttr attr;
          aggregation_attr_init(&attr, NULL, $3, AGG_AVG);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
        | AVG LBRACE ID DOT ID RBRACE attr_list {
          RelAttr attr;
          aggregation_attr_init(&attr, $3, $5, AGG_AVG);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
    ;

attr_list:
    /* empty */
    | COMMA ID attr_list {
			RelAttr attr;
			relation_attr_init(&attr, NULL, $2);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
	| COMMA ID DOT STAR attr_list {
			RelAttr attr;
			relation_attr_init(&attr, $2, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
    | COMMA ID DOT ID attr_list {
			RelAttr attr;
			relation_attr_init(&attr, $2, $4);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
//  	| COMMA agg_func attr_list
	| COMMA MAX LBRACE ID RBRACE attr_list {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, $4, AGG_MAX);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
	| COMMA MAX LBRACE ID DOT ID RBRACE attr_list {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, $4, $6, AGG_MAX);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
	| COMMA MIN LBRACE ID RBRACE attr_list {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, $4, AGG_MIN);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
	| COMMA MIN LBRACE ID DOT ID RBRACE attr_list {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, $4, $6, AGG_MIN);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
       	| COMMA SUM LBRACE ID RBRACE attr_list {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, $4, AGG_SUM);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
       	| COMMA SUM LBRACE ID DOT ID RBRACE attr_list {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, $4, $6, AGG_SUM);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
       	| COMMA COUNT LBRACE NUMBER RBRACE attr_list {
       	  RelAttr attr;
       	  char *str = malloc(10 * sizeof(char));
       	  snprintf(str, 10, "%d", $4);
       	  aggregation_attr_init(&attr, NULL, str, AGG_COUNT);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
       	| COMMA COUNT LBRACE STAR RBRACE attr_list {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, "*", AGG_COUNT);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
       	| COMMA COUNT LBRACE ID RBRACE attr_list {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, $4, AGG_COUNT);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
	| COMMA AVG LBRACE ID RBRACE attr_list {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, $4, AGG_AVG);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
	| COMMA AVG LBRACE ID DOT ID RBRACE attr_list {
	  RelAttr attr;
	  aggregation_attr_init(&attr, $4, $6, AGG_AVG);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
  	;

agg_func:
	MAX LBRACE ID RBRACE {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, $3, AGG_MAX);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
	| MAX LBRACE ID DOT ID RBRACE {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, $3, $5, AGG_MAX);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
	| MIN LBRACE ID RBRACE {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, $3, AGG_MIN);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
	| MIN LBRACE ID DOT ID RBRACE {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, $3, $5, AGG_MIN);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
       	| SUM LBRACE ID RBRACE {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, $3, AGG_SUM);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
       	| SUM LBRACE ID DOT ID RBRACE {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, $3, $5, AGG_SUM);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
       	| COUNT LBRACE NUMBER RBRACE {
       	  RelAttr attr;
       	  char *str = malloc(10 * sizeof(char));
       	  snprintf(str, 10, "%d", $3);
       	  aggregation_attr_init(&attr, NULL, str, AGG_COUNT);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
       	| COUNT LBRACE STAR RBRACE {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, "*", AGG_COUNT);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
       	| COUNT LBRACE ID RBRACE {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, $3, AGG_COUNT);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
	| AVG LBRACE ID RBRACE {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, $3, AGG_AVG);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
	| AVG LBRACE ID DOT ID RBRACE {
	  RelAttr attr;
	  aggregation_attr_init(&attr, $3, $5, AGG_AVG);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
	;

rel_list:
    /* empty */
    | COMMA ID rel_list {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, $2);
		  }
    ;
inner:
	/* empty */
	| INNER JOIN ID rel_list on inner {
				selects_append_relation(&CONTEXT->ssql->sstr.selection, $3);
		  }
	| JOIN ID rel_list on inner {
				selects_append_relation(&CONTEXT->ssql->sstr.selection, $2);
		  }
	;
on: 
	/* empty */
	| ON condition condition_list {

		  }
	;
where:
    /* empty */ 
    | WHERE condition condition_list {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
    ;
condition_list:
    /* empty */
    | AND condition condition_list {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
    ;
condition:
    ID comOp value 
		{
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, $1);

			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$ = ( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name = NULL;
			// $$->left_attr.attribute_name= $1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 0;
			// $$->right_attr.relation_name = NULL;
			// $$->right_attr.attribute_name = NULL;
			// $$->right_value = *$3;

		}
		|value comOp value 
		{
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 2];
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$ = ( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 0;
			// $$->right_attr.relation_name = NULL;
			// $$->right_attr.attribute_name = NULL;
			// $$->right_value = *$3;

		}
		|ID comOp ID 
		{
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, $1);
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, $3);

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=$1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 1;
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=$3;

		}
    |value comOp ID
		{
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, $3);

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp=CONTEXT->comp;
			
			// $$->right_is_attr = 1;
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=$3;
		
		}
    |ID DOT ID comOp value
		{
			RelAttr left_attr;
			relation_attr_init(&left_attr, $1, $3);
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name=$1;
			// $$->left_attr.attribute_name=$3;
			// $$->comp=CONTEXT->comp;
			// $$->right_is_attr = 0;   //属性值
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=NULL;
			// $$->right_value =*$5;			
							
    }
    |value comOp ID DOT ID
		{
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];

			RelAttr right_attr;
			relation_attr_init(&right_attr, $3, $5);

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;//属性值
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp =CONTEXT->comp;
			// $$->right_is_attr = 1;//属性
			// $$->right_attr.relation_name = $3;
			// $$->right_attr.attribute_name = $5;
									
    }
    |ID DOT ID comOp ID DOT ID
		{
			RelAttr left_attr;
			relation_attr_init(&left_attr, $1, $3);
			RelAttr right_attr;
			relation_attr_init(&right_attr, $5, $7);

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;		//属性
			// $$->left_attr.relation_name=$1;
			// $$->left_attr.attribute_name=$3;
			// $$->comp =CONTEXT->comp;
			// $$->right_is_attr = 1;		//属性
			// $$->right_attr.relation_name=$5;
			// $$->right_attr.attribute_name=$7;
    }
    ;

sub_where:
    /* empty */ 
    | WHERE sub_condition sub_condition_list {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
    ;
sub_condition_list:
    /* empty */
    | AND sub_condition sub_condition_list {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
    ;
sub_condition:
    ID sub_comOp sub_value 
		{
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, $1);

			Value *right_value = &GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, GET_SUB_CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			GET_SUB_CONTEXT->conditions[GET_SUB_CONTEXT->condition_length++] = condition;
		}
		|sub_value sub_comOp sub_value 
		{
			Value *left_value = &GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length - 2];
			Value *right_value = &GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, GET_SUB_CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
			GET_SUB_CONTEXT->conditions[GET_SUB_CONTEXT->condition_length++] = condition;
			// $$ = ( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 0;
			// $$->right_attr.relation_name = NULL;
			// $$->right_attr.attribute_name = NULL;
			// $$->right_value = *$3;

		}
		|ID sub_comOp ID 
		{
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, $1);
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, $3);

			Condition condition;
			condition_init(&condition, GET_SUB_CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			GET_SUB_CONTEXT->conditions[GET_SUB_CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=$1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 1;
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=$3;

		}
    |sub_value sub_comOp ID
		{
			Value *left_value = &GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length - 1];
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, $3);

			Condition condition;
			condition_init(&condition, GET_SUB_CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			GET_SUB_CONTEXT->conditions[GET_SUB_CONTEXT->condition_length++] = condition;

			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp=CONTEXT->comp;
			
			// $$->right_is_attr = 1;
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=$3;
		
		}
    |ID DOT ID sub_comOp sub_value
		{
			RelAttr left_attr;
			relation_attr_init(&left_attr, $1, $3);
			Value *right_value = &GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, GET_SUB_CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			GET_SUB_CONTEXT->conditions[GET_SUB_CONTEXT->condition_length++] = condition;

			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name=$1;
			// $$->left_attr.attribute_name=$3;
			// $$->comp=CONTEXT->comp;
			// $$->right_is_attr = 0;   //属性值
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=NULL;
			// $$->right_value =*$5;			
							
    }
    |sub_value sub_comOp ID DOT ID
		{
			Value *left_value = &GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length - 1];

			RelAttr right_attr;
			relation_attr_init(&right_attr, $3, $5);

			Condition condition;
			condition_init(&condition, GET_SUB_CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			GET_SUB_CONTEXT->conditions[GET_SUB_CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;//属性值
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp =CONTEXT->comp;
			// $$->right_is_attr = 1;//属性
			// $$->right_attr.relation_name = $3;
			// $$->right_attr.attribute_name = $5;
									
    }
    |ID DOT ID sub_comOp ID DOT ID
		{
			RelAttr left_attr;
			relation_attr_init(&left_attr, $1, $3);
			RelAttr right_attr;
			relation_attr_init(&right_attr, $5, $7);

			Condition condition;
			condition_init(&condition, GET_SUB_CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			GET_SUB_CONTEXT->conditions[GET_SUB_CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;		//属性
			// $$->left_attr.relation_name=$1;
			// $$->left_attr.attribute_name=$3;
			// $$->comp =CONTEXT->comp;
			// $$->right_is_attr = 1;		//属性
			// $$->right_attr.relation_name=$5;
			// $$->right_attr.attribute_name=$7;
    }
    ;

sub_value:
    NUMBER{	
  		value_init_integer(&GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length++], $1);
		}
    |FLOAT{
  		value_init_float(&GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length++], $1);
		}
    |SSS {
			$1 = substr($1,1,strlen($1)-2);
  		value_init_string(&GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length++], $1);
		}
	|NULL__ {
		value_init_null(&GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length++]);
	}
	;

sub_comOp:
  	  EQ { GET_SUB_CONTEXT->comp = EQUAL_TO; }
    | LT { GET_SUB_CONTEXT->comp = LESS_THAN; }
    | GT { GET_SUB_CONTEXT->comp = GREAT_THAN; }
    | LE { GET_SUB_CONTEXT->comp = LESS_EQUAL; }
    | GE { GET_SUB_CONTEXT->comp = GREAT_EQUAL; }
    | NE { GET_SUB_CONTEXT->comp = NOT_EQUAL; }
    | LIKE { GET_SUB_CONTEXT->comp = OP_LIKE; }
    | NOT LIKE { GET_SUB_CONTEXT->comp = OP_NOT_LIKE; }
	| IS       { CONTEXT->comp = EQUAL_IS; }
	| IS NOT   { CONTEXT->comp = NOT_EQUAL_IS; }
    ;

comOp:
  	  EQ { CONTEXT->comp = EQUAL_TO; }
    | LT { CONTEXT->comp = LESS_THAN; }
    | GT { CONTEXT->comp = GREAT_THAN; }
    | LE { CONTEXT->comp = LESS_EQUAL; }
    | GE { CONTEXT->comp = GREAT_EQUAL; }
    | NE { CONTEXT->comp = NOT_EQUAL; }
    | LIKE 	   { CONTEXT->comp = OP_LIKE; }
    | NOT LIKE { CONTEXT->comp = OP_NOT_LIKE; }
	| IS       { CONTEXT->comp = EQUAL_IS; }
	| IS NOT   { CONTEXT->comp = NOT_EQUAL_IS; }
    ;

load_data:
		LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON
		{
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, $7, $4);
		}
		;

order_by:
	| ORDER BY order_attr order_attr_list
	;

order_attr:
	ID {
		OrderBy order;
               	order_init(&order, NULL, $1, ORDER_ASC);
               	selects_append_order(&CONTEXT->ssql->sstr.selection, &order);
	}
	| ID ASC {
		OrderBy order;
                order_init(&order, NULL, $1, ORDER_ASC);
                selects_append_order(&CONTEXT->ssql->sstr.selection, &order);
	}
	| ID DESC {
		OrderBy order;
                order_init(&order, NULL, $1, ORDER_DESC);
                selects_append_order(&CONTEXT->ssql->sstr.selection, &order);
	}
	| ID DOT ID {
		OrderBy order;
                order_init(&order, $1, $3, ORDER_ASC);
                selects_append_order(&CONTEXT->ssql->sstr.selection, &order);
	}
	| ID DOT ID ASC {
		OrderBy order;
                order_init(&order, $1, $3, ORDER_ASC);
                selects_append_order(&CONTEXT->ssql->sstr.selection, &order);
	}
	| ID DOT ID DESC {
		OrderBy order;
                order_init(&order, $1, $3, ORDER_DESC);
                selects_append_order(&CONTEXT->ssql->sstr.selection, &order);
	}
	;

order_attr_list:
	| COMMA order_attr order_attr_list
	;

group_by:
	| GROUP BY group_attr group_attr_list
	;

group_attr:
	ID {
		GroupBy group;
               	group_init(&group, NULL, $1);
               	selects_append_group(&CONTEXT->ssql->sstr.selection, &group);
	}
	| ID DOT ID {
		GroupBy group;
                group_init(&group, $1, $3);
                selects_append_group(&CONTEXT->ssql->sstr.selection, &group);
	}
	;

group_attr_list:
	| COMMA group_attr group_attr_list
	;

having:
	| HAVING having_condition having_condition_list
	;

having_condition:
	MAX LBRACE ID RBRACE comOp value {
		RelAttr left_attr;
                aggregation_attr_init(&left_attr, NULL, $3, AGG_MAX);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
	}
	| MAX LBRACE ID DOT ID RBRACE comOp value {
          	RelAttr left_attr;
                aggregation_attr_init(&left_attr, $3, $5, AGG_MAX);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
        | MIN LBRACE ID RBRACE comOp value {
       		RelAttr left_attr;
                aggregation_attr_init(&left_attr, NULL, $3, AGG_MIN);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
       	}
       	| MIN LBRACE ID DOT ID RBRACE comOp value {
                RelAttr left_attr;
                aggregation_attr_init(&left_attr, $3, $5, AGG_MIN);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
        | SUM LBRACE ID RBRACE comOp value {
        	RelAttr left_attr;
                aggregation_attr_init(&left_attr, NULL, $3, AGG_SUM);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
        | SUM LBRACE ID DOT ID RBRACE comOp value {
          	RelAttr left_attr;
                aggregation_attr_init(&left_attr, $3, $5, AGG_SUM);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
        | COUNT LBRACE ID RBRACE comOp value {
        	RelAttr left_attr;
                aggregation_attr_init(&left_attr, NULL, $3, AGG_COUNT);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
        | COUNT LBRACE ID DOT ID RBRACE comOp value {
          	RelAttr left_attr;
                aggregation_attr_init(&left_attr, $3, $5, AGG_COUNT);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
        | AVG LBRACE ID RBRACE comOp value {
        	RelAttr left_attr;
                aggregation_attr_init(&left_attr, NULL, $3, AGG_AVG);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
        | AVG LBRACE ID DOT ID RBRACE comOp value {
          	RelAttr left_attr;
                aggregation_attr_init(&left_attr, $3, $5, AGG_AVG);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
	;

having_condition_list:
	| AND having_condition having_condition_list
	;

%%
//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, Query *sqls){
	ParserContext context;
	memset(&context, 0, sizeof(context));
	context.sub_context = (struct ParserContext *)malloc(sizeof(struct ParserContext));
	memset(context.sub_context, 0, sizeof(*context.sub_context));
	context.sub_context->ssql = (Query*)malloc(sizeof(Query));
	memset(context.sub_context->ssql, 0, sizeof(*context.sub_context->ssql));

	yyscan_t scanner;
	yylex_init_extra(&context, &scanner);
	context.ssql = sqls;
	scan_string(s, scanner);
	int result = yyparse(scanner);
	yylex_destroy(scanner);
	return result;
}
