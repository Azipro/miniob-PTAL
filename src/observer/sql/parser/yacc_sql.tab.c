/* A Bison parser, made by GNU Bison 3.5.1.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

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


#line 134 "yacc_sql.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_YACC_SQL_TAB_H_INCLUDED
# define YY_YY_YACC_SQL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SEMICOLON = 258,
    CREATE = 259,
    DROP = 260,
    TABLE = 261,
    TABLES = 262,
    UNIQUE = 263,
    INDEX = 264,
    SELECT = 265,
    DESC = 266,
    SHOW = 267,
    SYNC = 268,
    INSERT = 269,
    DELETE = 270,
    UPDATE = 271,
    LBRACE = 272,
    RBRACE = 273,
    COMMA = 274,
    TRX_BEGIN = 275,
    TRX_COMMIT = 276,
    TRX_ROLLBACK = 277,
    INT_T = 278,
    STRING_T = 279,
    FLOAT_T = 280,
    DATE_T = 281,
    HELP = 282,
    EXIT = 283,
    DOT = 284,
    INTO = 285,
    VALUES = 286,
    FROM = 287,
    WHERE = 288,
    AND = 289,
    SET = 290,
    INNER = 291,
    JOIN = 292,
    ON = 293,
    NOT = 294,
    NULL__ = 295,
    NULLABLE = 296,
    LOAD = 297,
    DATA = 298,
    INFILE = 299,
    EQ = 300,
    LT = 301,
    GT = 302,
    LE = 303,
    GE = 304,
    NE = 305,
    IS = 306,
    LIKE = 307,
    MAX = 308,
    MIN = 309,
    SUM = 310,
    COUNT = 311,
    AVG = 312,
    ORDER = 313,
    BY = 314,
    ASC = 315,
    NUMBER = 316,
    FLOAT = 317,
    ID = 318,
    PATH = 319,
    SSS = 320,
    STAR = 321,
    STRING_V = 322
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 130 "yacc_sql.y"

  struct _Attr *attr;
  struct _Condition *condition1;
  struct _Value *value1;
  char *string;
  int number;
  float floats;
	char *position;

#line 264 "yacc_sql.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void *scanner);

#endif /* !YY_YY_YACC_SQL_TAB_H_INCLUDED  */



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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYLAST   428

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  180
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  396

#define YYUNDEFTOK  2
#define YYMAXUTOK   322


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      65,    66,    67
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   156,   156,   158,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   183,   188,   193,   199,   205,   211,   217,   223,
     228,   235,   242,   248,   257,   259,   265,   272,   281,   283,
     287,   298,   311,   314,   315,   316,   317,   320,   323,   326,
     331,   340,   357,   359,   366,   369,   374,   379,   382,   386,
     390,   393,   396,   400,   406,   412,   422,   430,   437,   439,
     447,   461,   466,   471,   476,   481,   484,   486,   493,   498,
     505,   509,   514,   519,   524,   529,   534,   539,   546,   551,
     556,   561,   568,   570,   575,   591,   605,   610,   615,   620,
     625,   628,   630,   637,   642,   649,   653,   658,   663,   668,
     673,   678,   683,   690,   695,   700,   705,   712,   714,   718,
     720,   723,   727,   729,   733,   735,   739,   741,   746,   767,
     787,   807,   829,   850,   871,   892,   894,   898,   900,   905,
     916,   936,   956,   978,   999,  1020,  1042,  1045,  1048,  1052,
    1058,  1059,  1060,  1061,  1062,  1063,  1064,  1065,  1066,  1067,
    1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,
    1084,  1091,  1092,  1096,  1101,  1106,  1111,  1116,  1121,  1128,
    1129
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "CREATE", "DROP", "TABLE",
  "TABLES", "UNIQUE", "INDEX", "SELECT", "DESC", "SHOW", "SYNC", "INSERT",
  "DELETE", "UPDATE", "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN",
  "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "DATE_T",
  "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM", "WHERE", "AND", "SET",
  "INNER", "JOIN", "ON", "NOT", "NULL__", "NULLABLE", "LOAD", "DATA",
  "INFILE", "EQ", "LT", "GT", "LE", "GE", "NE", "IS", "LIKE", "MAX", "MIN",
  "SUM", "COUNT", "AVG", "ORDER", "BY", "ASC", "NUMBER", "FLOAT", "ID",
  "PATH", "SSS", "STAR", "STRING_V", "$accept", "commands", "command",
  "exit", "help", "sync", "begin", "commit", "rollback", "drop_table",
  "show_tables", "show_indexes", "desc_table", "create_index",
  "index_attr_list", "drop_index", "create_table", "attr_def_list",
  "attr_def", "number", "type", "is_null", "ID_get", "insert",
  "value_tuple", "value_list", "insert_vaule", "value", "delete", "update",
  "update_list", "set_list", "sub_select", "sub_select_attr",
  "sub_attr_list", "sub_agg_func", "sub_rel_list", "select", "select_attr",
  "attr_list", "agg_func", "rel_list", "inner", "on", "where",
  "condition_list", "condition", "sub_where", "sub_condition_list",
  "sub_condition", "sub_value", "sub_comOp", "comOp", "load_data",
  "order_by", "order_attr", "order_attr_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
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
     315,   316,   317,   318,   319,   320,   321,   322
};
# endif

#define YYPACT_NINF (-350)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -350,   124,  -350,   176,    27,   -35,   -29,   103,    14,    22,
      32,   -25,    56,    81,   168,   177,   199,    36,  -350,  -350,
    -350,  -350,  -350,  -350,  -350,  -350,  -350,  -350,  -350,  -350,
    -350,  -350,  -350,  -350,  -350,  -350,  -350,    43,   166,   151,
     165,   188,   222,   235,   237,   244,   245,   112,   246,   231,
     246,   261,   264,   236,  -350,   206,   207,   238,  -350,  -350,
    -350,  -350,  -350,   227,   255,   211,   239,   272,   273,   215,
     216,   217,    64,   218,   192,   149,  -350,  -350,   219,  -350,
    -350,  -350,   220,   253,   252,   223,   252,   224,   225,   249,
     228,  -350,  -350,     6,    47,    48,   274,   275,   276,    69,
     114,   246,   246,   246,   271,   292,   279,    10,   294,   254,
     295,   270,  -350,   282,   175,   240,   285,  -350,   241,  -350,
     242,  -350,   243,  -350,  -350,  -350,  -350,   247,   150,  -350,
    -350,  -350,  -350,   248,   125,  -350,   116,   297,  -350,  -350,
    -350,   144,  -350,   172,   278,  -350,    61,  -350,   302,   225,
     291,  -350,  -350,  -350,  -350,     8,   296,   251,   298,   299,
     300,   301,   246,   246,   271,   283,   258,   252,   257,  -350,
    -350,  -350,  -350,   303,   187,   305,   262,   277,  -350,  -350,
    -350,  -350,  -350,  -350,   287,  -350,    20,    34,    10,  -350,
     308,   265,   282,   321,   269,   293,  -350,  -350,   268,   313,
    -350,  -350,  -350,  -350,  -350,  -350,  -350,   280,   271,   257,
     281,   331,   116,   317,   319,   320,   322,   324,   325,   130,
     326,   306,   326,  -350,   172,  -350,  -350,  -350,  -350,   315,
    -350,   278,   284,  -350,   343,  -350,  -350,  -350,   330,  -350,
     313,   286,   332,   271,   314,   348,   290,  -350,   303,   335,
     304,   307,   309,   113,   310,   203,   163,  -350,  -350,   311,
    -350,    46,   312,  -350,   316,  -350,   147,   337,   313,   353,
     314,    10,    82,  -350,     1,   338,  -350,   341,   356,    75,
      76,    84,   342,   344,   345,    85,   131,   326,   326,   326,
     346,   339,  -350,  -350,    61,  -350,   361,  -350,  -350,    82,
     278,  -350,  -350,   318,  -350,   290,  -350,   116,  -350,  -350,
     323,  -350,   327,  -350,   328,  -350,  -350,  -350,  -350,   329,
     164,  -350,  -350,  -350,  -350,   333,   336,   334,   308,  -350,
    -350,  -350,     2,   338,   303,   358,   359,   360,   362,   326,
     326,   346,   -17,  -350,  -350,  -350,  -350,  -350,  -350,   364,
    -350,  -350,  -350,  -350,  -350,  -350,  -350,  -350,  -350,  -350,
     158,  -350,   349,   186,   335,   340,   347,  -350,  -350,  -350,
    -350,  -350,  -350,   350,  -350,    92,   -17,  -350,   102,  -350,
     186,  -350,  -350,  -350,  -350,   349,   355,  -350,   107,  -350,
     351,   365,  -350,  -350,   352,  -350
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
       0,     0,   101,   101,   117,     0,     0,   124,   171,    59,
      56,    57,    58,    54,     0,     0,     0,     0,   160,   161,
     162,   163,   164,   165,   168,   166,     0,     0,     0,   125,
      68,     0,    38,     0,     0,     0,    49,    41,     0,    34,
     107,   109,   111,   116,   104,   103,   118,     0,   117,   171,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    76,
      76,     0,    76,    63,     0,   167,   169,   130,   128,   131,
     129,   126,     0,    67,     0,    39,    37,    42,     0,    48,
      34,     0,     0,   117,   122,     0,     0,    94,    54,    52,
       0,     0,     0,     0,     0,     0,     0,    72,    71,     0,
      75,     0,     0,   127,     0,   170,    47,     0,    34,     0,
     122,     0,   119,    95,   173,   179,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    76,    76,    76,    76,
      92,     0,   132,   133,     0,    40,     0,    35,    32,   119,
     126,   121,   175,     0,   174,     0,   172,     0,    51,    81,
       0,    83,     0,    85,     0,    87,    89,    88,    90,     0,
       0,    77,    80,    73,    74,     0,   135,     0,    68,    33,
     120,   123,   176,   179,    54,     0,     0,     0,     0,    76,
      76,    92,     0,    70,   134,    69,   178,   177,   180,     0,
      82,    84,    86,    91,    79,    78,    93,   149,   146,   147,
       0,   148,   137,     0,    52,     0,     0,   150,   151,   152,
     153,   154,   155,   158,   156,     0,     0,   136,     0,    53,
       0,   157,   159,   141,   139,   137,   142,   140,     0,   138,
       0,     0,   143,   144,     0,   145
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -350,  -350,  -350,  -350,  -350,  -350,  -350,  -350,  -350,  -350,
    -350,  -350,  -350,  -350,  -226,  -350,  -350,   174,   230,  -350,
    -350,   105,  -350,  -350,    21,  -242,  -207,  -146,  -350,  -350,
    -350,    59,  -350,  -350,  -219,   133,    52,  -350,  -350,   -46,
     354,  -155,  -256,   128,   -76,  -220,  -181,  -350,    15,    19,
    -349,  -348,  -135,  -350,   193,    96,    71
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,   242,    30,    31,   150,   113,   238,
     155,   197,   114,    32,   278,   213,   173,   143,    33,    34,
      86,   233,   175,   221,   257,   222,   326,    35,    49,    76,
      50,   134,   167,   272,   108,   189,   144,   343,   377,   362,
     363,   375,   186,    36,   211,   275,   306
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     190,   258,    77,   260,    79,   248,   276,   231,   187,   206,
     110,   263,   302,   346,   267,   378,   301,    54,    42,    43,
      44,    45,    46,   357,   117,   194,   384,   137,    47,   387,
     303,    48,   388,    40,    51,   118,    41,   137,    57,   392,
     228,   230,   297,   330,   358,   359,   360,   195,   361,   196,
     138,   137,    55,   244,   129,   130,   131,   132,   168,    58,
     138,   304,   347,   137,    56,   119,   121,   321,   322,   323,
     324,   139,   140,   141,   138,   142,   120,   122,   137,    63,
     331,   139,   140,   227,    59,   142,   138,   126,   270,   261,
     300,   209,   349,   309,   311,   139,   140,   229,   127,   142,
     334,   138,   313,   318,   310,   312,    64,   139,   140,   291,
      52,   142,    53,   314,   319,   292,   204,   205,   165,   166,
     354,   355,   139,   140,     2,    96,   142,    97,     3,     4,
      98,    74,   357,    74,     5,     6,     7,     8,     9,    10,
      11,    75,   357,   128,    12,    13,    14,   357,   328,   255,
     255,    15,    16,   358,   359,   383,   169,   361,   107,   256,
     320,   165,   166,   358,   359,   386,    17,   361,   358,   359,
     391,    60,   361,   176,   282,    65,   283,   170,   171,   284,
      61,   172,    37,   177,    38,    39,   195,   365,   196,   178,
     179,   180,   181,   182,   183,   184,   185,   366,   151,   152,
     153,   154,    62,   367,   368,   369,   370,   371,   372,   373,
     374,   177,   102,   162,    66,   103,   163,   178,   179,   180,
     181,   182,   183,   184,   185,   366,   288,   339,    67,   289,
     340,   367,   368,   369,   370,   371,   372,   373,   374,    69,
     214,   215,   216,   217,   218,    42,    43,    44,    45,    46,
     219,    68,    70,   220,    71,   100,   214,   215,   216,   217,
     218,    72,    73,    78,    80,    74,   286,    81,    82,    83,
      84,    87,    88,    85,    89,    91,    92,    90,    93,    94,
      95,    99,   104,   105,   106,   107,   109,   115,   112,   111,
     133,   116,   123,   124,   125,   135,   136,   145,   147,   146,
     148,   149,   157,   156,   158,   159,   160,   174,   191,   193,
     161,   164,   188,   198,   199,   210,   200,   201,   202,   203,
     207,   208,   212,   223,   236,   224,   226,   232,   234,   225,
     237,   240,   241,   239,   247,   249,   250,   251,   259,   252,
     246,   253,   254,   243,   262,   255,   265,   264,   266,   268,
     269,   273,   271,   274,   277,   296,   298,   305,   307,   308,
     315,   294,   316,   317,   329,   325,   235,   279,   327,   342,
     280,   295,   281,   285,   290,   293,   350,   351,   352,   192,
     353,   332,   364,   376,   390,   379,   335,   345,   287,   382,
     336,   337,   338,   356,   394,   385,   341,   344,   299,   381,
     389,   333,   245,   380,   348,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   393,   395,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   101
};

static const yytype_int16 yycheck[] =
{
     146,   220,    48,   222,    50,   212,   248,   188,   143,   164,
      86,   231,    11,    11,   240,   363,   272,     3,    53,    54,
      55,    56,    57,    40,    18,    17,   375,    17,    63,   378,
      29,    66,   380,     6,    63,    29,     9,    17,    63,   388,
     186,   187,   268,   299,    61,    62,    63,    39,    65,    41,
      40,    17,    30,   208,   100,   101,   102,   103,   134,     3,
      40,    60,    60,    17,    32,    18,    18,   286,   287,   288,
     289,    61,    62,    63,    40,    65,    29,    29,    17,    43,
     300,    61,    62,    63,     3,    65,    40,    18,   243,   224,
     271,   167,   334,    18,    18,    61,    62,    63,    29,    65,
     307,    40,    18,    18,    29,    29,    63,    61,    62,    63,
       7,    65,     9,    29,    29,   261,   162,   163,    36,    37,
     339,   340,    61,    62,     0,    61,    65,    63,     4,     5,
      66,    19,    40,    19,    10,    11,    12,    13,    14,    15,
      16,    29,    40,    29,    20,    21,    22,    40,   294,    19,
      19,    27,    28,    61,    62,    63,    40,    65,    33,    29,
      29,    36,    37,    61,    62,    63,    42,    65,    61,    62,
      63,     3,    65,    29,    61,     9,    63,    61,    62,    66,
       3,    65,     6,    39,     8,     9,    39,    29,    41,    45,
      46,    47,    48,    49,    50,    51,    52,    39,    23,    24,
      25,    26,     3,    45,    46,    47,    48,    49,    50,    51,
      52,    39,    63,    63,    63,    66,    66,    45,    46,    47,
      48,    49,    50,    51,    52,    39,    63,    63,    63,    66,
      66,    45,    46,    47,    48,    49,    50,    51,    52,    17,
      53,    54,    55,    56,    57,    53,    54,    55,    56,    57,
      63,    63,    17,    66,    17,    63,    53,    54,    55,    56,
      57,    17,    17,    32,     3,    19,    63,     3,    32,    63,
      63,    44,    17,    35,    63,     3,     3,    38,    63,    63,
      63,    63,    63,    63,    31,    33,    63,    38,    63,    65,
      19,    63,    18,    18,    18,     3,    17,     3,     3,    45,
      30,    19,    17,    63,    63,    63,    63,    10,     6,    18,
      63,    63,    34,    17,    63,    58,    18,    18,    18,    18,
      37,    63,    19,    18,     3,    63,    39,    19,    63,    52,
      61,    63,    19,    40,     3,    18,    17,    17,    32,    17,
      59,    17,    17,    63,    29,    19,     3,    63,    18,    63,
      18,     3,    38,    63,    19,    18,     3,    19,    17,     3,
      18,    45,    18,    18,     3,    19,   192,    63,    29,    33,
      63,   266,    63,    63,    63,    63,    18,    18,    18,   149,
      18,    63,    18,    34,    29,   364,    63,   328,   255,    39,
      63,    63,    63,   341,    29,   376,    63,    63,   270,    52,
     385,   305,   209,    63,   333,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    69,     0,     4,     5,    10,    11,    12,    13,    14,
      15,    16,    20,    21,    22,    27,    28,    42,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      83,    84,    91,    96,    97,   105,   121,     6,     8,     9,
       6,     9,    53,    54,    55,    56,    57,    63,    66,   106,
     108,    63,     7,     9,     3,    30,    32,    63,     3,     3,
       3,     3,     3,    43,    63,     9,    63,    63,    63,    17,
      17,    17,    17,    17,    19,    29,   107,   107,    32,   107,
       3,     3,    32,    63,    63,    35,    98,    44,    17,    63,
      38,     3,     3,    63,    63,    63,    61,    63,    66,    63,
      63,   108,    63,    66,    63,    63,    31,    33,   112,    63,
     112,    65,    63,    86,    90,    38,    63,    18,    29,    18,
      29,    18,    29,    18,    18,    18,    18,    29,    29,   107,
     107,   107,   107,    19,   109,     3,    17,    17,    40,    61,
      62,    63,    65,    95,   114,     3,    45,     3,    30,    19,
      85,    23,    24,    25,    26,    88,    63,    17,    63,    63,
      63,    63,    63,    66,    63,    36,    37,   110,   112,    40,
      61,    62,    65,    94,    10,   100,    29,    39,    45,    46,
      47,    48,    49,    50,    51,    52,   120,   120,    34,   113,
      95,     6,    86,    18,    17,    39,    41,    89,    17,    63,
      18,    18,    18,    18,   107,   107,   109,    37,    63,   112,
      58,   122,    19,    93,    53,    54,    55,    56,    57,    63,
      66,   101,   103,    18,    63,    52,    39,    63,    95,    63,
      95,   114,    19,    99,    63,    85,     3,    61,    87,    40,
      63,    19,    82,    63,   109,   122,    59,     3,    94,    18,
      17,    17,    17,    17,    17,    19,    29,   102,   102,    32,
     102,   120,    29,   113,    63,     3,    18,    82,    63,    18,
     109,    38,   111,     3,    63,   123,    93,    19,    92,    63,
      63,    63,    61,    63,    66,    63,    63,   103,    63,    66,
      63,    63,    95,    63,    45,    89,    18,    82,     3,   111,
     114,   110,    11,    29,    60,    19,   124,    17,     3,    18,
      29,    18,    29,    18,    29,    18,    18,    18,    18,    29,
      29,   102,   102,   102,   102,    19,   104,    29,    95,     3,
     110,   113,    63,   123,    94,    63,    63,    63,    63,    63,
      66,    63,    33,   115,    63,    99,    11,    60,   124,    93,
      18,    18,    18,    18,   102,   102,   104,    40,    61,    62,
      63,    65,   117,   118,    18,    29,    39,    45,    46,    47,
      48,    49,    50,    51,    52,   119,    34,   116,   119,    92,
      63,    52,    39,    63,   118,   117,    63,   118,   119,   116,
      29,    63,   118,    63,    29,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    68,    69,    69,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    81,    82,    82,    83,    84,    85,    85,
      86,    86,    87,    88,    88,    88,    88,    89,    89,    89,
      90,    91,    92,    92,    93,    93,    94,    94,    94,    94,
      95,    95,    95,    95,    95,    96,    97,    98,    99,    99,
     100,   101,   101,   101,   101,   101,   102,   102,   102,   102,
     102,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   104,   104,   105,   105,   106,   106,   106,   106,
     106,   107,   107,   107,   107,   107,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   109,   109,   110,
     110,   110,   111,   111,   112,   112,   113,   113,   114,   114,
     114,   114,   114,   114,   114,   115,   115,   116,   116,   117,
     117,   117,   117,   117,   117,   117,   118,   118,   118,   118,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     121,   122,   122,   123,   123,   123,   123,   123,   123,   124,
     124
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
       4,     6,     0,     3,     8,     9,     2,     2,     4,     4,
       2,     0,     3,     5,     5,     3,     4,     6,     4,     6,
       4,     6,     4,     4,     4,     4,     6,     0,     3,     0,
       6,     5,     0,     3,     0,     3,     0,     3,     3,     3,
       3,     3,     5,     5,     7,     0,     3,     0,     3,     3,
       3,     3,     3,     5,     5,     7,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       8,     0,     4,     1,     2,     2,     3,     4,     4,     0,
       3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, void *scanner)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, void *scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, scanner);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, void *scanner)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              , scanner);
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, void *scanner)
{
  YYUSE (yyvaluep);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *scanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 22:
#line 183 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1729 "yacc_sql.tab.c"
    break;

  case 23:
#line 188 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1737 "yacc_sql.tab.c"
    break;

  case 24:
#line 193 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1745 "yacc_sql.tab.c"
    break;

  case 25:
#line 199 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1753 "yacc_sql.tab.c"
    break;

  case 26:
#line 205 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1761 "yacc_sql.tab.c"
    break;

  case 27:
#line 211 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1769 "yacc_sql.tab.c"
    break;

  case 28:
#line 217 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1778 "yacc_sql.tab.c"
    break;

  case 29:
#line 223 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1786 "yacc_sql.tab.c"
    break;

  case 30:
#line 228 "yacc_sql.y"
                                     {
	  CONTEXT->ssql->flag = SCF_SHOW_INDEXES;
	  create_show_index(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
	}
#line 1795 "yacc_sql.tab.c"
    break;

  case 31:
#line 235 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1804 "yacc_sql.tab.c"
    break;

  case 32:
#line 243 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[-3].string));
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), DEFAULT_INDEX);
		}
#line 1814 "yacc_sql.tab.c"
    break;

  case 33:
#line 249 "yacc_sql.y"
        {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
            create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[-3].string));
            create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), UNIQUE_INDEX);
        }
#line 1824 "yacc_sql.tab.c"
    break;

  case 35:
#line 259 "yacc_sql.y"
                               {
            create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[-1].string));
        }
#line 1832 "yacc_sql.tab.c"
    break;

  case 36:
#line 266 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1841 "yacc_sql.tab.c"
    break;

  case 37:
#line 273 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1853 "yacc_sql.tab.c"
    break;

  case 39:
#line 283 "yacc_sql.y"
                                   {    }
#line 1859 "yacc_sql.tab.c"
    break;

  case 40:
#line 288 "yacc_sql.y"
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
#line 1874 "yacc_sql.tab.c"
    break;

  case 41:
#line 299 "yacc_sql.y"
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
#line 1889 "yacc_sql.tab.c"
    break;

  case 42:
#line 311 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1895 "yacc_sql.tab.c"
    break;

  case 43:
#line 314 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1901 "yacc_sql.tab.c"
    break;

  case 44:
#line 315 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1907 "yacc_sql.tab.c"
    break;

  case 45:
#line 316 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1913 "yacc_sql.tab.c"
    break;

  case 46:
#line 317 "yacc_sql.y"
                { (yyval.number)=DATES; }
#line 1919 "yacc_sql.tab.c"
    break;

  case 47:
#line 320 "yacc_sql.y"
                   {
		CONTEXT->nullable = 0;
	}
#line 1927 "yacc_sql.tab.c"
    break;

  case 48:
#line 323 "yacc_sql.y"
                    {
		CONTEXT->nullable = 0;
	}
#line 1935 "yacc_sql.tab.c"
    break;

  case 49:
#line 326 "yacc_sql.y"
                   {
		CONTEXT->nullable = 1;
	}
#line 1943 "yacc_sql.tab.c"
    break;

  case 50:
#line 332 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1952 "yacc_sql.tab.c"
    break;

  case 51:
#line 341 "yacc_sql.y"
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
#line 1972 "yacc_sql.tab.c"
    break;

  case 53:
#line 359 "yacc_sql.y"
                                                                  {

	  }
#line 1980 "yacc_sql.tab.c"
    break;

  case 54:
#line 366 "yacc_sql.y"
        {
		inserts_more_init(&CONTEXT->inserts_more[CONTEXT->insert_length].value_num, &CONTEXT->insert_length);
	}
#line 1988 "yacc_sql.tab.c"
    break;

  case 55:
#line 369 "yacc_sql.y"
                                     { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1996 "yacc_sql.tab.c"
    break;

  case 56:
#line 374 "yacc_sql.y"
          {	
		// 匹配时insert规则时，保存在CONTEXT->inserts_more->values中
  		value_init_integer(&CONTEXT->inserts_more[CONTEXT->insert_length].values[CONTEXT->inserts_more[CONTEXT->insert_length].value_num++], (yyvsp[0].number));
		// 匹配Conditon规则时，values需要保存在CONTEXT->values中,使用下面的value规则
		}
#line 2006 "yacc_sql.tab.c"
    break;

  case 57:
#line 379 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->inserts_more[CONTEXT->insert_length].values[CONTEXT->inserts_more[CONTEXT->insert_length].value_num++], (yyvsp[0].floats));
		}
#line 2014 "yacc_sql.tab.c"
    break;

  case 58:
#line 382 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->inserts_more[CONTEXT->insert_length].values[CONTEXT->inserts_more[CONTEXT->insert_length].value_num++], (yyvsp[0].string));
		}
#line 2023 "yacc_sql.tab.c"
    break;

  case 59:
#line 386 "yacc_sql.y"
            {
		value_init_null(&CONTEXT->inserts_more[CONTEXT->insert_length].values[CONTEXT->inserts_more[CONTEXT->insert_length].value_num++]);
	}
#line 2031 "yacc_sql.tab.c"
    break;

  case 60:
#line 390 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 2039 "yacc_sql.tab.c"
    break;

  case 61:
#line 393 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 2047 "yacc_sql.tab.c"
    break;

  case 62:
#line 396 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 2056 "yacc_sql.tab.c"
    break;

  case 63:
#line 400 "yacc_sql.y"
                                  {
		value_init_query(&CONTEXT->values[CONTEXT->value_length++], GET_SUB_CONTEXT->ssql);
		// 赋值后将子句清空
		memset(GET_SUB_CONTEXT->ssql, 0, sizeof(*GET_SUB_CONTEXT->ssql));
	}
#line 2066 "yacc_sql.tab.c"
    break;

  case 64:
#line 406 "yacc_sql.y"
                {
		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
	}
#line 2074 "yacc_sql.tab.c"
    break;

  case 65:
#line 413 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 2086 "yacc_sql.tab.c"
    break;

  case 66:
#line 423 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-3].string), CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 2096 "yacc_sql.tab.c"
    break;

  case 67:
#line 430 "yacc_sql.y"
                            {
		SetValue set_value;
		set_value_init(&set_value, (yyvsp[-3].string), &CONTEXT->values[--CONTEXT->value_length]);
		update_append_value_list(&CONTEXT->ssql->sstr.update, &set_value);
	}
#line 2106 "yacc_sql.tab.c"
    break;

  case 69:
#line 439 "yacc_sql.y"
                                    {
		SetValue set_value;
		set_value_init(&set_value, (yyvsp[-3].string), &CONTEXT->values[--CONTEXT->value_length]);
		update_append_value_list(&CONTEXT->ssql->sstr.update, &set_value);
	}
#line 2116 "yacc_sql.tab.c"
    break;

  case 70:
#line 447 "yacc_sql.y"
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
#line 2133 "yacc_sql.tab.c"
    break;

  case 71:
#line 461 "yacc_sql.y"
                      {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2143 "yacc_sql.tab.c"
    break;

  case 72:
#line 466 "yacc_sql.y"
                       {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2153 "yacc_sql.tab.c"
    break;

  case 73:
#line 471 "yacc_sql.y"
                                  {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2163 "yacc_sql.tab.c"
    break;

  case 74:
#line 476 "yacc_sql.y"
                                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2173 "yacc_sql.tab.c"
    break;

  case 75:
#line 481 "yacc_sql.y"
                                    {
	}
#line 2180 "yacc_sql.tab.c"
    break;

  case 77:
#line 486 "yacc_sql.y"
                             {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
#line 2192 "yacc_sql.tab.c"
    break;

  case 78:
#line 493 "yacc_sql.y"
                                          {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2202 "yacc_sql.tab.c"
    break;

  case 79:
#line 498 "yacc_sql.y"
                                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
#line 2214 "yacc_sql.tab.c"
    break;

  case 81:
#line 509 "yacc_sql.y"
                             {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_MAX);
	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2224 "yacc_sql.tab.c"
    break;

  case 82:
#line 514 "yacc_sql.y"
                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_MAX);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2234 "yacc_sql.tab.c"
    break;

  case 83:
#line 519 "yacc_sql.y"
                               {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_MIN);
	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2244 "yacc_sql.tab.c"
    break;

  case 84:
#line 524 "yacc_sql.y"
                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_MIN);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2254 "yacc_sql.tab.c"
    break;

  case 85:
#line 529 "yacc_sql.y"
                               {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_SUM);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2264 "yacc_sql.tab.c"
    break;

  case 86:
#line 534 "yacc_sql.y"
                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_SUM);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2274 "yacc_sql.tab.c"
    break;

  case 87:
#line 539 "yacc_sql.y"
                                     {
       	  RelAttr attr;
       	  char *str = malloc(10 * sizeof(char));
       	  snprintf(str, 10, "%d", (yyvsp[-1].number));
       	  aggregation_attr_init(&attr, NULL, str, AGG_COUNT);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2286 "yacc_sql.tab.c"
    break;

  case 88:
#line 546 "yacc_sql.y"
                                   {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, "*", AGG_COUNT);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2296 "yacc_sql.tab.c"
    break;

  case 89:
#line 551 "yacc_sql.y"
                                 {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_COUNT);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2306 "yacc_sql.tab.c"
    break;

  case 90:
#line 556 "yacc_sql.y"
                               {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_AVG);
	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2316 "yacc_sql.tab.c"
    break;

  case 91:
#line 561 "yacc_sql.y"
                                      {
	  RelAttr attr;
	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_AVG);
	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2326 "yacc_sql.tab.c"
    break;

  case 93:
#line 570 "yacc_sql.y"
                            {	
			selects_append_relation(&GET_SUB_CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 2334 "yacc_sql.tab.c"
    break;

  case 94:
#line 576 "yacc_sql.y"
                {
			// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string));

			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);

			CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;

			//临时变量清零
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
#line 2354 "yacc_sql.tab.c"
    break;

  case 95:
#line 592 "yacc_sql.y"
                {
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string));
			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);

			CONTEXT->ssql->flag=SCF_SELECT;
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
#line 2369 "yacc_sql.tab.c"
    break;

  case 96:
#line 605 "yacc_sql.y"
                  {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2379 "yacc_sql.tab.c"
    break;

  case 97:
#line 610 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2389 "yacc_sql.tab.c"
    break;

  case 98:
#line 615 "yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2399 "yacc_sql.tab.c"
    break;

  case 99:
#line 620 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2409 "yacc_sql.tab.c"
    break;

  case 102:
#line 630 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
#line 2421 "yacc_sql.tab.c"
    break;

  case 103:
#line 637 "yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2431 "yacc_sql.tab.c"
    break;

  case 104:
#line 642 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
#line 2443 "yacc_sql.tab.c"
    break;

  case 106:
#line 653 "yacc_sql.y"
                             {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_MAX);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2453 "yacc_sql.tab.c"
    break;

  case 107:
#line 658 "yacc_sql.y"
                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_MAX);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2463 "yacc_sql.tab.c"
    break;

  case 108:
#line 663 "yacc_sql.y"
                               {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_MIN);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2473 "yacc_sql.tab.c"
    break;

  case 109:
#line 668 "yacc_sql.y"
                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_MIN);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2483 "yacc_sql.tab.c"
    break;

  case 110:
#line 673 "yacc_sql.y"
                               {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_SUM);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2493 "yacc_sql.tab.c"
    break;

  case 111:
#line 678 "yacc_sql.y"
                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_SUM);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2503 "yacc_sql.tab.c"
    break;

  case 112:
#line 683 "yacc_sql.y"
                                     {
       	  RelAttr attr;
       	  char *str = malloc(10 * sizeof(char));
       	  snprintf(str, 10, "%d", (yyvsp[-1].number));
       	  aggregation_attr_init(&attr, NULL, str, AGG_COUNT);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2515 "yacc_sql.tab.c"
    break;

  case 113:
#line 690 "yacc_sql.y"
                                   {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, "*", AGG_COUNT);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2525 "yacc_sql.tab.c"
    break;

  case 114:
#line 695 "yacc_sql.y"
                                 {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_COUNT);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2535 "yacc_sql.tab.c"
    break;

  case 115:
#line 700 "yacc_sql.y"
                               {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_AVG);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2545 "yacc_sql.tab.c"
    break;

  case 116:
#line 705 "yacc_sql.y"
                                      {
	  RelAttr attr;
	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_AVG);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2555 "yacc_sql.tab.c"
    break;

  case 118:
#line 714 "yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 2563 "yacc_sql.tab.c"
    break;

  case 120:
#line 720 "yacc_sql.y"
                                          {
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
		  }
#line 2571 "yacc_sql.tab.c"
    break;

  case 121:
#line 723 "yacc_sql.y"
                                    {
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
		  }
#line 2579 "yacc_sql.tab.c"
    break;

  case 123:
#line 729 "yacc_sql.y"
                                      {

		  }
#line 2587 "yacc_sql.tab.c"
    break;

  case 125:
#line 735 "yacc_sql.y"
                                     {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2595 "yacc_sql.tab.c"
    break;

  case 127:
#line 741 "yacc_sql.y"
                                   {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2603 "yacc_sql.tab.c"
    break;

  case 128:
#line 747 "yacc_sql.y"
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
#line 2628 "yacc_sql.tab.c"
    break;

  case 129:
#line 768 "yacc_sql.y"
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
#line 2652 "yacc_sql.tab.c"
    break;

  case 130:
#line 788 "yacc_sql.y"
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
#line 2676 "yacc_sql.tab.c"
    break;

  case 131:
#line 808 "yacc_sql.y"
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
#line 2702 "yacc_sql.tab.c"
    break;

  case 132:
#line 830 "yacc_sql.y"
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
#line 2727 "yacc_sql.tab.c"
    break;

  case 133:
#line 851 "yacc_sql.y"
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
#line 2752 "yacc_sql.tab.c"
    break;

  case 134:
#line 872 "yacc_sql.y"
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
#line 2775 "yacc_sql.tab.c"
    break;

  case 136:
#line 894 "yacc_sql.y"
                                             {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2783 "yacc_sql.tab.c"
    break;

  case 138:
#line 900 "yacc_sql.y"
                                           {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2791 "yacc_sql.tab.c"
    break;

  case 139:
#line 906 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

			Value *right_value = &GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, GET_SUB_CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			GET_SUB_CONTEXT->conditions[GET_SUB_CONTEXT->condition_length++] = condition;
		}
#line 2806 "yacc_sql.tab.c"
    break;

  case 140:
#line 917 "yacc_sql.y"
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
#line 2830 "yacc_sql.tab.c"
    break;

  case 141:
#line 937 "yacc_sql.y"
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
#line 2854 "yacc_sql.tab.c"
    break;

  case 142:
#line 957 "yacc_sql.y"
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
#line 2880 "yacc_sql.tab.c"
    break;

  case 143:
#line 979 "yacc_sql.y"
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
#line 2905 "yacc_sql.tab.c"
    break;

  case 144:
#line 1000 "yacc_sql.y"
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
#line 2930 "yacc_sql.tab.c"
    break;

  case 145:
#line 1021 "yacc_sql.y"
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
#line 2953 "yacc_sql.tab.c"
    break;

  case 146:
#line 1042 "yacc_sql.y"
          {	
  		value_init_integer(&GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 2961 "yacc_sql.tab.c"
    break;

  case 147:
#line 1045 "yacc_sql.y"
          {
  		value_init_float(&GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 2969 "yacc_sql.tab.c"
    break;

  case 148:
#line 1048 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 2978 "yacc_sql.tab.c"
    break;

  case 149:
#line 1052 "yacc_sql.y"
                {
		value_init_null(&GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length++]);
	}
#line 2986 "yacc_sql.tab.c"
    break;

  case 150:
#line 1058 "yacc_sql.y"
             { GET_SUB_CONTEXT->comp = EQUAL_TO; }
#line 2992 "yacc_sql.tab.c"
    break;

  case 151:
#line 1059 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = LESS_THAN; }
#line 2998 "yacc_sql.tab.c"
    break;

  case 152:
#line 1060 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = GREAT_THAN; }
#line 3004 "yacc_sql.tab.c"
    break;

  case 153:
#line 1061 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = LESS_EQUAL; }
#line 3010 "yacc_sql.tab.c"
    break;

  case 154:
#line 1062 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = GREAT_EQUAL; }
#line 3016 "yacc_sql.tab.c"
    break;

  case 155:
#line 1063 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = NOT_EQUAL; }
#line 3022 "yacc_sql.tab.c"
    break;

  case 156:
#line 1064 "yacc_sql.y"
           { GET_SUB_CONTEXT->comp = OP_LIKE; }
#line 3028 "yacc_sql.tab.c"
    break;

  case 157:
#line 1065 "yacc_sql.y"
               { GET_SUB_CONTEXT->comp = OP_NOT_LIKE; }
#line 3034 "yacc_sql.tab.c"
    break;

  case 158:
#line 1066 "yacc_sql.y"
                   { CONTEXT->comp = EQUAL_IS; }
#line 3040 "yacc_sql.tab.c"
    break;

  case 159:
#line 1067 "yacc_sql.y"
                   { CONTEXT->comp = NOT_EQUAL_IS; }
#line 3046 "yacc_sql.tab.c"
    break;

  case 160:
#line 1071 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 3052 "yacc_sql.tab.c"
    break;

  case 161:
#line 1072 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 3058 "yacc_sql.tab.c"
    break;

  case 162:
#line 1073 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 3064 "yacc_sql.tab.c"
    break;

  case 163:
#line 1074 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 3070 "yacc_sql.tab.c"
    break;

  case 164:
#line 1075 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 3076 "yacc_sql.tab.c"
    break;

  case 165:
#line 1076 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 3082 "yacc_sql.tab.c"
    break;

  case 166:
#line 1077 "yacc_sql.y"
                   { CONTEXT->comp = OP_LIKE; }
#line 3088 "yacc_sql.tab.c"
    break;

  case 167:
#line 1078 "yacc_sql.y"
               { CONTEXT->comp = OP_NOT_LIKE; }
#line 3094 "yacc_sql.tab.c"
    break;

  case 168:
#line 1079 "yacc_sql.y"
                   { CONTEXT->comp = EQUAL_IS; }
#line 3100 "yacc_sql.tab.c"
    break;

  case 169:
#line 1080 "yacc_sql.y"
                   { CONTEXT->comp = NOT_EQUAL_IS; }
#line 3106 "yacc_sql.tab.c"
    break;

  case 170:
#line 1085 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 3115 "yacc_sql.tab.c"
    break;

  case 173:
#line 1096 "yacc_sql.y"
           {
		OrderBy order;
               	order_init(&order, NULL, (yyvsp[0].string), ORDER_ASC);
               	selects_append_order(&CONTEXT->ssql->sstr.selection, &order);
	}
#line 3125 "yacc_sql.tab.c"
    break;

  case 174:
#line 1101 "yacc_sql.y"
                 {
		OrderBy order;
                order_init(&order, NULL, (yyvsp[-1].string), ORDER_ASC);
                selects_append_order(&CONTEXT->ssql->sstr.selection, &order);
	}
#line 3135 "yacc_sql.tab.c"
    break;

  case 175:
#line 1106 "yacc_sql.y"
                  {
		OrderBy order;
                order_init(&order, NULL, (yyvsp[-1].string), ORDER_DESC);
                selects_append_order(&CONTEXT->ssql->sstr.selection, &order);
	}
#line 3145 "yacc_sql.tab.c"
    break;

  case 176:
#line 1111 "yacc_sql.y"
                    {
		OrderBy order;
                order_init(&order, (yyvsp[-2].string), (yyvsp[0].string), ORDER_ASC);
                selects_append_order(&CONTEXT->ssql->sstr.selection, &order);
	}
#line 3155 "yacc_sql.tab.c"
    break;

  case 177:
#line 1116 "yacc_sql.y"
                        {
		OrderBy order;
                order_init(&order, (yyvsp[-3].string), (yyvsp[-1].string), ORDER_ASC);
                selects_append_order(&CONTEXT->ssql->sstr.selection, &order);
	}
#line 3165 "yacc_sql.tab.c"
    break;

  case 178:
#line 1121 "yacc_sql.y"
                         {
		OrderBy order;
                order_init(&order, (yyvsp[-3].string), (yyvsp[-1].string), ORDER_DESC);
                selects_append_order(&CONTEXT->ssql->sstr.selection, &order);
	}
#line 3175 "yacc_sql.tab.c"
    break;


#line 3179 "yacc_sql.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (scanner, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (scanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1132 "yacc_sql.y"

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
