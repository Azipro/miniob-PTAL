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
  context->ssql->sstr.insertion.inserts_more_num = 0;
  printf("parse sql failed. error=%s", str);
}

ParserContext *get_context(yyscan_t scanner)
{
  return (ParserContext *)yyget_extra(scanner);
}

#define CONTEXT get_context(scanner)
#define GET_SUB_CONTEXT CONTEXT->sub_context


#line 132 "yacc_sql.tab.c"

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
    LOAD = 294,
    DATA = 295,
    INFILE = 296,
    EQ = 297,
    LT = 298,
    GT = 299,
    LE = 300,
    GE = 301,
    NE = 302,
    NOT = 303,
    LIKE = 304,
    MAX = 305,
    MIN = 306,
    SUM = 307,
    COUNT = 308,
    AVG = 309,
    NUMBER = 310,
    FLOAT = 311,
    ID = 312,
    PATH = 313,
    SSS = 314,
    STAR = 315,
    STRING_V = 316
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 122 "yacc_sql.y"

  struct _Attr *attr;
  struct _Condition *condition1;
  struct _Value *value1;
  char *string;
  int number;
  float floats;
	char *position;

#line 256 "yacc_sql.tab.c"

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
#define YYLAST   411

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  160
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  368

#define YYUNDEFTOK  2
#define YYMAXUTOK   316


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
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   148,   148,   150,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   175,   180,   185,   191,   197,   203,   209,   215,
     220,   227,   234,   240,   249,   251,   257,   264,   273,   275,
     279,   290,   303,   306,   307,   308,   309,   312,   321,   338,
     340,   347,   350,   355,   360,   363,   369,   372,   375,   379,
     387,   397,   405,   412,   414,   422,   436,   441,   446,   451,
     456,   459,   461,   468,   473,   480,   484,   489,   494,   499,
     504,   509,   514,   521,   526,   531,   536,   543,   545,   550,
     566,   580,   585,   590,   595,   600,   603,   605,   612,   617,
     624,   628,   633,   638,   643,   648,   653,   658,   665,   670,
     675,   680,   687,   689,   693,   695,   698,   702,   704,   708,
     710,   714,   716,   721,   742,   762,   782,   804,   825,   846,
     867,   869,   873,   875,   880,   891,   911,   931,   953,   974,
     995,  1017,  1020,  1023,  1030,  1031,  1032,  1033,  1034,  1035,
    1036,  1037,  1041,  1042,  1043,  1044,  1045,  1046,  1047,  1048,
    1052
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
  "INNER", "JOIN", "ON", "LOAD", "DATA", "INFILE", "EQ", "LT", "GT", "LE",
  "GE", "NE", "NOT", "LIKE", "MAX", "MIN", "SUM", "COUNT", "AVG", "NUMBER",
  "FLOAT", "ID", "PATH", "SSS", "STAR", "STRING_V", "$accept", "commands",
  "command", "exit", "help", "sync", "begin", "commit", "rollback",
  "drop_table", "show_tables", "show_indexes", "desc_table",
  "create_index", "index_attr_list", "drop_index", "create_table",
  "attr_def_list", "attr_def", "number", "type", "ID_get", "insert",
  "value_tuple", "value_list", "insert_vaule", "value", "delete", "update",
  "update_list", "set_list", "sub_select", "sub_select_attr",
  "sub_attr_list", "sub_agg_func", "sub_rel_list", "select", "select_attr",
  "attr_list", "agg_func", "rel_list", "inner", "on", "where",
  "condition_list", "condition", "sub_where", "sub_condition_list",
  "sub_condition", "sub_value", "sub_comOp", "comOp", "load_data", YY_NULLPTR
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
     315,   316
};
# endif

#define YYPACT_NINF (-337)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -337,   118,  -337,   169,    93,   108,   -38,    85,    56,    73,
      39,    23,   101,   110,   122,   123,   124,    71,  -337,  -337,
    -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,
    -337,  -337,  -337,  -337,  -337,  -337,  -337,    80,   132,    86,
     117,   139,   125,   150,   193,   194,   199,    -3,   145,   170,
     145,   200,   218,   203,  -337,   174,   179,   191,  -337,  -337,
    -337,  -337,  -337,   207,   232,   195,   212,   248,   250,   197,
     198,   201,    33,   202,   147,   106,  -337,  -337,   204,  -337,
    -337,  -337,   205,   225,   224,   206,   224,   208,   209,   222,
     211,  -337,  -337,     0,     2,     3,   246,   247,   251,     4,
      57,   145,   145,   145,   252,   267,   255,    10,   270,   233,
     271,   249,  -337,   257,   215,   220,   261,  -337,   223,  -337,
     226,  -337,   227,  -337,  -337,  -337,  -337,   228,   185,  -337,
    -337,  -337,  -337,   229,   111,  -337,   178,   272,  -337,  -337,
      -1,  -337,   138,   253,  -337,    61,  -337,   275,   209,   273,
    -337,  -337,  -337,  -337,   276,   277,   231,   274,   278,   279,
     280,   145,   145,   252,   258,   242,   224,   286,  -337,  -337,
    -337,   281,   119,   283,   245,  -337,  -337,  -337,  -337,  -337,
    -337,   241,  -337,    18,    41,    10,  -337,   284,   254,   257,
     301,   259,   256,   287,  -337,  -337,  -337,  -337,  -337,  -337,
    -337,   260,   252,   302,  -337,   178,   289,   291,   292,   293,
     295,   298,    66,   297,   288,   297,  -337,   138,  -337,  -337,
    -337,   290,  -337,   253,   264,  -337,   315,  -337,  -337,  -337,
     304,   287,   266,   306,   252,   294,  -337,   281,   307,   268,
     282,   285,    64,   296,   155,   186,  -337,  -337,   299,  -337,
      53,   300,  -337,   303,  -337,  -337,   309,   287,   325,   294,
      10,    14,  -337,   312,   327,     5,     7,    31,   313,   316,
     317,    50,    72,   297,   297,   297,   314,   308,  -337,  -337,
      61,   333,  -337,  -337,    14,   253,  -337,   178,  -337,  -337,
     305,  -337,   310,  -337,   311,  -337,  -337,  -337,  -337,   318,
     187,  -337,  -337,  -337,  -337,   319,   321,   320,   284,  -337,
    -337,  -337,   281,   322,   323,   326,   328,   297,   297,   314,
     158,  -337,  -337,  -337,   329,  -337,  -337,  -337,  -337,  -337,
    -337,  -337,  -337,  -337,   107,  -337,   324,   146,   307,   330,
    -337,  -337,  -337,  -337,  -337,  -337,   331,  -337,   163,   158,
    -337,   168,  -337,   146,  -337,  -337,  -337,   324,   332,  -337,
     173,  -337,   334,   335,  -337,  -337,   336,  -337
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
       0,     0,     0,     0,     0,     0,     0,    96,    96,     0,
      96,     0,     0,     0,    24,     0,     0,     0,    25,    26,
      27,    23,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,    91,     0,    95,
      31,    29,     0,     0,   119,     0,   119,     0,     0,     0,
       0,    28,    36,     0,     0,     0,     0,     0,     0,     0,
      96,    96,    96,    96,   112,     0,     0,     0,     0,     0,
       0,     0,    47,    38,     0,     0,     0,   101,     0,   103,
       0,   105,     0,   107,   109,   108,   110,     0,     0,    97,
     100,    93,    94,     0,   114,    30,     0,     0,    56,    57,
       0,    58,     0,   121,    60,     0,    61,     0,     0,     0,
      43,    44,    45,    46,    41,     0,     0,     0,     0,     0,
       0,    96,    96,   112,     0,     0,   119,     0,    53,    54,
      55,    51,     0,     0,     0,   152,   153,   154,   155,   156,
     157,     0,   158,     0,     0,     0,   120,    63,     0,    38,
       0,     0,     0,    34,   102,   104,   106,   111,    99,    98,
     113,     0,   112,     0,    89,     0,     0,     0,     0,     0,
       0,     0,    71,    71,     0,    71,    59,     0,   159,   125,
     123,   126,   124,   121,     0,    62,     0,    39,    37,    42,
       0,    34,     0,     0,   112,   117,    90,    51,    49,     0,
       0,     0,     0,     0,     0,     0,    67,    66,     0,    70,
       0,     0,   122,     0,   160,    40,     0,    34,     0,   117,
       0,   114,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,    71,    71,    71,    87,     0,   127,   128,
       0,     0,    35,    32,   114,   121,   116,     0,    48,    76,
       0,    78,     0,    80,     0,    82,    84,    83,    85,     0,
       0,    72,    75,    68,    69,     0,   130,     0,    63,    33,
     115,   118,    51,     0,     0,     0,     0,    71,    71,    87,
       0,    65,   129,    64,     0,    77,    79,    81,    86,    74,
      73,    88,   141,   142,     0,   143,   132,     0,    49,     0,
     144,   145,   146,   147,   148,   149,     0,   150,     0,     0,
     131,     0,    50,     0,   151,   136,   134,   132,   137,   135,
       0,   133,     0,     0,   138,   139,     0,   140
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,
    -337,  -337,  -337,  -337,  -220,  -337,  -337,   149,   217,  -337,
    -337,  -337,  -337,    11,  -231,  -200,  -145,  -337,  -337,  -337,
      35,  -337,  -337,  -211,   104,    32,  -337,  -337,   -47,   337,
    -150,  -244,    91,   -77,  -213,  -178,  -337,    -5,     6,  -336,
    -323,  -134,  -337
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,   233,    30,    31,   149,   113,   230,
     154,   114,    32,   264,   206,   171,   142,    33,    34,    86,
     225,   173,   214,   246,   215,   306,    35,    49,    76,    50,
     134,   166,   261,   108,   186,   143,   321,   350,   336,   337,
     348,   183,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     187,    77,   247,    79,   249,   237,   262,   223,   184,   110,
     252,   256,   356,   200,   351,   359,    74,   286,   117,    51,
     119,   121,   126,   289,   364,   291,    75,   137,   174,   118,
     360,   120,   122,   127,   290,   137,   292,   282,   220,   222,
     310,   175,   176,   177,   178,   179,   180,   181,   182,   293,
     164,   165,   235,   129,   130,   131,   132,   167,   137,    54,
     294,   301,   302,   303,   304,   138,   139,   140,   298,   141,
     137,    56,   311,   138,   139,   219,    74,   141,   137,   299,
      57,   324,   285,   250,   259,   244,   128,   312,    96,   203,
      97,   244,    52,    98,    53,   245,   138,   139,   221,    40,
     141,   300,    41,    55,    58,   278,   329,   330,   138,   139,
     277,    63,   141,    59,   198,   199,   138,   139,     2,   268,
     141,   269,     3,     4,   270,    60,    61,    62,     5,     6,
       7,     8,     9,    10,    11,   308,   339,    64,    12,    13,
      14,    65,    69,    66,   107,    15,    16,   164,   165,   340,
     341,   342,   343,   344,   345,   346,   347,    17,    42,    43,
      44,    45,    46,   102,    74,    47,   103,    70,    48,   207,
     208,   209,   210,   211,    67,    37,   212,    38,    39,   213,
     175,   176,   177,   178,   179,   180,   181,   182,   340,   341,
     342,   343,   344,   345,   346,   347,    68,    42,    43,    44,
      45,    46,    78,    80,   100,   207,   208,   209,   210,   211,
      71,    72,   272,   332,   333,   334,    73,   335,   332,   333,
     355,    81,   335,   332,   333,   358,    85,   335,   332,   333,
     363,    83,   335,   168,   169,    82,    84,   170,   150,   151,
     152,   153,   161,   274,   317,   162,   275,   318,    87,    88,
      90,    91,    89,    92,    93,    94,   106,   107,    95,    99,
     115,   104,   105,   109,   123,   124,   112,   111,   116,   125,
     135,   133,   136,   144,   146,   145,   148,   155,   156,   147,
     157,   188,   172,   158,   159,   160,   163,   185,   193,   204,
     218,   190,   194,   191,   192,   201,   195,   196,   197,   202,
     205,   216,   217,   224,   228,   236,   232,   238,   239,   240,
     241,   226,   242,   231,   229,   243,   244,   234,   254,   251,
     248,   253,   255,   257,   258,   265,   263,   281,   283,   287,
     288,   295,   260,   305,   296,   297,   309,   307,   227,   266,
     325,   326,   267,   323,   327,   280,   328,   338,   273,   352,
     284,   331,   361,   271,   320,   357,   276,   279,   349,     0,
       0,   362,   313,     0,   366,   189,     0,   314,   315,     0,
       0,     0,     0,     0,     0,   316,   319,   322,     0,     0,
     354,     0,     0,     0,     0,     0,     0,   353,     0,     0,
       0,   365,     0,   367,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   101
};

static const yytype_int16 yycheck[] =
{
     145,    48,   213,    50,   215,   205,   237,   185,   142,    86,
     223,   231,   348,   163,   337,   351,    19,   261,    18,    57,
      18,    18,    18,    18,   360,    18,    29,    17,    29,    29,
     353,    29,    29,    29,    29,    17,    29,   257,   183,   184,
     284,    42,    43,    44,    45,    46,    47,    48,    49,    18,
      36,    37,   202,   100,   101,   102,   103,   134,    17,     3,
      29,   272,   273,   274,   275,    55,    56,    57,    18,    59,
      17,    32,   285,    55,    56,    57,    19,    59,    17,    29,
      57,   312,   260,   217,   234,    19,    29,   287,    55,   166,
      57,    19,     7,    60,     9,    29,    55,    56,    57,     6,
      59,    29,     9,    30,     3,   250,   317,   318,    55,    56,
      57,    40,    59,     3,   161,   162,    55,    56,     0,    55,
      59,    57,     4,     5,    60,     3,     3,     3,    10,    11,
      12,    13,    14,    15,    16,   280,    29,    57,    20,    21,
      22,     9,    17,    57,    33,    27,    28,    36,    37,    42,
      43,    44,    45,    46,    47,    48,    49,    39,    50,    51,
      52,    53,    54,    57,    19,    57,    60,    17,    60,    50,
      51,    52,    53,    54,    57,     6,    57,     8,     9,    60,
      42,    43,    44,    45,    46,    47,    48,    49,    42,    43,
      44,    45,    46,    47,    48,    49,    57,    50,    51,    52,
      53,    54,    32,     3,    57,    50,    51,    52,    53,    54,
      17,    17,    57,    55,    56,    57,    17,    59,    55,    56,
      57,     3,    59,    55,    56,    57,    35,    59,    55,    56,
      57,    57,    59,    55,    56,    32,    57,    59,    23,    24,
      25,    26,    57,    57,    57,    60,    60,    60,    41,    17,
      38,     3,    57,     3,    57,    57,    31,    33,    57,    57,
      38,    57,    57,    57,    18,    18,    57,    59,    57,    18,
       3,    19,    17,     3,     3,    42,    19,    57,    17,    30,
      57,     6,    10,    57,    57,    57,    57,    34,    57,     3,
      49,    18,    18,    17,    17,    37,    18,    18,    18,    57,
      19,    18,    57,    19,     3,     3,    19,    18,    17,    17,
      17,    57,    17,    57,    55,    17,    19,    57,     3,    29,
      32,    57,    18,    57,    18,    57,    19,    18,     3,    17,
       3,    18,    38,    19,    18,    18,     3,    29,   189,    57,
      18,    18,    57,   308,    18,    42,    18,    18,   244,   338,
     259,   319,   357,    57,    33,   349,    57,    57,    34,    -1,
      -1,    29,    57,    -1,    29,   148,    -1,    57,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    57,    57,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    57,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    63,     0,     4,     5,    10,    11,    12,    13,    14,
      15,    16,    20,    21,    22,    27,    28,    39,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      77,    78,    84,    89,    90,    98,   114,     6,     8,     9,
       6,     9,    50,    51,    52,    53,    54,    57,    60,    99,
     101,    57,     7,     9,     3,    30,    32,    57,     3,     3,
       3,     3,     3,    40,    57,     9,    57,    57,    57,    17,
      17,    17,    17,    17,    19,    29,   100,   100,    32,   100,
       3,     3,    32,    57,    57,    35,    91,    41,    17,    57,
      38,     3,     3,    57,    57,    57,    55,    57,    60,    57,
      57,   101,    57,    60,    57,    57,    31,    33,   105,    57,
     105,    59,    57,    80,    83,    38,    57,    18,    29,    18,
      29,    18,    29,    18,    18,    18,    18,    29,    29,   100,
     100,   100,   100,    19,   102,     3,    17,    17,    55,    56,
      57,    59,    88,   107,     3,    42,     3,    30,    19,    79,
      23,    24,    25,    26,    82,    57,    17,    57,    57,    57,
      57,    57,    60,    57,    36,    37,   103,   105,    55,    56,
      59,    87,    10,    93,    29,    42,    43,    44,    45,    46,
      47,    48,    49,   113,   113,    34,   106,    88,     6,    80,
      18,    17,    17,    57,    18,    18,    18,    18,   100,   100,
     102,    37,    57,   105,     3,    19,    86,    50,    51,    52,
      53,    54,    57,    60,    94,    96,    18,    57,    49,    57,
      88,    57,    88,   107,    19,    92,    57,    79,     3,    55,
      81,    57,    19,    76,    57,   102,     3,    87,    18,    17,
      17,    17,    17,    17,    19,    29,    95,    95,    32,    95,
     113,    29,   106,    57,     3,    18,    76,    57,    18,   102,
      38,   104,    86,    19,    85,    57,    57,    57,    55,    57,
      60,    57,    57,    96,    57,    60,    57,    57,    88,    57,
      42,    18,    76,     3,   104,   107,   103,    17,     3,    18,
      29,    18,    29,    18,    29,    18,    18,    18,    18,    29,
      29,    95,    95,    95,    95,    19,    97,    29,    88,     3,
     103,   106,    87,    57,    57,    57,    57,    57,    60,    57,
      33,   108,    57,    92,    86,    18,    18,    18,    18,    95,
      95,    97,    55,    56,    57,    59,   110,   111,    18,    29,
      42,    43,    44,    45,    46,    47,    48,    49,   112,    34,
     109,   112,    85,    57,    49,    57,   111,   110,    57,   111,
     112,   109,    29,    57,   111,    57,    29,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    63,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    75,    76,    76,    77,    78,    79,    79,
      80,    80,    81,    82,    82,    82,    82,    83,    84,    85,
      85,    86,    86,    87,    87,    87,    88,    88,    88,    88,
      89,    90,    91,    92,    92,    93,    94,    94,    94,    94,
      94,    95,    95,    95,    95,    95,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    97,    97,    98,
      98,    99,    99,    99,    99,    99,   100,   100,   100,   100,
     100,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   102,   102,   103,   103,   103,   104,   104,   105,
     105,   106,   106,   107,   107,   107,   107,   107,   107,   107,
     108,   108,   109,   109,   110,   110,   110,   110,   110,   110,
     110,   111,   111,   111,   112,   112,   112,   112,   112,   112,
     112,   112,   113,   113,   113,   113,   113,   113,   113,   113,
     114
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     4,     3,
       5,     3,    10,    11,     0,     3,     4,     8,     0,     3,
       5,     2,     1,     1,     1,     1,     1,     1,    10,     0,
       6,     0,     3,     1,     1,     1,     1,     1,     1,     3,
       5,     5,     5,     0,     5,     6,     2,     2,     4,     4,
       2,     0,     3,     5,     5,     3,     4,     6,     4,     6,
       4,     6,     4,     4,     4,     4,     6,     0,     3,     7,
       8,     2,     2,     4,     4,     2,     0,     3,     5,     5,
       3,     4,     6,     4,     6,     4,     6,     4,     4,     4,
       4,     6,     0,     3,     0,     6,     5,     0,     3,     0,
       3,     0,     3,     3,     3,     3,     3,     5,     5,     7,
       0,     3,     0,     3,     3,     3,     3,     3,     5,     5,
       7,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       8
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
#line 175 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1701 "yacc_sql.tab.c"
    break;

  case 23:
#line 180 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1709 "yacc_sql.tab.c"
    break;

  case 24:
#line 185 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1717 "yacc_sql.tab.c"
    break;

  case 25:
#line 191 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1725 "yacc_sql.tab.c"
    break;

  case 26:
#line 197 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1733 "yacc_sql.tab.c"
    break;

  case 27:
#line 203 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1741 "yacc_sql.tab.c"
    break;

  case 28:
#line 209 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1750 "yacc_sql.tab.c"
    break;

  case 29:
#line 215 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1758 "yacc_sql.tab.c"
    break;

  case 30:
#line 220 "yacc_sql.y"
                                     {
	  CONTEXT->ssql->flag = SCF_SHOW_INDEXES;
	  create_show_index(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
	}
#line 1767 "yacc_sql.tab.c"
    break;

  case 31:
#line 227 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1776 "yacc_sql.tab.c"
    break;

  case 32:
#line 235 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[-3].string));
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), DEFAULT_INDEX);
		}
#line 1786 "yacc_sql.tab.c"
    break;

  case 33:
#line 241 "yacc_sql.y"
        {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
            create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[-3].string));
            create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), UNIQUE_INDEX);
        }
#line 1796 "yacc_sql.tab.c"
    break;

  case 35:
#line 251 "yacc_sql.y"
                               {
            create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[-1].string));
        }
#line 1804 "yacc_sql.tab.c"
    break;

  case 36:
#line 258 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1813 "yacc_sql.tab.c"
    break;

  case 37:
#line 265 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1825 "yacc_sql.tab.c"
    break;

  case 39:
#line 275 "yacc_sql.y"
                                   {    }
#line 1831 "yacc_sql.tab.c"
    break;

  case 40:
#line 280 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-3].number), (yyvsp[-1].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;
			CONTEXT->value_length++;
		}
#line 1846 "yacc_sql.tab.c"
    break;

  case 41:
#line 291 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[0].number), 4);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}
#line 1861 "yacc_sql.tab.c"
    break;

  case 42:
#line 303 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1867 "yacc_sql.tab.c"
    break;

  case 43:
#line 306 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1873 "yacc_sql.tab.c"
    break;

  case 44:
#line 307 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1879 "yacc_sql.tab.c"
    break;

  case 45:
#line 308 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1885 "yacc_sql.tab.c"
    break;

  case 46:
#line 309 "yacc_sql.y"
                { (yyval.number)=DATES; }
#line 1891 "yacc_sql.tab.c"
    break;

  case 47:
#line 313 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1900 "yacc_sql.tab.c"
    break;

  case 48:
#line 322 "yacc_sql.y"
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
#line 1920 "yacc_sql.tab.c"
    break;

  case 50:
#line 340 "yacc_sql.y"
                                                                  {

	  }
#line 1928 "yacc_sql.tab.c"
    break;

  case 51:
#line 347 "yacc_sql.y"
        {
		inserts_more_init(&CONTEXT->inserts_more[CONTEXT->insert_length].value_num, &CONTEXT->insert_length);
	}
#line 1936 "yacc_sql.tab.c"
    break;

  case 52:
#line 350 "yacc_sql.y"
                                     { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1944 "yacc_sql.tab.c"
    break;

  case 53:
#line 355 "yacc_sql.y"
          {	
		// 匹配时insert规则时，保存在CONTEXT->inserts_more->values中
  		value_init_integer(&CONTEXT->inserts_more[CONTEXT->insert_length].values[CONTEXT->inserts_more[CONTEXT->insert_length].value_num++], (yyvsp[0].number));
		// 匹配Conditon规则时，values需要保存在CONTEXT->values中,使用下面的value规则
		}
#line 1954 "yacc_sql.tab.c"
    break;

  case 54:
#line 360 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->inserts_more[CONTEXT->insert_length].values[CONTEXT->inserts_more[CONTEXT->insert_length].value_num++], (yyvsp[0].floats));
		}
#line 1962 "yacc_sql.tab.c"
    break;

  case 55:
#line 363 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->inserts_more[CONTEXT->insert_length].values[CONTEXT->inserts_more[CONTEXT->insert_length].value_num++], (yyvsp[0].string));
		}
#line 1971 "yacc_sql.tab.c"
    break;

  case 56:
#line 369 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1979 "yacc_sql.tab.c"
    break;

  case 57:
#line 372 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1987 "yacc_sql.tab.c"
    break;

  case 58:
#line 375 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 1996 "yacc_sql.tab.c"
    break;

  case 59:
#line 379 "yacc_sql.y"
                                  {
		value_init_query(&CONTEXT->values[CONTEXT->value_length++], GET_SUB_CONTEXT->ssql);
		// 赋值后将子句清空
		memset(GET_SUB_CONTEXT->ssql, 0, sizeof(*GET_SUB_CONTEXT->ssql));
	}
#line 2006 "yacc_sql.tab.c"
    break;

  case 60:
#line 388 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 2018 "yacc_sql.tab.c"
    break;

  case 61:
#line 398 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-3].string), CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 2028 "yacc_sql.tab.c"
    break;

  case 62:
#line 405 "yacc_sql.y"
                            {
		SetValue set_value;
		set_value_init(&set_value, (yyvsp[-3].string), &CONTEXT->values[--CONTEXT->value_length]);
		update_append_value_list(&CONTEXT->ssql->sstr.update, &set_value);
	}
#line 2038 "yacc_sql.tab.c"
    break;

  case 64:
#line 414 "yacc_sql.y"
                                    {
		SetValue set_value;
		set_value_init(&set_value, (yyvsp[-3].string), &CONTEXT->values[--CONTEXT->value_length]);
		update_append_value_list(&CONTEXT->ssql->sstr.update, &set_value);
	}
#line 2048 "yacc_sql.tab.c"
    break;

  case 65:
#line 422 "yacc_sql.y"
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
#line 2065 "yacc_sql.tab.c"
    break;

  case 66:
#line 436 "yacc_sql.y"
                      {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2075 "yacc_sql.tab.c"
    break;

  case 67:
#line 441 "yacc_sql.y"
                       {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2085 "yacc_sql.tab.c"
    break;

  case 68:
#line 446 "yacc_sql.y"
                                  {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2095 "yacc_sql.tab.c"
    break;

  case 69:
#line 451 "yacc_sql.y"
                                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2105 "yacc_sql.tab.c"
    break;

  case 70:
#line 456 "yacc_sql.y"
                                    {
	}
#line 2112 "yacc_sql.tab.c"
    break;

  case 72:
#line 461 "yacc_sql.y"
                             {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
#line 2124 "yacc_sql.tab.c"
    break;

  case 73:
#line 468 "yacc_sql.y"
                                          {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2134 "yacc_sql.tab.c"
    break;

  case 74:
#line 473 "yacc_sql.y"
                                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
#line 2146 "yacc_sql.tab.c"
    break;

  case 76:
#line 484 "yacc_sql.y"
                             {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_MAX);
	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2156 "yacc_sql.tab.c"
    break;

  case 77:
#line 489 "yacc_sql.y"
                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_MAX);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2166 "yacc_sql.tab.c"
    break;

  case 78:
#line 494 "yacc_sql.y"
                               {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_MIN);
	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2176 "yacc_sql.tab.c"
    break;

  case 79:
#line 499 "yacc_sql.y"
                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_MIN);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2186 "yacc_sql.tab.c"
    break;

  case 80:
#line 504 "yacc_sql.y"
                               {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_SUM);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2196 "yacc_sql.tab.c"
    break;

  case 81:
#line 509 "yacc_sql.y"
                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_SUM);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2206 "yacc_sql.tab.c"
    break;

  case 82:
#line 514 "yacc_sql.y"
                                     {
       	  RelAttr attr;
       	  char *str = malloc(10 * sizeof(char));
       	  snprintf(str, 10, "%d", (yyvsp[-1].number));
       	  aggregation_attr_init(&attr, NULL, str, AGG_COUNT);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2218 "yacc_sql.tab.c"
    break;

  case 83:
#line 521 "yacc_sql.y"
                                   {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, "*", AGG_COUNT);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2228 "yacc_sql.tab.c"
    break;

  case 84:
#line 526 "yacc_sql.y"
                                 {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_COUNT);
       	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2238 "yacc_sql.tab.c"
    break;

  case 85:
#line 531 "yacc_sql.y"
                               {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_AVG);
	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2248 "yacc_sql.tab.c"
    break;

  case 86:
#line 536 "yacc_sql.y"
                                      {
	  RelAttr attr;
	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_AVG);
	  selects_append_attribute(&GET_SUB_CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2258 "yacc_sql.tab.c"
    break;

  case 88:
#line 545 "yacc_sql.y"
                            {	
			selects_append_relation(&GET_SUB_CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 2266 "yacc_sql.tab.c"
    break;

  case 89:
#line 551 "yacc_sql.y"
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
#line 2286 "yacc_sql.tab.c"
    break;

  case 90:
#line 567 "yacc_sql.y"
                {
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string));
			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);

			CONTEXT->ssql->flag=SCF_SELECT;
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
#line 2301 "yacc_sql.tab.c"
    break;

  case 91:
#line 580 "yacc_sql.y"
                  {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2311 "yacc_sql.tab.c"
    break;

  case 92:
#line 585 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2321 "yacc_sql.tab.c"
    break;

  case 93:
#line 590 "yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2331 "yacc_sql.tab.c"
    break;

  case 94:
#line 595 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2341 "yacc_sql.tab.c"
    break;

  case 97:
#line 605 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
#line 2353 "yacc_sql.tab.c"
    break;

  case 98:
#line 612 "yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2363 "yacc_sql.tab.c"
    break;

  case 99:
#line 617 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
#line 2375 "yacc_sql.tab.c"
    break;

  case 101:
#line 628 "yacc_sql.y"
                             {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_MAX);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2385 "yacc_sql.tab.c"
    break;

  case 102:
#line 633 "yacc_sql.y"
                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_MAX);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2395 "yacc_sql.tab.c"
    break;

  case 103:
#line 638 "yacc_sql.y"
                               {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_MIN);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2405 "yacc_sql.tab.c"
    break;

  case 104:
#line 643 "yacc_sql.y"
                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_MIN);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2415 "yacc_sql.tab.c"
    break;

  case 105:
#line 648 "yacc_sql.y"
                               {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_SUM);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2425 "yacc_sql.tab.c"
    break;

  case 106:
#line 653 "yacc_sql.y"
                                      {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_SUM);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2435 "yacc_sql.tab.c"
    break;

  case 107:
#line 658 "yacc_sql.y"
                                     {
       	  RelAttr attr;
       	  char *str = malloc(10 * sizeof(char));
       	  snprintf(str, 10, "%d", (yyvsp[-1].number));
       	  aggregation_attr_init(&attr, NULL, str, AGG_COUNT);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2447 "yacc_sql.tab.c"
    break;

  case 108:
#line 665 "yacc_sql.y"
                                   {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, "*", AGG_COUNT);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2457 "yacc_sql.tab.c"
    break;

  case 109:
#line 670 "yacc_sql.y"
                                 {
       	  RelAttr attr;
       	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_COUNT);
       	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
       	}
#line 2467 "yacc_sql.tab.c"
    break;

  case 110:
#line 675 "yacc_sql.y"
                               {
	  RelAttr attr;
	  aggregation_attr_init(&attr, NULL, (yyvsp[-1].string), AGG_AVG);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2477 "yacc_sql.tab.c"
    break;

  case 111:
#line 680 "yacc_sql.y"
                                      {
	  RelAttr attr;
	  aggregation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), AGG_AVG);
	  selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2487 "yacc_sql.tab.c"
    break;

  case 113:
#line 689 "yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 2495 "yacc_sql.tab.c"
    break;

  case 115:
#line 695 "yacc_sql.y"
                                          {
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
		  }
#line 2503 "yacc_sql.tab.c"
    break;

  case 116:
#line 698 "yacc_sql.y"
                                    {
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
		  }
#line 2511 "yacc_sql.tab.c"
    break;

  case 118:
#line 704 "yacc_sql.y"
                                      {

		  }
#line 2519 "yacc_sql.tab.c"
    break;

  case 120:
#line 710 "yacc_sql.y"
                                     {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2527 "yacc_sql.tab.c"
    break;

  case 122:
#line 716 "yacc_sql.y"
                                   {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2535 "yacc_sql.tab.c"
    break;

  case 123:
#line 722 "yacc_sql.y"
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
#line 2560 "yacc_sql.tab.c"
    break;

  case 124:
#line 743 "yacc_sql.y"
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
#line 2584 "yacc_sql.tab.c"
    break;

  case 125:
#line 763 "yacc_sql.y"
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
#line 2608 "yacc_sql.tab.c"
    break;

  case 126:
#line 783 "yacc_sql.y"
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
#line 2634 "yacc_sql.tab.c"
    break;

  case 127:
#line 805 "yacc_sql.y"
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
#line 2659 "yacc_sql.tab.c"
    break;

  case 128:
#line 826 "yacc_sql.y"
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
#line 2684 "yacc_sql.tab.c"
    break;

  case 129:
#line 847 "yacc_sql.y"
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
#line 2707 "yacc_sql.tab.c"
    break;

  case 131:
#line 869 "yacc_sql.y"
                                             {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2715 "yacc_sql.tab.c"
    break;

  case 133:
#line 875 "yacc_sql.y"
                                           {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2723 "yacc_sql.tab.c"
    break;

  case 134:
#line 881 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

			Value *right_value = &GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, GET_SUB_CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			GET_SUB_CONTEXT->conditions[GET_SUB_CONTEXT->condition_length++] = condition;
		}
#line 2738 "yacc_sql.tab.c"
    break;

  case 135:
#line 892 "yacc_sql.y"
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
#line 2762 "yacc_sql.tab.c"
    break;

  case 136:
#line 912 "yacc_sql.y"
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
#line 2786 "yacc_sql.tab.c"
    break;

  case 137:
#line 932 "yacc_sql.y"
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
#line 2812 "yacc_sql.tab.c"
    break;

  case 138:
#line 954 "yacc_sql.y"
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
#line 2837 "yacc_sql.tab.c"
    break;

  case 139:
#line 975 "yacc_sql.y"
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
#line 2862 "yacc_sql.tab.c"
    break;

  case 140:
#line 996 "yacc_sql.y"
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
#line 2885 "yacc_sql.tab.c"
    break;

  case 141:
#line 1017 "yacc_sql.y"
          {	
  		value_init_integer(&GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 2893 "yacc_sql.tab.c"
    break;

  case 142:
#line 1020 "yacc_sql.y"
          {
  		value_init_float(&GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 2901 "yacc_sql.tab.c"
    break;

  case 143:
#line 1023 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&GET_SUB_CONTEXT->values[GET_SUB_CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 2910 "yacc_sql.tab.c"
    break;

  case 144:
#line 1030 "yacc_sql.y"
             { GET_SUB_CONTEXT->comp = EQUAL_TO; }
#line 2916 "yacc_sql.tab.c"
    break;

  case 145:
#line 1031 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = LESS_THAN; }
#line 2922 "yacc_sql.tab.c"
    break;

  case 146:
#line 1032 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = GREAT_THAN; }
#line 2928 "yacc_sql.tab.c"
    break;

  case 147:
#line 1033 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = LESS_EQUAL; }
#line 2934 "yacc_sql.tab.c"
    break;

  case 148:
#line 1034 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = GREAT_EQUAL; }
#line 2940 "yacc_sql.tab.c"
    break;

  case 149:
#line 1035 "yacc_sql.y"
         { GET_SUB_CONTEXT->comp = NOT_EQUAL; }
#line 2946 "yacc_sql.tab.c"
    break;

  case 150:
#line 1036 "yacc_sql.y"
           { GET_SUB_CONTEXT->comp = OP_LIKE; }
#line 2952 "yacc_sql.tab.c"
    break;

  case 151:
#line 1037 "yacc_sql.y"
               { GET_SUB_CONTEXT->comp = OP_NOT_LIKE; }
#line 2958 "yacc_sql.tab.c"
    break;

  case 152:
#line 1041 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 2964 "yacc_sql.tab.c"
    break;

  case 153:
#line 1042 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 2970 "yacc_sql.tab.c"
    break;

  case 154:
#line 1043 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 2976 "yacc_sql.tab.c"
    break;

  case 155:
#line 1044 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 2982 "yacc_sql.tab.c"
    break;

  case 156:
#line 1045 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 2988 "yacc_sql.tab.c"
    break;

  case 157:
#line 1046 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 2994 "yacc_sql.tab.c"
    break;

  case 158:
#line 1047 "yacc_sql.y"
           { CONTEXT->comp = OP_LIKE; }
#line 3000 "yacc_sql.tab.c"
    break;

  case 159:
#line 1048 "yacc_sql.y"
               { CONTEXT->comp = OP_NOT_LIKE; }
#line 3006 "yacc_sql.tab.c"
    break;

  case 160:
#line 1053 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 3015 "yacc_sql.tab.c"
    break;


#line 3019 "yacc_sql.tab.c"

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
#line 1058 "yacc_sql.y"

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
