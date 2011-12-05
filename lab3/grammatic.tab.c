
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "grammatic.y"


#include <stdio.h>
#include <malloc.h>
#include "grammatic_struct.h"
#include "grammatic_func.h"
#define YYERROR_VERBOSE 
extern int yylex(void);

struct Program *prg;



/* Line 189 of yacc.c  */
#line 87 "grammatic.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CLASS = 258,
     NIL = 259,
     SELF = 260,
     DEF = 261,
     BOOL = 262,
     SUPER = 263,
     WHILE = 264,
     FOR = 265,
     THEN = 266,
     DO = 267,
     IF = 268,
     ELSE = 269,
     IN = 270,
     BREAK = 271,
     END = 272,
     RETURN = 273,
     UNTIL = 274,
     CONST = 275,
     ID = 276,
     NL = 277,
     PUBLIC = 278,
     PRIVATE = 279,
     PROTECTED = 280,
     INT = 281,
     FLOAT = 282,
     STRING = 283,
     ORWORD = 284,
     ANDWORD = 285,
     NOTWORD = 286,
     DIVASSIGN = 287,
     MULASSIGN = 288,
     SUBASSIGN = 289,
     ADDASSIGN = 290,
     THREEPOINT = 291,
     TWOPOINT = 292,
     AND = 293,
     OR = 294,
     MOREEQ = 295,
     LESSEQ = 296,
     LESSMORE = 297,
     NEQ = 298,
     EQ = 299,
     UMINUS = 300,
     NOT = 301,
     UPLUS = 302,
     DOUBLECOLON = 303
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 13 "grammatic.y"

	long int_const;
	float float_const;
	char* string_const;
	int bool_const;
	
	struct Expression *exp;
	struct Statement *stm;
	struct Program *prg;
	struct Name_and_type_var *var;
	struct Statements_list *stm_l;
	struct Expressions_list *exp_l;
	struct Expressions_list * id_l;



/* Line 214 of yacc.c  */
#line 188 "grammatic.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 200 "grammatic.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1082

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNRULES -- Number of states.  */
#define YYNSTATES  223

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      62,    59,    43,    42,    61,    41,    57,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    60,     2,
      46,    32,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    33,    34,    35,
      36,    37,    38,    39,    40,    47,    48,    49,    50,    51,
      52,    53,    54,    58
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     8,    10,    13,    16,    18,
      21,    24,    27,    30,    34,    37,    40,    43,    46,    48,
      51,    54,    57,    60,    64,    67,    69,    72,    74,    75,
      77,    80,    83,    88,    93,    98,   102,   106,   110,   112,
     115,   121,   129,   135,   143,   151,   159,   165,   171,   177,
     183,   187,   189,   195,   204,   210,   218,   220,   221,   225,
     227,   229,   231,   233,   235,   237,   239,   241,   243,   247,
     251,   255,   259,   263,   267,   271,   275,   279,   283,   287,
     291,   295,   299,   302,   306,   310,   313,   317,   321,   325,
     329,   333,   337,   341,   344,   347,   351,   357,   364,   368,
     373,   375,   379,   384,   386,   391
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      64,     0,    -1,    65,    -1,    66,    -1,    -1,    67,    -1,
      66,    67,    -1,    82,    22,    -1,    22,    -1,    73,    22,
      -1,    74,    22,    -1,    75,    22,    -1,    76,    22,    -1,
      18,    82,    22,    -1,    16,    22,    -1,    79,    22,    -1,
      78,    22,    -1,    82,    22,    -1,    22,    -1,    73,    22,
      -1,    74,    22,    -1,    75,    22,    -1,    76,    22,    -1,
      18,    82,    22,    -1,    16,    22,    -1,    68,    -1,    69,
      68,    -1,    69,    -1,    -1,    22,    -1,    21,    22,    -1,
      78,    22,    -1,    23,    60,    21,    22,    -1,    24,    60,
      21,    22,    -1,    25,    60,    21,    22,    -1,    23,    78,
      22,    -1,    24,    78,    22,    -1,    25,    78,    22,    -1,
      71,    -1,    72,    71,    -1,    13,    82,    11,    69,    17,
      -1,    13,    82,    11,    69,    14,    69,    17,    -1,    13,
      82,    22,    69,    17,    -1,    13,    82,    22,    69,    14,
      69,    17,    -1,    10,    82,    15,    82,    12,    69,    17,
      -1,    10,    82,    15,    82,    22,    69,    17,    -1,     9,
      82,    12,    69,    17,    -1,     9,    82,    22,    69,    17,
      -1,    19,    82,    12,    69,    17,    -1,    19,    82,    22,
      69,    17,    -1,    77,    61,    82,    -1,    82,    -1,     6,
      21,    22,    70,    17,    -1,     6,    21,    62,    80,    59,
      22,    70,    17,    -1,     3,    20,    22,    72,    17,    -1,
       3,    20,    46,    20,    22,    72,    17,    -1,    81,    -1,
      -1,    81,    61,    21,    -1,    21,    -1,    20,    -1,    21,
      -1,    28,    -1,    26,    -1,    27,    -1,     7,    -1,     4,
      -1,     5,    -1,    82,    42,    82,    -1,    82,    41,    82,
      -1,    82,    43,    82,    -1,    82,    44,    82,    -1,    82,
      46,    82,    -1,    82,    45,    82,    -1,    82,    32,    82,
      -1,    82,    48,    82,    -1,    82,    47,    82,    -1,    82,
      51,    82,    -1,    82,    50,    82,    -1,    82,    49,    82,
      -1,    82,    30,    82,    -1,    82,    29,    82,    -1,    31,
      82,    -1,    82,    40,    82,    -1,    82,    39,    82,    -1,
      53,    82,    -1,    82,    58,    82,    -1,    82,    36,    82,
      -1,    82,    35,    82,    -1,    82,    34,    82,    -1,    82,
      33,    82,    -1,    82,    38,    82,    -1,    82,    37,    82,
      -1,    41,    82,    -1,    42,    82,    -1,    82,    57,    21,
      -1,    82,    57,    21,    62,    59,    -1,    82,    57,    21,
      62,    77,    59,    -1,    21,    62,    59,    -1,    21,    62,
      77,    59,    -1,     8,    -1,     8,    62,    59,    -1,     8,
      62,    77,    59,    -1,    83,    -1,    82,    55,    82,    56,
      -1,    55,    77,    56,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    97,    97,   100,   101,   104,   105,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   119,   120,   121,
     122,   123,   124,   125,   126,   129,   130,   133,   134,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   148,   149,
     152,   153,   154,   155,   158,   159,   162,   163,   166,   167,
     170,   171,   174,   175,   178,   179,   182,   183,   185,   186,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   236
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "NIL", "SELF", "DEF", "BOOL",
  "SUPER", "WHILE", "FOR", "THEN", "DO", "IF", "ELSE", "IN", "BREAK",
  "END", "RETURN", "UNTIL", "CONST", "ID", "NL", "PUBLIC", "PRIVATE",
  "PROTECTED", "INT", "FLOAT", "STRING", "ORWORD", "ANDWORD", "NOTWORD",
  "'='", "DIVASSIGN", "MULASSIGN", "SUBASSIGN", "ADDASSIGN", "THREEPOINT",
  "TWOPOINT", "AND", "OR", "'-'", "'+'", "'*'", "'/'", "'>'", "'<'",
  "MOREEQ", "LESSEQ", "LESSMORE", "NEQ", "EQ", "UMINUS", "NOT", "UPLUS",
  "'['", "']'", "'.'", "DOUBLECOLON", "')'", "':'", "','", "'('",
  "$accept", "program", "stmt_list", "stmt_list_ne", "stmt",
  "method_member", "method_members_ne", "method_members", "class_member",
  "class_member_list", "if_stmt", "for_stmt", "while_stmt", "until_stmt",
  "expr_list", "def_stmt", "class_stmt", "id_listE", "id_list", "expr",
  "init_array_expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,    61,   287,   288,   289,   290,   291,   292,   293,
     294,    45,    43,    42,    47,    62,    60,   295,   296,   297,
     298,   299,   300,   301,   302,    91,    93,    46,   303,    41,
      58,    44,    40
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    65,    66,    66,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    68,    68,    68,
      68,    68,    68,    68,    68,    69,    69,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    72,    72,
      73,    73,    73,    73,    74,    74,    75,    75,    76,    76,
      77,    77,    78,    78,    79,    79,    80,    80,    81,    81,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    83
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     1,     2,     2,     1,     2,
       2,     2,     2,     3,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     3,     2,     1,     2,     1,     0,     1,
       2,     2,     4,     4,     4,     3,     3,     3,     1,     2,
       5,     7,     5,     7,     7,     7,     5,     5,     5,     5,
       3,     1,     5,     8,     5,     7,     1,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     3,     5,     6,     3,     4,
       1,     3,     4,     1,     4,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,    66,    67,     0,    65,   100,     0,     0,     0,
       0,     0,     0,    60,    61,     8,    63,    64,    62,     0,
       0,     0,     0,     0,     0,     2,     3,     5,     0,     0,
       0,     0,     0,     0,     0,   103,     0,     0,     0,     0,
       0,     0,    14,     0,     0,     0,    82,    93,    94,    85,
       0,    51,     1,     6,     9,    10,    11,    12,    16,    15,
       7,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,    57,
     101,     0,     0,     0,     0,     0,     0,    13,     0,     0,
      98,     0,   105,     0,    81,    80,    74,    90,    89,    88,
      87,    92,    91,    84,    83,    69,    68,    70,    71,    73,
      72,    76,    75,    79,    78,    77,     0,    95,    86,     0,
      29,     0,     0,     0,    38,     0,     0,     0,     0,     0,
      18,    25,    27,     0,     0,     0,     0,     0,     0,    59,
       0,    56,   102,     0,     0,     0,     0,     0,     0,     0,
      99,    50,   104,     0,    30,     0,     0,     0,     0,     0,
       0,    54,    39,    31,     0,    24,     0,    26,    52,    19,
      20,    21,    22,    17,     0,     0,    46,    47,     0,     0,
       0,    40,     0,    42,    48,    49,    96,     0,     0,    35,
       0,    36,     0,    37,     0,    23,    28,    58,     0,     0,
       0,     0,    97,    32,    33,    34,    55,     0,    44,    45,
      41,    43,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    24,    25,    26,    27,   141,   142,   143,   134,   135,
     144,   145,   146,   147,    50,   136,    33,   150,   151,   148,
      35
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -121
static const yytype_int16 yypact[] =
{
     205,   -14,  -121,  -121,    -5,  -121,   -38,   565,   565,   565,
       3,   565,   565,  -121,   -34,  -121,  -121,  -121,  -121,   565,
     565,   565,   565,   565,    48,  -121,   205,  -121,    30,    38,
      64,    73,    74,    79,   779,  -121,    -9,   -20,   115,   632,
     749,   592,  -121,   809,   672,   145,   956,    32,    32,    32,
     -15,   929,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,   565,   565,   565,   565,   565,   565,   565,   565,   565,
     565,   565,   565,   565,   565,   565,   565,   565,   565,   565,
     565,   565,   565,   565,    90,   565,   169,    98,   535,   100,
    -121,   -12,   535,   535,   565,   535,   535,  -121,   535,   535,
    -121,    43,  -121,   565,   956,   956,   956,   956,   956,   956,
     956,   976,   976,   994,   994,  1010,  1010,  1024,  1024,    42,
      42,    42,    42,    32,    32,    32,   899,    62,  -121,   108,
    -121,    -2,    -1,    28,  -121,    92,   109,   116,   118,   565,
    -121,  -121,   535,   120,   122,   123,   125,   126,   839,  -121,
      95,    94,  -121,   295,   325,   712,   235,   265,   355,   385,
    -121,   929,  -121,   175,  -121,   130,   136,   138,   139,   141,
     142,  -121,  -121,  -121,   169,  -121,   869,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,   147,   146,  -121,  -121,   535,   535,
     535,  -121,   535,  -121,  -121,  -121,  -121,    51,   155,  -121,
     156,  -121,   159,  -121,   558,  -121,   535,  -121,   415,   445,
     475,   505,  -121,  -121,  -121,  -121,  -121,   143,  -121,  -121,
    -121,  -121,  -121
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,  -121,  -121,   158,  -103,   -63,   -21,  -120,    15,
      14,    17,    18,    31,   -35,     1,  -121,  -121,  -121,     0,
    -121
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      34,    32,    88,    91,     4,     4,    36,    39,    40,    41,
     101,    43,    44,    86,    28,   172,    37,    29,    30,    46,
      47,    48,    49,    51,    38,    42,    34,    32,    45,   153,
     154,    31,   156,   157,     4,   158,   159,    87,    51,   177,
      28,   102,    89,    29,    30,    51,   103,   152,    52,   103,
     177,   177,    54,   177,   177,   177,   177,    31,   165,   167,
      55,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   172,   128,    56,    83,   169,    84,
      85,    80,    81,    82,   155,    57,    58,    83,     4,    84,
      85,    59,   160,   161,   103,   177,   177,   177,   177,   171,
     212,   127,   103,   129,   130,   131,   132,   133,   137,     2,
       3,   149,     5,     6,   163,   208,   209,   210,   197,   211,
     164,   173,   166,   168,   170,    13,    14,   178,   174,   176,
     175,    16,    17,    18,   179,   180,    19,   181,   182,     2,
       3,   198,     5,     6,   184,   185,    20,    21,   199,   200,
     222,   201,   202,    51,   203,    13,    14,   207,    22,   206,
      23,    16,    17,    18,    90,     4,    19,   213,   214,     2,
       3,   215,     5,     6,    53,   217,    20,    21,     0,   204,
     129,   130,   131,   132,   133,    13,    14,     0,    22,     0,
      23,    16,    17,    18,   100,     0,    19,     0,     1,     2,
       3,     4,     5,     6,     7,     8,    20,    21,     9,     0,
       0,    10,     0,    11,    12,    13,    14,    15,    22,     0,
      23,    16,    17,    18,   196,     0,    19,     0,     0,     2,
       3,     0,     5,     6,     7,     8,    20,    21,     9,   190,
       0,   138,   191,   139,    12,    13,    14,   140,    22,     0,
      23,    16,    17,    18,     0,     0,    19,     0,     0,     2,
       3,     0,     5,     6,     7,     8,    20,    21,     9,   192,
       0,   138,   193,   139,    12,    13,    14,   140,    22,     0,
      23,    16,    17,    18,     0,     0,    19,     0,     0,     2,
       3,     0,     5,     6,     7,     8,    20,    21,     9,     0,
       0,   138,   186,   139,    12,    13,    14,   140,    22,     0,
      23,    16,    17,    18,     0,     0,    19,     0,     0,     2,
       3,     0,     5,     6,     7,     8,    20,    21,     9,     0,
       0,   138,   187,   139,    12,    13,    14,   140,    22,     0,
      23,    16,    17,    18,     0,     0,    19,     0,     0,     2,
       3,     0,     5,     6,     7,     8,    20,    21,     9,     0,
       0,   138,   194,   139,    12,    13,    14,   140,    22,     0,
      23,    16,    17,    18,     0,     0,    19,     0,     0,     2,
       3,     0,     5,     6,     7,     8,    20,    21,     9,     0,
       0,   138,   195,   139,    12,    13,    14,   140,    22,     0,
      23,    16,    17,    18,     0,     0,    19,     0,     0,     2,
       3,     0,     5,     6,     7,     8,    20,    21,     9,     0,
       0,   138,   218,   139,    12,    13,    14,   140,    22,     0,
      23,    16,    17,    18,     0,     0,    19,     0,     0,     2,
       3,     0,     5,     6,     7,     8,    20,    21,     9,     0,
       0,   138,   219,   139,    12,    13,    14,   140,    22,     0,
      23,    16,    17,    18,     0,     0,    19,     0,     0,     2,
       3,     0,     5,     6,     7,     8,    20,    21,     9,     0,
       0,   138,   220,   139,    12,    13,    14,   140,    22,     0,
      23,    16,    17,    18,     0,     0,    19,     0,     0,     2,
       3,     0,     5,     6,     7,     8,    20,    21,     9,     0,
       0,   138,   221,   139,    12,    13,    14,   140,    22,     0,
      23,    16,    17,    18,     0,     0,    19,     0,     0,     2,
       3,     0,     5,     6,     7,     8,    20,    21,     9,     0,
       0,   138,     0,   139,    12,    13,    14,   140,    22,     0,
      23,    16,    17,    18,     4,     0,    19,     0,     0,     2,
       3,     0,     5,     6,     0,   216,    20,    21,     0,   129,
     130,   131,   132,   133,     0,    13,    14,     0,    22,     0,
      23,    16,    17,    18,     0,     0,    19,     0,     0,     0,
       0,     0,     0,    95,     0,     0,    20,    21,     0,     0,
       0,     0,     0,     0,    96,     0,     0,     0,    22,     0,
      23,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    92,     0,     0,    83,     0,    84,
      85,     0,     0,     0,    93,     0,     0,     0,     0,     0,
       0,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    98,     0,     0,    83,     0,    84,
      85,     0,     0,     0,    99,     0,     0,     0,     0,     0,
       0,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,   188,     0,     0,    83,     0,    84,
      85,     0,     0,     0,   189,     0,     0,     0,     0,     0,
       0,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    94,     0,     0,    83,     0,    84,
      85,     0,     0,     0,     0,     0,     0,     0,    61,    62,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    60,     0,     0,    83,     0,    84,    85,    61,    62,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    97,     0,     0,    83,     0,    84,    85,    61,    62,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,   183,     0,     0,    83,     0,    84,    85,    61,    62,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,   205,     0,     0,    83,     0,    84,    85,    61,    62,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,     0,     0,     0,    83,     0,    84,    85,    61,    62,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,     0,     0,     0,    83,   162,    84,    85,    61,    62,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,     0,     0,     0,    83,     0,    84,    85,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,     0,     0,
       0,    83,     0,    84,    85,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,     0,     0,
       0,    83,     0,    84,    85,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,     0,     0,     0,    83,
       0,    84,    85,    74,    75,    76,    77,    78,    79,    80,
      81,    82,     0,     0,     0,    83,     0,    84,    85,    76,
      77,    78,    79,    80,    81,    82,     0,     0,     0,    83,
       0,    84,    85
};

static const yytype_int16 yycheck[] =
{
       0,     0,    22,    38,     6,     6,    20,     7,     8,     9,
      45,    11,    12,    22,     0,   135,    21,     0,     0,    19,
      20,    21,    22,    23,    62,    22,    26,    26,    62,    92,
      93,     0,    95,    96,     6,    98,    99,    46,    38,   142,
      26,    56,    62,    26,    26,    45,    61,    59,     0,    61,
     153,   154,    22,   156,   157,   158,   159,    26,    60,    60,
      22,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,   204,    85,    22,    55,    60,    57,
      58,    49,    50,    51,    94,    22,    22,    55,     6,    57,
      58,    22,    59,   103,    61,   208,   209,   210,   211,    17,
      59,    21,    61,    21,    22,    23,    24,    25,    20,     4,
       5,    21,     7,     8,    62,   188,   189,   190,   163,   192,
      22,    22,   131,   132,   133,    20,    21,    17,    22,   139,
      22,    26,    27,    28,    22,    22,    31,    22,    22,     4,
       5,    21,     7,     8,    59,    61,    41,    42,    22,    21,
      17,    22,    21,   163,    22,    20,    21,    21,    53,    22,
      55,    26,    27,    28,    59,     6,    31,    22,    22,     4,
       5,    22,     7,     8,    26,   206,    41,    42,    -1,   174,
      21,    22,    23,    24,    25,    20,    21,    -1,    53,    -1,
      55,    26,    27,    28,    59,    -1,    31,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    41,    42,    13,    -1,
      -1,    16,    -1,    18,    19,    20,    21,    22,    53,    -1,
      55,    26,    27,    28,    59,    -1,    31,    -1,    -1,     4,
       5,    -1,     7,     8,     9,    10,    41,    42,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    53,    -1,
      55,    26,    27,    28,    -1,    -1,    31,    -1,    -1,     4,
       5,    -1,     7,     8,     9,    10,    41,    42,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    53,    -1,
      55,    26,    27,    28,    -1,    -1,    31,    -1,    -1,     4,
       5,    -1,     7,     8,     9,    10,    41,    42,    13,    -1,
      -1,    16,    17,    18,    19,    20,    21,    22,    53,    -1,
      55,    26,    27,    28,    -1,    -1,    31,    -1,    -1,     4,
       5,    -1,     7,     8,     9,    10,    41,    42,    13,    -1,
      -1,    16,    17,    18,    19,    20,    21,    22,    53,    -1,
      55,    26,    27,    28,    -1,    -1,    31,    -1,    -1,     4,
       5,    -1,     7,     8,     9,    10,    41,    42,    13,    -1,
      -1,    16,    17,    18,    19,    20,    21,    22,    53,    -1,
      55,    26,    27,    28,    -1,    -1,    31,    -1,    -1,     4,
       5,    -1,     7,     8,     9,    10,    41,    42,    13,    -1,
      -1,    16,    17,    18,    19,    20,    21,    22,    53,    -1,
      55,    26,    27,    28,    -1,    -1,    31,    -1,    -1,     4,
       5,    -1,     7,     8,     9,    10,    41,    42,    13,    -1,
      -1,    16,    17,    18,    19,    20,    21,    22,    53,    -1,
      55,    26,    27,    28,    -1,    -1,    31,    -1,    -1,     4,
       5,    -1,     7,     8,     9,    10,    41,    42,    13,    -1,
      -1,    16,    17,    18,    19,    20,    21,    22,    53,    -1,
      55,    26,    27,    28,    -1,    -1,    31,    -1,    -1,     4,
       5,    -1,     7,     8,     9,    10,    41,    42,    13,    -1,
      -1,    16,    17,    18,    19,    20,    21,    22,    53,    -1,
      55,    26,    27,    28,    -1,    -1,    31,    -1,    -1,     4,
       5,    -1,     7,     8,     9,    10,    41,    42,    13,    -1,
      -1,    16,    17,    18,    19,    20,    21,    22,    53,    -1,
      55,    26,    27,    28,    -1,    -1,    31,    -1,    -1,     4,
       5,    -1,     7,     8,     9,    10,    41,    42,    13,    -1,
      -1,    16,    -1,    18,    19,    20,    21,    22,    53,    -1,
      55,    26,    27,    28,     6,    -1,    31,    -1,    -1,     4,
       5,    -1,     7,     8,    -1,    17,    41,    42,    -1,    21,
      22,    23,    24,    25,    -1,    20,    21,    -1,    53,    -1,
      55,    26,    27,    28,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    53,    -1,
      55,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    12,    -1,    -1,    55,    -1,    57,
      58,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    12,    -1,    -1,    55,    -1,    57,
      58,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    12,    -1,    -1,    55,    -1,    57,
      58,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    15,    -1,    -1,    55,    -1,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    22,    -1,    -1,    55,    -1,    57,    58,    29,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    22,    -1,    -1,    55,    -1,    57,    58,    29,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    22,    -1,    -1,    55,    -1,    57,    58,    29,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    22,    -1,    -1,    55,    -1,    57,    58,    29,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    -1,    -1,    55,    -1,    57,    58,    29,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    -1,    -1,    55,    56,    57,    58,    29,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    -1,    -1,    55,    -1,    57,    58,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    -1,    -1,
      -1,    55,    -1,    57,    58,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    -1,    -1,
      -1,    55,    -1,    57,    58,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    -1,    -1,    55,
      -1,    57,    58,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    -1,    -1,    -1,    55,    -1,    57,    58,    45,
      46,    47,    48,    49,    50,    51,    -1,    -1,    -1,    55,
      -1,    57,    58
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    13,
      16,    18,    19,    20,    21,    22,    26,    27,    28,    31,
      41,    42,    53,    55,    64,    65,    66,    67,    73,    74,
      75,    76,    78,    79,    82,    83,    20,    21,    62,    82,
      82,    82,    22,    82,    82,    62,    82,    82,    82,    82,
      77,    82,     0,    67,    22,    22,    22,    22,    22,    22,
      22,    29,    30,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    55,    57,    58,    22,    46,    22,    62,
      59,    77,    12,    22,    15,    11,    22,    22,    12,    22,
      59,    77,    56,    61,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    21,    82,    21,
      22,    23,    24,    25,    71,    72,    78,    20,    16,    18,
      22,    68,    69,    70,    73,    74,    75,    76,    82,    21,
      80,    81,    59,    69,    69,    82,    69,    69,    69,    69,
      59,    82,    56,    62,    22,    60,    78,    60,    78,    60,
      78,    17,    71,    22,    22,    22,    82,    68,    17,    22,
      22,    22,    22,    22,    59,    61,    17,    17,    12,    22,
      14,    17,    14,    17,    17,    17,    59,    77,    21,    22,
      21,    22,    21,    22,    72,    22,    22,    21,    69,    69,
      69,    69,    59,    22,    22,    22,    17,    70,    17,    17,
      17,    17,    17
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 97 "grammatic.y"
    {(yyval.prg) = prg = create_program((yyvsp[(1) - (1)].stm_l));}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 100 "grammatic.y"
    {(yyval.stm_l)=(yyvsp[(1) - (1)].stm_l);}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 101 "grammatic.y"
    {(yyval.stm_l)=NULL;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 104 "grammatic.y"
    {(yyval.stm_l) = create_stmt_list((yyvsp[(1) - (1)].stm));}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 105 "grammatic.y"
    {(yyval.stm_l) = add_to_stmt_list((yyvsp[(1) - (2)].stm_l),(yyvsp[(2) - (2)].stm));}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 108 "grammatic.y"
    {(yyval.stm) = create_stmt((yyvsp[(1) - (2)].exp));}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 109 "grammatic.y"
    {(yyval.stm)=NULL;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 110 "grammatic.y"
    {(yyval.stm)=(yyvsp[(1) - (2)].stm);}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 111 "grammatic.y"
    {(yyval.stm)=(yyvsp[(1) - (2)].stm);}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 112 "grammatic.y"
    {(yyval.stm)=(yyvsp[(1) - (2)].stm);}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 113 "grammatic.y"
    {(yyval.stm)=(yyvsp[(1) - (2)].stm);}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 114 "grammatic.y"
    {(yyval.stm) = create_return_stmt((yyvsp[(2) - (3)].exp));}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 115 "grammatic.y"
    {(yyval.stm) = create_break_stmt();}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 116 "grammatic.y"
    {(yyval.stm)=(yyvsp[(1) - (2)].stm);}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 117 "grammatic.y"
    {(yyval.stm)=(yyvsp[(1) - (2)].stm);}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 119 "grammatic.y"
    {(yyval.stm) = create_stmt((yyvsp[(1) - (2)].exp));}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 120 "grammatic.y"
    {(yyval.stm)=NULL;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 121 "grammatic.y"
    {(yyval.stm)=(yyvsp[(1) - (2)].stm);}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 122 "grammatic.y"
    {(yyval.stm)=(yyvsp[(1) - (2)].stm);}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 123 "grammatic.y"
    {(yyval.stm)=(yyvsp[(1) - (2)].stm);}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 124 "grammatic.y"
    {(yyval.stm)=(yyvsp[(1) - (2)].stm);}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 125 "grammatic.y"
    {(yyval.stm) = create_return_stmt((yyvsp[(2) - (3)].exp));}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 126 "grammatic.y"
    {(yyval.stm) = create_break_stmt();}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 129 "grammatic.y"
    {(yyval.stm_l) = create_stmt_list((yyvsp[(1) - (1)].stm));}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 130 "grammatic.y"
    {(yyval.stm_l) = add_to_stmt_list((yyvsp[(1) - (2)].stm_l),(yyvsp[(2) - (2)].stm));}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 133 "grammatic.y"
    {(yyval.stm_l)=(yyvsp[(1) - (1)].stm_l);}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 134 "grammatic.y"
    {(yyval.stm_l)=NULL;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 137 "grammatic.y"
    {(yyval.stm)=NULL;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 138 "grammatic.y"
    {(yyval.stm) = create_access_rule(Public,(yyvsp[(1) - (2)].var),NULL);}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 139 "grammatic.y"
    {(yyval.stm) = create_access_rule(Public,NULL,(yyvsp[(1) - (2)].stm));}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 140 "grammatic.y"
    {(yyval.stm) = create_access_rule(Public,(yyvsp[(3) - (4)].var),NULL);}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 141 "grammatic.y"
    {(yyval.stm) = create_access_rule(Private,(yyvsp[(3) - (4)].var),NULL);}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 142 "grammatic.y"
    {(yyval.stm) = create_access_rule(Protected,(yyvsp[(3) - (4)].var),NULL);}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 143 "grammatic.y"
    {(yyval.stm) = create_access_rule(Public,NULL,(yyvsp[(2) - (3)].stm));}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 144 "grammatic.y"
    {(yyval.stm) = create_access_rule(Private,NULL,(yyvsp[(2) - (3)].stm));}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 145 "grammatic.y"
    {(yyval.stm) = create_access_rule(Protected,NULL,(yyvsp[(2) - (3)].stm));}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 148 "grammatic.y"
    {(yyval.stm_l)=create_stmt_list((yyvsp[(1) - (1)].stm));}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 149 "grammatic.y"
    {(yyval.stm_l)=add_to_stmt_list((yyvsp[(1) - (2)].stm_l),(yyvsp[(2) - (2)].stm));}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 152 "grammatic.y"
    {(yyval.stm)=create_if_stmt((yyvsp[(2) - (5)].exp), (yyvsp[(4) - (5)].stm_l), NULL);}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 153 "grammatic.y"
    {(yyval.stm)=create_if_stmt((yyvsp[(2) - (7)].exp), (yyvsp[(4) - (7)].stm_l), (yyvsp[(6) - (7)].stm_l));}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 154 "grammatic.y"
    {(yyval.stm)=create_if_stmt((yyvsp[(2) - (5)].exp), (yyvsp[(4) - (5)].stm_l), NULL);}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 155 "grammatic.y"
    {(yyval.stm)=create_if_stmt((yyvsp[(2) - (7)].exp), (yyvsp[(4) - (7)].stm_l), (yyvsp[(6) - (7)].stm_l));}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 158 "grammatic.y"
    {(yyval.stm)=create_for_stmt((yyvsp[(2) - (7)].exp),(yyvsp[(4) - (7)].exp), (yyvsp[(6) - (7)].stm_l));}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 159 "grammatic.y"
    {(yyval.stm)=create_for_stmt((yyvsp[(2) - (7)].exp),(yyvsp[(4) - (7)].exp), (yyvsp[(6) - (7)].stm_l));}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 162 "grammatic.y"
    {(yyval.stm)=create_while_stmt((yyvsp[(2) - (5)].exp),(yyvsp[(4) - (5)].stm_l));}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 163 "grammatic.y"
    {(yyval.stm)=create_while_stmt((yyvsp[(2) - (5)].exp),(yyvsp[(4) - (5)].stm_l));}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 166 "grammatic.y"
    {(yyval.stm)=create_until_stmt((yyvsp[(2) - (5)].exp),(yyvsp[(4) - (5)].stm_l));}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 167 "grammatic.y"
    {(yyval.stm)=create_until_stmt((yyvsp[(2) - (5)].exp),(yyvsp[(4) - (5)].stm_l));}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 170 "grammatic.y"
    {(yyval.exp_l)=add_to_expr_list((yyvsp[(1) - (3)].exp_l),(yyvsp[(3) - (3)].exp));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 171 "grammatic.y"
    {(yyval.exp_l)=create_expr_list((yyvsp[(1) - (1)].exp));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 174 "grammatic.y"
    {(yyval.stm) = create_def_stmt((yyvsp[(2) - (5)].var),NULL,(yyvsp[(4) - (5)].stm_l));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 175 "grammatic.y"
    {(yyval.stm) = create_def_stmt((yyvsp[(2) - (8)].var),(yyvsp[(4) - (8)].id_l),(yyvsp[(7) - (8)].stm_l));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 178 "grammatic.y"
    {(yyval.stm) = create_class_stmt((yyvsp[(2) - (5)].var), NULL, (yyvsp[(4) - (5)].stm_l));}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 179 "grammatic.y"
    {(yyval.stm) = create_class_stmt((yyvsp[(2) - (7)].var), (yyvsp[(4) - (7)].var), (yyvsp[(6) - (7)].stm_l));}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 182 "grammatic.y"
    {(yyval.id_l)=(yyvsp[(1) - (1)].id_l);}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 183 "grammatic.y"
    {(yyval.id_l)=NULL;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 185 "grammatic.y"
    {(yyval.id_l) = add_to_id_list((yyvsp[(1) - (3)].id_l),(yyvsp[(3) - (3)].var));}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 186 "grammatic.y"
    {(yyval.id_l) = create_id_list((yyvsp[(1) - (1)].var));}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 189 "grammatic.y"
    {(yyval.exp) = create_expr(Const);}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 190 "grammatic.y"
    {(yyval.exp) = create_expr(Id);}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 191 "grammatic.y"
    {(yyval.exp) = create_expr(String);}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 192 "grammatic.y"
    {(yyval.exp) = create_expr(Int);}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 193 "grammatic.y"
    {(yyval.exp) = create_expr(Float);}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 194 "grammatic.y"
    {(yyval.exp) = create_expr(Bool);}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 195 "grammatic.y"
    {(yyval.exp) = create_expr(Nil);}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 196 "grammatic.y"
    {(yyval.exp) = create_expr(Self);}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 197 "grammatic.y"
    {(yyval.exp) = create_two_expr(Plus,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 198 "grammatic.y"
    {(yyval.exp) = create_two_expr(Minus,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 199 "grammatic.y"
    {(yyval.exp) = create_two_expr(Multiply,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 200 "grammatic.y"
    {(yyval.exp) = create_two_expr(Division,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 201 "grammatic.y"
    {(yyval.exp) = create_two_expr(Less,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 202 "grammatic.y"
    {(yyval.exp) = create_two_expr(More,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 203 "grammatic.y"
    {(yyval.exp) = create_two_expr(Assign,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 204 "grammatic.y"
    {(yyval.exp) = create_two_expr(LessEq,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 205 "grammatic.y"
    {(yyval.exp) = create_two_expr(MoreEq,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 206 "grammatic.y"
    {(yyval.exp) = create_two_expr(Equivalent,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 207 "grammatic.y"
    {(yyval.exp) = create_two_expr(NotEquivalent,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 208 "grammatic.y"
    {(yyval.exp) = create_two_expr(LessMore,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 209 "grammatic.y"
    {(yyval.exp) = create_two_expr(AndWord,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 210 "grammatic.y"
    {(yyval.exp) = create_two_expr(OrWord,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 211 "grammatic.y"
    {(yyval.exp) = create_one_expr(NotWord, (yyvsp[(2) - (2)].exp));;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 212 "grammatic.y"
    {(yyval.exp) = create_two_expr(Or,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 213 "grammatic.y"
    {(yyval.exp) = create_two_expr(And,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 214 "grammatic.y"
    {(yyval.exp) = create_one_expr(Not, (yyvsp[(2) - (2)].exp));;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 215 "grammatic.y"
    {(yyval.exp) = create_two_expr(Doublecolon,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 216 "grammatic.y"
    {(yyval.exp) = create_two_expr(AddAssign,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 217 "grammatic.y"
    {(yyval.exp) = create_two_expr(SubAssign,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 218 "grammatic.y"
    {(yyval.exp) = create_two_expr(MulAssign,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 219 "grammatic.y"
    {(yyval.exp) = create_two_expr(DivAssign,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 220 "grammatic.y"
    {(yyval.exp) = create_two_expr(TwoPoint,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 221 "grammatic.y"
    {(yyval.exp) = create_two_expr(ThreePoint,(yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 222 "grammatic.y"
    {(yyval.exp) = create_one_expr(Uminus, (yyvsp[(2) - (2)].exp));}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 223 "grammatic.y"
    {(yyval.exp) = create_one_expr(Uplus, (yyvsp[(2) - (2)].exp));}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 224 "grammatic.y"
    {(yyval.exp) = create_call_method((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].var), NULL);;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 225 "grammatic.y"
    {(yyval.exp) = create_call_method((yyvsp[(1) - (5)].exp), (yyvsp[(3) - (5)].var), NULL);;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 226 "grammatic.y"
    {(yyval.exp) = create_call_method((yyvsp[(1) - (6)].exp), (yyvsp[(3) - (6)].var), (yyvsp[(5) - (6)].exp_l));;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 227 "grammatic.y"
    {(yyval.exp) = create_call_method(NULL, (yyvsp[(1) - (3)].var), NULL);;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 228 "grammatic.y"
    {(yyval.exp) = create_call_method(NULL, (yyvsp[(1) - (4)].var), (yyvsp[(3) - (4)].exp_l));;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 229 "grammatic.y"
    {(yyval.exp) = create_super_expr(NULL);;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 230 "grammatic.y"
    {(yyval.exp) = create_super_expr(NULL);;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 231 "grammatic.y"
    {(yyval.exp) = create_super_expr((yyvsp[(3) - (4)].exp_l));;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 232 "grammatic.y"
    {(yyval.exp)=(yyvsp[(1) - (1)].exp);;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 233 "grammatic.y"
    {(yyval.exp) = create_call_array_expr((yyvsp[(1) - (4)].exp),(yyvsp[(3) - (4)].exp));;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 236 "grammatic.y"
    {(yyval.exp) = create_array((yyvsp[(2) - (3)].exp_l));;}
    break;



/* Line 1455 of yacc.c  */
#line 2492 "grammatic.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
		      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 238 "grammatic.y"


