/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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
  YYSYMBOL_NUMBER = 58,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 59,                     /* FLOAT  */
  YYSYMBOL_ID = 60,                        /* ID  */
  YYSYMBOL_PATH = 61,                      /* PATH  */
  YYSYMBOL_SSS = 62,                       /* SSS  */
  YYSYMBOL_STAR = 63,                      /* STAR  */
  YYSYMBOL_STRING_V = 64,                  /* STRING_V  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_commands = 66,                  /* commands  */
  YYSYMBOL_command = 67,                   /* command  */
  YYSYMBOL_exit = 68,                      /* exit  */
  YYSYMBOL_help = 69,                      /* help  */
  YYSYMBOL_sync = 70,                      /* sync  */
  YYSYMBOL_begin = 71,                     /* begin  */
  YYSYMBOL_commit = 72,                    /* commit  */
  YYSYMBOL_rollback = 73,                  /* rollback  */
  YYSYMBOL_drop_table = 74,                /* drop_table  */
  YYSYMBOL_show_tables = 75,               /* show_tables  */
  YYSYMBOL_show_indexes = 76,              /* show_indexes  */
  YYSYMBOL_desc_table = 77,                /* desc_table  */
  YYSYMBOL_create_index = 78,              /* create_index  */
  YYSYMBOL_index_attr_list = 79,           /* index_attr_list  */
  YYSYMBOL_drop_index = 80,                /* drop_index  */
  YYSYMBOL_create_table = 81,              /* create_table  */
  YYSYMBOL_attr_def_list = 82,             /* attr_def_list  */
  YYSYMBOL_attr_def = 83,                  /* attr_def  */
  YYSYMBOL_number = 84,                    /* number  */
  YYSYMBOL_type = 85,                      /* type  */
  YYSYMBOL_is_null = 86,                   /* is_null  */
  YYSYMBOL_ID_get = 87,                    /* ID_get  */
  YYSYMBOL_insert = 88,                    /* insert  */
  YYSYMBOL_value_tuple = 89,               /* value_tuple  */
  YYSYMBOL_value_list = 90,                /* value_list  */
  YYSYMBOL_insert_vaule = 91,              /* insert_vaule  */
  YYSYMBOL_value = 92,                     /* value  */
  YYSYMBOL_delete = 93,                    /* delete  */
  YYSYMBOL_update = 94,                    /* update  */
  YYSYMBOL_update_list = 95,               /* update_list  */
  YYSYMBOL_set_list = 96,                  /* set_list  */
  YYSYMBOL_sub_select = 97,                /* sub_select  */
  YYSYMBOL_sub_select_attr = 98,           /* sub_select_attr  */
  YYSYMBOL_sub_attr_list = 99,             /* sub_attr_list  */
  YYSYMBOL_sub_agg_func = 100,             /* sub_agg_func  */
  YYSYMBOL_sub_rel_list = 101,             /* sub_rel_list  */
  YYSYMBOL_select = 102,                   /* select  */
  YYSYMBOL_select_attr = 103,              /* select_attr  */
  YYSYMBOL_attr_list = 104,                /* attr_list  */
  YYSYMBOL_agg_func = 105,                 /* agg_func  */
  YYSYMBOL_rel_list = 106,                 /* rel_list  */
  YYSYMBOL_inner = 107,                    /* inner  */
  YYSYMBOL_on = 108,                       /* on  */
  YYSYMBOL_where = 109,                    /* where  */
  YYSYMBOL_condition_list = 110,           /* condition_list  */
  YYSYMBOL_condition = 111,                /* condition  */
  YYSYMBOL_sub_where = 112,                /* sub_where  */
  YYSYMBOL_sub_condition_list = 113,       /* sub_condition_list  */
  YYSYMBOL_sub_condition = 114,            /* sub_condition  */
  YYSYMBOL_sub_value = 115,                /* sub_value  */
  YYSYMBOL_sub_comOp = 116,                /* sub_comOp  */
  YYSYMBOL_comOp = 117,                    /* comOp  */
  YYSYMBOL_load_data = 118                 /* load_data  */
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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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
#define YYLAST   429

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  170
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  380

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   319


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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   153,   153,   155,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   180,   185,   190,   196,   202,   208,   214,   220,
     225,   232,   239,   245,   254,   256,   262,   269,   278,   280,
     284,   295,   308,   311,   312,   313,   314,   317,   320,   323,
     328,   337,   354,   356,   363,   366,   371,   376,   379,   383,
     387,   390,   393,   397,   403,   409,   419,   427,   434,   436,
     444,   458,   463,   468,   473,   478,   481,   483,   490,   495,
     502,   506,   511,   516,   521,   526,   531,   536,   543,   548,
     553,   558,   565,   567,   572,   588,   602,   607,   612,   617,
     622,   625,   627,   634,   639,   646,   650,   655,   660,   665,
     670,   675,   680,   687,   692,   697,   702,   709,   711,   715,
     717,   720,   724,   726,   730,   732,   736,   738,   743,   764,
     784,   804,   826,   847,   868,   889,   891,   895,   897,   902,
     913,   933,   953,   975,   996,  1017,  1039,  1042,  1045,  1049,
    1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,
    1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,
    1081
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
  "IS", "LIKE", "MAX", "MIN", "SUM", "COUNT", "AVG", "NUMBER", "FLOAT",
  "ID", "PATH", "SSS", "STAR", "STRING_V", "$accept", "commands",
  "command", "exit", "help", "sync", "begin", "commit", "rollback",
  "drop_table", "show_tables", "show_indexes", "desc_table",
  "create_index", "index_attr_list", "drop_index", "create_table",
  "attr_def_list", "attr_def", "number", "type", "is_null", "ID_get",
  "insert", "value_tuple", "value_list", "insert_vaule", "value", "delete",
  "update", "update_list", "set_list", "sub_select", "sub_select_attr",
  "sub_attr_list", "sub_agg_func", "sub_rel_list", "select", "select_attr",
  "attr_list", "agg_func", "rel_list", "inner", "on", "where",
  "condition_list", "condition", "sub_where", "sub_condition_list",
  "sub_condition", "sub_value", "sub_comOp", "comOp", "load_data", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-343)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -343,   125,  -343,   105,    16,   169,   -37,    37,    49,    50,
      62,    67,   131,   146,   153,   158,   179,    85,  -343,  -343,
    -343,  -343,  -343,  -343,  -343,  -343,  -343,  -343,  -343,  -343,
    -343,  -343,  -343,  -343,  -343,  -343,  -343,    97,   172,   138,
     150,   161,   211,   214,   222,   225,   232,    53,   231,   229,
     231,   254,   259,   233,  -343,   203,   204,   234,  -343,  -343,
    -343,  -343,  -343,   223,   249,   208,   235,   267,   268,   212,
     215,   216,   -39,   217,   191,   148,  -343,  -343,   218,  -343,
    -343,  -343,   220,   243,   246,   221,   246,   224,   227,   244,
     228,  -343,  -343,    -2,    10,    32,   265,   266,   271,    33,
     114,   231,   231,   231,   272,   282,   273,     9,   289,   248,
     291,   269,  -343,   276,   171,   236,   280,  -343,   238,  -343,
     240,  -343,   241,  -343,  -343,  -343,  -343,   242,   149,  -343,
    -343,  -343,  -343,   245,   147,  -343,    92,   293,  -343,  -343,
    -343,   126,  -343,   154,   270,  -343,    30,  -343,   300,   227,
     290,  -343,  -343,  -343,  -343,    -3,   292,   247,   294,   295,
     296,   297,   231,   231,   272,   274,   250,   246,   313,  -343,
    -343,  -343,  -343,   298,   180,   301,   258,   275,  -343,  -343,
    -343,  -343,  -343,  -343,   281,  -343,    17,    43,     9,  -343,
     302,   262,   276,   320,   277,   284,  -343,  -343,   278,   306,
    -343,  -343,  -343,  -343,  -343,  -343,  -343,   279,   272,   323,
    -343,    92,   310,   312,   314,   315,   316,   317,   139,   311,
     304,   311,  -343,   154,  -343,  -343,  -343,  -343,   308,  -343,
     270,   283,  -343,   337,  -343,  -343,  -343,   324,  -343,   306,
     285,   326,   272,   303,  -343,   298,   327,   287,   288,   299,
     -15,   305,   199,   167,  -343,  -343,   307,  -343,    64,   309,
    -343,   318,  -343,   219,   331,   306,   347,   303,     9,    71,
    -343,   334,   349,    56,    77,   102,   335,   336,   338,   130,
     141,   311,   311,   311,   339,   328,  -343,  -343,    30,  -343,
     352,  -343,  -343,    71,   270,  -343,    92,  -343,  -343,   319,
    -343,   321,  -343,   322,  -343,  -343,  -343,  -343,   325,   178,
    -343,  -343,  -343,  -343,   329,   333,   330,   302,  -343,  -343,
    -343,   298,   342,   343,   344,   346,   311,   311,   339,   -27,
    -343,  -343,  -343,   350,  -343,  -343,  -343,  -343,  -343,  -343,
    -343,  -343,  -343,  -343,   140,  -343,   340,   168,   327,   332,
     341,  -343,  -343,  -343,  -343,  -343,  -343,   345,  -343,    38,
     -27,  -343,    59,  -343,   168,  -343,  -343,  -343,  -343,   340,
     348,  -343,   104,  -343,   351,   354,  -343,  -343,   353,  -343
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
       0,     0,     0,     0,     0,     0,     0,   101,   101,     0,
     101,     0,     0,     0,    24,     0,     0,     0,    25,    26,
      27,    23,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    97,    96,     0,   100,
      31,    29,     0,     0,   124,     0,   124,     0,     0,     0,
       0,    28,    36,     0,     0,     0,     0,     0,     0,     0,
     101,   101,   101,   101,   117,     0,     0,     0,     0,     0,
       0,     0,    50,    38,     0,     0,     0,   106,     0,   108,
       0,   110,     0,   112,   114,   113,   115,     0,     0,   102,
     105,    98,    99,     0,   119,    30,     0,     0,    64,    60,
      61,     0,    62,     0,   126,    65,     0,    66,     0,     0,
       0,    43,    44,    45,    46,    47,     0,     0,     0,     0,
       0,     0,   101,   101,   117,     0,     0,   124,     0,    59,
      56,    57,    58,    54,     0,     0,     0,     0,   160,   161,
     162,   163,   164,   165,   168,   166,     0,     0,     0,   125,
      68,     0,    38,     0,     0,     0,    49,    41,     0,    34,
     107,   109,   111,   116,   104,   103,   118,     0,   117,     0,
      94,     0,     0,     0,     0,     0,     0,     0,    76,    76,
       0,    76,    63,     0,   167,   169,   130,   128,   131,   129,
     126,     0,    67,     0,    39,    37,    42,     0,    48,    34,
       0,     0,   117,   122,    95,    54,    52,     0,     0,     0,
       0,     0,     0,     0,    72,    71,     0,    75,     0,     0,
     127,     0,   170,    47,     0,    34,     0,   122,     0,   119,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,    76,    76,    76,    92,     0,   132,   133,     0,    40,
       0,    35,    32,   119,   126,   121,     0,    51,    81,     0,
      83,     0,    85,     0,    87,    89,    88,    90,     0,     0,
      77,    80,    73,    74,     0,   135,     0,    68,    33,   120,
     123,    54,     0,     0,     0,     0,    76,    76,    92,     0,
      70,   134,    69,     0,    82,    84,    86,    91,    79,    78,
      93,   149,   146,   147,     0,   148,   137,     0,    52,     0,
       0,   150,   151,   152,   153,   154,   155,   158,   156,     0,
       0,   136,     0,    53,     0,   157,   159,   141,   139,   137,
     142,   140,     0,   138,     0,     0,   143,   144,     0,   145
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -343,  -343,  -343,  -343,  -343,  -343,  -343,  -343,  -343,  -343,
    -343,  -343,  -343,  -343,  -228,  -343,  -343,   181,   226,  -343,
    -343,   107,  -343,  -343,    23,  -237,  -206,  -146,  -343,  -343,
    -343,    55,  -343,  -343,  -217,   124,    52,  -343,  -343,   -47,
     355,  -149,  -251,   111,   -76,  -221,  -182,  -343,    18,    26,
    -342,  -335,  -136,  -343
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,   241,    30,    31,   150,   113,   237,
     155,   197,   114,    32,   272,   212,   173,   143,    33,    34,
      86,   232,   175,   220,   254,   221,   315,    35,    49,    76,
      50,   134,   167,   269,   108,   189,   144,   330,   361,   346,
     347,   359,   186,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     190,    77,   255,    79,   257,   245,   230,   187,   270,   260,
     110,   264,   362,   341,   194,   206,   117,   368,   295,    96,
     371,    97,    40,    51,    98,    41,   137,   118,   119,   372,
     376,   342,   343,   344,   137,   345,   195,   291,   196,   120,
     227,   229,   319,   276,    52,   277,    53,   137,   278,   138,
     121,   126,    54,   129,   130,   131,   132,   138,   168,   243,
     137,   122,   127,   310,   311,   312,   313,   139,   140,   141,
     138,   142,    74,   320,   298,   139,   140,   226,   341,   142,
      55,   137,    75,   138,   333,   299,   294,   258,   139,   140,
     321,   209,   142,   267,    56,   300,   342,   343,   367,   341,
     345,   139,   140,   228,   138,   142,   301,   165,   166,   338,
     339,    37,   286,    38,    39,   204,   205,   342,   343,   370,
     302,   345,   139,   140,   285,     2,   142,    57,    63,     3,
       4,   303,   169,    74,    58,     5,     6,     7,     8,     9,
      10,    11,   317,   128,   341,    12,    13,    14,   307,    59,
     170,   171,    15,    16,   172,   176,    60,    64,   252,   308,
     252,    61,   342,   343,   375,   177,   345,    17,   253,   349,
     309,   178,   179,   180,   181,   182,   183,   184,   185,   350,
     107,    65,    62,   165,   166,   351,   352,   353,   354,   355,
     356,   357,   358,   177,   151,   152,   153,   154,    66,   178,
     179,   180,   181,   182,   183,   184,   185,   350,   102,   162,
      67,   103,   163,   351,   352,   353,   354,   355,   356,   357,
     358,    68,    42,    43,    44,    45,    46,   282,    69,    47,
     283,    70,    48,   213,   214,   215,   216,   217,   326,    71,
     218,   327,    72,   219,    42,    43,    44,    45,    46,    73,
      74,   100,   213,   214,   215,   216,   217,    80,   195,   280,
     196,    78,    81,    83,    84,    82,    88,    87,    89,    85,
      91,    92,    93,    90,   106,    94,    95,    99,   104,   107,
     105,   109,   115,   123,   124,   135,   111,   112,   116,   125,
     136,   133,   145,   146,   147,   149,   156,   157,   158,   148,
     159,   160,   161,   174,   188,   164,   191,   199,   193,   198,
     208,   207,   200,   201,   202,   203,   210,   211,   223,   222,
     225,   231,   233,   235,   238,   240,   244,   224,   246,   247,
     252,   248,   249,   250,   251,   236,   256,   259,   239,   242,
     262,   268,   263,   261,   266,   265,   271,   273,   274,   290,
     292,   296,   297,   304,   305,   318,   306,   316,   314,   275,
     334,   335,   336,   288,   337,   279,   329,   284,   348,   287,
     289,   363,   332,   234,   360,   192,   281,   374,   293,   322,
     340,   323,   324,   378,   366,   325,   369,   373,     0,   328,
     331,     0,   364,   365,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   377,     0,   379,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   101
};

static const yytype_int16 yycheck[] =
{
     146,    48,   219,    50,   221,   211,   188,   143,   245,   230,
      86,   239,   347,    40,    17,   164,    18,   359,   269,    58,
     362,    60,     6,    60,    63,     9,    17,    29,    18,   364,
     372,    58,    59,    60,    17,    62,    39,   265,    41,    29,
     186,   187,   293,    58,     7,    60,     9,    17,    63,    40,
      18,    18,     3,   100,   101,   102,   103,    40,   134,   208,
      17,    29,    29,   280,   281,   282,   283,    58,    59,    60,
      40,    62,    19,   294,    18,    58,    59,    60,    40,    62,
      30,    17,    29,    40,   321,    29,   268,   223,    58,    59,
     296,   167,    62,   242,    32,    18,    58,    59,    60,    40,
      62,    58,    59,    60,    40,    62,    29,    36,    37,   326,
     327,     6,   258,     8,     9,   162,   163,    58,    59,    60,
      18,    62,    58,    59,    60,     0,    62,    60,    43,     4,
       5,    29,    40,    19,     3,    10,    11,    12,    13,    14,
      15,    16,   288,    29,    40,    20,    21,    22,    18,     3,
      58,    59,    27,    28,    62,    29,     3,    60,    19,    29,
      19,     3,    58,    59,    60,    39,    62,    42,    29,    29,
      29,    45,    46,    47,    48,    49,    50,    51,    52,    39,
      33,     9,     3,    36,    37,    45,    46,    47,    48,    49,
      50,    51,    52,    39,    23,    24,    25,    26,    60,    45,
      46,    47,    48,    49,    50,    51,    52,    39,    60,    60,
      60,    63,    63,    45,    46,    47,    48,    49,    50,    51,
      52,    60,    53,    54,    55,    56,    57,    60,    17,    60,
      63,    17,    63,    53,    54,    55,    56,    57,    60,    17,
      60,    63,    17,    63,    53,    54,    55,    56,    57,    17,
      19,    60,    53,    54,    55,    56,    57,     3,    39,    60,
      41,    32,     3,    60,    60,    32,    17,    44,    60,    35,
       3,     3,    60,    38,    31,    60,    60,    60,    60,    33,
      60,    60,    38,    18,    18,     3,    62,    60,    60,    18,
      17,    19,     3,    45,     3,    19,    60,    17,    60,    30,
      60,    60,    60,    10,    34,    60,     6,    60,    18,    17,
      60,    37,    18,    18,    18,    18,     3,    19,    60,    18,
      39,    19,    60,     3,    40,    19,     3,    52,    18,    17,
      19,    17,    17,    17,    17,    58,    32,    29,    60,    60,
       3,    38,    18,    60,    18,    60,    19,    60,    60,    18,
       3,    17,     3,    18,    18,     3,    18,    29,    19,    60,
      18,    18,    18,    45,    18,    60,    33,    60,    18,    60,
     263,   348,   317,   192,    34,   149,   252,    29,   267,    60,
     328,    60,    60,    29,    39,    60,   360,   369,    -1,    60,
      60,    -1,    60,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    66,     0,     4,     5,    10,    11,    12,    13,    14,
      15,    16,    20,    21,    22,    27,    28,    42,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      80,    81,    88,    93,    94,   102,   118,     6,     8,     9,
       6,     9,    53,    54,    55,    56,    57,    60,    63,   103,
     105,    60,     7,     9,     3,    30,    32,    60,     3,     3,
       3,     3,     3,    43,    60,     9,    60,    60,    60,    17,
      17,    17,    17,    17,    19,    29,   104,   104,    32,   104,
       3,     3,    32,    60,    60,    35,    95,    44,    17,    60,
      38,     3,     3,    60,    60,    60,    58,    60,    63,    60,
      60,   105,    60,    63,    60,    60,    31,    33,   109,    60,
     109,    62,    60,    83,    87,    38,    60,    18,    29,    18,
      29,    18,    29,    18,    18,    18,    18,    29,    29,   104,
     104,   104,   104,    19,   106,     3,    17,    17,    40,    58,
      59,    60,    62,    92,   111,     3,    45,     3,    30,    19,
      82,    23,    24,    25,    26,    85,    60,    17,    60,    60,
      60,    60,    60,    63,    60,    36,    37,   107,   109,    40,
      58,    59,    62,    91,    10,    97,    29,    39,    45,    46,
      47,    48,    49,    50,    51,    52,   117,   117,    34,   110,
      92,     6,    83,    18,    17,    39,    41,    86,    17,    60,
      18,    18,    18,    18,   104,   104,   106,    37,    60,   109,
       3,    19,    90,    53,    54,    55,    56,    57,    60,    63,
      98,   100,    18,    60,    52,    39,    60,    92,    60,    92,
     111,    19,    96,    60,    82,     3,    58,    84,    40,    60,
      19,    79,    60,   106,     3,    91,    18,    17,    17,    17,
      17,    17,    19,    29,    99,    99,    32,    99,   117,    29,
     110,    60,     3,    18,    79,    60,    18,   106,    38,   108,
      90,    19,    89,    60,    60,    60,    58,    60,    63,    60,
      60,   100,    60,    63,    60,    60,    92,    60,    45,    86,
      18,    79,     3,   108,   111,   107,    17,     3,    18,    29,
      18,    29,    18,    29,    18,    18,    18,    18,    29,    29,
      99,    99,    99,    99,    19,   101,    29,    92,     3,   107,
     110,    91,    60,    60,    60,    60,    60,    63,    60,    33,
     112,    60,    96,    90,    18,    18,    18,    18,    99,    99,
     101,    40,    58,    59,    60,    62,   114,   115,    18,    29,
      39,    45,    46,    47,    48,    49,    50,    51,    52,   116,
      34,   113,   116,    89,    60,    52,    39,    60,   115,   114,
      60,   115,   116,   113,    29,    60,   115,    60,    29,    60
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    66,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    78,    79,    79,    80,    81,    82,    82,
      83,    83,    84,    85,    85,    85,    85,    86,    86,    86,
      87,    88,    89,    89,    90,    90,    91,    91,    91,    91,
      92,    92,    92,    92,    92,    93,    94,    95,    96,    96,
      97,    98,    98,    98,    98,    98,    99,    99,    99,    99,
      99,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   101,   101,   102,   102,   103,   103,   103,   103,
     103,   104,   104,   104,   104,   104,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   106,   106,   107,
     107,   107,   108,   108,   109,   109,   110,   110,   111,   111,
     111,   111,   111,   111,   111,   112,   112,   113,   113,   114,
     114,   114,   114,   114,   114,   114,   115,   115,   115,   115,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     118
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
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
       4,     6,     0,     3,     7,     8,     2,     2,     4,     4,
       2,     0,     3,     5,     5,     3,     4,     6,     4,     6,
       4,     6,     4,     4,     4,     4,     6,     0,     3,     0,
       6,     5,     0,     3,     0,     3,     0,     3,     3,     3,
       3,     3,     5,     5,     7,     0,     3,     0,     3,     3,
       3,     3,     3,     5,     5,     7,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       8
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
  YY_USE (yyoutput);
  YY_USE (scanner);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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
  YY_USE (yyvaluep);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
#line 180 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1515 "yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 185 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1523 "yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 190 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1531 "yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 196 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1539 "yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 202 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1547 "yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 208 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1555 "yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 214 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1564 "yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 220 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1572 "yacc_sql.tab.c"
    break;

  case 30: /* show_indexes: SHOW INDEX FROM ID SEMICOLON  */
#line 225 "yacc_sql.y"
                                     {
	  CONTEXT->ssql->flag = SCF_SHOW_INDEXES;
	  create_show_index(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
	}
#line 1581 "yacc_sql.tab.c"
    break;

  case 31: /* desc_table: DESC ID SEMICOLON  */
#line 232 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1590 "yacc_sql.tab.c"
    break;

  case 32: /* create_index: CREATE INDEX ID ON ID LBRACE ID index_attr_list RBRACE SEMICOLON  */
#line 240 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[-3].string));
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), DEFAULT_INDEX);
		}
#line 1600 "yacc_sql.tab.c"
    break;

  case 33: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE ID index_attr_list RBRACE SEMICOLON  */
#line 246 "yacc_sql.y"
        {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
            create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[-3].string));
            create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), UNIQUE_INDEX);
        }
#line 1610 "yacc_sql.tab.c"
    break;

  case 35: /* index_attr_list: COMMA ID index_attr_list  */
#line 256 "yacc_sql.y"
                               {
            create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[-1].string));
        }
#line 1618 "yacc_sql.tab.c"
    break;

  case 36: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 263 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1627 "yacc_sql.tab.c"
    break;

  case 37: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 270 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1639 "yacc_sql.tab.c"
    break;

  case 39: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 280 "yacc_sql.y"
                                   {    }
#line 1645 "yacc_sql.tab.c"
    break;

  case 40: /* attr_def: ID_get type LBRACE number RBRACE is_null  */
#line 285 "yacc_sql.y"
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
#line 1660 "yacc_sql.tab.c"
    break;

  case 41: /* attr_def: ID_get type is_null  */
#line 296 "yacc_sql.y"
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
#line 1675 "yacc_sql.tab.c"
    break;

  case 42: /* number: NUMBER  */
#line 308 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1681 "yacc_sql.tab.c"
    break;

  case 43: /* type: INT_T  */
#line 311 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1687 "yacc_sql.tab.c"
    break;

  case 44: /* type: STRING_T  */
#line 312 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1693 "yacc_sql.tab.c"
    break;

  case 45: /* type: FLOAT_T  */
#line 313 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1699 "yacc_sql.tab.c"
    break;

  case 46: /* type: DATE_T  */
#line 314 "yacc_sql.y"
                { (yyval.number)=DATES; }
#line 1705 "yacc_sql.tab.c"
    break;

  case 47: /* is_null: %empty  */
#line 317 "yacc_sql.y"
                   {
		CONTEXT->nullable = 0;
	}
#line 1713 "yacc_sql.tab.c"
    break;

  case 48: /* is_null: NOT NULL__  */
#line 320 "yacc_sql.y"
                    {
		CONTEXT->nullable = 0;
	}
#line 1721 "yacc_sql.tab.c"
    break;

  case 49: /* is_null: NULLABLE  */
#line 323 "yacc_sql.y"
                   {
		CONTEXT->nullable = 1;
	}
#line 1729 "yacc_sql.tab.c"
    break;

  case 50: /* ID_get: ID  */
#line 329 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1738 "yacc_sql.tab.c"
    break;

  case 51: /* insert: INSERT INTO ID VALUES LBRACE insert_vaule value_list RBRACE value_tuple SEMICOLON  */
#line 338 "yacc_sql.y"
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
#line 1758 "yacc_sql.tab.c"
    break;

  case 53: /* value_tuple: COMMA LBRACE insert_vaule value_list RBRACE value_tuple  */
#line 356 "yacc_sql.y"
                                                                  {

	  }
#line 1766 "yacc_sql.tab.c"
    break;

  case 54: /* value_list: %empty  */
#line 363 "yacc_sql.y"
        {
		inserts_more_init(&CONTEXT->inserts_more[CONTEXT->insert_length].value_num, &CONTEXT->insert_length);
	}
#line 1774 "yacc_sql.tab.c"
    break;

  case 55: /* value_list: COMMA insert_vaule value_list  */
#line 366 "yacc_sql.y"
                                     { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1782 "yacc_sql.tab.c"
    break;

  case 56: /* insert_vaule: NUMBER  */
#line 371 "yacc_sql.y"
          {	
		// 匹配时insert规则时，保存在CONTEXT->inserts_more->values中
  		value_init_integer(&CONTEXT->inserts_more[CONTEXT->insert_length].values[CONTEXT->inserts_more[CONTEXT->insert_length].value_num++], (yyvsp[0].number));
		// 匹配Conditon规则时，values需要保存在CONTEXT->values中,使用下面的value规则
		}
#line 1792 "yacc_sql.tab.c"
    break;

  case 57: /* insert_vaule: FLOAT  */
#line 376 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->inserts_more[CONTEXT->insert_length].values[CONTEXT->inserts_more[CONTEXT->insert_length].value_num++], (yyvsp[0].floats));
		}
#line 1800 "yacc_sql.tab.c"
    break;

  case 58: /* insert_vaule: SSS  */
#line 379 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->inserts_more[CONTEXT->insert_length].values[CONTEXT->inserts_more[CONTEXT->insert_length].value_num++], (yyvsp[0].string));
		}
#line 1809 "yacc_sql.tab.c"
    break;

  case 59: /* insert_vaule: NULL__  */
#line 383 "yacc_sql.y"
            {
		value_init_null(&CONTEXT->inserts_more[CONTEXT->insert_length].values[CONTEXT->inserts_more[CONTEXT->insert_length].value_num++]);
	}
#line 1817 "yacc_sql.tab.c"
    break;

  case 60: /* value: NUMBER  */
#line 387 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1825 "yacc_sql.tab.c"
    break;

  case 61: /* value: FLOAT  */
#line 390 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1833 "yacc_sql.tab.c"
    break;

  case 62: /* value: SSS  */
#line 393 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 1842 "yacc_sql.tab.c"
    break;

  case 63: /* value: LBRACE sub_select RBRACE  */
#line 397 "yacc_sql.y"
                                  {
		value_init_query(&CONTEXT->values[CONTEXT->value_length++], GET_SUB_CONTEXT->ssql);
		// 赋值后将子句清空
		memset(GET_SUB_CONTEXT->ssql, 0, sizeof(*GET_SUB_CONTEXT->ssql));
	}
#line 1852 "yacc_sql.tab.c"
    break;

  case 64: /* value: NULL__  */
#line 403 "yacc_sql.y"
                {
		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
	}
#line 1860 "yacc_sql.tab.c"
    break;

  case 65: /* delete: DELETE FROM ID where SEMICOLON  */
#line 410 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 1872 "yacc_sql.tab.c"
    break;

  case 66: /* update: UPDATE ID update_list where SEMICOLON  */
#line 420 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-3].string), CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 1882 "yacc_sql.tab.c"
    break;

  case 67: /* update_list: SET ID EQ value set_list  */
#line 427 "yacc_sql.y"
                            {
		SetValue set_value;
		set_value_init(&set_value, (yyvsp[-3].string), &CONTEXT->values[--CONTEXT->value_length]);
		update_append_value_list(&CONTEXT->ssql->sstr.update, &set_value);
	}
#line 1892 "yacc_sql.tab.c"
    break;

  case 69: /* set_list: COMMA ID EQ value set_list  */
#line 436 "yacc_sql.y"
                                    {
		SetValue set_value;
		set_value_init(&set_value, (yyvsp[-3].string), &CONTEXT->values[--CONTEXT->value_length]);
		update_append_value_list(&CONTEXT->ssql->sstr.update, &set_value);
	}
#line 1902 "yacc_sql.tab.c"
    break;

  case 70: /* sub_select: SELECT sub_select_attr FROM ID sub_rel_list sub_where  */
#line 444 "yacc_sql.y"
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
#line 1919 "yacc_sql.tab.c"
    break;

  case 71: /* sub_select_attr: STAR sub_attr_list  */
#line 458 "yacc_sql.y"
                      {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1929 "yacc_sql.tab.c"
    break;

  case 72: /* sub_select_attr: ID sub_attr_list  */
#line 463 "yacc_sql.y"
                       {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1939 "yacc_sql.tab.c"
    break;

  case 73: /* sub_select_attr: ID DOT ID sub_attr_list  */
#line 468 "yacc_sql.y"
                                  {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1949 "yacc_sql.tab.c"
    break;

  case 74: /* sub_select_attr: ID DOT STAR sub_attr_list  */
#line 473 "yacc_sql.y"
                                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 1959 "yacc_sql.tab.c"
    break;

  case 75: /* sub_select_attr: sub_agg_func sub_attr_list  */
#line 478 "yacc_sql.y"
                                    {
	}
#line 1966 "yacc_sql.tab.c"
    break;

  case 77: /* sub_attr_list: COMMA ID sub_attr_list  */
#line 483 "yacc_sql.y"
                             {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
#line 1978 "yacc_sql.tab.c"
    break;

  case 78: /* sub_attr_list: COMMA ID DOT STAR sub_attr_list  */
#line 490 "yacc_sql.y"
                                          {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 1988 "yacc_sql.tab.c"
    break;

  case 79: /* sub_attr_list: COMMA ID DOT ID sub_attr_list  */
#line 495 "yacc_sql.y"
                                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
#line 2000 "yacc_sql.tab.c"
    break;

  case 81: /* sub_agg_func: MAX LBRACE ID RBRACE  */
#line 506 "yacc_sql.y"
                             {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_MAX);
	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2010 "yacc_sql.tab.c"
    break;

  case 82: /* sub_agg_func: MAX LBRACE ID DOT ID RBRACE  */
#line 511 "yacc_sql.y"
                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_MAX);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2020 "yacc_sql.tab.c"
    break;

  case 83: /* sub_agg_func: MIN LBRACE ID RBRACE  */
#line 516 "yacc_sql.y"
                               {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_MIN);
	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2030 "yacc_sql.tab.c"
    break;

  case 84: /* sub_agg_func: MIN LBRACE ID DOT ID RBRACE  */
#line 521 "yacc_sql.y"
                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_MIN);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2040 "yacc_sql.tab.c"
    break;

  case 85: /* sub_agg_func: SUM LBRACE ID RBRACE  */
#line 526 "yacc_sql.y"
                               {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_SUM);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2050 "yacc_sql.tab.c"
    break;

  case 86: /* sub_agg_func: SUM LBRACE ID DOT ID RBRACE  */
#line 531 "yacc_sql.y"
                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_SUM);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2060 "yacc_sql.tab.c"
    break;

  case 87: /* sub_agg_func: COUNT LBRACE NUMBER RBRACE  */
#line 536 "yacc_sql.y"
                                     {
       	  RelAttr attr;
       	  char *str = malloc(10 * sizeof(char));
       	  snprintf(str, 10, "%d", (yyvsp[-1].number));
       	  aggregation_attr_init(&attr, NULL, str, AGG_COUNT);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2072 "yacc_sql.tab.c"
    break;

  case 88: /* sub_agg_func: COUNT LBRACE STAR RBRACE  */
#line 543 "yacc_sql.y"
                                   {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, "*", AGG_COUNT);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2082 "yacc_sql.tab.c"
    break;

  case 89: /* sub_agg_func: COUNT LBRACE ID RBRACE  */
#line 548 "yacc_sql.y"
                                 {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_COUNT);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2092 "yacc_sql.tab.c"
    break;

  case 90: /* sub_agg_func: AVG LBRACE ID RBRACE  */
#line 553 "yacc_sql.y"
                               {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_AVG);
	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2102 "yacc_sql.tab.c"
    break;

  case 91: /* sub_agg_func: AVG LBRACE ID DOT ID RBRACE  */
#line 558 "yacc_sql.y"
                                      {
	  RelAttr attr;
	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_AVG);
	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2112 "yacc_sql.tab.c"
    break;

  case 93: /* sub_rel_list: COMMA ID sub_rel_list  */
#line 567 "yacc_sql.y"
                            {	
			selects_append_relation(&GET_SUB_CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 2120 "yacc_sql.tab.c"
    break;

  case 94: /* select: SELECT select_attr FROM ID rel_list where SEMICOLON  */
#line 573 "yacc_sql.y"
                {
			// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));

			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);

			CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;

			//临时变量清零
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
#line 2140 "yacc_sql.tab.c"
    break;

  case 95: /* select: SELECT select_attr FROM ID rel_list inner where SEMICOLON  */
#line 589 "yacc_sql.y"
                {
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string));
			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);

			CONTEXT->ssql->flag=SCF_SELECT;
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
#line 2155 "yacc_sql.tab.c"
    break;

  case 96: /* select_attr: STAR attr_list  */
#line 602 "yacc_sql.y"
                  {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2165 "yacc_sql.tab.c"
    break;

  case 97: /* select_attr: ID attr_list  */
#line 607 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2175 "yacc_sql.tab.c"
    break;

  case 98: /* select_attr: ID DOT ID attr_list  */
#line 612 "yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2185 "yacc_sql.tab.c"
    break;

  case 99: /* select_attr: ID DOT STAR attr_list  */
#line 617 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2195 "yacc_sql.tab.c"
    break;

  case 102: /* attr_list: COMMA ID attr_list  */
#line 627 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
#line 2207 "yacc_sql.tab.c"
    break;

  case 103: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 634 "yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2217 "yacc_sql.tab.c"
    break;

  case 104: /* attr_list: COMMA ID DOT ID attr_list  */
#line 639 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
#line 2229 "yacc_sql.tab.c"
    break;

  case 106: /* agg_func: MAX LBRACE ID RBRACE  */
#line 650 "yacc_sql.y"
                             {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_MAX);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2239 "yacc_sql.tab.c"
    break;

  case 107: /* agg_func: MAX LBRACE ID DOT ID RBRACE  */
#line 655 "yacc_sql.y"
                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_MAX);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2249 "yacc_sql.tab.c"
    break;

  case 108: /* agg_func: MIN LBRACE ID RBRACE  */
#line 660 "yacc_sql.y"
                               {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_MIN);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2259 "yacc_sql.tab.c"
    break;

  case 109: /* agg_func: MIN LBRACE ID DOT ID RBRACE  */
#line 665 "yacc_sql.y"
                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_MIN);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2269 "yacc_sql.tab.c"
    break;

  case 110: /* agg_func: SUM LBRACE ID RBRACE  */
#line 670 "yacc_sql.y"
                               {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_SUM);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2279 "yacc_sql.tab.c"
    break;

  case 111: /* agg_func: SUM LBRACE ID DOT ID RBRACE  */
#line 675 "yacc_sql.y"
                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_SUM);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2289 "yacc_sql.tab.c"
    break;

  case 112: /* agg_func: COUNT LBRACE NUMBER RBRACE  */
#line 680 "yacc_sql.y"
                                     {
       	  RelAttr attr;
       	  char *str = malloc(10 * sizeof(char));
       	  snprintf(str, 10, "%d", (yyvsp[-1].number));
       	  aggregation_attr_init(&attr, NULL, str, AGG_COUNT);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2301 "yacc_sql.tab.c"
    break;

  case 113: /* agg_func: COUNT LBRACE STAR RBRACE  */
#line 687 "yacc_sql.y"
                                   {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, "*", AGG_COUNT);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2311 "yacc_sql.tab.c"
    break;

  case 114: /* agg_func: COUNT LBRACE ID RBRACE  */
#line 692 "yacc_sql.y"
                                 {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_COUNT);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2321 "yacc_sql.tab.c"
    break;

  case 115: /* agg_func: AVG LBRACE ID RBRACE  */
#line 697 "yacc_sql.y"
                               {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_AVG);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2331 "yacc_sql.tab.c"
    break;

  case 116: /* agg_func: AVG LBRACE ID DOT ID RBRACE  */
#line 702 "yacc_sql.y"
                                      {
	  RelAttr attr;
	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_AVG);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2341 "yacc_sql.tab.c"
    break;

  case 118: /* rel_list: COMMA ID rel_list  */
#line 711 "yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 2349 "yacc_sql.tab.c"
    break;

  case 120: /* inner: INNER JOIN ID rel_list on inner  */
#line 717 "yacc_sql.y"
                                          {
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
		  }
#line 2357 "yacc_sql.tab.c"
    break;

  case 121: /* inner: JOIN ID rel_list on inner  */
#line 720 "yacc_sql.y"
                                    {
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
		  }
#line 2365 "yacc_sql.tab.c"
    break;

  case 123: /* on: ON condition condition_list  */
#line 726 "yacc_sql.y"
                                      {

		  }
#line 2373 "yacc_sql.tab.c"
    break;

  case 125: /* where: WHERE condition condition_list  */
#line 732 "yacc_sql.y"
                                     {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2381 "yacc_sql.tab.c"
    break;

  case 127: /* condition_list: AND condition condition_list  */
#line 738 "yacc_sql.y"
                                   {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2389 "yacc_sql.tab.c"
    break;

  case 128: /* condition: ID comOp value  */
#line 744 "yacc_sql.y"
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
#line 2414 "yacc_sql.tab.c"
    break;

  case 129: /* condition: value comOp value  */
#line 765 "yacc_sql.y"
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
#line 2438 "yacc_sql.tab.c"
    break;

  case 130: /* condition: ID comOp ID  */
#line 785 "yacc_sql.y"
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
#line 2462 "yacc_sql.tab.c"
    break;

  case 131: /* condition: value comOp ID  */
#line 805 "yacc_sql.y"
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
#line 2488 "yacc_sql.tab.c"
    break;

  case 132: /* condition: ID DOT ID comOp value  */
#line 827 "yacc_sql.y"
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
#line 2513 "yacc_sql.tab.c"
    break;

  case 133: /* condition: value comOp ID DOT ID  */
#line 848 "yacc_sql.y"
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
#line 2538 "yacc_sql.tab.c"
    break;

  case 134: /* condition: ID DOT ID comOp ID DOT ID  */
#line 869 "yacc_sql.y"
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
#line 2561 "yacc_sql.tab.c"
    break;

  case 136: /* sub_where: WHERE sub_condition sub_condition_list  */
#line 891 "yacc_sql.y"
                                             {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2569 "yacc_sql.tab.c"
    break;

  case 138: /* sub_condition_list: AND sub_condition sub_condition_list  */
#line 897 "yacc_sql.y"
                                           {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2577 "yacc_sql.tab.c"
    break;

  case 139: /* sub_condition: ID sub_comOp sub_value  */
#line 903 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

			Value *right_value = &GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, GET_SUB_CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			GET_SUB_CONTEXT->conditions[GET_SUB_CONTEXT->condition_length++] = condition;
		}
#line 2592 "yacc_sql.tab.c"
    break;

  case 140: /* sub_condition: sub_value sub_comOp sub_value  */
#line 914 "yacc_sql.y"
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
#line 2616 "yacc_sql.tab.c"
    break;

  case 141: /* sub_condition: ID sub_comOp ID  */
#line 934 "yacc_sql.y"
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
#line 2640 "yacc_sql.tab.c"
    break;

  case 142: /* sub_condition: sub_value sub_comOp ID  */
#line 954 "yacc_sql.y"
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
#line 2666 "yacc_sql.tab.c"
    break;

  case 143: /* sub_condition: ID DOT ID sub_comOp sub_value  */
#line 976 "yacc_sql.y"
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
#line 2691 "yacc_sql.tab.c"
    break;

  case 144: /* sub_condition: sub_value sub_comOp ID DOT ID  */
#line 997 "yacc_sql.y"
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
#line 2716 "yacc_sql.tab.c"
    break;

  case 145: /* sub_condition: ID DOT ID sub_comOp ID DOT ID  */
#line 1018 "yacc_sql.y"
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
#line 2739 "yacc_sql.tab.c"
    break;

  case 146: /* sub_value: NUMBER  */
#line 1039 "yacc_sql.y"
          {	
  		value_init_integer(&GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 2747 "yacc_sql.tab.c"
    break;

  case 147: /* sub_value: FLOAT  */
#line 1042 "yacc_sql.y"
          {
  		value_init_float(&GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 2755 "yacc_sql.tab.c"
    break;

  case 148: /* sub_value: SSS  */
#line 1045 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 2764 "yacc_sql.tab.c"
    break;

  case 149: /* sub_value: NULL__  */
#line 1049 "yacc_sql.y"
                {
		value_init_null(&GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length++]);
	}
#line 2772 "yacc_sql.tab.c"
    break;

  case 150: /* sub_comOp: EQ  */
#line 1055 "yacc_sql.y"
             { GET_SUB_CONTEXT->comp = EQUAL_TO; }
#line 2778 "yacc_sql.tab.c"
    break;

  case 151: /* sub_comOp: LT  */
#line 1056 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = LESS_THAN; }
#line 2784 "yacc_sql.tab.c"
    break;

  case 152: /* sub_comOp: GT  */
#line 1057 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = GREAT_THAN; }
#line 2790 "yacc_sql.tab.c"
    break;

  case 153: /* sub_comOp: LE  */
#line 1058 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = LESS_EQUAL; }
#line 2796 "yacc_sql.tab.c"
    break;

  case 154: /* sub_comOp: GE  */
#line 1059 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = GREAT_EQUAL; }
#line 2802 "yacc_sql.tab.c"
    break;

  case 155: /* sub_comOp: NE  */
#line 1060 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = NOT_EQUAL; }
#line 2808 "yacc_sql.tab.c"
    break;

  case 156: /* sub_comOp: LIKE  */
#line 1061 "yacc_sql.y"
           { GET_SUB_CONTEXT->comp = OP_LIKE; }
#line 2814 "yacc_sql.tab.c"
    break;

  case 157: /* sub_comOp: NOT LIKE  */
#line 1062 "yacc_sql.y"
               { GET_SUB_CONTEXT->comp = OP_NOT_LIKE; }
#line 2820 "yacc_sql.tab.c"
    break;

  case 158: /* sub_comOp: IS  */
#line 1063 "yacc_sql.y"
                   { CONTEXT->comp = EQUAL_IS; }
#line 2826 "yacc_sql.tab.c"
    break;

  case 159: /* sub_comOp: IS NOT  */
#line 1064 "yacc_sql.y"
                   { CONTEXT->comp = NOT_EQUAL_IS; }
#line 2832 "yacc_sql.tab.c"
    break;

  case 160: /* comOp: EQ  */
#line 1068 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 2838 "yacc_sql.tab.c"
    break;

  case 161: /* comOp: LT  */
#line 1069 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 2844 "yacc_sql.tab.c"
    break;

  case 162: /* comOp: GT  */
#line 1070 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 2850 "yacc_sql.tab.c"
    break;

  case 163: /* comOp: LE  */
#line 1071 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 2856 "yacc_sql.tab.c"
    break;

  case 164: /* comOp: GE  */
#line 1072 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 2862 "yacc_sql.tab.c"
    break;

  case 165: /* comOp: NE  */
#line 1073 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 2868 "yacc_sql.tab.c"
    break;

  case 166: /* comOp: LIKE  */
#line 1074 "yacc_sql.y"
                   { CONTEXT->comp = OP_LIKE; }
#line 2874 "yacc_sql.tab.c"
    break;

  case 167: /* comOp: NOT LIKE  */
#line 1075 "yacc_sql.y"
               { CONTEXT->comp = OP_NOT_LIKE; }
#line 2880 "yacc_sql.tab.c"
    break;

  case 168: /* comOp: IS  */
#line 1076 "yacc_sql.y"
                   { CONTEXT->comp = EQUAL_IS; }
#line 2886 "yacc_sql.tab.c"
    break;

  case 169: /* comOp: IS NOT  */
#line 1077 "yacc_sql.y"
                   { CONTEXT->comp = NOT_EQUAL_IS; }
#line 2892 "yacc_sql.tab.c"
    break;

  case 170: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 1082 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2901 "yacc_sql.tab.c"
    break;


#line 2905 "yacc_sql.tab.c"

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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

#line 1087 "yacc_sql.y"

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
