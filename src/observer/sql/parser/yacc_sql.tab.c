/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yacc_sql.y"


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


#line 135 "yacc_sql.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "yacc_sql.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_CREATE = 4,                     /* CREATE  */
  YYSYMBOL_DROP = 5,                       /* DROP  */
  YYSYMBOL_TABLE = 6,                      /* TABLE  */
  YYSYMBOL_TABLES = 7,                     /* TABLES  */
  YYSYMBOL_UNIQUE = 8,                     /* UNIQUE  */
  YYSYMBOL_INDEX = 9,                      /* INDEX  */
  YYSYMBOL_SELECT = 10,                    /* SELECT  */
  YYSYMBOL_DESC = 11,                      /* DESC  */
  YYSYMBOL_SHOW = 12,                      /* SHOW  */
  YYSYMBOL_SYNC = 13,                      /* SYNC  */
  YYSYMBOL_INSERT = 14,                    /* INSERT  */
  YYSYMBOL_DELETE = 15,                    /* DELETE  */
  YYSYMBOL_UPDATE = 16,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 17,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 18,                    /* RBRACE  */
  YYSYMBOL_COMMA = 19,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 20,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 21,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 22,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 23,                     /* INT_T  */
  YYSYMBOL_STRING_T = 24,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 25,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 26,                    /* DATE_T  */
  YYSYMBOL_HELP = 27,                      /* HELP  */
  YYSYMBOL_EXIT = 28,                      /* EXIT  */
  YYSYMBOL_DOT = 29,                       /* DOT  */
  YYSYMBOL_INTO = 30,                      /* INTO  */
  YYSYMBOL_VALUES = 31,                    /* VALUES  */
  YYSYMBOL_FROM = 32,                      /* FROM  */
  YYSYMBOL_WHERE = 33,                     /* WHERE  */
  YYSYMBOL_AND = 34,                       /* AND  */
  YYSYMBOL_SET = 35,                       /* SET  */
  YYSYMBOL_INNER = 36,                     /* INNER  */
  YYSYMBOL_JOIN = 37,                      /* JOIN  */
  YYSYMBOL_ON = 38,                        /* ON  */
  YYSYMBOL_NOT = 39,                       /* NOT  */
  YYSYMBOL_NULL__ = 40,                    /* NULL__  */
  YYSYMBOL_NULLABLE = 41,                  /* NULLABLE  */
  YYSYMBOL_LOAD = 42,                      /* LOAD  */
  YYSYMBOL_DATA = 43,                      /* DATA  */
  YYSYMBOL_INFILE = 44,                    /* INFILE  */
  YYSYMBOL_EQ = 45,                        /* EQ  */
  YYSYMBOL_LT = 46,                        /* LT  */
  YYSYMBOL_GT = 47,                        /* GT  */
  YYSYMBOL_LE = 48,                        /* LE  */
  YYSYMBOL_GE = 49,                        /* GE  */
  YYSYMBOL_NE = 50,                        /* NE  */
  YYSYMBOL_IS = 51,                        /* IS  */
  YYSYMBOL_LIKE = 52,                      /* LIKE  */
  YYSYMBOL_MAX = 53,                       /* MAX  */
  YYSYMBOL_MIN = 54,                       /* MIN  */
  YYSYMBOL_SUM = 55,                       /* SUM  */
  YYSYMBOL_COUNT = 56,                     /* COUNT  */
  YYSYMBOL_AVG = 57,                       /* AVG  */
  YYSYMBOL_ORDER = 58,                     /* ORDER  */
  YYSYMBOL_GROUP = 59,                     /* GROUP  */
  YYSYMBOL_BY = 60,                        /* BY  */
  YYSYMBOL_ASC = 61,                       /* ASC  */
  YYSYMBOL_HAVING = 62,                    /* HAVING  */
  YYSYMBOL_NUMBER = 63,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 64,                     /* FLOAT  */
  YYSYMBOL_ID = 65,                        /* ID  */
  YYSYMBOL_PATH = 66,                      /* PATH  */
  YYSYMBOL_SSS = 67,                       /* SSS  */
  YYSYMBOL_STAR = 68,                      /* STAR  */
  YYSYMBOL_STRING_V = 69,                  /* STRING_V  */
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_commands = 71,                  /* commands  */
  YYSYMBOL_command = 72,                   /* command  */
  YYSYMBOL_exit = 73,                      /* exit  */
  YYSYMBOL_help = 74,                      /* help  */
  YYSYMBOL_sync = 75,                      /* sync  */
  YYSYMBOL_begin = 76,                     /* begin  */
  YYSYMBOL_commit = 77,                    /* commit  */
  YYSYMBOL_rollback = 78,                  /* rollback  */
  YYSYMBOL_drop_table = 79,                /* drop_table  */
  YYSYMBOL_show_tables = 80,               /* show_tables  */
  YYSYMBOL_show_indexes = 81,              /* show_indexes  */
  YYSYMBOL_desc_table = 82,                /* desc_table  */
  YYSYMBOL_create_index = 83,              /* create_index  */
  YYSYMBOL_index_attr_list = 84,           /* index_attr_list  */
  YYSYMBOL_drop_index = 85,                /* drop_index  */
  YYSYMBOL_create_table = 86,              /* create_table  */
  YYSYMBOL_attr_def_list = 87,             /* attr_def_list  */
  YYSYMBOL_attr_def = 88,                  /* attr_def  */
  YYSYMBOL_number = 89,                    /* number  */
  YYSYMBOL_type = 90,                      /* type  */
  YYSYMBOL_is_null = 91,                   /* is_null  */
  YYSYMBOL_ID_get = 92,                    /* ID_get  */
  YYSYMBOL_insert = 93,                    /* insert  */
  YYSYMBOL_value_tuple = 94,               /* value_tuple  */
  YYSYMBOL_value_list = 95,                /* value_list  */
  YYSYMBOL_insert_vaule = 96,              /* insert_vaule  */
  YYSYMBOL_value = 97,                     /* value  */
  YYSYMBOL_delete = 98,                    /* delete  */
  YYSYMBOL_update = 99,                    /* update  */
  YYSYMBOL_update_list = 100,              /* update_list  */
  YYSYMBOL_set_list = 101,                 /* set_list  */
  YYSYMBOL_sub_select = 102,               /* sub_select  */
  YYSYMBOL_sub_select_attr = 103,          /* sub_select_attr  */
  YYSYMBOL_sub_attr_list = 104,            /* sub_attr_list  */
  YYSYMBOL_sub_agg_func = 105,             /* sub_agg_func  */
  YYSYMBOL_sub_rel_list = 106,             /* sub_rel_list  */
  YYSYMBOL_select = 107,                   /* select  */
  YYSYMBOL_select_attr = 108,              /* select_attr  */
  YYSYMBOL_attr_list = 109,                /* attr_list  */
  YYSYMBOL_rel_list = 110,                 /* rel_list  */
  YYSYMBOL_inner = 111,                    /* inner  */
  YYSYMBOL_on = 112,                       /* on  */
  YYSYMBOL_where = 113,                    /* where  */
  YYSYMBOL_condition_list = 114,           /* condition_list  */
  YYSYMBOL_condition = 115,                /* condition  */
  YYSYMBOL_sub_where = 116,                /* sub_where  */
  YYSYMBOL_sub_condition_list = 117,       /* sub_condition_list  */
  YYSYMBOL_sub_condition = 118,            /* sub_condition  */
  YYSYMBOL_sub_value = 119,                /* sub_value  */
  YYSYMBOL_sub_comOp = 120,                /* sub_comOp  */
  YYSYMBOL_comOp = 121,                    /* comOp  */
  YYSYMBOL_load_data = 122,                /* load_data  */
  YYSYMBOL_order_by = 123,                 /* order_by  */
  YYSYMBOL_order_attr = 124,               /* order_attr  */
  YYSYMBOL_order_attr_list = 125,          /* order_attr_list  */
  YYSYMBOL_group_by = 126,                 /* group_by  */
  YYSYMBOL_group_attr = 127,               /* group_attr  */
  YYSYMBOL_group_attr_list = 128,          /* group_attr_list  */
  YYSYMBOL_having = 129,                   /* having  */
  YYSYMBOL_having_condition = 130,         /* having_condition  */
  YYSYMBOL_having_condition_list = 131     /* having_condition_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   566

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  211
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  533

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   324


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   158,   158,   160,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   185,   190,   195,   201,   207,   213,   219,   225,
     230,   237,   244,   250,   259,   261,   267,   274,   283,   285,
     289,   300,   313,   316,   317,   318,   319,   322,   325,   328,
     333,   342,   359,   361,   368,   371,   376,   381,   384,   388,
     392,   395,   398,   402,   408,   414,   424,   432,   439,   441,
     449,   463,   468,   473,   478,   483,   486,   488,   495,   500,
     507,   511,   516,   521,   526,   531,   536,   541,   548,   553,
     558,   563,   570,   572,   577,   593,   607,   612,   617,   622,
     628,   633,   638,   643,   648,   653,   658,   665,   670,   675,
     680,   687,   689,   696,   701,   709,   714,   719,   724,   729,
     734,   739,   746,   751,   756,   761,   828,   830,   834,   836,
     839,   843,   845,   849,   851,   855,   857,   862,   883,   903,
     923,   945,   966,   987,  1008,  1010,  1014,  1016,  1021,  1032,
    1052,  1072,  1094,  1115,  1136,  1158,  1161,  1164,  1168,  1174,
    1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1187,
    1188,  1189,  1190,  1191,  1192,  1193,  1194,  1195,  1196,  1200,
    1207,  1208,  1212,  1217,  1222,  1227,  1232,  1237,  1244,  1245,
    1248,  1249,  1253,  1258,  1265,  1266,  1269,  1270,  1274,  1283,
    1292,  1301,  1310,  1319,  1328,  1337,  1346,  1357,  1366,  1375,
    1386,  1387
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "CREATE",
  "DROP", "TABLE", "TABLES", "UNIQUE", "INDEX", "SELECT", "DESC", "SHOW",
  "SYNC", "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE", "COMMA",
  "TRX_BEGIN", "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T",
  "FLOAT_T", "DATE_T", "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM",
  "WHERE", "AND", "SET", "INNER", "JOIN", "ON", "NOT", "NULL__",
  "NULLABLE", "LOAD", "DATA", "INFILE", "EQ", "LT", "GT", "LE", "GE", "NE",
  "IS", "LIKE", "MAX", "MIN", "SUM", "COUNT", "AVG", "ORDER", "GROUP",
  "BY", "ASC", "HAVING", "NUMBER", "FLOAT", "ID", "PATH", "SSS", "STAR",
  "STRING_V", "$accept", "commands", "command", "exit", "help", "sync",
  "begin", "commit", "rollback", "drop_table", "show_tables",
  "show_indexes", "desc_table", "create_index", "index_attr_list",
  "drop_index", "create_table", "attr_def_list", "attr_def", "number",
  "type", "is_null", "ID_get", "insert", "value_tuple", "value_list",
  "insert_vaule", "value", "delete", "update", "update_list", "set_list",
  "sub_select", "sub_select_attr", "sub_attr_list", "sub_agg_func",
  "sub_rel_list", "select", "select_attr", "attr_list", "rel_list",
  "inner", "on", "where", "condition_list", "condition", "sub_where",
  "sub_condition_list", "sub_condition", "sub_value", "sub_comOp", "comOp",
  "load_data", "order_by", "order_attr", "order_attr_list", "group_by",
  "group_attr", "group_attr_list", "having", "having_condition",
  "having_condition_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324
};
#endif

#define YYPACT_NINF (-465)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -465,   187,  -465,   300,    26,   189,   -13,   144,    67,    45,
      57,    25,    92,    99,   114,   129,   155,   151,  -465,  -465,
    -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,
    -465,  -465,  -465,  -465,  -465,  -465,  -465,   107,   179,   141,
     146,   165,   224,   239,   243,   252,   265,     1,   233,   280,
     262,   313,   285,  -465,   253,   254,   286,  -465,  -465,  -465,
    -465,  -465,   276,   305,   258,   287,   321,   323,   263,   264,
     266,   -37,   268,   230,   145,  -465,  -465,   270,  -465,  -465,
     277,   296,   311,   281,   311,   271,   284,   314,   288,  -465,
    -465,    -5,     4,     5,   336,   337,   338,     9,   340,   341,
     342,   343,   344,   161,   233,   233,   345,   359,   346,     2,
     362,   326,   369,   347,  -465,   354,   273,   309,   358,   233,
     315,   233,   316,   233,   317,   233,   233,   233,   233,   318,
     319,   320,   322,    87,   324,   199,  -465,  -465,  -465,   325,
     195,  -465,   -19,   366,  -465,  -465,  -465,   115,  -465,   173,
     352,  -465,    46,  -465,   372,   284,   361,  -465,  -465,  -465,
    -465,     8,   371,   327,  -465,   376,  -465,   378,  -465,   379,
    -465,  -465,  -465,  -465,   381,    53,    59,    85,   382,   384,
     385,    86,   233,   233,   345,   367,   348,   311,   349,  -465,
    -465,  -465,  -465,   386,   194,   388,   350,   356,  -465,  -465,
    -465,  -465,  -465,  -465,   370,  -465,    20,    33,     2,  -465,
     391,   351,   354,   408,   355,   374,  -465,  -465,   357,   393,
     233,   233,   233,   233,   233,   360,   233,   363,   233,   364,
     233,   233,   233,   233,   365,  -465,  -465,  -465,   368,   345,
     349,   375,   373,   -19,   399,   402,   403,   404,   406,   407,
     176,   412,   394,   412,  -465,   173,  -465,  -465,  -465,  -465,
     398,  -465,   352,   377,  -465,   431,  -465,  -465,  -465,   418,
    -465,   393,   380,   419,  -465,  -465,  -465,  -465,  -465,   420,
    -465,   421,  -465,   422,  -465,  -465,  -465,  -465,   423,   345,
     405,   373,   383,   387,   389,   386,   425,   390,   392,   395,
     190,   396,   235,   242,  -465,  -465,   397,  -465,    82,   400,
    -465,   401,  -465,   274,   432,   393,   446,   233,   233,   233,
     233,   405,     2,   257,   389,     0,   433,   409,   248,   450,
    -465,   437,   453,    89,    90,   105,   440,   441,   445,   109,
     197,   412,   412,   412,   447,   435,  -465,  -465,    46,  -465,
     464,  -465,  -465,  -465,  -465,  -465,  -465,   257,   352,  -465,
     465,  -465,   410,  -465,   383,  -465,   442,   451,   452,   455,
     456,   459,   460,   444,  -465,   -19,  -465,  -465,   414,  -465,
     415,  -465,   416,  -465,  -465,  -465,  -465,   417,   246,  -465,
    -465,  -465,  -465,   424,   454,   426,   391,  -465,  -465,  -465,
    -465,     7,   433,   427,   409,  -465,   428,   429,   430,   198,
     434,   248,  -465,   386,   466,   467,   468,   470,   412,   412,
     447,   -24,  -465,  -465,  -465,  -465,  -465,  -465,  -465,   451,
     130,   139,   153,   472,   160,   478,   175,   444,   479,  -465,
    -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,   188,
    -465,   449,   229,  -465,   173,   436,   173,   438,   173,   439,
     173,   173,   443,   173,   173,   448,  -465,   425,   457,   458,
    -465,  -465,  -465,  -465,  -465,  -465,   461,  -465,    61,   -24,
    -465,    66,    46,   480,    46,   484,    46,   487,    46,    46,
     488,    46,    46,   489,  -465,   229,  -465,  -465,  -465,  -465,
     449,   482,  -465,  -465,   173,  -465,   173,  -465,   173,  -465,
    -465,   173,  -465,  -465,   173,    76,  -465,   462,    46,    46,
      46,    46,    46,   483,  -465,  -465,  -465,  -465,  -465,  -465,
    -465,   463,  -465
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,    21,
      20,    15,    16,    17,    18,     9,    10,    11,    12,    13,
      14,     8,     5,     7,     6,     4,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   111,   111,     0,
       0,     0,     0,    24,     0,     0,     0,    25,    26,    27,
      23,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,    96,     0,    31,    29,
       0,     0,   133,     0,   133,     0,     0,     0,     0,    28,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   111,   111,   111,   126,     0,     0,     0,
       0,     0,     0,     0,    50,    38,     0,     0,     0,   111,
       0,   111,     0,   111,     0,   111,   111,   111,   111,     0,
       0,     0,     0,     0,     0,     0,   112,    98,    99,     0,
     128,    30,     0,     0,    64,    60,    61,     0,    62,     0,
     135,    65,     0,    66,     0,     0,     0,    43,    44,    45,
      46,    47,     0,     0,   100,     0,   102,     0,   104,     0,
     106,   108,   107,   109,     0,     0,     0,     0,     0,     0,
       0,     0,   111,   111,   126,     0,     0,   133,   180,    59,
      56,    57,    58,    54,     0,     0,     0,     0,   169,   170,
     171,   172,   173,   174,   177,   175,     0,     0,     0,   134,
      68,     0,    38,     0,     0,     0,    49,    41,     0,    34,
     111,   111,   111,   111,   111,     0,   111,     0,   111,     0,
     111,   111,   111,   111,     0,   114,   113,   127,     0,   126,
     180,     0,   190,     0,     0,     0,     0,     0,     0,     0,
      76,    76,     0,    76,    63,     0,   176,   178,   139,   137,
     140,   138,   135,     0,    67,     0,    39,    37,    42,     0,
      48,    34,     0,     0,   101,   103,   105,   110,   115,     0,
     117,     0,   119,     0,   121,   123,   122,   124,     0,   126,
     131,   190,     0,     0,   196,    54,    52,     0,     0,     0,
       0,     0,     0,     0,    72,    71,     0,    75,     0,     0,
     136,     0,   179,    47,     0,    34,     0,   111,   111,   111,
     111,   131,     0,   128,   196,   182,   188,     0,     0,     0,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,    76,    76,    76,    92,     0,   141,   142,     0,    40,
       0,    35,    32,   116,   118,   120,   125,   128,   135,   130,
       0,   184,     0,   183,     0,   181,   192,   194,     0,     0,
       0,     0,     0,   210,    94,     0,    51,    81,     0,    83,
       0,    85,     0,    87,    89,    88,    90,     0,     0,    77,
      80,    73,    74,     0,   144,     0,    68,    33,   129,   132,
      95,   185,   188,     0,     0,   191,     0,     0,     0,     0,
       0,     0,   197,    54,     0,     0,     0,     0,    76,    76,
      92,     0,    70,   143,    69,   187,   186,   189,   193,   194,
       0,     0,     0,     0,     0,     0,     0,   210,     0,    82,
      84,    86,    91,    79,    78,    93,   158,   155,   156,     0,
     157,   146,     0,   195,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   211,    52,     0,     0,
     159,   160,   161,   162,   163,   164,   167,   165,     0,     0,
     145,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,     0,   166,   168,   150,   148,
     146,   151,   149,   198,     0,   200,     0,   202,     0,   206,
     204,     0,   207,   208,     0,     0,   147,     0,     0,     0,
       0,     0,     0,     0,   152,   153,   199,   201,   203,   205,
     209,     0,   154
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,
    -465,  -465,  -465,  -465,  -256,  -465,  -465,   297,   411,  -465,
    -465,   201,  -465,  -465,    48,  -292,  -238,  -152,  -465,  -465,
    -465,   120,  -465,  -465,  -249,   215,    98,  -465,  -465,   -47,
    -177,  -311,   200,   -76,  -253,  -202,  -465,    19,    41,  -464,
    -442,  -113,  -465,   283,   162,   122,   234,   125,   101,   207,
     121,    96
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,   273,    30,    31,   156,   115,   269,
     161,   217,   116,    32,   332,   244,   193,   149,    33,    34,
      84,   264,   195,   252,   304,   253,   394,    35,    49,    75,
     140,   187,   323,   110,   209,   150,   422,   480,   451,   452,
     478,   206,    36,   242,   326,   365,   294,   367,   405,   329,
     373,   412
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     210,    76,   305,   330,   307,   295,   262,   237,   112,   310,
     481,   361,   359,   119,   499,   314,   446,   502,   425,   143,
      73,   189,   121,   123,   120,   214,    94,   128,    95,   362,
      74,    96,    40,   122,   124,    41,   207,   143,   129,   447,
     448,   449,   144,   450,   190,   191,   398,   215,   192,   216,
     143,   524,    50,   515,   259,   261,   136,   137,   138,   351,
     144,   363,   290,   143,   188,   145,   146,   147,   426,   148,
      53,   224,   164,   144,   166,    54,   168,   226,   170,   171,
     172,   173,   225,   145,   146,   258,   144,   148,   227,    55,
      56,   389,   390,   391,   392,    57,   145,   146,   260,   143,
     148,   446,    58,   228,   233,   399,   446,   377,   379,   145,
     146,   240,   321,   148,   229,   234,   446,    59,   378,   380,
     358,   438,   144,   381,   447,   448,   498,   386,   450,   447,
     448,   501,    60,   450,   382,   235,   236,   413,   387,   447,
     448,   523,   308,   450,   196,   145,   146,   345,   454,   148,
     178,    51,   179,    52,   197,   180,   346,   456,    61,   455,
     198,   199,   200,   201,   202,   203,   204,   205,   457,   443,
     444,   458,    63,   274,   275,   276,   277,   278,   461,   280,
      73,   282,   459,   284,   285,   286,   287,     2,    64,   462,
     135,     3,     4,   464,    62,   302,   396,     5,     6,     7,
       8,     9,    10,    11,   465,   303,    65,    12,    13,    14,
     104,    66,   197,   105,    15,    16,   302,   468,   198,   199,
     200,   201,   202,   203,   204,   205,   388,   469,   109,    17,
      67,   185,   186,   470,   471,   472,   473,   474,   475,   476,
     477,    68,    42,    43,    44,    45,    46,   245,   246,   247,
     248,   249,    73,   336,    47,   337,    69,    48,   338,   250,
      70,   433,   251,   434,   182,    78,   435,   183,   469,    71,
     353,   354,   355,   356,   470,   471,   472,   473,   474,   475,
     476,   477,    72,    98,    99,   100,   101,   102,   245,   246,
     247,   248,   249,   185,   186,   103,   157,   158,   159,   160,
     340,   368,   369,   370,   371,   372,    37,   342,    38,    39,
     343,   418,    77,   215,   419,   216,    79,    80,    81,    82,
      85,    83,    86,    87,    89,    88,    90,   108,    91,    92,
     503,    93,   505,    97,   507,   106,   509,   510,   113,   512,
     513,   482,   107,   484,   109,   486,   111,   488,   489,   114,
     491,   492,   117,   118,   125,   126,   127,   130,   131,   132,
     133,   134,   141,   142,   139,   151,   526,   527,   528,   529,
     530,   152,   153,   155,   162,   163,   194,   154,   211,   213,
     165,   167,   169,   174,   175,   176,   208,   177,   218,   181,
     184,   518,   219,   519,   220,   520,   221,   222,   521,   223,
     230,   522,   231,   232,   238,   243,   254,   241,   256,   257,
     263,   267,   272,   239,   270,   255,   265,   296,   268,   297,
     298,   299,   271,   300,   301,   279,   306,   309,   281,   283,
     288,   302,   293,   289,   312,   292,   313,   316,   317,   318,
     319,   320,   311,   322,   331,   315,   348,   327,   325,   352,
     350,   328,   364,   374,   375,   333,   376,   334,   383,   384,
     335,   339,   344,   385,   395,   347,   393,   397,   400,   406,
     404,   403,   407,   408,   366,   401,   409,   410,   411,   414,
     415,   416,   417,   479,   439,   440,   441,   421,   442,   420,
     460,   423,   428,   430,   431,   432,   463,   467,   504,   436,
     497,   483,   506,   485,   487,   508,   511,   514,   490,   266,
     496,   517,   531,   493,   349,   494,   424,   341,   445,   516,
     500,   357,   495,   291,   427,   324,   402,   525,   532,   429,
     453,   360,   437,   466,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   212
};

static const yytype_int16 yycheck[] =
{
     152,    48,   251,   295,   253,   243,   208,   184,    84,   262,
     452,    11,   323,    18,   478,   271,    40,   481,    11,    17,
      19,    40,    18,    18,    29,    17,    63,    18,    65,    29,
      29,    68,     6,    29,    29,     9,   149,    17,    29,    63,
      64,    65,    40,    67,    63,    64,   357,    39,    67,    41,
      17,   515,    65,   495,   206,   207,   103,   104,   105,   315,
      40,    61,   239,    17,   140,    63,    64,    65,    61,    67,
       3,    18,   119,    40,   121,    30,   123,    18,   125,   126,
     127,   128,    29,    63,    64,    65,    40,    67,    29,    32,
      65,   340,   341,   342,   343,     3,    63,    64,    65,    17,
      67,    40,     3,    18,    18,   358,    40,    18,    18,    63,
      64,   187,   289,    67,    29,    29,    40,     3,    29,    29,
     322,   413,    40,    18,    63,    64,    65,    18,    67,    63,
      64,    65,     3,    67,    29,   182,   183,   375,    29,    63,
      64,    65,   255,    67,    29,    63,    64,    65,    18,    67,
      63,     7,    65,     9,    39,    68,   308,    18,     3,    29,
      45,    46,    47,    48,    49,    50,    51,    52,    29,   418,
     419,    18,    65,   220,   221,   222,   223,   224,    18,   226,
      19,   228,    29,   230,   231,   232,   233,     0,     9,    29,
      29,     4,     5,    18,    43,    19,   348,    10,    11,    12,
      13,    14,    15,    16,    29,    29,    65,    20,    21,    22,
      65,    65,    39,    68,    27,    28,    19,    29,    45,    46,
      47,    48,    49,    50,    51,    52,    29,    39,    33,    42,
      65,    36,    37,    45,    46,    47,    48,    49,    50,    51,
      52,    17,    53,    54,    55,    56,    57,    53,    54,    55,
      56,    57,    19,    63,    65,    65,    17,    68,    68,    65,
      17,    63,    68,    65,    65,     3,    68,    68,    39,    17,
     317,   318,   319,   320,    45,    46,    47,    48,    49,    50,
      51,    52,    17,    53,    54,    55,    56,    57,    53,    54,
      55,    56,    57,    36,    37,    65,    23,    24,    25,    26,
      65,    53,    54,    55,    56,    57,     6,    65,     8,     9,
      68,    65,    32,    39,    68,    41,     3,    32,    65,    65,
      44,    35,    17,    65,     3,    38,     3,    31,    65,    65,
     482,    65,   484,    65,   486,    65,   488,   489,    67,   491,
     492,   454,    65,   456,    33,   458,    65,   460,   461,    65,
     463,   464,    38,    65,    18,    18,    18,    17,    17,    17,
      17,    17,     3,    17,    19,     3,   518,   519,   520,   521,
     522,    45,     3,    19,    65,    17,    10,    30,     6,    18,
      65,    65,    65,    65,    65,    65,    34,    65,    17,    65,
      65,   504,    65,   506,    18,   508,    18,    18,   511,    18,
      18,   514,    18,    18,    37,    19,    18,    58,    52,    39,
      19,     3,    19,    65,    40,    65,    65,    18,    63,    17,
      17,    17,    65,    17,    17,    65,    32,    29,    65,    65,
      65,    19,    59,    65,     3,    60,    18,    18,    18,    18,
      18,    18,    65,    38,    19,    65,    45,    60,    65,     3,
      18,    62,    19,     3,    17,    65,     3,    65,    18,    18,
      65,    65,    65,    18,    29,    65,    19,     3,     3,    17,
      19,    29,    17,    17,    65,    65,    17,    17,    34,    65,
      65,    65,    65,    34,    18,    18,    18,    33,    18,    65,
      18,    65,    65,    65,    65,    65,    18,    18,    18,    65,
      39,    65,    18,    65,    65,    18,    18,    18,    65,   212,
      52,    29,    29,    65,   313,   467,   396,   302,   420,   500,
     479,   321,    65,   240,   402,   291,   364,    65,    65,   404,
     429,   324,   411,   437,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   155
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    71,     0,     4,     5,    10,    11,    12,    13,    14,
      15,    16,    20,    21,    22,    27,    28,    42,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      85,    86,    93,    98,    99,   107,   122,     6,     8,     9,
       6,     9,    53,    54,    55,    56,    57,    65,    68,   108,
      65,     7,     9,     3,    30,    32,    65,     3,     3,     3,
       3,     3,    43,    65,     9,    65,    65,    65,    17,    17,
      17,    17,    17,    19,    29,   109,   109,    32,     3,     3,
      32,    65,    65,    35,   100,    44,    17,    65,    38,     3,
       3,    65,    65,    65,    63,    65,    68,    65,    53,    54,
      55,    56,    57,    65,    65,    68,    65,    65,    31,    33,
     113,    65,   113,    67,    65,    88,    92,    38,    65,    18,
      29,    18,    29,    18,    29,    18,    18,    18,    18,    29,
      17,    17,    17,    17,    17,    29,   109,   109,   109,    19,
     110,     3,    17,    17,    40,    63,    64,    65,    67,    97,
     115,     3,    45,     3,    30,    19,    87,    23,    24,    25,
      26,    90,    65,    17,   109,    65,   109,    65,   109,    65,
     109,   109,   109,   109,    65,    65,    65,    65,    63,    65,
      68,    65,    65,    68,    65,    36,    37,   111,   113,    40,
      63,    64,    67,    96,    10,   102,    29,    39,    45,    46,
      47,    48,    49,    50,    51,    52,   121,   121,    34,   114,
      97,     6,    88,    18,    17,    39,    41,    91,    17,    65,
      18,    18,    18,    18,    18,    29,    18,    29,    18,    29,
      18,    18,    18,    18,    29,   109,   109,   110,    37,    65,
     113,    58,   123,    19,    95,    53,    54,    55,    56,    57,
      65,    68,   103,   105,    18,    65,    52,    39,    65,    97,
      65,    97,   115,    19,   101,    65,    87,     3,    63,    89,
      40,    65,    19,    84,   109,   109,   109,   109,   109,    65,
     109,    65,   109,    65,   109,   109,   109,   109,    65,    65,
     110,   123,    60,    59,   126,    96,    18,    17,    17,    17,
      17,    17,    19,    29,   104,   104,    32,   104,   121,    29,
     114,    65,     3,    18,    84,    65,    18,    18,    18,    18,
      18,   110,    38,   112,   126,    65,   124,    60,    62,   129,
      95,    19,    94,    65,    65,    65,    63,    65,    68,    65,
      65,   105,    65,    68,    65,    65,    97,    65,    45,    91,
      18,    84,     3,   109,   109,   109,   109,   112,   115,   111,
     129,    11,    29,    61,    19,   125,    65,   127,    53,    54,
      55,    56,    57,   130,     3,    17,     3,    18,    29,    18,
      29,    18,    29,    18,    18,    18,    18,    29,    29,   104,
     104,   104,   104,    19,   106,    29,    97,     3,   111,   114,
       3,    65,   124,    29,    19,   128,    17,    17,    17,    17,
      17,    34,   131,    96,    65,    65,    65,    65,    65,    68,
      65,    33,   116,    65,   101,    11,    61,   125,    65,   127,
      65,    65,    65,    63,    65,    68,    65,   130,    95,    18,
      18,    18,    18,   104,   104,   106,    40,    63,    64,    65,
      67,   118,   119,   128,    18,    29,    18,    29,    18,    29,
      18,    18,    29,    18,    18,    29,   131,    18,    29,    39,
      45,    46,    47,    48,    49,    50,    51,    52,   120,    34,
     117,   120,   121,    65,   121,    65,   121,    65,   121,   121,
      65,   121,   121,    65,    94,    65,    52,    39,    65,   119,
     118,    65,   119,    97,    18,    97,    18,    97,    18,    97,
      97,    18,    97,    97,    18,   120,   117,    29,   121,   121,
     121,   121,   121,    65,   119,    65,    97,    97,    97,    97,
      97,    29,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    71,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    83,    84,    84,    85,    86,    87,    87,
      88,    88,    89,    90,    90,    90,    90,    91,    91,    91,
      92,    93,    94,    94,    95,    95,    96,    96,    96,    96,
      97,    97,    97,    97,    97,    98,    99,   100,   101,   101,
     102,   103,   103,   103,   103,   103,   104,   104,   104,   104,
     104,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   106,   106,   107,   107,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   110,   110,   111,   111,
     111,   112,   112,   113,   113,   114,   114,   115,   115,   115,
     115,   115,   115,   115,   116,   116,   117,   117,   118,   118,
     118,   118,   118,   118,   118,   119,   119,   119,   119,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   122,
     123,   123,   124,   124,   124,   124,   124,   124,   125,   125,
     126,   126,   127,   127,   128,   128,   129,   129,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     131,   131
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     4,     3,
       5,     3,    10,    11,     0,     3,     4,     8,     0,     3,
       6,     3,     1,     1,     1,     1,     1,     0,     2,     1,
       1,    10,     0,     6,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     5,     5,     5,     0,     5,
       6,     2,     2,     4,     4,     2,     0,     3,     5,     5,
       3,     4,     6,     4,     6,     4,     6,     4,     4,     4,
       4,     6,     0,     3,    10,    11,     2,     2,     4,     4,
       5,     7,     5,     7,     5,     7,     5,     5,     5,     5,
       7,     0,     3,     5,     5,     6,     8,     6,     8,     6,
       8,     6,     6,     6,     6,     8,     0,     3,     0,     6,
       5,     0,     3,     0,     3,     0,     3,     3,     3,     3,
       3,     5,     5,     7,     0,     3,     0,     3,     3,     3,
       3,     3,     5,     5,     7,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     8,
       0,     4,     1,     2,     2,     3,     4,     4,     0,     3,
       0,     4,     1,     3,     0,     3,     0,     3,     6,     8,
       6,     8,     6,     8,     6,     8,     6,     6,     6,     8,
       0,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *scanner)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, scanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, void *scanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, void *scanner)
{
  YYUSE (yyvaluep);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 22: /* exit: EXIT SEMICOLON  */
#line 185 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1623 "yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 190 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1631 "yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 195 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1639 "yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 201 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1647 "yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 207 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1655 "yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 213 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1663 "yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 219 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1672 "yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 225 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1680 "yacc_sql.tab.c"
    break;

  case 30: /* show_indexes: SHOW INDEX FROM ID SEMICOLON  */
#line 230 "yacc_sql.y"
                                     {
	  CONTEXT->ssql->flag = SCF_SHOW_INDEXES;
	  create_show_index(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
	}
#line 1689 "yacc_sql.tab.c"
    break;

  case 31: /* desc_table: DESC ID SEMICOLON  */
#line 237 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1698 "yacc_sql.tab.c"
    break;

  case 32: /* create_index: CREATE INDEX ID ON ID LBRACE ID index_attr_list RBRACE SEMICOLON  */
#line 245 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[-3].string));
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), DEFAULT_INDEX);
		}
#line 1708 "yacc_sql.tab.c"
    break;

  case 33: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE ID index_attr_list RBRACE SEMICOLON  */
#line 251 "yacc_sql.y"
        {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
            create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[-3].string));
            create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), UNIQUE_INDEX);
        }
#line 1718 "yacc_sql.tab.c"
    break;

  case 35: /* index_attr_list: COMMA ID index_attr_list  */
#line 261 "yacc_sql.y"
                               {
            create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[-1].string));
        }
#line 1726 "yacc_sql.tab.c"
    break;

  case 36: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 268 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1735 "yacc_sql.tab.c"
    break;

  case 37: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 275 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1747 "yacc_sql.tab.c"
    break;

  case 39: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 285 "yacc_sql.y"
                                   {    }
#line 1753 "yacc_sql.tab.c"
    break;

  case 40: /* attr_def: ID_get type LBRACE number RBRACE is_null  */
#line 290 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-4].number), (yyvsp[-2].number), CONTEXT->nullable);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;
			CONTEXT->value_length++;
		}
#line 1768 "yacc_sql.tab.c"
    break;

  case 41: /* attr_def: ID_get type is_null  */
#line 301 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-1].number), 4, CONTEXT->nullable);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}
#line 1783 "yacc_sql.tab.c"
    break;

  case 42: /* number: NUMBER  */
#line 313 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1789 "yacc_sql.tab.c"
    break;

  case 43: /* type: INT_T  */
#line 316 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1795 "yacc_sql.tab.c"
    break;

  case 44: /* type: STRING_T  */
#line 317 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1801 "yacc_sql.tab.c"
    break;

  case 45: /* type: FLOAT_T  */
#line 318 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1807 "yacc_sql.tab.c"
    break;

  case 46: /* type: DATE_T  */
#line 319 "yacc_sql.y"
                { (yyval.number)=DATES; }
#line 1813 "yacc_sql.tab.c"
    break;

  case 47: /* is_null: %empty  */
#line 322 "yacc_sql.y"
                   {
		CONTEXT->nullable = 0;
	}
#line 1821 "yacc_sql.tab.c"
    break;

  case 48: /* is_null: NOT NULL__  */
#line 325 "yacc_sql.y"
                    {
		CONTEXT->nullable = 0;
	}
#line 1829 "yacc_sql.tab.c"
    break;

  case 49: /* is_null: NULLABLE  */
#line 328 "yacc_sql.y"
                   {
		CONTEXT->nullable = 1;
	}
#line 1837 "yacc_sql.tab.c"
    break;

  case 50: /* ID_get: ID  */
#line 334 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1846 "yacc_sql.tab.c"
    break;

  case 51: /* insert: INSERT INTO ID VALUES LBRACE insert_vaule value_list RBRACE value_tuple SEMICOLON  */
#line 343 "yacc_sql.y"
                {
			// CONTEXT->values[CONTEXT->value_length++] = *$6;

			CONTEXT->ssql->flag=SCF_INSERT;//"insert";
			// CONTEXT->ssql->sstr.insertion.relation_name = $3;
			// CONTEXT->ssql->sstr.insertion.value_num = CONTEXT->value_length;
			// for(i = 0; i < CONTEXT->value_length; i++){
			// 	CONTEXT->ssql->sstr.insertion.values[i] = CONTEXT->values[i];
      // }
			inserts_init(&CONTEXT->ssql->sstr.insertion, (yyvsp[-7].string), CONTEXT->inserts_more, CONTEXT->insert_length);

      //临时变量清零
      // CONTEXT->value_length=0;
	  inserts_more_destroy(CONTEXT->inserts_more, &CONTEXT->insert_length);
    }
#line 1866 "yacc_sql.tab.c"
    break;

  case 53: /* value_tuple: COMMA LBRACE insert_vaule value_list RBRACE value_tuple  */
#line 361 "yacc_sql.y"
                                                                  {

	  }
#line 1874 "yacc_sql.tab.c"
    break;

  case 54: /* value_list: %empty  */
#line 368 "yacc_sql.y"
        {
		inserts_more_init(&CONTEXT->inserts_more[CONTEXT->insert_length].value_num, &CONTEXT->insert_length);
	}
#line 1882 "yacc_sql.tab.c"
    break;

  case 55: /* value_list: COMMA insert_vaule value_list  */
#line 371 "yacc_sql.y"
                                     { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1890 "yacc_sql.tab.c"
    break;

  case 56: /* insert_vaule: NUMBER  */
#line 376 "yacc_sql.y"
          {	
		// 匹配时insert规则时，保存在CONTEXT->inserts_more->values中
  		value_init_integer(&CONTEXT->inserts_more[CONTEXT->insert_length].values[CONTEXT->inserts_more[CONTEXT->insert_length].value_num++], (yyvsp[0].number));
		// 匹配Conditon规则时，values需要保存在CONTEXT->values中,使用下面的value规则
		}
#line 1900 "yacc_sql.tab.c"
    break;

  case 57: /* insert_vaule: FLOAT  */
#line 381 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->inserts_more[CONTEXT->insert_length].values[CONTEXT->inserts_more[CONTEXT->insert_length].value_num++], (yyvsp[0].floats));
		}
#line 1908 "yacc_sql.tab.c"
    break;

  case 58: /* insert_vaule: SSS  */
#line 384 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->inserts_more[CONTEXT->insert_length].values[CONTEXT->inserts_more[CONTEXT->insert_length].value_num++], (yyvsp[0].string));
		}
#line 1917 "yacc_sql.tab.c"
    break;

  case 59: /* insert_vaule: NULL__  */
#line 388 "yacc_sql.y"
            {
		value_init_null(&CONTEXT->inserts_more[CONTEXT->insert_length].values[CONTEXT->inserts_more[CONTEXT->insert_length].value_num++]);
	}
#line 1925 "yacc_sql.tab.c"
    break;

  case 60: /* value: NUMBER  */
#line 392 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1933 "yacc_sql.tab.c"
    break;

  case 61: /* value: FLOAT  */
#line 395 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1941 "yacc_sql.tab.c"
    break;

  case 62: /* value: SSS  */
#line 398 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 1950 "yacc_sql.tab.c"
    break;

  case 63: /* value: LBRACE sub_select RBRACE  */
#line 402 "yacc_sql.y"
                                  {
		value_init_query(&CONTEXT->values[CONTEXT->value_length++], GET_SUB_CONTEXT->ssql);
		// 赋值后将子句清空
		memset(GET_SUB_CONTEXT->ssql, 0, sizeof(*GET_SUB_CONTEXT->ssql));
	}
#line 1960 "yacc_sql.tab.c"
    break;

  case 64: /* value: NULL__  */
#line 408 "yacc_sql.y"
                {
		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
	}
#line 1968 "yacc_sql.tab.c"
    break;

  case 65: /* delete: DELETE FROM ID where SEMICOLON  */
#line 415 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 1980 "yacc_sql.tab.c"
    break;

  case 66: /* update: UPDATE ID update_list where SEMICOLON  */
#line 425 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-3].string), CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 1990 "yacc_sql.tab.c"
    break;

  case 67: /* update_list: SET ID EQ value set_list  */
#line 432 "yacc_sql.y"
                            {
		SetValue set_value;
		set_value_init(&set_value, (yyvsp[-3].string), &CONTEXT->values[--CONTEXT->value_length]);
		update_append_value_list(&CONTEXT->ssql->sstr.update, &set_value);
	}
#line 2000 "yacc_sql.tab.c"
    break;

  case 69: /* set_list: COMMA ID EQ value set_list  */
#line 441 "yacc_sql.y"
                                    {
		SetValue set_value;
		set_value_init(&set_value, (yyvsp[-3].string), &CONTEXT->values[--CONTEXT->value_length]);
		update_append_value_list(&CONTEXT->ssql->sstr.update, &set_value);
	}
#line 2010 "yacc_sql.tab.c"
    break;

  case 70: /* sub_select: SELECT sub_select_attr FROM ID sub_rel_list sub_where  */
#line 449 "yacc_sql.y"
                                                         {
		// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
		selects_append_relation(&GET_SUB_CONTEXT->ssql->sstr.selection, (yyvsp[-2].string));
		selects_append_conditions(&GET_SUB_CONTEXT->ssql->sstr.selection, GET_SUB_CONTEXT->conditions, GET_SUB_CONTEXT->condition_length);
		GET_SUB_CONTEXT->ssql->flag=SCF_SELECT;//"select";
		// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;
		//临时变量清零
		GET_SUB_CONTEXT->condition_length=0;
		GET_SUB_CONTEXT->from_length=0;
		GET_SUB_CONTEXT->select_length=0;
		GET_SUB_CONTEXT->value_length = 0;
	}
#line 2027 "yacc_sql.tab.c"
    break;

  case 71: /* sub_select_attr: STAR sub_attr_list  */
#line 463 "yacc_sql.y"
                      {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2037 "yacc_sql.tab.c"
    break;

  case 72: /* sub_select_attr: ID sub_attr_list  */
#line 468 "yacc_sql.y"
                       {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2047 "yacc_sql.tab.c"
    break;

  case 73: /* sub_select_attr: ID DOT ID sub_attr_list  */
#line 473 "yacc_sql.y"
                                  {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2057 "yacc_sql.tab.c"
    break;

  case 74: /* sub_select_attr: ID DOT STAR sub_attr_list  */
#line 478 "yacc_sql.y"
                                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2067 "yacc_sql.tab.c"
    break;

  case 75: /* sub_select_attr: sub_agg_func sub_attr_list  */
#line 483 "yacc_sql.y"
                                    {
	}
#line 2074 "yacc_sql.tab.c"
    break;

  case 77: /* sub_attr_list: COMMA ID sub_attr_list  */
#line 488 "yacc_sql.y"
                             {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
#line 2086 "yacc_sql.tab.c"
    break;

  case 78: /* sub_attr_list: COMMA ID DOT STAR sub_attr_list  */
#line 495 "yacc_sql.y"
                                          {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2096 "yacc_sql.tab.c"
    break;

  case 79: /* sub_attr_list: COMMA ID DOT ID sub_attr_list  */
#line 500 "yacc_sql.y"
                                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
#line 2108 "yacc_sql.tab.c"
    break;

  case 81: /* sub_agg_func: MAX LBRACE ID RBRACE  */
#line 511 "yacc_sql.y"
                             {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_MAX);
	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2118 "yacc_sql.tab.c"
    break;

  case 82: /* sub_agg_func: MAX LBRACE ID DOT ID RBRACE  */
#line 516 "yacc_sql.y"
                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_MAX);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2128 "yacc_sql.tab.c"
    break;

  case 83: /* sub_agg_func: MIN LBRACE ID RBRACE  */
#line 521 "yacc_sql.y"
                               {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_MIN);
	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2138 "yacc_sql.tab.c"
    break;

  case 84: /* sub_agg_func: MIN LBRACE ID DOT ID RBRACE  */
#line 526 "yacc_sql.y"
                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_MIN);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2148 "yacc_sql.tab.c"
    break;

  case 85: /* sub_agg_func: SUM LBRACE ID RBRACE  */
#line 531 "yacc_sql.y"
                               {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_SUM);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2158 "yacc_sql.tab.c"
    break;

  case 86: /* sub_agg_func: SUM LBRACE ID DOT ID RBRACE  */
#line 536 "yacc_sql.y"
                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_SUM);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2168 "yacc_sql.tab.c"
    break;

  case 87: /* sub_agg_func: COUNT LBRACE NUMBER RBRACE  */
#line 541 "yacc_sql.y"
                                     {
       	  RelAttr attr;
       	  char *str = malloc(10 * sizeof(char));
       	  snprintf(str, 10, "%d", (yyvsp[-1].number));
       	  aggregation_attr_init(&attr, NULL, str, AGG_COUNT);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2180 "yacc_sql.tab.c"
    break;

  case 88: /* sub_agg_func: COUNT LBRACE STAR RBRACE  */
#line 548 "yacc_sql.y"
                                   {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, "*", AGG_COUNT);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2190 "yacc_sql.tab.c"
    break;

  case 89: /* sub_agg_func: COUNT LBRACE ID RBRACE  */
#line 553 "yacc_sql.y"
                                 {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_COUNT);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2200 "yacc_sql.tab.c"
    break;

  case 90: /* sub_agg_func: AVG LBRACE ID RBRACE  */
#line 558 "yacc_sql.y"
                               {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_AVG);
	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2210 "yacc_sql.tab.c"
    break;

  case 91: /* sub_agg_func: AVG LBRACE ID DOT ID RBRACE  */
#line 563 "yacc_sql.y"
                                      {
	  RelAttr attr;
	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_AVG);
	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2220 "yacc_sql.tab.c"
    break;

  case 93: /* sub_rel_list: COMMA ID sub_rel_list  */
#line 572 "yacc_sql.y"
                            {	
			selects_append_relation(&GET_SUB_CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 2228 "yacc_sql.tab.c"
    break;

  case 94: /* select: SELECT select_attr FROM ID rel_list where order_by group_by having SEMICOLON  */
#line 578 "yacc_sql.y"
                {
			// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-6].string));

			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);

			CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;

			//临时变量清零
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
#line 2248 "yacc_sql.tab.c"
    break;

  case 95: /* select: SELECT select_attr FROM ID rel_list inner where order_by group_by having SEMICOLON  */
#line 594 "yacc_sql.y"
                {
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-7].string));
			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);

			CONTEXT->ssql->flag=SCF_SELECT;
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
#line 2263 "yacc_sql.tab.c"
    break;

  case 96: /* select_attr: STAR attr_list  */
#line 607 "yacc_sql.y"
                  {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2273 "yacc_sql.tab.c"
    break;

  case 97: /* select_attr: ID attr_list  */
#line 612 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2283 "yacc_sql.tab.c"
    break;

  case 98: /* select_attr: ID DOT ID attr_list  */
#line 617 "yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2293 "yacc_sql.tab.c"
    break;

  case 99: /* select_attr: ID DOT STAR attr_list  */
#line 622 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2303 "yacc_sql.tab.c"
    break;

  case 100: /* select_attr: MAX LBRACE ID RBRACE attr_list  */
#line 628 "yacc_sql.y"
                                         {
          RelAttr attr;
          aggregation_attr_init(&attr, NULL, (yyvsp[-2].string), AGG_MAX);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 2313 "yacc_sql.tab.c"
    break;

  case 101: /* select_attr: MAX LBRACE ID DOT ID RBRACE attr_list  */
#line 633 "yacc_sql.y"
                                                {
           RelAttr attr;
           aggregation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), AGG_MAX);
           selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
         }
#line 2323 "yacc_sql.tab.c"
    break;

  case 102: /* select_attr: MIN LBRACE ID RBRACE attr_list  */
#line 638 "yacc_sql.y"
                                         {
          RelAttr attr;
          aggregation_attr_init(&attr, NULL, (yyvsp[-2].string), AGG_MIN);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 2333 "yacc_sql.tab.c"
    break;

  case 103: /* select_attr: MIN LBRACE ID DOT ID RBRACE attr_list  */
#line 643 "yacc_sql.y"
                                                {
          RelAttr attr;
          aggregation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), AGG_MIN);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 2343 "yacc_sql.tab.c"
    break;

  case 104: /* select_attr: SUM LBRACE ID RBRACE attr_list  */
#line 648 "yacc_sql.y"
                                         {
          RelAttr attr;
          aggregation_attr_init(&attr, NULL, (yyvsp[-2].string), AGG_SUM);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 2353 "yacc_sql.tab.c"
    break;

  case 105: /* select_attr: SUM LBRACE ID DOT ID RBRACE attr_list  */
#line 653 "yacc_sql.y"
                                                {
          RelAttr attr;
          aggregation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), AGG_SUM);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 2363 "yacc_sql.tab.c"
    break;

  case 106: /* select_attr: COUNT LBRACE NUMBER RBRACE attr_list  */
#line 658 "yacc_sql.y"
                                               {
          RelAttr attr;
          char *str = malloc(10 * sizeof(char));
          snprintf(str, 10, "%d", (yyvsp[-2].number));
          aggregation_attr_init(&attr, NULL, str, AGG_COUNT);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 2375 "yacc_sql.tab.c"
    break;

  case 107: /* select_attr: COUNT LBRACE STAR RBRACE attr_list  */
#line 665 "yacc_sql.y"
                                             {
          RelAttr attr;
          aggregation_attr_init(&attr, NULL, "*", AGG_COUNT);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 2385 "yacc_sql.tab.c"
    break;

  case 108: /* select_attr: COUNT LBRACE ID RBRACE attr_list  */
#line 670 "yacc_sql.y"
                                           {
          RelAttr attr;
          aggregation_attr_init(&attr, NULL, (yyvsp[-2].string), AGG_COUNT);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 2395 "yacc_sql.tab.c"
    break;

  case 109: /* select_attr: AVG LBRACE ID RBRACE attr_list  */
#line 675 "yacc_sql.y"
                                         {
          RelAttr attr;
          aggregation_attr_init(&attr, NULL, (yyvsp[-2].string), AGG_AVG);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 2405 "yacc_sql.tab.c"
    break;

  case 110: /* select_attr: AVG LBRACE ID DOT ID RBRACE attr_list  */
#line 680 "yacc_sql.y"
                                                {
          RelAttr attr;
          aggregation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), AGG_AVG);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 2415 "yacc_sql.tab.c"
    break;

  case 112: /* attr_list: COMMA ID attr_list  */
#line 689 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
#line 2427 "yacc_sql.tab.c"
    break;

  case 113: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 696 "yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2437 "yacc_sql.tab.c"
    break;

  case 114: /* attr_list: COMMA ID DOT ID attr_list  */
#line 701 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
#line 2449 "yacc_sql.tab.c"
    break;

  case 115: /* attr_list: COMMA MAX LBRACE ID RBRACE attr_list  */
#line 709 "yacc_sql.y"
                                               {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-2].string), AGG_MAX);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2459 "yacc_sql.tab.c"
    break;

  case 116: /* attr_list: COMMA MAX LBRACE ID DOT ID RBRACE attr_list  */
#line 714 "yacc_sql.y"
                                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), AGG_MAX);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2469 "yacc_sql.tab.c"
    break;

  case 117: /* attr_list: COMMA MIN LBRACE ID RBRACE attr_list  */
#line 719 "yacc_sql.y"
                                               {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-2].string), AGG_MIN);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2479 "yacc_sql.tab.c"
    break;

  case 118: /* attr_list: COMMA MIN LBRACE ID DOT ID RBRACE attr_list  */
#line 724 "yacc_sql.y"
                                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), AGG_MIN);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2489 "yacc_sql.tab.c"
    break;

  case 119: /* attr_list: COMMA SUM LBRACE ID RBRACE attr_list  */
#line 729 "yacc_sql.y"
                                               {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, (yyvsp[-2].string), AGG_SUM);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2499 "yacc_sql.tab.c"
    break;

  case 120: /* attr_list: COMMA SUM LBRACE ID DOT ID RBRACE attr_list  */
#line 734 "yacc_sql.y"
                                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), AGG_SUM);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2509 "yacc_sql.tab.c"
    break;

  case 121: /* attr_list: COMMA COUNT LBRACE NUMBER RBRACE attr_list  */
#line 739 "yacc_sql.y"
                                                     {
       	  RelAttr attr;
       	  char *str = malloc(10 * sizeof(char));
       	  snprintf(str, 10, "%d", (yyvsp[-2].number));
       	  aggregation_attr_init(&attr, NULL, str, AGG_COUNT);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2521 "yacc_sql.tab.c"
    break;

  case 122: /* attr_list: COMMA COUNT LBRACE STAR RBRACE attr_list  */
#line 746 "yacc_sql.y"
                                                   {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, "*", AGG_COUNT);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2531 "yacc_sql.tab.c"
    break;

  case 123: /* attr_list: COMMA COUNT LBRACE ID RBRACE attr_list  */
#line 751 "yacc_sql.y"
                                                 {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, (yyvsp[-2].string), AGG_COUNT);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2541 "yacc_sql.tab.c"
    break;

  case 124: /* attr_list: COMMA AVG LBRACE ID RBRACE attr_list  */
#line 756 "yacc_sql.y"
                                               {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-2].string), AGG_AVG);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2551 "yacc_sql.tab.c"
    break;

  case 125: /* attr_list: COMMA AVG LBRACE ID DOT ID RBRACE attr_list  */
#line 761 "yacc_sql.y"
                                                      {
	  RelAttr attr;
	  aggregation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), AGG_AVG);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2561 "yacc_sql.tab.c"
    break;

  case 127: /* rel_list: COMMA ID rel_list  */
#line 830 "yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 2569 "yacc_sql.tab.c"
    break;

  case 129: /* inner: INNER JOIN ID rel_list on inner  */
#line 836 "yacc_sql.y"
                                          {
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
		  }
#line 2577 "yacc_sql.tab.c"
    break;

  case 130: /* inner: JOIN ID rel_list on inner  */
#line 839 "yacc_sql.y"
                                    {
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
		  }
#line 2585 "yacc_sql.tab.c"
    break;

  case 132: /* on: ON condition condition_list  */
#line 845 "yacc_sql.y"
                                      {

		  }
#line 2593 "yacc_sql.tab.c"
    break;

  case 134: /* where: WHERE condition condition_list  */
#line 851 "yacc_sql.y"
                                     {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2601 "yacc_sql.tab.c"
    break;

  case 136: /* condition_list: AND condition condition_list  */
#line 857 "yacc_sql.y"
                                   {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2609 "yacc_sql.tab.c"
    break;

  case 137: /* condition: ID comOp value  */
#line 863 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

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
#line 2634 "yacc_sql.tab.c"
    break;

  case 138: /* condition: value comOp value  */
#line 884 "yacc_sql.y"
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
#line 2658 "yacc_sql.tab.c"
    break;

  case 139: /* condition: ID comOp ID  */
#line 904 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

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
#line 2682 "yacc_sql.tab.c"
    break;

  case 140: /* condition: value comOp ID  */
#line 924 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

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
#line 2708 "yacc_sql.tab.c"
    break;

  case 141: /* condition: ID DOT ID comOp value  */
#line 946 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
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
#line 2733 "yacc_sql.tab.c"
    break;

  case 142: /* condition: value comOp ID DOT ID  */
#line 967 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];

			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

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
#line 2758 "yacc_sql.tab.c"
    break;

  case 143: /* condition: ID DOT ID comOp ID DOT ID  */
#line 988 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

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
#line 2781 "yacc_sql.tab.c"
    break;

  case 145: /* sub_where: WHERE sub_condition sub_condition_list  */
#line 1010 "yacc_sql.y"
                                             {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2789 "yacc_sql.tab.c"
    break;

  case 147: /* sub_condition_list: AND sub_condition sub_condition_list  */
#line 1016 "yacc_sql.y"
                                           {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2797 "yacc_sql.tab.c"
    break;

  case 148: /* sub_condition: ID sub_comOp sub_value  */
#line 1022 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

			Value *right_value = &GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, GET_SUB_CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			GET_SUB_CONTEXT->conditions[GET_SUB_CONTEXT->condition_length++] = condition;
		}
#line 2812 "yacc_sql.tab.c"
    break;

  case 149: /* sub_condition: sub_value sub_comOp sub_value  */
#line 1033 "yacc_sql.y"
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
#line 2836 "yacc_sql.tab.c"
    break;

  case 150: /* sub_condition: ID sub_comOp ID  */
#line 1053 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

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
#line 2860 "yacc_sql.tab.c"
    break;

  case 151: /* sub_condition: sub_value sub_comOp ID  */
#line 1073 "yacc_sql.y"
                {
			Value *left_value = &GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length - 1];
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

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
#line 2886 "yacc_sql.tab.c"
    break;

  case 152: /* sub_condition: ID DOT ID sub_comOp sub_value  */
#line 1095 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
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
#line 2911 "yacc_sql.tab.c"
    break;

  case 153: /* sub_condition: sub_value sub_comOp ID DOT ID  */
#line 1116 "yacc_sql.y"
                {
			Value *left_value = &GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length - 1];

			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

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
#line 2936 "yacc_sql.tab.c"
    break;

  case 154: /* sub_condition: ID DOT ID sub_comOp ID DOT ID  */
#line 1137 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

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
#line 2959 "yacc_sql.tab.c"
    break;

  case 155: /* sub_value: NUMBER  */
#line 1158 "yacc_sql.y"
          {	
  		value_init_integer(&GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 2967 "yacc_sql.tab.c"
    break;

  case 156: /* sub_value: FLOAT  */
#line 1161 "yacc_sql.y"
          {
  		value_init_float(&GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 2975 "yacc_sql.tab.c"
    break;

  case 157: /* sub_value: SSS  */
#line 1164 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 2984 "yacc_sql.tab.c"
    break;

  case 158: /* sub_value: NULL__  */
#line 1168 "yacc_sql.y"
                {
		value_init_null(&GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length++]);
	}
#line 2992 "yacc_sql.tab.c"
    break;

  case 159: /* sub_comOp: EQ  */
#line 1174 "yacc_sql.y"
             { GET_SUB_CONTEXT->comp = EQUAL_TO; }
#line 2998 "yacc_sql.tab.c"
    break;

  case 160: /* sub_comOp: LT  */
#line 1175 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = LESS_THAN; }
#line 3004 "yacc_sql.tab.c"
    break;

  case 161: /* sub_comOp: GT  */
#line 1176 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = GREAT_THAN; }
#line 3010 "yacc_sql.tab.c"
    break;

  case 162: /* sub_comOp: LE  */
#line 1177 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = LESS_EQUAL; }
#line 3016 "yacc_sql.tab.c"
    break;

  case 163: /* sub_comOp: GE  */
#line 1178 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = GREAT_EQUAL; }
#line 3022 "yacc_sql.tab.c"
    break;

  case 164: /* sub_comOp: NE  */
#line 1179 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = NOT_EQUAL; }
#line 3028 "yacc_sql.tab.c"
    break;

  case 165: /* sub_comOp: LIKE  */
#line 1180 "yacc_sql.y"
           { GET_SUB_CONTEXT->comp = OP_LIKE; }
#line 3034 "yacc_sql.tab.c"
    break;

  case 166: /* sub_comOp: NOT LIKE  */
#line 1181 "yacc_sql.y"
               { GET_SUB_CONTEXT->comp = OP_NOT_LIKE; }
#line 3040 "yacc_sql.tab.c"
    break;

  case 167: /* sub_comOp: IS  */
#line 1182 "yacc_sql.y"
                   { CONTEXT->comp = EQUAL_IS; }
#line 3046 "yacc_sql.tab.c"
    break;

  case 168: /* sub_comOp: IS NOT  */
#line 1183 "yacc_sql.y"
                   { CONTEXT->comp = NOT_EQUAL_IS; }
#line 3052 "yacc_sql.tab.c"
    break;

  case 169: /* comOp: EQ  */
#line 1187 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 3058 "yacc_sql.tab.c"
    break;

  case 170: /* comOp: LT  */
#line 1188 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 3064 "yacc_sql.tab.c"
    break;

  case 171: /* comOp: GT  */
#line 1189 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 3070 "yacc_sql.tab.c"
    break;

  case 172: /* comOp: LE  */
#line 1190 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 3076 "yacc_sql.tab.c"
    break;

  case 173: /* comOp: GE  */
#line 1191 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 3082 "yacc_sql.tab.c"
    break;

  case 174: /* comOp: NE  */
#line 1192 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 3088 "yacc_sql.tab.c"
    break;

  case 175: /* comOp: LIKE  */
#line 1193 "yacc_sql.y"
                   { CONTEXT->comp = OP_LIKE; }
#line 3094 "yacc_sql.tab.c"
    break;

  case 176: /* comOp: NOT LIKE  */
#line 1194 "yacc_sql.y"
               { CONTEXT->comp = OP_NOT_LIKE; }
#line 3100 "yacc_sql.tab.c"
    break;

  case 177: /* comOp: IS  */
#line 1195 "yacc_sql.y"
                   { CONTEXT->comp = EQUAL_IS; }
#line 3106 "yacc_sql.tab.c"
    break;

  case 178: /* comOp: IS NOT  */
#line 1196 "yacc_sql.y"
                   { CONTEXT->comp = NOT_EQUAL_IS; }
#line 3112 "yacc_sql.tab.c"
    break;

  case 179: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 1201 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 3121 "yacc_sql.tab.c"
    break;

  case 182: /* order_attr: ID  */
#line 1212 "yacc_sql.y"
           {
		OrderBy order;
               	order_init(&order, NULL, (yyvsp[0].string), ORDER_ASC);
               	selects_append_order(&CONTEXT->ssql->sstr.selection, &order);
	}
#line 3131 "yacc_sql.tab.c"
    break;

  case 183: /* order_attr: ID ASC  */
#line 1217 "yacc_sql.y"
                 {
		OrderBy order;
                order_init(&order, NULL, (yyvsp[-1].string), ORDER_ASC);
                selects_append_order(&CONTEXT->ssql->sstr.selection, &order);
	}
#line 3141 "yacc_sql.tab.c"
    break;

  case 184: /* order_attr: ID DESC  */
#line 1222 "yacc_sql.y"
                  {
		OrderBy order;
                order_init(&order, NULL, (yyvsp[-1].string), ORDER_DESC);
                selects_append_order(&CONTEXT->ssql->sstr.selection, &order);
	}
#line 3151 "yacc_sql.tab.c"
    break;

  case 185: /* order_attr: ID DOT ID  */
#line 1227 "yacc_sql.y"
                    {
		OrderBy order;
                order_init(&order, (yyvsp[-2].string), (yyvsp[0].string), ORDER_ASC);
                selects_append_order(&CONTEXT->ssql->sstr.selection, &order);
	}
#line 3161 "yacc_sql.tab.c"
    break;

  case 186: /* order_attr: ID DOT ID ASC  */
#line 1232 "yacc_sql.y"
                        {
		OrderBy order;
                order_init(&order, (yyvsp[-3].string), (yyvsp[-1].string), ORDER_ASC);
                selects_append_order(&CONTEXT->ssql->sstr.selection, &order);
	}
#line 3171 "yacc_sql.tab.c"
    break;

  case 187: /* order_attr: ID DOT ID DESC  */
#line 1237 "yacc_sql.y"
                         {
		OrderBy order;
                order_init(&order, (yyvsp[-3].string), (yyvsp[-1].string), ORDER_DESC);
                selects_append_order(&CONTEXT->ssql->sstr.selection, &order);
	}
#line 3181 "yacc_sql.tab.c"
    break;

  case 192: /* group_attr: ID  */
#line 1253 "yacc_sql.y"
           {
		GroupBy group;
               	group_init(&group, NULL, (yyvsp[0].string));
               	selects_append_group(&CONTEXT->ssql->sstr.selection, &group);
	}
#line 3191 "yacc_sql.tab.c"
    break;

  case 193: /* group_attr: ID DOT ID  */
#line 1258 "yacc_sql.y"
                    {
		GroupBy group;
                group_init(&group, (yyvsp[-2].string), (yyvsp[0].string));
                selects_append_group(&CONTEXT->ssql->sstr.selection, &group);
	}
#line 3201 "yacc_sql.tab.c"
    break;

  case 198: /* having_condition: MAX LBRACE ID RBRACE comOp value  */
#line 1274 "yacc_sql.y"
                                         {
		RelAttr left_attr;
                aggregation_attr_init(&left_attr, NULL, (yyvsp[-3].string), AGG_MAX);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
	}
#line 3215 "yacc_sql.tab.c"
    break;

  case 199: /* having_condition: MAX LBRACE ID DOT ID RBRACE comOp value  */
#line 1283 "yacc_sql.y"
                                                  {
          	RelAttr left_attr;
                aggregation_attr_init(&left_attr, (yyvsp[-5].string), (yyvsp[-3].string), AGG_MAX);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
#line 3229 "yacc_sql.tab.c"
    break;

  case 200: /* having_condition: MIN LBRACE ID RBRACE comOp value  */
#line 1292 "yacc_sql.y"
                                           {
       		RelAttr left_attr;
                aggregation_attr_init(&left_attr, NULL, (yyvsp[-3].string), AGG_MIN);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
       	}
#line 3243 "yacc_sql.tab.c"
    break;

  case 201: /* having_condition: MIN LBRACE ID DOT ID RBRACE comOp value  */
#line 1301 "yacc_sql.y"
                                                  {
                RelAttr left_attr;
                aggregation_attr_init(&left_attr, (yyvsp[-5].string), (yyvsp[-3].string), AGG_MIN);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
#line 3257 "yacc_sql.tab.c"
    break;

  case 202: /* having_condition: SUM LBRACE ID RBRACE comOp value  */
#line 1310 "yacc_sql.y"
                                           {
        	RelAttr left_attr;
                aggregation_attr_init(&left_attr, NULL, (yyvsp[-3].string), AGG_SUM);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
#line 3271 "yacc_sql.tab.c"
    break;

  case 203: /* having_condition: SUM LBRACE ID DOT ID RBRACE comOp value  */
#line 1319 "yacc_sql.y"
                                                  {
          	RelAttr left_attr;
                aggregation_attr_init(&left_attr, (yyvsp[-5].string), (yyvsp[-3].string), AGG_SUM);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
#line 3285 "yacc_sql.tab.c"
    break;

  case 204: /* having_condition: COUNT LBRACE ID RBRACE comOp value  */
#line 1328 "yacc_sql.y"
                                             {
        	RelAttr left_attr;
                aggregation_attr_init(&left_attr, NULL, (yyvsp[-3].string), AGG_COUNT);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
#line 3299 "yacc_sql.tab.c"
    break;

  case 205: /* having_condition: COUNT LBRACE ID DOT ID RBRACE comOp value  */
#line 1337 "yacc_sql.y"
                                                    {
          	RelAttr left_attr;
                aggregation_attr_init(&left_attr, (yyvsp[-5].string), (yyvsp[-3].string), AGG_COUNT);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
#line 3313 "yacc_sql.tab.c"
    break;

  case 206: /* having_condition: COUNT LBRACE NUMBER RBRACE comOp value  */
#line 1346 "yacc_sql.y"
                                                 {
          RelAttr left_attr;
          char *str = malloc(10 * sizeof(char));
          snprintf(str, 10, "%d", (yyvsp[-3].number));
          aggregation_attr_init(&left_attr, NULL, str, AGG_COUNT);
          Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

          Having having;
          having_init(&having, CONTEXT->comp, &left_attr, right_value);
          selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
#line 3329 "yacc_sql.tab.c"
    break;

  case 207: /* having_condition: COUNT LBRACE STAR RBRACE comOp value  */
#line 1357 "yacc_sql.y"
                                               {
          RelAttr left_attr;
          aggregation_attr_init(&left_attr, NULL, "*", AGG_COUNT);
          Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

          Having having;
          having_init(&having, CONTEXT->comp, &left_attr, right_value);
          selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
#line 3343 "yacc_sql.tab.c"
    break;

  case 208: /* having_condition: AVG LBRACE ID RBRACE comOp value  */
#line 1366 "yacc_sql.y"
                                           {
        	RelAttr left_attr;
                aggregation_attr_init(&left_attr, NULL, (yyvsp[-3].string), AGG_AVG);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
#line 3357 "yacc_sql.tab.c"
    break;

  case 209: /* having_condition: AVG LBRACE ID DOT ID RBRACE comOp value  */
#line 1375 "yacc_sql.y"
                                                  {
          	RelAttr left_attr;
                aggregation_attr_init(&left_attr, (yyvsp[-5].string), (yyvsp[-3].string), AGG_AVG);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
#line 3371 "yacc_sql.tab.c"
    break;


#line 3375 "yacc_sql.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (scanner, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, scanner);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1390 "yacc_sql.y"

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
