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
    TEXT_T = 282,
    HELP = 283,
    EXIT = 284,
    DOT = 285,
    INTO = 286,
    VALUES = 287,
    FROM = 288,
    WHERE = 289,
    AND = 290,
    SET = 291,
    INNER = 292,
    JOIN = 293,
    ON = 294,
    NOT = 295,
    NULL__ = 296,
    NULLABLE = 297,
    LOAD = 298,
    DATA = 299,
    INFILE = 300,
    EQ = 301,
    LT = 302,
    GT = 303,
    LE = 304,
    GE = 305,
    NE = 306,
    IS = 307,
    LIKE = 308,
    MAX = 309,
    MIN = 310,
    SUM = 311,
    COUNT = 312,
    AVG = 313,
    ORDER = 314,
    GROUP = 315,
    BY = 316,
    ASC = 317,
    HAVING = 318,
    NUMBER = 319,
    FLOAT = 320,
    ID = 321,
    PATH = 322,
    SSS = 323,
    STAR = 324,
    STRING_V = 325
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 133 "yacc_sql.y"

  struct _Attr *attr;
  struct _Condition *condition1;
  struct _Value *value1;
  char *string;
  int number;
  float floats;
	char *position;

#line 267 "yacc_sql.tab.c"

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
#define YYLAST   535

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  534

#define YYUNDEFTOK  2
#define YYMAXUTOK   325


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
      65,    66,    67,    68,    69,    70
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   159,   159,   161,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   186,   191,   196,   202,   208,   214,   220,   226,
     231,   238,   245,   251,   260,   262,   268,   275,   284,   286,
     290,   301,   318,   321,   322,   323,   324,   325,   328,   331,
     334,   339,   348,   365,   367,   374,   377,   382,   387,   390,
     394,   398,   401,   404,   408,   414,   420,   430,   438,   445,
     447,   455,   469,   474,   479,   484,   489,   492,   494,   501,
     506,   513,   517,   522,   527,   532,   537,   542,   547,   554,
     559,   564,   569,   576,   578,   583,   599,   613,   618,   623,
     628,   634,   639,   644,   649,   654,   659,   664,   671,   676,
     681,   686,   693,   695,   702,   707,   715,   720,   725,   730,
     735,   740,   745,   752,   757,   762,   767,   834,   836,   840,
     842,   845,   849,   851,   855,   857,   861,   863,   868,   889,
     909,   929,   951,   972,   993,  1014,  1016,  1020,  1022,  1027,
    1038,  1058,  1078,  1100,  1121,  1142,  1164,  1167,  1170,  1174,
    1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,
    1193,  1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,
    1206,  1213,  1214,  1218,  1223,  1228,  1233,  1238,  1243,  1250,
    1251,  1254,  1255,  1259,  1264,  1271,  1272,  1275,  1276,  1280,
    1289,  1298,  1307,  1316,  1325,  1334,  1343,  1352,  1363,  1372,
    1381,  1392,  1393
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
  "TEXT_T", "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM", "WHERE",
  "AND", "SET", "INNER", "JOIN", "ON", "NOT", "NULL__", "NULLABLE", "LOAD",
  "DATA", "INFILE", "EQ", "LT", "GT", "LE", "GE", "NE", "IS", "LIKE",
  "MAX", "MIN", "SUM", "COUNT", "AVG", "ORDER", "GROUP", "BY", "ASC",
  "HAVING", "NUMBER", "FLOAT", "ID", "PATH", "SSS", "STAR", "STRING_V",
  "$accept", "commands", "command", "exit", "help", "sync", "begin",
  "commit", "rollback", "drop_table", "show_tables", "show_indexes",
  "desc_table", "create_index", "index_attr_list", "drop_index",
  "create_table", "attr_def_list", "attr_def", "number", "type", "is_null",
  "ID_get", "insert", "value_tuple", "value_list", "insert_vaule", "value",
  "delete", "update", "update_list", "set_list", "sub_select",
  "sub_select_attr", "sub_attr_list", "sub_agg_func", "sub_rel_list",
  "select", "select_attr", "attr_list", "rel_list", "inner", "on", "where",
  "condition_list", "condition", "sub_where", "sub_condition_list",
  "sub_condition", "sub_value", "sub_comOp", "comOp", "load_data",
  "order_by", "order_attr", "order_attr_list", "group_by", "group_attr",
  "group_attr_list", "having", "having_condition", "having_condition_list", YY_NULLPTR
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325
};
# endif

#define YYPACT_NINF (-469)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -469,   189,  -469,   206,    18,   -25,   -21,   275,    17,    33,
      41,    39,    80,   112,   121,   132,   159,   154,  -469,  -469,
    -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,
    -469,  -469,  -469,  -469,  -469,  -469,  -469,    73,   147,   142,
     182,   226,   196,   276,   284,   285,   290,    59,   293,   282,
     313,   314,   286,  -469,   252,   254,   287,  -469,  -469,  -469,
    -469,  -469,   277,   304,   258,   288,   322,   323,   262,   263,
     264,    95,   268,   116,   239,  -469,  -469,   270,  -469,  -469,
     273,   300,   309,   279,   309,   289,   281,   311,   292,  -469,
    -469,    -5,    -2,     4,   335,   336,   337,     5,   339,   342,
     343,   344,   345,    89,   293,   293,   346,   360,   347,     2,
     363,   326,   370,   348,  -469,   355,   236,   310,   358,   293,
     312,   293,   315,   293,   316,   293,   293,   293,   293,   317,
     318,   319,   320,   217,   321,   240,  -469,  -469,  -469,   324,
     266,  -469,   -26,   367,  -469,  -469,  -469,   176,  -469,   204,
     353,  -469,    46,  -469,   374,   281,   371,  -469,  -469,  -469,
    -469,  -469,   105,   376,   325,  -469,   377,  -469,   379,  -469,
     380,  -469,  -469,  -469,  -469,   382,    79,    88,    98,   383,
     385,   386,   103,   293,   293,   346,   368,   341,   309,   349,
    -469,  -469,  -469,  -469,   390,    94,   387,   350,   357,  -469,
    -469,  -469,  -469,  -469,  -469,   372,  -469,    20,    30,     2,
    -469,   392,   351,   355,   410,   354,   373,  -469,  -469,   356,
     396,   293,   293,   293,   293,   293,   359,   293,   361,   293,
     362,   293,   293,   293,   293,   364,  -469,  -469,  -469,   365,
     346,   349,   375,   366,   -26,   401,   403,   404,   406,   407,
     412,   215,   413,   400,   413,  -469,   204,  -469,  -469,  -469,
    -469,   405,  -469,   353,   378,  -469,   431,  -469,  -469,  -469,
     419,  -469,   396,   381,   420,  -469,  -469,  -469,  -469,  -469,
     421,  -469,   422,  -469,   423,  -469,  -469,  -469,  -469,   424,
     346,   409,   366,   384,   388,   389,   390,   426,   391,   393,
     394,   221,   395,   222,   244,  -469,  -469,   397,  -469,    35,
     398,  -469,   408,  -469,   207,   425,   396,   443,   293,   293,
     293,   293,   409,     2,   153,   389,    10,   432,   399,   241,
     450,  -469,   438,   453,   128,   135,   136,   440,   444,   448,
     137,   216,   413,   413,   413,   449,   437,  -469,  -469,    46,
    -469,   466,  -469,  -469,  -469,  -469,  -469,  -469,   153,   353,
    -469,   467,  -469,   411,  -469,   384,  -469,   441,   454,   455,
     457,   458,   459,   461,   445,  -469,   -26,  -469,  -469,   415,
    -469,   416,  -469,   417,  -469,  -469,  -469,  -469,   418,   245,
    -469,  -469,  -469,  -469,   427,   451,   428,   392,  -469,  -469,
    -469,  -469,     7,   432,   429,   399,  -469,   430,   433,   434,
     225,   435,   241,  -469,   390,   468,   469,   470,   471,   413,
     413,   449,   -15,  -469,  -469,  -469,  -469,  -469,  -469,  -469,
     454,   162,   166,   177,   472,   201,   473,   203,   445,   474,
    -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,
     190,  -469,   462,   218,  -469,   204,   436,   204,   439,   204,
     442,   204,   204,   446,   204,   204,   447,  -469,   426,   452,
     456,  -469,  -469,  -469,  -469,  -469,  -469,   463,  -469,    61,
     -15,  -469,    66,    46,   480,    46,   486,    46,   488,    46,
      46,   489,    46,    46,   492,  -469,   218,  -469,  -469,  -469,
    -469,   462,   481,  -469,  -469,   204,  -469,   204,  -469,   204,
    -469,  -469,   204,  -469,  -469,   204,    76,  -469,   460,    46,
      46,    46,    46,    46,   484,  -469,  -469,  -469,  -469,  -469,
    -469,  -469,   464,  -469
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
       0,     0,     0,     0,     0,     0,     0,   112,   112,     0,
       0,     0,     0,    24,     0,     0,     0,    25,    26,    27,
      23,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,    97,     0,    31,    29,
       0,     0,   134,     0,   134,     0,     0,     0,     0,    28,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   112,   112,   112,   127,     0,     0,     0,
       0,     0,     0,     0,    51,    38,     0,     0,     0,   112,
       0,   112,     0,   112,     0,   112,   112,   112,   112,     0,
       0,     0,     0,     0,     0,     0,   113,    99,   100,     0,
     129,    30,     0,     0,    65,    61,    62,     0,    63,     0,
     136,    66,     0,    67,     0,     0,     0,    43,    44,    45,
      46,    47,    48,     0,     0,   101,     0,   103,     0,   105,
       0,   107,   109,   108,   110,     0,     0,     0,     0,     0,
       0,     0,     0,   112,   112,   127,     0,     0,   134,   181,
      60,    57,    58,    59,    55,     0,     0,     0,     0,   170,
     171,   172,   173,   174,   175,   178,   176,     0,     0,     0,
     135,    69,     0,    38,     0,     0,     0,    50,    41,     0,
      34,   112,   112,   112,   112,   112,     0,   112,     0,   112,
       0,   112,   112,   112,   112,     0,   115,   114,   128,     0,
     127,   181,     0,   191,     0,     0,     0,     0,     0,     0,
       0,    77,    77,     0,    77,    64,     0,   177,   179,   140,
     138,   141,   139,   136,     0,    68,     0,    39,    37,    42,
       0,    49,    34,     0,     0,   102,   104,   106,   111,   116,
       0,   118,     0,   120,     0,   122,   124,   123,   125,     0,
     127,   132,   191,     0,     0,   197,    55,    53,     0,     0,
       0,     0,     0,     0,     0,    73,    72,     0,    76,     0,
       0,   137,     0,   180,    48,     0,    34,     0,   112,   112,
     112,   112,   132,     0,   129,   197,   183,   189,     0,     0,
       0,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,    77,    77,    77,    93,     0,   142,   143,     0,
      40,     0,    35,    32,   117,   119,   121,   126,   129,   136,
     131,     0,   185,     0,   184,     0,   182,   193,   195,     0,
       0,     0,     0,     0,   211,    95,     0,    52,    82,     0,
      84,     0,    86,     0,    88,    90,    89,    91,     0,     0,
      78,    81,    74,    75,     0,   145,     0,    69,    33,   130,
     133,    96,   186,   189,     0,     0,   192,     0,     0,     0,
       0,     0,     0,   198,    55,     0,     0,     0,     0,    77,
      77,    93,     0,    71,   144,    70,   188,   187,   190,   194,
     195,     0,     0,     0,     0,     0,     0,     0,   211,     0,
      83,    85,    87,    92,    80,    79,    94,   159,   156,   157,
       0,   158,   147,     0,   196,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   212,    53,     0,
       0,   160,   161,   162,   163,   164,   165,   168,   166,     0,
       0,   146,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,     0,   167,   169,   151,
     149,   147,   152,   150,   199,     0,   201,     0,   203,     0,
     207,   205,     0,   208,   209,     0,     0,   148,     0,     0,
       0,     0,     0,     0,     0,   153,   154,   200,   202,   204,
     206,   210,     0,   155
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,
    -469,  -469,  -469,  -469,  -262,  -469,  -469,   302,   369,  -469,
    -469,   165,  -469,  -469,    48,  -291,  -240,  -152,  -469,  -469,
    -469,   120,  -469,  -469,  -251,   219,    99,  -469,  -469,   -46,
    -178,  -312,   197,   -75,  -255,  -203,  -469,    22,    45,  -468,
    -436,  -113,  -469,   280,   163,   124,   237,   126,   102,   208,
     122,    97
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,   274,    30,    31,   156,   115,   270,
     162,   218,   116,    32,   333,   245,   194,   149,    33,    34,
      84,   265,   196,   253,   305,   254,   395,    35,    49,    75,
     140,   188,   324,   110,   210,   150,   423,   481,   452,   453,
     479,   207,    36,   243,   327,   366,   295,   368,   406,   330,
     374,   413
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     211,   306,    76,   308,   296,   331,   263,   238,   311,   112,
     315,   500,   360,   119,   503,   190,   121,   482,   426,   143,
      53,   362,   123,   128,    40,   120,   447,    41,   122,    42,
      43,    44,    45,    46,   124,   129,   208,   143,   191,   192,
     363,    47,   193,   144,    48,    50,   399,   143,   525,   448,
     449,   450,   143,   451,   352,   260,   262,   136,   137,   138,
     516,   144,   291,   143,    54,   189,   145,   146,   147,   427,
     148,   144,   364,   165,    55,   167,   144,   169,    73,   171,
     172,   173,   174,    57,   145,   146,   259,   144,   148,    74,
     390,   391,   392,   393,   145,   146,   261,   225,   148,   145,
     146,   346,   447,   148,   400,    56,   227,   447,    73,   226,
     145,   146,   322,   241,   148,    58,   229,   447,   228,   135,
     359,   234,   215,   439,    59,   448,   449,   499,   230,   451,
     448,   449,   502,   235,   451,    60,   414,   236,   237,    63,
     448,   449,   524,   309,   451,   216,   378,   217,   246,   247,
     248,   249,   250,   380,   382,   387,    64,   347,   379,    94,
     251,    95,    61,   252,    96,   381,   383,   388,   444,   445,
      98,    99,   100,   101,   102,   275,   276,   277,   278,   279,
     455,   281,   103,   283,   457,   285,   286,   287,   288,     2,
     186,   187,   456,     3,     4,   459,   458,   397,    62,     5,
       6,     7,     8,     9,    10,    11,   197,   460,    65,    12,
      13,    14,    37,    68,    38,    39,   198,    15,    16,   462,
     469,   465,   199,   200,   201,   202,   203,   204,   205,   206,
     470,   463,    17,   466,   303,   303,   471,   472,   473,   474,
     475,   476,   477,   478,   198,   304,   389,   216,    66,   217,
     199,   200,   201,   202,   203,   204,   205,   206,   470,   157,
     158,   159,   160,   161,   471,   472,   473,   474,   475,   476,
     477,   478,   354,   355,   356,   357,   246,   247,   248,   249,
     250,   179,    51,   180,    52,   337,   181,   338,   341,   434,
     339,   435,    67,    69,   436,   369,   370,   371,   372,   373,
     109,    70,    71,   186,   187,   104,   183,    72,   105,   184,
     343,   419,    73,   344,   420,    77,    78,    79,    81,    80,
      82,    86,    85,    83,    87,    89,    90,    88,    91,    92,
      93,   504,   108,   506,    97,   508,   106,   510,   511,   107,
     513,   514,   483,   109,   485,   111,   487,   114,   489,   490,
     117,   492,   493,   125,   126,   127,   130,   113,   118,   131,
     132,   133,   134,   141,   142,   139,   151,   527,   528,   529,
     530,   531,   152,   153,   155,   164,   163,   195,   166,   154,
     212,   168,   170,   175,   176,   177,   178,   182,   209,   214,
     185,   220,   519,   219,   520,   221,   521,   222,   223,   522,
     224,   231,   523,   232,   233,   255,   239,   240,   242,   244,
     257,   264,   258,   268,   271,   273,   256,   266,   269,   297,
     298,   299,   272,   300,   301,   280,   294,   282,   284,   302,
     289,   290,   303,   307,   313,   310,   293,   314,   317,   318,
     319,   320,   321,   351,   312,   332,   353,   316,   323,   328,
     326,   365,   329,   375,   349,   376,   377,   334,   384,   335,
     336,   340,   385,   345,   348,   367,   386,   396,   394,   398,
     401,   404,   407,   405,   408,   409,   410,   402,   411,   350,
     412,   415,   416,   417,   418,   422,   440,   441,   442,   443,
     461,   464,   468,   421,   424,   429,   431,   480,   505,   432,
     433,   437,   484,   498,   507,   486,   509,   512,   488,   497,
     515,   518,   491,   494,   532,   267,   495,   425,   496,   358,
     446,   292,   342,   517,   213,   501,   526,   428,   403,   325,
     533,   430,   454,   361,   438,   467
};

static const yytype_int16 yycheck[] =
{
     152,   252,    48,   254,   244,   296,   209,   185,   263,    84,
     272,   479,   324,    18,   482,    41,    18,   453,    11,    17,
       3,    11,    18,    18,     6,    30,    41,     9,    30,    54,
      55,    56,    57,    58,    30,    30,   149,    17,    64,    65,
      30,    66,    68,    41,    69,    66,   358,    17,   516,    64,
      65,    66,    17,    68,   316,   207,   208,   103,   104,   105,
     496,    41,   240,    17,    31,   140,    64,    65,    66,    62,
      68,    41,    62,   119,    33,   121,    41,   123,    19,   125,
     126,   127,   128,     3,    64,    65,    66,    41,    68,    30,
     341,   342,   343,   344,    64,    65,    66,    18,    68,    64,
      65,    66,    41,    68,   359,    66,    18,    41,    19,    30,
      64,    65,   290,   188,    68,     3,    18,    41,    30,    30,
     323,    18,    17,   414,     3,    64,    65,    66,    30,    68,
      64,    65,    66,    30,    68,     3,   376,   183,   184,    66,
      64,    65,    66,   256,    68,    40,    18,    42,    54,    55,
      56,    57,    58,    18,    18,    18,     9,   309,    30,    64,
      66,    66,     3,    69,    69,    30,    30,    30,   419,   420,
      54,    55,    56,    57,    58,   221,   222,   223,   224,   225,
      18,   227,    66,   229,    18,   231,   232,   233,   234,     0,
      37,    38,    30,     4,     5,    18,    30,   349,    44,    10,
      11,    12,    13,    14,    15,    16,    30,    30,    66,    20,
      21,    22,     6,    17,     8,     9,    40,    28,    29,    18,
      30,    18,    46,    47,    48,    49,    50,    51,    52,    53,
      40,    30,    43,    30,    19,    19,    46,    47,    48,    49,
      50,    51,    52,    53,    40,    30,    30,    40,    66,    42,
      46,    47,    48,    49,    50,    51,    52,    53,    40,    23,
      24,    25,    26,    27,    46,    47,    48,    49,    50,    51,
      52,    53,   318,   319,   320,   321,    54,    55,    56,    57,
      58,    64,     7,    66,     9,    64,    69,    66,    66,    64,
      69,    66,    66,    17,    69,    54,    55,    56,    57,    58,
      34,    17,    17,    37,    38,    66,    66,    17,    69,    69,
      66,    66,    19,    69,    69,    33,     3,     3,    66,    33,
      66,    17,    45,    36,    66,     3,     3,    39,    66,    66,
      66,   483,    32,   485,    66,   487,    66,   489,   490,    66,
     492,   493,   455,    34,   457,    66,   459,    66,   461,   462,
      39,   464,   465,    18,    18,    18,    17,    68,    66,    17,
      17,    17,    17,     3,    17,    19,     3,   519,   520,   521,
     522,   523,    46,     3,    19,    17,    66,    10,    66,    31,
       6,    66,    66,    66,    66,    66,    66,    66,    35,    18,
      66,    66,   505,    17,   507,    18,   509,    18,    18,   512,
      18,    18,   515,    18,    18,    18,    38,    66,    59,    19,
      53,    19,    40,     3,    41,    19,    66,    66,    64,    18,
      17,    17,    66,    17,    17,    66,    60,    66,    66,    17,
      66,    66,    19,    33,     3,    30,    61,    18,    18,    18,
      18,    18,    18,    18,    66,    19,     3,    66,    39,    61,
      66,    19,    63,     3,    46,    17,     3,    66,    18,    66,
      66,    66,    18,    66,    66,    66,    18,    30,    19,     3,
       3,    30,    17,    19,    17,    17,    17,    66,    17,   314,
      35,    66,    66,    66,    66,    34,    18,    18,    18,    18,
      18,    18,    18,    66,    66,    66,    66,    35,    18,    66,
      66,    66,    66,    40,    18,    66,    18,    18,    66,    53,
      18,    30,    66,    66,    30,   213,   468,   397,    66,   322,
     421,   241,   303,   501,   155,   480,    66,   403,   365,   292,
      66,   405,   430,   325,   412,   438
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    72,     0,     4,     5,    10,    11,    12,    13,    14,
      15,    16,    20,    21,    22,    28,    29,    43,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      86,    87,    94,    99,   100,   108,   123,     6,     8,     9,
       6,     9,    54,    55,    56,    57,    58,    66,    69,   109,
      66,     7,     9,     3,    31,    33,    66,     3,     3,     3,
       3,     3,    44,    66,     9,    66,    66,    66,    17,    17,
      17,    17,    17,    19,    30,   110,   110,    33,     3,     3,
      33,    66,    66,    36,   101,    45,    17,    66,    39,     3,
       3,    66,    66,    66,    64,    66,    69,    66,    54,    55,
      56,    57,    58,    66,    66,    69,    66,    66,    32,    34,
     114,    66,   114,    68,    66,    89,    93,    39,    66,    18,
      30,    18,    30,    18,    30,    18,    18,    18,    18,    30,
      17,    17,    17,    17,    17,    30,   110,   110,   110,    19,
     111,     3,    17,    17,    41,    64,    65,    66,    68,    98,
     116,     3,    46,     3,    31,    19,    88,    23,    24,    25,
      26,    27,    91,    66,    17,   110,    66,   110,    66,   110,
      66,   110,   110,   110,   110,    66,    66,    66,    66,    64,
      66,    69,    66,    66,    69,    66,    37,    38,   112,   114,
      41,    64,    65,    68,    97,    10,   103,    30,    40,    46,
      47,    48,    49,    50,    51,    52,    53,   122,   122,    35,
     115,    98,     6,    89,    18,    17,    40,    42,    92,    17,
      66,    18,    18,    18,    18,    18,    30,    18,    30,    18,
      30,    18,    18,    18,    18,    30,   110,   110,   111,    38,
      66,   114,    59,   124,    19,    96,    54,    55,    56,    57,
      58,    66,    69,   104,   106,    18,    66,    53,    40,    66,
      98,    66,    98,   116,    19,   102,    66,    88,     3,    64,
      90,    41,    66,    19,    85,   110,   110,   110,   110,   110,
      66,   110,    66,   110,    66,   110,   110,   110,   110,    66,
      66,   111,   124,    61,    60,   127,    97,    18,    17,    17,
      17,    17,    17,    19,    30,   105,   105,    33,   105,   122,
      30,   115,    66,     3,    18,    85,    66,    18,    18,    18,
      18,    18,   111,    39,   113,   127,    66,   125,    61,    63,
     130,    96,    19,    95,    66,    66,    66,    64,    66,    69,
      66,    66,   106,    66,    69,    66,    66,    98,    66,    46,
      92,    18,    85,     3,   110,   110,   110,   110,   113,   116,
     112,   130,    11,    30,    62,    19,   126,    66,   128,    54,
      55,    56,    57,    58,   131,     3,    17,     3,    18,    30,
      18,    30,    18,    30,    18,    18,    18,    18,    30,    30,
     105,   105,   105,   105,    19,   107,    30,    98,     3,   112,
     115,     3,    66,   125,    30,    19,   129,    17,    17,    17,
      17,    17,    35,   132,    97,    66,    66,    66,    66,    66,
      69,    66,    34,   117,    66,   102,    11,    62,   126,    66,
     128,    66,    66,    66,    64,    66,    69,    66,   131,    96,
      18,    18,    18,    18,   105,   105,   107,    41,    64,    65,
      66,    68,   119,   120,   129,    18,    30,    18,    30,    18,
      30,    18,    18,    30,    18,    18,    30,   132,    18,    30,
      40,    46,    47,    48,    49,    50,    51,    52,    53,   121,
      35,   118,   121,   122,    66,   122,    66,   122,    66,   122,
     122,    66,   122,   122,    66,    95,    66,    53,    40,    66,
     120,   119,    66,   120,    98,    18,    98,    18,    98,    18,
      98,    98,    18,    98,    98,    18,   121,   118,    30,   122,
     122,   122,   122,   122,    66,   120,    66,    98,    98,    98,
      98,    98,    30,    66
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    72,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    84,    85,    85,    86,    87,    88,    88,
      89,    89,    90,    91,    91,    91,    91,    91,    92,    92,
      92,    93,    94,    95,    95,    96,    96,    97,    97,    97,
      97,    98,    98,    98,    98,    98,    99,   100,   101,   102,
     102,   103,   104,   104,   104,   104,   104,   105,   105,   105,
     105,   105,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   107,   107,   108,   108,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   111,   111,   112,
     112,   112,   113,   113,   114,   114,   115,   115,   116,   116,
     116,   116,   116,   116,   116,   117,   117,   118,   118,   119,
     119,   119,   119,   119,   119,   119,   120,   120,   120,   120,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     123,   124,   124,   125,   125,   125,   125,   125,   125,   126,
     126,   127,   127,   128,   128,   129,   129,   130,   130,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   132,   132
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     4,     3,
       5,     3,    10,    11,     0,     3,     4,     8,     0,     3,
       6,     3,     1,     1,     1,     1,     1,     1,     0,     2,
       1,     1,    10,     0,     6,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     5,     5,     5,     0,
       5,     6,     2,     2,     4,     4,     2,     0,     3,     5,
       5,     3,     4,     6,     4,     6,     4,     6,     4,     4,
       4,     4,     6,     0,     3,    10,    11,     2,     2,     4,
       4,     5,     7,     5,     7,     5,     7,     5,     5,     5,
       5,     7,     0,     3,     5,     5,     6,     8,     6,     8,
       6,     8,     6,     6,     6,     6,     8,     0,     3,     0,
       6,     5,     0,     3,     0,     3,     0,     3,     3,     3,
       3,     3,     5,     5,     7,     0,     3,     0,     3,     3,
       3,     3,     3,     5,     5,     7,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       8,     0,     4,     1,     2,     2,     3,     4,     4,     0,
       3,     0,     4,     1,     3,     0,     3,     0,     3,     6,
       8,     6,     8,     6,     8,     6,     8,     6,     6,     6,
       8,     0,     3
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
#line 186 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1809 "yacc_sql.tab.c"
    break;

  case 23:
#line 191 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1817 "yacc_sql.tab.c"
    break;

  case 24:
#line 196 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1825 "yacc_sql.tab.c"
    break;

  case 25:
#line 202 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1833 "yacc_sql.tab.c"
    break;

  case 26:
#line 208 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1841 "yacc_sql.tab.c"
    break;

  case 27:
#line 214 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1849 "yacc_sql.tab.c"
    break;

  case 28:
#line 220 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1858 "yacc_sql.tab.c"
    break;

  case 29:
#line 226 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1866 "yacc_sql.tab.c"
    break;

  case 30:
#line 231 "yacc_sql.y"
                                     {
	  CONTEXT->ssql->flag = SCF_SHOW_INDEXES;
	  create_show_index(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
	}
#line 1875 "yacc_sql.tab.c"
    break;

  case 31:
#line 238 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1884 "yacc_sql.tab.c"
    break;

  case 32:
#line 246 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[-3].string));
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), DEFAULT_INDEX);
		}
#line 1894 "yacc_sql.tab.c"
    break;

  case 33:
#line 252 "yacc_sql.y"
        {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
            create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[-3].string));
            create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), UNIQUE_INDEX);
        }
#line 1904 "yacc_sql.tab.c"
    break;

  case 35:
#line 262 "yacc_sql.y"
                               {
            create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[-1].string));
        }
#line 1912 "yacc_sql.tab.c"
    break;

  case 36:
#line 269 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1921 "yacc_sql.tab.c"
    break;

  case 37:
#line 276 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1933 "yacc_sql.tab.c"
    break;

  case 39:
#line 286 "yacc_sql.y"
                                   {    }
#line 1939 "yacc_sql.tab.c"
    break;

  case 40:
#line 291 "yacc_sql.y"
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
#line 1954 "yacc_sql.tab.c"
    break;

  case 41:
#line 302 "yacc_sql.y"
                {
			AttrInfo attribute;
			if ((yyvsp[-1].number) != TEXTS) {
				attr_info_init(&attribute, CONTEXT->id, (yyvsp[-1].number), 4, CONTEXT->nullable);
			} else {
				attr_info_init(&attribute, CONTEXT->id, (yyvsp[-1].number), 8, CONTEXT->nullable);
			}
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}
#line 1973 "yacc_sql.tab.c"
    break;

  case 42:
#line 318 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1979 "yacc_sql.tab.c"
    break;

  case 43:
#line 321 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1985 "yacc_sql.tab.c"
    break;

  case 44:
#line 322 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1991 "yacc_sql.tab.c"
    break;

  case 45:
#line 323 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1997 "yacc_sql.tab.c"
    break;

  case 46:
#line 324 "yacc_sql.y"
                { (yyval.number)=DATES; }
#line 2003 "yacc_sql.tab.c"
    break;

  case 47:
#line 325 "yacc_sql.y"
                    { (yyval.number)=TEXTS; }
#line 2009 "yacc_sql.tab.c"
    break;

  case 48:
#line 328 "yacc_sql.y"
                   {
		CONTEXT->nullable = 0;
	}
#line 2017 "yacc_sql.tab.c"
    break;

  case 49:
#line 331 "yacc_sql.y"
                    {
		CONTEXT->nullable = 0;
	}
#line 2025 "yacc_sql.tab.c"
    break;

  case 50:
#line 334 "yacc_sql.y"
                   {
		CONTEXT->nullable = 1;
	}
#line 2033 "yacc_sql.tab.c"
    break;

  case 51:
#line 340 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 2042 "yacc_sql.tab.c"
    break;

  case 52:
#line 349 "yacc_sql.y"
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
#line 2062 "yacc_sql.tab.c"
    break;

  case 54:
#line 367 "yacc_sql.y"
                                                                  {

	  }
#line 2070 "yacc_sql.tab.c"
    break;

  case 55:
#line 374 "yacc_sql.y"
        {
		inserts_more_init(&CONTEXT->inserts_more[CONTEXT->insert_length].value_num, &CONTEXT->insert_length);
	}
#line 2078 "yacc_sql.tab.c"
    break;

  case 56:
#line 377 "yacc_sql.y"
                                     { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 2086 "yacc_sql.tab.c"
    break;

  case 57:
#line 382 "yacc_sql.y"
          {	
		// 匹配时insert规则时，保存在CONTEXT->inserts_more->values中
  		value_init_integer(&CONTEXT->inserts_more[CONTEXT->insert_length].values[CONTEXT->inserts_more[CONTEXT->insert_length].value_num++], (yyvsp[0].number));
		// 匹配Conditon规则时，values需要保存在CONTEXT->values中,使用下面的value规则
		}
#line 2096 "yacc_sql.tab.c"
    break;

  case 58:
#line 387 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->inserts_more[CONTEXT->insert_length].values[CONTEXT->inserts_more[CONTEXT->insert_length].value_num++], (yyvsp[0].floats));
		}
#line 2104 "yacc_sql.tab.c"
    break;

  case 59:
#line 390 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->inserts_more[CONTEXT->insert_length].values[CONTEXT->inserts_more[CONTEXT->insert_length].value_num++], (yyvsp[0].string));
		}
#line 2113 "yacc_sql.tab.c"
    break;

  case 60:
#line 394 "yacc_sql.y"
            {
		value_init_null(&CONTEXT->inserts_more[CONTEXT->insert_length].values[CONTEXT->inserts_more[CONTEXT->insert_length].value_num++]);
	}
#line 2121 "yacc_sql.tab.c"
    break;

  case 61:
#line 398 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 2129 "yacc_sql.tab.c"
    break;

  case 62:
#line 401 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 2137 "yacc_sql.tab.c"
    break;

  case 63:
#line 404 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 2146 "yacc_sql.tab.c"
    break;

  case 64:
#line 408 "yacc_sql.y"
                                  {
		value_init_query(&CONTEXT->values[CONTEXT->value_length++], GET_SUB_CONTEXT->ssql);
		// 赋值后将子句清空
		memset(GET_SUB_CONTEXT->ssql, 0, sizeof(*GET_SUB_CONTEXT->ssql));
	}
#line 2156 "yacc_sql.tab.c"
    break;

  case 65:
#line 414 "yacc_sql.y"
                {
		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
	}
#line 2164 "yacc_sql.tab.c"
    break;

  case 66:
#line 421 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 2176 "yacc_sql.tab.c"
    break;

  case 67:
#line 431 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-3].string), CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 2186 "yacc_sql.tab.c"
    break;

  case 68:
#line 438 "yacc_sql.y"
                            {
		SetValue set_value;
		set_value_init(&set_value, (yyvsp[-3].string), &CONTEXT->values[--CONTEXT->value_length]);
		update_append_value_list(&CONTEXT->ssql->sstr.update, &set_value);
	}
#line 2196 "yacc_sql.tab.c"
    break;

  case 70:
#line 447 "yacc_sql.y"
                                    {
		SetValue set_value;
		set_value_init(&set_value, (yyvsp[-3].string), &CONTEXT->values[--CONTEXT->value_length]);
		update_append_value_list(&CONTEXT->ssql->sstr.update, &set_value);
	}
#line 2206 "yacc_sql.tab.c"
    break;

  case 71:
#line 455 "yacc_sql.y"
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
#line 2223 "yacc_sql.tab.c"
    break;

  case 72:
#line 469 "yacc_sql.y"
                      {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2233 "yacc_sql.tab.c"
    break;

  case 73:
#line 474 "yacc_sql.y"
                       {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2243 "yacc_sql.tab.c"
    break;

  case 74:
#line 479 "yacc_sql.y"
                                  {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2253 "yacc_sql.tab.c"
    break;

  case 75:
#line 484 "yacc_sql.y"
                                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2263 "yacc_sql.tab.c"
    break;

  case 76:
#line 489 "yacc_sql.y"
                                    {
	}
#line 2270 "yacc_sql.tab.c"
    break;

  case 78:
#line 494 "yacc_sql.y"
                             {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
#line 2282 "yacc_sql.tab.c"
    break;

  case 79:
#line 501 "yacc_sql.y"
                                          {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2292 "yacc_sql.tab.c"
    break;

  case 80:
#line 506 "yacc_sql.y"
                                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
#line 2304 "yacc_sql.tab.c"
    break;

  case 82:
#line 517 "yacc_sql.y"
                             {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_MAX);
	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2314 "yacc_sql.tab.c"
    break;

  case 83:
#line 522 "yacc_sql.y"
                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_MAX);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2324 "yacc_sql.tab.c"
    break;

  case 84:
#line 527 "yacc_sql.y"
                               {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_MIN);
	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2334 "yacc_sql.tab.c"
    break;

  case 85:
#line 532 "yacc_sql.y"
                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_MIN);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2344 "yacc_sql.tab.c"
    break;

  case 86:
#line 537 "yacc_sql.y"
                               {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_SUM);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2354 "yacc_sql.tab.c"
    break;

  case 87:
#line 542 "yacc_sql.y"
                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_SUM);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2364 "yacc_sql.tab.c"
    break;

  case 88:
#line 547 "yacc_sql.y"
                                     {
       	  RelAttr attr;
       	  char *str = malloc(10 * sizeof(char));
       	  snprintf(str, 10, "%d", (yyvsp[-1].number));
       	  aggregation_attr_init(&attr, NULL, str, AGG_COUNT);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2376 "yacc_sql.tab.c"
    break;

  case 89:
#line 554 "yacc_sql.y"
                                   {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, "*", AGG_COUNT);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2386 "yacc_sql.tab.c"
    break;

  case 90:
#line 559 "yacc_sql.y"
                                 {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_COUNT);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2396 "yacc_sql.tab.c"
    break;

  case 91:
#line 564 "yacc_sql.y"
                               {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_AVG);
	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2406 "yacc_sql.tab.c"
    break;

  case 92:
#line 569 "yacc_sql.y"
                                      {
	  RelAttr attr;
	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_AVG);
	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2416 "yacc_sql.tab.c"
    break;

  case 94:
#line 578 "yacc_sql.y"
                            {	
			selects_append_relation(&GET_SUB_CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 2424 "yacc_sql.tab.c"
    break;

  case 95:
#line 584 "yacc_sql.y"
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
#line 2444 "yacc_sql.tab.c"
    break;

  case 96:
#line 600 "yacc_sql.y"
                {
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-7].string));
			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);

			CONTEXT->ssql->flag=SCF_SELECT;
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
#line 2459 "yacc_sql.tab.c"
    break;

  case 97:
#line 613 "yacc_sql.y"
                  {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2469 "yacc_sql.tab.c"
    break;

  case 98:
#line 618 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2479 "yacc_sql.tab.c"
    break;

  case 99:
#line 623 "yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2489 "yacc_sql.tab.c"
    break;

  case 100:
#line 628 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2499 "yacc_sql.tab.c"
    break;

  case 101:
#line 634 "yacc_sql.y"
                                         {
          RelAttr attr;
          aggregation_attr_init(&attr, NULL, (yyvsp[-2].string), AGG_MAX);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 2509 "yacc_sql.tab.c"
    break;

  case 102:
#line 639 "yacc_sql.y"
                                                {
           RelAttr attr;
           aggregation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), AGG_MAX);
           selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
         }
#line 2519 "yacc_sql.tab.c"
    break;

  case 103:
#line 644 "yacc_sql.y"
                                         {
          RelAttr attr;
          aggregation_attr_init(&attr, NULL, (yyvsp[-2].string), AGG_MIN);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 2529 "yacc_sql.tab.c"
    break;

  case 104:
#line 649 "yacc_sql.y"
                                                {
          RelAttr attr;
          aggregation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), AGG_MIN);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 2539 "yacc_sql.tab.c"
    break;

  case 105:
#line 654 "yacc_sql.y"
                                         {
          RelAttr attr;
          aggregation_attr_init(&attr, NULL, (yyvsp[-2].string), AGG_SUM);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 2549 "yacc_sql.tab.c"
    break;

  case 106:
#line 659 "yacc_sql.y"
                                                {
          RelAttr attr;
          aggregation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), AGG_SUM);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 2559 "yacc_sql.tab.c"
    break;

  case 107:
#line 664 "yacc_sql.y"
                                               {
          RelAttr attr;
          char *str = malloc(10 * sizeof(char));
          snprintf(str, 10, "%d", (yyvsp[-2].number));
          aggregation_attr_init(&attr, NULL, str, AGG_COUNT);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 2571 "yacc_sql.tab.c"
    break;

  case 108:
#line 671 "yacc_sql.y"
                                             {
          RelAttr attr;
          aggregation_attr_init(&attr, NULL, "*", AGG_COUNT);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 2581 "yacc_sql.tab.c"
    break;

  case 109:
#line 676 "yacc_sql.y"
                                           {
          RelAttr attr;
          aggregation_attr_init(&attr, NULL, (yyvsp[-2].string), AGG_COUNT);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 2591 "yacc_sql.tab.c"
    break;

  case 110:
#line 681 "yacc_sql.y"
                                         {
          RelAttr attr;
          aggregation_attr_init(&attr, NULL, (yyvsp[-2].string), AGG_AVG);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 2601 "yacc_sql.tab.c"
    break;

  case 111:
#line 686 "yacc_sql.y"
                                                {
          RelAttr attr;
          aggregation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), AGG_AVG);
          selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 2611 "yacc_sql.tab.c"
    break;

  case 113:
#line 695 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
#line 2623 "yacc_sql.tab.c"
    break;

  case 114:
#line 702 "yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2633 "yacc_sql.tab.c"
    break;

  case 115:
#line 707 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
#line 2645 "yacc_sql.tab.c"
    break;

  case 116:
#line 715 "yacc_sql.y"
                                               {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-2].string), AGG_MAX);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2655 "yacc_sql.tab.c"
    break;

  case 117:
#line 720 "yacc_sql.y"
                                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), AGG_MAX);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2665 "yacc_sql.tab.c"
    break;

  case 118:
#line 725 "yacc_sql.y"
                                               {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-2].string), AGG_MIN);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2675 "yacc_sql.tab.c"
    break;

  case 119:
#line 730 "yacc_sql.y"
                                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), AGG_MIN);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2685 "yacc_sql.tab.c"
    break;

  case 120:
#line 735 "yacc_sql.y"
                                               {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, (yyvsp[-2].string), AGG_SUM);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2695 "yacc_sql.tab.c"
    break;

  case 121:
#line 740 "yacc_sql.y"
                                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), AGG_SUM);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2705 "yacc_sql.tab.c"
    break;

  case 122:
#line 745 "yacc_sql.y"
                                                     {
       	  RelAttr attr;
       	  char *str = malloc(10 * sizeof(char));
       	  snprintf(str, 10, "%d", (yyvsp[-2].number));
       	  aggregation_attr_init(&attr, NULL, str, AGG_COUNT);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2717 "yacc_sql.tab.c"
    break;

  case 123:
#line 752 "yacc_sql.y"
                                                   {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, "*", AGG_COUNT);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2727 "yacc_sql.tab.c"
    break;

  case 124:
#line 757 "yacc_sql.y"
                                                 {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, (yyvsp[-2].string), AGG_COUNT);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2737 "yacc_sql.tab.c"
    break;

  case 125:
#line 762 "yacc_sql.y"
                                               {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-2].string), AGG_AVG);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2747 "yacc_sql.tab.c"
    break;

  case 126:
#line 767 "yacc_sql.y"
                                                      {
	  RelAttr attr;
	  aggregation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), AGG_AVG);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2757 "yacc_sql.tab.c"
    break;

  case 128:
#line 836 "yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 2765 "yacc_sql.tab.c"
    break;

  case 130:
#line 842 "yacc_sql.y"
                                          {
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
		  }
#line 2773 "yacc_sql.tab.c"
    break;

  case 131:
#line 845 "yacc_sql.y"
                                    {
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
		  }
#line 2781 "yacc_sql.tab.c"
    break;

  case 133:
#line 851 "yacc_sql.y"
                                      {

		  }
#line 2789 "yacc_sql.tab.c"
    break;

  case 135:
#line 857 "yacc_sql.y"
                                     {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2797 "yacc_sql.tab.c"
    break;

  case 137:
#line 863 "yacc_sql.y"
                                   {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2805 "yacc_sql.tab.c"
    break;

  case 138:
#line 869 "yacc_sql.y"
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
#line 2830 "yacc_sql.tab.c"
    break;

  case 139:
#line 890 "yacc_sql.y"
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
#line 2854 "yacc_sql.tab.c"
    break;

  case 140:
#line 910 "yacc_sql.y"
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
#line 2878 "yacc_sql.tab.c"
    break;

  case 141:
#line 930 "yacc_sql.y"
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
#line 2904 "yacc_sql.tab.c"
    break;

  case 142:
#line 952 "yacc_sql.y"
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
#line 2929 "yacc_sql.tab.c"
    break;

  case 143:
#line 973 "yacc_sql.y"
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
#line 2954 "yacc_sql.tab.c"
    break;

  case 144:
#line 994 "yacc_sql.y"
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
#line 2977 "yacc_sql.tab.c"
    break;

  case 146:
#line 1016 "yacc_sql.y"
                                             {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2985 "yacc_sql.tab.c"
    break;

  case 148:
#line 1022 "yacc_sql.y"
                                           {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2993 "yacc_sql.tab.c"
    break;

  case 149:
#line 1028 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

			Value *right_value = &GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, GET_SUB_CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			GET_SUB_CONTEXT->conditions[GET_SUB_CONTEXT->condition_length++] = condition;
		}
#line 3008 "yacc_sql.tab.c"
    break;

  case 150:
#line 1039 "yacc_sql.y"
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
#line 3032 "yacc_sql.tab.c"
    break;

  case 151:
#line 1059 "yacc_sql.y"
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
#line 3056 "yacc_sql.tab.c"
    break;

  case 152:
#line 1079 "yacc_sql.y"
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
#line 3082 "yacc_sql.tab.c"
    break;

  case 153:
#line 1101 "yacc_sql.y"
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
#line 3107 "yacc_sql.tab.c"
    break;

  case 154:
#line 1122 "yacc_sql.y"
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
#line 3132 "yacc_sql.tab.c"
    break;

  case 155:
#line 1143 "yacc_sql.y"
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
#line 3155 "yacc_sql.tab.c"
    break;

  case 156:
#line 1164 "yacc_sql.y"
          {	
  		value_init_integer(&GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 3163 "yacc_sql.tab.c"
    break;

  case 157:
#line 1167 "yacc_sql.y"
          {
  		value_init_float(&GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 3171 "yacc_sql.tab.c"
    break;

  case 158:
#line 1170 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 3180 "yacc_sql.tab.c"
    break;

  case 159:
#line 1174 "yacc_sql.y"
                {
		value_init_null(&GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length++]);
	}
#line 3188 "yacc_sql.tab.c"
    break;

  case 160:
#line 1180 "yacc_sql.y"
             { GET_SUB_CONTEXT->comp = EQUAL_TO; }
#line 3194 "yacc_sql.tab.c"
    break;

  case 161:
#line 1181 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = LESS_THAN; }
#line 3200 "yacc_sql.tab.c"
    break;

  case 162:
#line 1182 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = GREAT_THAN; }
#line 3206 "yacc_sql.tab.c"
    break;

  case 163:
#line 1183 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = LESS_EQUAL; }
#line 3212 "yacc_sql.tab.c"
    break;

  case 164:
#line 1184 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = GREAT_EQUAL; }
#line 3218 "yacc_sql.tab.c"
    break;

  case 165:
#line 1185 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = NOT_EQUAL; }
#line 3224 "yacc_sql.tab.c"
    break;

  case 166:
#line 1186 "yacc_sql.y"
           { GET_SUB_CONTEXT->comp = OP_LIKE; }
#line 3230 "yacc_sql.tab.c"
    break;

  case 167:
#line 1187 "yacc_sql.y"
               { GET_SUB_CONTEXT->comp = OP_NOT_LIKE; }
#line 3236 "yacc_sql.tab.c"
    break;

  case 168:
#line 1188 "yacc_sql.y"
                   { CONTEXT->comp = EQUAL_IS; }
#line 3242 "yacc_sql.tab.c"
    break;

  case 169:
#line 1189 "yacc_sql.y"
                   { CONTEXT->comp = NOT_EQUAL_IS; }
#line 3248 "yacc_sql.tab.c"
    break;

  case 170:
#line 1193 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 3254 "yacc_sql.tab.c"
    break;

  case 171:
#line 1194 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 3260 "yacc_sql.tab.c"
    break;

  case 172:
#line 1195 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 3266 "yacc_sql.tab.c"
    break;

  case 173:
#line 1196 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 3272 "yacc_sql.tab.c"
    break;

  case 174:
#line 1197 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 3278 "yacc_sql.tab.c"
    break;

  case 175:
#line 1198 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 3284 "yacc_sql.tab.c"
    break;

  case 176:
#line 1199 "yacc_sql.y"
                   { CONTEXT->comp = OP_LIKE; }
#line 3290 "yacc_sql.tab.c"
    break;

  case 177:
#line 1200 "yacc_sql.y"
               { CONTEXT->comp = OP_NOT_LIKE; }
#line 3296 "yacc_sql.tab.c"
    break;

  case 178:
#line 1201 "yacc_sql.y"
                   { CONTEXT->comp = EQUAL_IS; }
#line 3302 "yacc_sql.tab.c"
    break;

  case 179:
#line 1202 "yacc_sql.y"
                   { CONTEXT->comp = NOT_EQUAL_IS; }
#line 3308 "yacc_sql.tab.c"
    break;

  case 180:
#line 1207 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 3317 "yacc_sql.tab.c"
    break;

  case 183:
#line 1218 "yacc_sql.y"
           {
		OrderBy order;
               	order_init(&order, NULL, (yyvsp[0].string), ORDER_ASC);
               	selects_append_order(&CONTEXT->ssql->sstr.selection, &order);
	}
#line 3327 "yacc_sql.tab.c"
    break;

  case 184:
#line 1223 "yacc_sql.y"
                 {
		OrderBy order;
                order_init(&order, NULL, (yyvsp[-1].string), ORDER_ASC);
                selects_append_order(&CONTEXT->ssql->sstr.selection, &order);
	}
#line 3337 "yacc_sql.tab.c"
    break;

  case 185:
#line 1228 "yacc_sql.y"
                  {
		OrderBy order;
                order_init(&order, NULL, (yyvsp[-1].string), ORDER_DESC);
                selects_append_order(&CONTEXT->ssql->sstr.selection, &order);
	}
#line 3347 "yacc_sql.tab.c"
    break;

  case 186:
#line 1233 "yacc_sql.y"
                    {
		OrderBy order;
                order_init(&order, (yyvsp[-2].string), (yyvsp[0].string), ORDER_ASC);
                selects_append_order(&CONTEXT->ssql->sstr.selection, &order);
	}
#line 3357 "yacc_sql.tab.c"
    break;

  case 187:
#line 1238 "yacc_sql.y"
                        {
		OrderBy order;
                order_init(&order, (yyvsp[-3].string), (yyvsp[-1].string), ORDER_ASC);
                selects_append_order(&CONTEXT->ssql->sstr.selection, &order);
	}
#line 3367 "yacc_sql.tab.c"
    break;

  case 188:
#line 1243 "yacc_sql.y"
                         {
		OrderBy order;
                order_init(&order, (yyvsp[-3].string), (yyvsp[-1].string), ORDER_DESC);
                selects_append_order(&CONTEXT->ssql->sstr.selection, &order);
	}
#line 3377 "yacc_sql.tab.c"
    break;

  case 193:
#line 1259 "yacc_sql.y"
           {
		GroupBy group;
               	group_init(&group, NULL, (yyvsp[0].string));
               	selects_append_group(&CONTEXT->ssql->sstr.selection, &group);
	}
#line 3387 "yacc_sql.tab.c"
    break;

  case 194:
#line 1264 "yacc_sql.y"
                    {
		GroupBy group;
                group_init(&group, (yyvsp[-2].string), (yyvsp[0].string));
                selects_append_group(&CONTEXT->ssql->sstr.selection, &group);
	}
#line 3397 "yacc_sql.tab.c"
    break;

  case 199:
#line 1280 "yacc_sql.y"
                                         {
		RelAttr left_attr;
                aggregation_attr_init(&left_attr, NULL, (yyvsp[-3].string), AGG_MAX);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
	}
#line 3411 "yacc_sql.tab.c"
    break;

  case 200:
#line 1289 "yacc_sql.y"
                                                  {
          	RelAttr left_attr;
                aggregation_attr_init(&left_attr, (yyvsp[-5].string), (yyvsp[-3].string), AGG_MAX);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
#line 3425 "yacc_sql.tab.c"
    break;

  case 201:
#line 1298 "yacc_sql.y"
                                           {
       		RelAttr left_attr;
                aggregation_attr_init(&left_attr, NULL, (yyvsp[-3].string), AGG_MIN);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
       	}
#line 3439 "yacc_sql.tab.c"
    break;

  case 202:
#line 1307 "yacc_sql.y"
                                                  {
                RelAttr left_attr;
                aggregation_attr_init(&left_attr, (yyvsp[-5].string), (yyvsp[-3].string), AGG_MIN);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
#line 3453 "yacc_sql.tab.c"
    break;

  case 203:
#line 1316 "yacc_sql.y"
                                           {
        	RelAttr left_attr;
                aggregation_attr_init(&left_attr, NULL, (yyvsp[-3].string), AGG_SUM);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
#line 3467 "yacc_sql.tab.c"
    break;

  case 204:
#line 1325 "yacc_sql.y"
                                                  {
          	RelAttr left_attr;
                aggregation_attr_init(&left_attr, (yyvsp[-5].string), (yyvsp[-3].string), AGG_SUM);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
#line 3481 "yacc_sql.tab.c"
    break;

  case 205:
#line 1334 "yacc_sql.y"
                                             {
        	RelAttr left_attr;
                aggregation_attr_init(&left_attr, NULL, (yyvsp[-3].string), AGG_COUNT);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
#line 3495 "yacc_sql.tab.c"
    break;

  case 206:
#line 1343 "yacc_sql.y"
                                                    {
          	RelAttr left_attr;
                aggregation_attr_init(&left_attr, (yyvsp[-5].string), (yyvsp[-3].string), AGG_COUNT);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
#line 3509 "yacc_sql.tab.c"
    break;

  case 207:
#line 1352 "yacc_sql.y"
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
#line 3525 "yacc_sql.tab.c"
    break;

  case 208:
#line 1363 "yacc_sql.y"
                                               {
          RelAttr left_attr;
          aggregation_attr_init(&left_attr, NULL, "*", AGG_COUNT);
          Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

          Having having;
          having_init(&having, CONTEXT->comp, &left_attr, right_value);
          selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
#line 3539 "yacc_sql.tab.c"
    break;

  case 209:
#line 1372 "yacc_sql.y"
                                           {
        	RelAttr left_attr;
                aggregation_attr_init(&left_attr, NULL, (yyvsp[-3].string), AGG_AVG);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
#line 3553 "yacc_sql.tab.c"
    break;

  case 210:
#line 1381 "yacc_sql.y"
                                                  {
          	RelAttr left_attr;
                aggregation_attr_init(&left_attr, (yyvsp[-5].string), (yyvsp[-3].string), AGG_AVG);
                Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

                Having having;
                having_init(&having, CONTEXT->comp, &left_attr, right_value);
                selects_append_having(&CONTEXT->ssql->sstr.selection, &having);
        }
#line 3567 "yacc_sql.tab.c"
    break;


#line 3571 "yacc_sql.tab.c"

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
#line 1396 "yacc_sql.y"

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
