
/*  A Bison parser, made from grammatic.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	CLASS	258
#define	NIL	259
#define	SELF	260
#define	DEF	261
#define	BOOL	262
#define	SUPER	263
#define	WHILE	264
#define	FOR	265
#define	THEN	266
#define	DO	267
#define	IF	268
#define	ELSE	269
#define	IN	270
#define	BREAK	271
#define	END	272
#define	RETURN	273
#define	UNTIL	274
#define	CONST	275
#define	ID	276
#define	NL	277
#define	PUBLIC	278
#define	PRIVATE	279
#define	PROTECTED	280
#define	INT	281
#define	FLOAT	282
#define	STRING	283
#define	ANDWORD	284
#define	ORWORD	285
#define	NOTWORD	286
#define	ADDASSIGN	287
#define	SUBASSIGN	288
#define	MULASSIGN	289
#define	DIVASSIGN	290
#define	TWOPOINT	291
#define	THREEPOINT	292
#define	OR	293
#define	AND	294
#define	LESSEQ	295
#define	MOREEQ	296
#define	EQ	297
#define	NEQ	298
#define	LESSMORE	299
#define	UPLUS	300
#define	NOT	301
#define	UMINUS	302
#define	DOUBLECOLON	303

#line 1 "grammatic.y"


#include <stdio.h>
#include <malloc.h>
#include "grammatic_struct.h"
#include "grammatic_func.h"
extern int yylex(void);

struct Program *prg;


#line 12 "grammatic.y"
typedef union {
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
} YYSTYPE;

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		223
#define	YYFLAG		-32768
#define	YYNTBASE	63

#define YYTRANSLATE(x) ((unsigned)(x) <= 303 ? yytranslate[x] : 83)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    62,
    59,    43,    42,    61,    41,    57,    44,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    60,     2,    46,
    32,    45,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    55,     2,    56,     2,     2,     2,     2,     2,     2,     2,
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
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    33,    34,    35,    36,
    37,    38,    39,    40,    47,    48,    49,    50,    51,    52,
    53,    54,    58
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     5,     7,    10,    13,    15,    18,    21,
    24,    27,    31,    34,    37,    40,    43,    45,    48,    51,
    54,    57,    61,    64,    66,    69,    71,    72,    74,    77,
    80,    85,    90,    95,    99,   103,   107,   109,   112,   118,
   126,   132,   140,   148,   156,   162,   168,   174,   180,   184,
   186,   192,   201,   207,   215,   217,   218,   222,   224,   226,
   228,   230,   232,   234,   236,   238,   240,   244,   248,   252,
   256,   260,   264,   268,   272,   276,   280,   284,   288,   292,
   296,   299,   303,   307,   310,   314,   318,   322,   326,   330,
   334,   338,   341,   344,   348,   354,   361,   365,   370,   372,
   376,   381,   383,   388
};

static const short yyrhs[] = {    64,
     0,    65,     0,     0,    66,     0,    65,    66,     0,    81,
    22,     0,    22,     0,    72,    22,     0,    73,    22,     0,
    74,    22,     0,    75,    22,     0,    18,    81,    22,     0,
    16,    22,     0,    78,    22,     0,    77,    22,     0,    81,
    22,     0,    22,     0,    72,    22,     0,    73,    22,     0,
    74,    22,     0,    75,    22,     0,    18,    81,    22,     0,
    16,    22,     0,    67,     0,    68,    67,     0,    68,     0,
     0,    22,     0,    21,    22,     0,    77,    22,     0,    23,
    60,    21,    22,     0,    24,    60,    21,    22,     0,    25,
    60,    21,    22,     0,    23,    77,    22,     0,    24,    77,
    22,     0,    25,    77,    22,     0,    70,     0,    71,    70,
     0,    13,    81,    11,    68,    17,     0,    13,    81,    11,
    68,    14,    68,    17,     0,    13,    81,    22,    68,    17,
     0,    13,    81,    22,    68,    14,    68,    17,     0,    10,
    81,    15,    81,    12,    68,    17,     0,    10,    81,    15,
    81,    22,    68,    17,     0,     9,    81,    12,    68,    17,
     0,     9,    81,    22,    68,    17,     0,    19,    81,    12,
    68,    17,     0,    19,    81,    22,    68,    17,     0,    76,
    61,    81,     0,    81,     0,     6,    21,    22,    69,    17,
     0,     6,    21,    62,    79,    59,    22,    69,    17,     0,
     3,    20,    22,    71,    17,     0,     3,    20,    46,    20,
    22,    71,    17,     0,    80,     0,     0,    80,    61,    21,
     0,    21,     0,    20,     0,    21,     0,    28,     0,    26,
     0,    27,     0,     7,     0,     4,     0,     5,     0,    81,
    42,    81,     0,    81,    41,    81,     0,    81,    43,    81,
     0,    81,    44,    81,     0,    81,    46,    81,     0,    81,
    45,    81,     0,    81,    32,    81,     0,    81,    47,    81,
     0,    81,    48,    81,     0,    81,    49,    81,     0,    81,
    50,    81,     0,    81,    51,    81,     0,    81,    29,    81,
     0,    81,    30,    81,     0,    31,    81,     0,    81,    39,
    81,     0,    81,    40,    81,     0,    53,    81,     0,    81,
    58,    81,     0,    81,    33,    81,     0,    81,    34,    81,
     0,    81,    35,    81,     0,    81,    36,    81,     0,    81,
    37,    81,     0,    81,    38,    81,     0,    41,    81,     0,
    42,    81,     0,    81,    57,    21,     0,    81,    57,    21,
    62,    59,     0,    81,    57,    21,    62,    76,    59,     0,
    21,    62,    59,     0,    21,    62,    76,    59,     0,     8,
     0,     8,    62,    59,     0,     8,    62,    76,    59,     0,
    82,     0,    81,    55,    81,    56,     0,    55,    76,    56,
     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    96,    99,   100,   103,   104,   107,   108,   109,   110,   111,
   112,   113,   114,   115,   116,   118,   119,   120,   121,   122,
   123,   124,   125,   128,   129,   132,   133,   136,   137,   138,
   139,   140,   141,   142,   143,   144,   147,   148,   151,   152,
   153,   154,   157,   158,   161,   162,   165,   166,   169,   170,
   173,   174,   177,   178,   181,   182,   184,   185,   188,   189,
   190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
   200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
   210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
   220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
   230,   231,   232,   235
};

static const char * const yytname[] = {   "$","error","$undefined.","CLASS",
"NIL","SELF","DEF","BOOL","SUPER","WHILE","FOR","THEN","DO","IF","ELSE","IN",
"BREAK","END","RETURN","UNTIL","CONST","ID","NL","PUBLIC","PRIVATE","PROTECTED",
"INT","FLOAT","STRING","ANDWORD","ORWORD","NOTWORD","'='","ADDASSIGN","SUBASSIGN",
"MULASSIGN","DIVASSIGN","TWOPOINT","THREEPOINT","OR","AND","'-'","'+'","'*'",
"'/'","'>'","'<'","LESSEQ","MOREEQ","EQ","NEQ","LESSMORE","UPLUS","NOT","UMINUS",
"'['","']'","'.'","DOUBLECOLON","')'","':'","','","'('","program","stmt_list",
"stmt_list_ne","stmt","method_member","method_members_ne","method_members","class_member",
"class_member_list","if_stmt","for_stmt","while_stmt","until_stmt","expr_list",
"def_stmt","class_stmt","id_listE","id_list","expr","init_array_expr",""
};
#endif

static const short yyr1[] = {     0,
    63,    64,    64,    65,    65,    66,    66,    66,    66,    66,
    66,    66,    66,    66,    66,    67,    67,    67,    67,    67,
    67,    67,    67,    68,    68,    69,    69,    70,    70,    70,
    70,    70,    70,    70,    70,    70,    71,    71,    72,    72,
    72,    72,    73,    73,    74,    74,    75,    75,    76,    76,
    77,    77,    78,    78,    79,    79,    80,    80,    81,    81,
    81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
    81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
    81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
    81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
    81,    81,    81,    82
};

static const short yyr2[] = {     0,
     1,     1,     0,     1,     2,     2,     1,     2,     2,     2,
     2,     3,     2,     2,     2,     2,     1,     2,     2,     2,
     2,     3,     2,     1,     2,     1,     0,     1,     2,     2,
     4,     4,     4,     3,     3,     3,     1,     2,     5,     7,
     5,     7,     7,     7,     5,     5,     5,     5,     3,     1,
     5,     8,     5,     7,     1,     0,     3,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     2,     3,     3,     2,     3,     3,     3,     3,     3,     3,
     3,     2,     2,     3,     5,     6,     3,     4,     1,     3,
     4,     1,     4,     3
};

static const short yydefact[] = {     3,
     0,    65,    66,     0,    64,    99,     0,     0,     0,     0,
     0,     0,    59,    60,     7,    62,    63,    61,     0,     0,
     0,     0,     0,     1,     2,     4,     0,     0,     0,     0,
     0,     0,     0,   102,     0,     0,     0,     0,     0,     0,
    13,     0,     0,     0,    81,    92,    93,    84,     0,    50,
     5,     8,     9,    10,    11,    15,    14,     6,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    27,    56,   100,     0,     0,
     0,     0,     0,     0,    12,     0,     0,    97,     0,   104,
     0,    79,    80,    73,    86,    87,    88,    89,    90,    91,
    82,    83,    68,    67,    69,    70,    72,    71,    74,    75,
    76,    77,    78,     0,    94,    85,     0,    28,     0,     0,
     0,    37,     0,     0,     0,     0,     0,    17,    24,    26,
     0,     0,     0,     0,     0,     0,    58,     0,    55,   101,
     0,     0,     0,     0,     0,     0,     0,    98,    49,   103,
     0,    29,     0,     0,     0,     0,     0,     0,    53,    38,
    30,     0,    23,     0,    25,    51,    18,    19,    20,    21,
    16,     0,     0,    45,    46,     0,     0,     0,    39,     0,
    41,    47,    48,    95,     0,     0,    34,     0,    35,     0,
    36,     0,    22,    27,    57,     0,     0,     0,     0,    96,
    31,    32,    33,    54,     0,    43,    44,    40,    42,    52,
     0,     0,     0
};

static const short yydefgoto[] = {   221,
    24,    25,    26,   139,   140,   141,   132,   133,   142,   143,
   144,   145,    49,   134,    32,   148,   149,   146,    34
};

static const short yypact[] = {   202,
   -14,-32768,-32768,    -3,-32768,   -38,   562,   562,   562,     5,
   562,   562,-32768,   -16,-32768,-32768,-32768,-32768,   562,   562,
   562,   562,   562,-32768,   202,-32768,    27,    32,    33,    64,
    67,    68,   776,-32768,    11,   -17,    92,   629,   746,   589,
-32768,   806,   669,   136,   953,    30,    30,    30,   -18,   926,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   562,   562,
   562,   562,   562,   562,   562,   562,   562,   562,   562,   562,
   562,   562,   562,   562,   562,   562,   562,   562,   562,   562,
   562,    73,   562,    85,    78,   532,    90,-32768,    34,   532,
   532,   562,   532,   532,-32768,   532,   532,-32768,    55,-32768,
   562,   953,   953,   953,   953,   953,   953,   953,   973,   973,
   991,   991,  1007,  1007,  1021,  1021,   599,   599,   599,   599,
    30,    30,    30,   896,    59,-32768,   100,-32768,    -4,    -2,
    24,-32768,   555,   107,   113,   114,   562,-32768,-32768,   532,
   121,   117,   120,   124,   126,   836,-32768,    95,    94,-32768,
   292,   322,   709,   232,   262,   352,   382,-32768,   926,-32768,
   145,-32768,   137,   138,   147,   148,   153,   157,-32768,-32768,
-32768,    85,-32768,   866,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   158,   154,-32768,-32768,   532,   532,   532,-32768,   532,
-32768,-32768,-32768,-32768,    56,   159,-32768,   160,-32768,   161,
-32768,   585,-32768,   532,-32768,   412,   442,   472,   502,-32768,
-32768,-32768,-32768,-32768,   142,-32768,-32768,-32768,-32768,-32768,
   169,   184,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,   163,  -104,   -62,   -19,  -120,    18,    14,    15,
    16,    17,   -34,     1,-32768,-32768,-32768,     0,-32768
};


#define	YYLAST		1079


static const short yytable[] = {    33,
    31,     4,    89,     4,    86,    35,    38,    39,    40,    99,
    42,    43,   170,    27,    28,    29,    30,    36,    45,    46,
    47,    48,    50,    37,    33,    31,    41,   151,   152,     4,
   154,   155,    84,   156,   157,   175,    50,   100,    27,    28,
    29,    30,   101,    50,    87,    44,   175,   175,    52,   175,
   175,   175,   175,    53,    54,   163,    85,   165,   102,   103,
   104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
   114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
   124,   170,   126,   167,    81,    55,    82,    83,    56,    57,
     4,   153,   150,   125,   101,     2,     3,   135,     5,     6,
   159,   175,   175,   175,   175,   127,   128,   129,   130,   131,
   147,    13,    14,   158,   210,   101,   101,    16,    17,    18,
   161,   162,    19,   206,   207,   208,   195,   209,   171,   164,
   166,   168,    20,    21,   172,   173,   174,   176,   177,     2,
     3,   178,     5,     6,    22,   179,    23,   180,     2,     3,
    88,     5,     6,   182,   183,    13,    14,   196,   220,   197,
    50,    16,    17,    18,    13,    14,    19,   198,   222,   199,
    16,    17,    18,   200,   205,    19,    20,    21,   201,   204,
   211,   212,   213,   223,   215,    20,    21,    51,    22,   202,
    23,     0,     0,     0,    98,     0,     0,    22,     0,    23,
     0,     0,     0,   194,     1,     2,     3,     4,     5,     6,
     7,     8,     0,     0,     9,     0,     0,    10,     0,    11,
    12,    13,    14,    15,     0,     0,     0,    16,    17,    18,
     0,     0,    19,     0,     0,     2,     3,     0,     5,     6,
     7,     8,    20,    21,     9,   188,     0,   136,   189,   137,
    12,    13,    14,   138,    22,     0,    23,    16,    17,    18,
     0,     0,    19,     0,     0,     2,     3,     0,     5,     6,
     7,     8,    20,    21,     9,   190,     0,   136,   191,   137,
    12,    13,    14,   138,    22,     0,    23,    16,    17,    18,
     0,     0,    19,     0,     0,     2,     3,     0,     5,     6,
     7,     8,    20,    21,     9,     0,     0,   136,   184,   137,
    12,    13,    14,   138,    22,     0,    23,    16,    17,    18,
     0,     0,    19,     0,     0,     2,     3,     0,     5,     6,
     7,     8,    20,    21,     9,     0,     0,   136,   185,   137,
    12,    13,    14,   138,    22,     0,    23,    16,    17,    18,
     0,     0,    19,     0,     0,     2,     3,     0,     5,     6,
     7,     8,    20,    21,     9,     0,     0,   136,   192,   137,
    12,    13,    14,   138,    22,     0,    23,    16,    17,    18,
     0,     0,    19,     0,     0,     2,     3,     0,     5,     6,
     7,     8,    20,    21,     9,     0,     0,   136,   193,   137,
    12,    13,    14,   138,    22,     0,    23,    16,    17,    18,
     0,     0,    19,     0,     0,     2,     3,     0,     5,     6,
     7,     8,    20,    21,     9,     0,     0,   136,   216,   137,
    12,    13,    14,   138,    22,     0,    23,    16,    17,    18,
     0,     0,    19,     0,     0,     2,     3,     0,     5,     6,
     7,     8,    20,    21,     9,     0,     0,   136,   217,   137,
    12,    13,    14,   138,    22,     0,    23,    16,    17,    18,
     0,     0,    19,     0,     0,     2,     3,     0,     5,     6,
     7,     8,    20,    21,     9,     0,     0,   136,   218,   137,
    12,    13,    14,   138,    22,     0,    23,    16,    17,    18,
     0,     0,    19,     0,     0,     2,     3,     0,     5,     6,
     7,     8,    20,    21,     9,     0,     0,   136,   219,   137,
    12,    13,    14,   138,    22,     0,    23,    16,    17,    18,
     0,     0,    19,     0,     0,     2,     3,     0,     5,     6,
     7,     8,    20,    21,     9,     0,     0,   136,     0,   137,
    12,    13,    14,   138,    22,     0,    23,    16,    17,    18,
     4,     0,    19,     0,     0,     2,     3,     0,     5,     6,
     0,   169,    20,    21,     0,   127,   128,   129,   130,   131,
     0,    13,    14,     0,    22,     0,    23,    16,    17,    18,
     4,     0,    19,     0,     0,     0,     0,     0,     0,    93,
     0,   214,    20,    21,     0,   127,   128,   129,   130,   131,
    94,     0,     0,     0,    22,     0,    23,    59,    60,     0,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    90,     0,     0,    81,     0,    82,    83,    78,    79,    80,
    91,     0,     0,    81,     0,    82,    83,    59,    60,     0,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    96,     0,     0,    81,     0,    82,    83,     0,     0,     0,
    97,     0,     0,     0,     0,     0,     0,    59,    60,     0,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
   186,     0,     0,    81,     0,    82,    83,     0,     0,     0,
   187,     0,     0,     0,     0,     0,     0,    59,    60,     0,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    92,     0,     0,    81,     0,    82,    83,     0,     0,     0,
     0,     0,     0,     0,    59,    60,     0,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    58,     0,     0,
    81,     0,    82,    83,    59,    60,     0,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    95,     0,     0,
    81,     0,    82,    83,    59,    60,     0,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,   181,     0,     0,
    81,     0,    82,    83,    59,    60,     0,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,   203,     0,     0,
    81,     0,    82,    83,    59,    60,     0,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,     0,     0,     0,
    81,     0,    82,    83,    59,    60,     0,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,     0,     0,     0,
    81,   160,    82,    83,    59,    60,     0,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,     0,     0,     0,
    81,     0,    82,    83,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
    77,    78,    79,    80,     0,     0,     0,    81,     0,    82,
    83,    68,    69,    70,    71,    72,    73,    74,    75,    76,
    77,    78,    79,    80,     0,     0,     0,    81,     0,    82,
    83,    70,    71,    72,    73,    74,    75,    76,    77,    78,
    79,    80,     0,     0,     0,    81,     0,    82,    83,    72,
    73,    74,    75,    76,    77,    78,    79,    80,     0,     0,
     0,    81,     0,    82,    83,    74,    75,    76,    77,    78,
    79,    80,     0,     0,     0,    81,     0,    82,    83
};

static const short yycheck[] = {     0,
     0,     6,    37,     6,    22,    20,     7,     8,     9,    44,
    11,    12,   133,     0,     0,     0,     0,    21,    19,    20,
    21,    22,    23,    62,    25,    25,    22,    90,    91,     6,
    93,    94,    22,    96,    97,   140,    37,    56,    25,    25,
    25,    25,    61,    44,    62,    62,   151,   152,    22,   154,
   155,   156,   157,    22,    22,    60,    46,    60,    59,    60,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,   202,    83,    60,    55,    22,    57,    58,    22,    22,
     6,    92,    59,    21,    61,     4,     5,    20,     7,     8,
   101,   206,   207,   208,   209,    21,    22,    23,    24,    25,
    21,    20,    21,    59,    59,    61,    61,    26,    27,    28,
    62,    22,    31,   186,   187,   188,   161,   190,    22,   129,
   130,   131,    41,    42,    22,    22,   137,    17,    22,     4,
     5,    22,     7,     8,    53,    22,    55,    22,     4,     5,
    59,     7,     8,    59,    61,    20,    21,    21,    17,    22,
   161,    26,    27,    28,    20,    21,    31,    21,     0,    22,
    26,    27,    28,    21,    21,    31,    41,    42,    22,    22,
    22,    22,    22,     0,   204,    41,    42,    25,    53,   172,
    55,    -1,    -1,    -1,    59,    -1,    -1,    53,    -1,    55,
    -1,    -1,    -1,    59,     3,     4,     5,     6,     7,     8,
     9,    10,    -1,    -1,    13,    -1,    -1,    16,    -1,    18,
    19,    20,    21,    22,    -1,    -1,    -1,    26,    27,    28,
    -1,    -1,    31,    -1,    -1,     4,     5,    -1,     7,     8,
     9,    10,    41,    42,    13,    14,    -1,    16,    17,    18,
    19,    20,    21,    22,    53,    -1,    55,    26,    27,    28,
    -1,    -1,    31,    -1,    -1,     4,     5,    -1,     7,     8,
     9,    10,    41,    42,    13,    14,    -1,    16,    17,    18,
    19,    20,    21,    22,    53,    -1,    55,    26,    27,    28,
    -1,    -1,    31,    -1,    -1,     4,     5,    -1,     7,     8,
     9,    10,    41,    42,    13,    -1,    -1,    16,    17,    18,
    19,    20,    21,    22,    53,    -1,    55,    26,    27,    28,
    -1,    -1,    31,    -1,    -1,     4,     5,    -1,     7,     8,
     9,    10,    41,    42,    13,    -1,    -1,    16,    17,    18,
    19,    20,    21,    22,    53,    -1,    55,    26,    27,    28,
    -1,    -1,    31,    -1,    -1,     4,     5,    -1,     7,     8,
     9,    10,    41,    42,    13,    -1,    -1,    16,    17,    18,
    19,    20,    21,    22,    53,    -1,    55,    26,    27,    28,
    -1,    -1,    31,    -1,    -1,     4,     5,    -1,     7,     8,
     9,    10,    41,    42,    13,    -1,    -1,    16,    17,    18,
    19,    20,    21,    22,    53,    -1,    55,    26,    27,    28,
    -1,    -1,    31,    -1,    -1,     4,     5,    -1,     7,     8,
     9,    10,    41,    42,    13,    -1,    -1,    16,    17,    18,
    19,    20,    21,    22,    53,    -1,    55,    26,    27,    28,
    -1,    -1,    31,    -1,    -1,     4,     5,    -1,     7,     8,
     9,    10,    41,    42,    13,    -1,    -1,    16,    17,    18,
    19,    20,    21,    22,    53,    -1,    55,    26,    27,    28,
    -1,    -1,    31,    -1,    -1,     4,     5,    -1,     7,     8,
     9,    10,    41,    42,    13,    -1,    -1,    16,    17,    18,
    19,    20,    21,    22,    53,    -1,    55,    26,    27,    28,
    -1,    -1,    31,    -1,    -1,     4,     5,    -1,     7,     8,
     9,    10,    41,    42,    13,    -1,    -1,    16,    17,    18,
    19,    20,    21,    22,    53,    -1,    55,    26,    27,    28,
    -1,    -1,    31,    -1,    -1,     4,     5,    -1,     7,     8,
     9,    10,    41,    42,    13,    -1,    -1,    16,    -1,    18,
    19,    20,    21,    22,    53,    -1,    55,    26,    27,    28,
     6,    -1,    31,    -1,    -1,     4,     5,    -1,     7,     8,
    -1,    17,    41,    42,    -1,    21,    22,    23,    24,    25,
    -1,    20,    21,    -1,    53,    -1,    55,    26,    27,    28,
     6,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    11,
    -1,    17,    41,    42,    -1,    21,    22,    23,    24,    25,
    22,    -1,    -1,    -1,    53,    -1,    55,    29,    30,    -1,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    12,    -1,    -1,    55,    -1,    57,    58,    49,    50,    51,
    22,    -1,    -1,    55,    -1,    57,    58,    29,    30,    -1,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    12,    -1,    -1,    55,    -1,    57,    58,    -1,    -1,    -1,
    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    12,    -1,    -1,    55,    -1,    57,    58,    -1,    -1,    -1,
    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    15,    -1,    -1,    55,    -1,    57,    58,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    29,    30,    -1,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    22,    -1,    -1,
    55,    -1,    57,    58,    29,    30,    -1,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    22,    -1,    -1,
    55,    -1,    57,    58,    29,    30,    -1,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    22,    -1,    -1,
    55,    -1,    57,    58,    29,    30,    -1,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    22,    -1,    -1,
    55,    -1,    57,    58,    29,    30,    -1,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    -1,    -1,    -1,
    55,    -1,    57,    58,    29,    30,    -1,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    -1,    -1,    -1,
    55,    56,    57,    58,    29,    30,    -1,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    -1,    -1,    -1,
    55,    -1,    57,    58,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
    48,    49,    50,    51,    -1,    -1,    -1,    55,    -1,    57,
    58,    39,    40,    41,    42,    43,    44,    45,    46,    47,
    48,    49,    50,    51,    -1,    -1,    -1,    55,    -1,    57,
    58,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    51,    -1,    -1,    -1,    55,    -1,    57,    58,    43,
    44,    45,    46,    47,    48,    49,    50,    51,    -1,    -1,
    -1,    55,    -1,    57,    58,    45,    46,    47,    48,    49,
    50,    51,    -1,    -1,    -1,    55,    -1,    57,    58
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 96 "grammatic.y"
{yyval.prg = prg = create_program(yyvsp[0].stm_l);
    break;}
case 2:
#line 99 "grammatic.y"
{yyval.stm_l=yyvsp[0].stm_l;
    break;}
case 3:
#line 100 "grammatic.y"
{yyval.stm_l=NULL;
    break;}
case 4:
#line 103 "grammatic.y"
{yyval.stm_l = create_stmt_list(yyvsp[0].stm);
    break;}
case 5:
#line 104 "grammatic.y"
{yyval.stm_l = add_to_stmt_list(yyvsp[-1].stm_l,yyvsp[0].stm);
    break;}
case 6:
#line 107 "grammatic.y"
{yyval.stm = create_stmt(yyvsp[-1].exp);
    break;}
case 7:
#line 108 "grammatic.y"
{yyval.stm=NULL;
    break;}
case 8:
#line 109 "grammatic.y"
{yyval.stm=yyvsp[-1].stm;
    break;}
case 9:
#line 110 "grammatic.y"
{yyval.stm=yyvsp[-1].stm;
    break;}
case 10:
#line 111 "grammatic.y"
{yyval.stm=yyvsp[-1].stm;
    break;}
case 11:
#line 112 "grammatic.y"
{yyval.stm=yyvsp[-1].stm;
    break;}
case 12:
#line 113 "grammatic.y"
{yyval.stm = create_return_stmt(yyvsp[-1].exp);
    break;}
case 13:
#line 114 "grammatic.y"
{yyval.stm = create_break_stmt();
    break;}
case 14:
#line 115 "grammatic.y"
{yyval.stm=yyvsp[-1].stm;
    break;}
case 15:
#line 116 "grammatic.y"
{yyval.stm=yyvsp[-1].stm;
    break;}
case 16:
#line 118 "grammatic.y"
{yyval.stm = create_stmt(yyvsp[-1].exp);
    break;}
case 17:
#line 119 "grammatic.y"
{yyval.stm=NULL;
    break;}
case 18:
#line 120 "grammatic.y"
{yyval.stm=yyvsp[-1].stm;
    break;}
case 19:
#line 121 "grammatic.y"
{yyval.stm=yyvsp[-1].stm;
    break;}
case 20:
#line 122 "grammatic.y"
{yyval.stm=yyvsp[-1].stm;
    break;}
case 21:
#line 123 "grammatic.y"
{yyval.stm=yyvsp[-1].stm;
    break;}
case 22:
#line 124 "grammatic.y"
{yyval.stm = create_return_stmt(yyvsp[-1].exp);
    break;}
case 23:
#line 125 "grammatic.y"
{yyval.stm = create_break_stmt();
    break;}
case 24:
#line 128 "grammatic.y"
{yyval.stm_l = create_stmt_list(yyvsp[0].stm);
    break;}
case 25:
#line 129 "grammatic.y"
{yyval.stm_l = add_to_stmt_list(yyvsp[-1].stm_l,yyvsp[0].stm);
    break;}
case 26:
#line 132 "grammatic.y"
{yyval.stm_l=yyvsp[0].stm_l;
    break;}
case 27:
#line 133 "grammatic.y"
{yyval.stm_l=NULL;
    break;}
case 28:
#line 136 "grammatic.y"
{yyval.stm=NULL;
    break;}
case 29:
#line 137 "grammatic.y"
{yyval.stm = create_access_rule(Public,yyvsp[-1].var,NULL);
    break;}
case 30:
#line 138 "grammatic.y"
{yyval.stm = create_access_rule(Public,NULL,yyvsp[-1].stm);
    break;}
case 31:
#line 139 "grammatic.y"
{yyval.stm = create_access_rule(Public,yyvsp[-1].var,NULL);
    break;}
case 32:
#line 140 "grammatic.y"
{yyval.stm = create_access_rule(Private,yyvsp[-1].var,NULL);
    break;}
case 33:
#line 141 "grammatic.y"
{yyval.stm = create_access_rule(Protected,yyvsp[-1].var,NULL);
    break;}
case 34:
#line 142 "grammatic.y"
{yyval.stm = create_access_rule(Public,NULL,yyvsp[-1].stm);
    break;}
case 35:
#line 143 "grammatic.y"
{yyval.stm = create_access_rule(Private,NULL,yyvsp[-1].stm);
    break;}
case 36:
#line 144 "grammatic.y"
{yyval.stm = create_access_rule(Protected,NULL,yyvsp[-1].stm);
    break;}
case 37:
#line 147 "grammatic.y"
{yyval.stm_l=create_stmt_list(yyvsp[0].stm);
    break;}
case 38:
#line 148 "grammatic.y"
{yyval.stm_l=add_to_stmt_list(yyvsp[-1].stm_l,yyvsp[0].stm);
    break;}
case 39:
#line 151 "grammatic.y"
{yyval.stm=create_if_stmt(yyvsp[-3].exp, yyvsp[-1].stm_l, NULL);
    break;}
case 40:
#line 152 "grammatic.y"
{yyval.stm=create_if_stmt(yyvsp[-5].exp, yyvsp[-3].stm_l, yyvsp[-1].stm_l);
    break;}
case 41:
#line 153 "grammatic.y"
{yyval.stm=create_if_stmt(yyvsp[-3].exp, yyvsp[-1].stm_l, NULL);
    break;}
case 42:
#line 154 "grammatic.y"
{yyval.stm=create_if_stmt(yyvsp[-5].exp, yyvsp[-3].stm_l, yyvsp[-1].stm_l);
    break;}
case 43:
#line 157 "grammatic.y"
{yyval.stm=create_for_stmt(yyvsp[-5].exp,yyvsp[-3].exp, yyvsp[-1].stm_l);
    break;}
case 44:
#line 158 "grammatic.y"
{yyval.stm=create_for_stmt(yyvsp[-5].exp,yyvsp[-3].exp, yyvsp[-1].stm_l);
    break;}
case 45:
#line 161 "grammatic.y"
{yyval.stm=create_while_stmt(yyvsp[-3].exp,yyvsp[-1].stm_l);
    break;}
case 46:
#line 162 "grammatic.y"
{yyval.stm=create_while_stmt(yyvsp[-3].exp,yyvsp[-1].stm_l);
    break;}
case 47:
#line 165 "grammatic.y"
{yyval.stm=create_until_stmt(yyvsp[-3].exp,yyvsp[-1].stm_l);
    break;}
case 48:
#line 166 "grammatic.y"
{yyval.stm=create_until_stmt(yyvsp[-3].exp,yyvsp[-1].stm_l);
    break;}
case 49:
#line 169 "grammatic.y"
{yyval.exp_l=add_to_expr_list(yyvsp[-2].exp_l,yyvsp[0].exp);;
    break;}
case 50:
#line 170 "grammatic.y"
{yyval.exp_l=create_expr_list(yyvsp[0].exp);;
    break;}
case 51:
#line 173 "grammatic.y"
{yyval.stm = create_def_stmt(yyvsp[-3].var,NULL,yyvsp[-1].stm_l);;
    break;}
case 52:
#line 174 "grammatic.y"
{yyval.stm = create_def_stmt(yyvsp[-6].var,yyvsp[-4].id_l,yyvsp[-1].stm_l);;
    break;}
case 53:
#line 177 "grammatic.y"
{yyval.stm = create_class_stmt(yyvsp[-3].var, NULL, yyvsp[-1].stm_l);
    break;}
case 54:
#line 178 "grammatic.y"
{yyval.stm = create_class_stmt(yyvsp[-5].var, yyvsp[-3].var, yyvsp[-1].stm_l);
    break;}
case 55:
#line 181 "grammatic.y"
{yyval.id_l=yyvsp[0].id_l;
    break;}
case 56:
#line 182 "grammatic.y"
{yyval.id_l=NULL;
    break;}
case 57:
#line 184 "grammatic.y"
{yyval.id_l = add_to_id_list(yyvsp[-2].id_l,yyvsp[0].var);
    break;}
case 58:
#line 185 "grammatic.y"
{yyval.id_l = create_id_list(yyvsp[0].var);
    break;}
case 59:
#line 188 "grammatic.y"
{yyval.exp = create_expr(Const);
    break;}
case 60:
#line 189 "grammatic.y"
{yyval.exp = create_expr(Id);
    break;}
case 61:
#line 190 "grammatic.y"
{yyval.exp = create_expr(String);
    break;}
case 62:
#line 191 "grammatic.y"
{yyval.exp = create_expr(Int);
    break;}
case 63:
#line 192 "grammatic.y"
{yyval.exp = create_expr(Float);
    break;}
case 64:
#line 193 "grammatic.y"
{yyval.exp = create_expr(Bool);
    break;}
case 65:
#line 194 "grammatic.y"
{yyval.exp = create_expr(Nil);
    break;}
case 66:
#line 195 "grammatic.y"
{yyval.exp = create_expr(Self);
    break;}
case 67:
#line 196 "grammatic.y"
{yyval.exp = create_two_expr(Plus,yyvsp[-2].exp,yyvsp[0].exp);
    break;}
case 68:
#line 197 "grammatic.y"
{yyval.exp = create_two_expr(Minus,yyvsp[-2].exp,yyvsp[0].exp);
    break;}
case 69:
#line 198 "grammatic.y"
{yyval.exp = create_two_expr(Multiply,yyvsp[-2].exp,yyvsp[0].exp);
    break;}
case 70:
#line 199 "grammatic.y"
{yyval.exp = create_two_expr(Division,yyvsp[-2].exp,yyvsp[0].exp);
    break;}
case 71:
#line 200 "grammatic.y"
{yyval.exp = create_two_expr(Less,yyvsp[-2].exp,yyvsp[0].exp);
    break;}
case 72:
#line 201 "grammatic.y"
{yyval.exp = create_two_expr(More,yyvsp[-2].exp,yyvsp[0].exp);
    break;}
case 73:
#line 202 "grammatic.y"
{yyval.exp = create_two_expr(Assign,yyvsp[-2].exp,yyvsp[0].exp);
    break;}
case 74:
#line 203 "grammatic.y"
{yyval.exp = create_two_expr(LessEq,yyvsp[-2].exp,yyvsp[0].exp);;
    break;}
case 75:
#line 204 "grammatic.y"
{yyval.exp = create_two_expr(MoreEq,yyvsp[-2].exp,yyvsp[0].exp);;
    break;}
case 76:
#line 205 "grammatic.y"
{yyval.exp = create_two_expr(Equivalent,yyvsp[-2].exp,yyvsp[0].exp);;
    break;}
case 77:
#line 206 "grammatic.y"
{yyval.exp = create_two_expr(NotEquivalent,yyvsp[-2].exp,yyvsp[0].exp);;
    break;}
case 78:
#line 207 "grammatic.y"
{yyval.exp = create_two_expr(LessMore,yyvsp[-2].exp,yyvsp[0].exp);;
    break;}
case 79:
#line 208 "grammatic.y"
{yyval.exp = create_two_expr(AndWord,yyvsp[-2].exp,yyvsp[0].exp);
    break;}
case 80:
#line 209 "grammatic.y"
{yyval.exp = create_two_expr(OrWord,yyvsp[-2].exp,yyvsp[0].exp);
    break;}
case 81:
#line 210 "grammatic.y"
{yyval.exp = create_one_expr(NotWord, yyvsp[0].exp);;
    break;}
case 82:
#line 211 "grammatic.y"
{yyval.exp = create_two_expr(Or,yyvsp[-2].exp,yyvsp[0].exp);;
    break;}
case 83:
#line 212 "grammatic.y"
{yyval.exp = create_two_expr(And,yyvsp[-2].exp,yyvsp[0].exp);;
    break;}
case 84:
#line 213 "grammatic.y"
{yyval.exp = create_one_expr(Not, yyvsp[0].exp);;
    break;}
case 85:
#line 214 "grammatic.y"
{yyval.exp = create_two_expr(Doublecolon,yyvsp[-2].exp,yyvsp[0].exp);;
    break;}
case 86:
#line 215 "grammatic.y"
{yyval.exp = create_two_expr(AddAssign,yyvsp[-2].exp,yyvsp[0].exp);;
    break;}
case 87:
#line 216 "grammatic.y"
{yyval.exp = create_two_expr(SubAssign,yyvsp[-2].exp,yyvsp[0].exp);;
    break;}
case 88:
#line 217 "grammatic.y"
{yyval.exp = create_two_expr(MulAssign,yyvsp[-2].exp,yyvsp[0].exp);;
    break;}
case 89:
#line 218 "grammatic.y"
{yyval.exp = create_two_expr(DivAssign,yyvsp[-2].exp,yyvsp[0].exp);;
    break;}
case 90:
#line 219 "grammatic.y"
{yyval.exp = create_two_expr(TwoPoint,yyvsp[-2].exp,yyvsp[0].exp);;
    break;}
case 91:
#line 220 "grammatic.y"
{yyval.exp = create_two_expr(ThreePoint,yyvsp[-2].exp,yyvsp[0].exp);;
    break;}
case 92:
#line 221 "grammatic.y"
{yyval.exp = create_one_expr(Uminus, yyvsp[0].exp);
    break;}
case 93:
#line 222 "grammatic.y"
{yyval.exp = create_one_expr(Uplus, yyvsp[0].exp);
    break;}
case 94:
#line 223 "grammatic.y"
{yyval.exp = create_call_method(yyvsp[-2].exp, yyvsp[0].var, NULL);;
    break;}
case 95:
#line 224 "grammatic.y"
{yyval.exp = create_call_method(yyvsp[-4].exp, yyvsp[-2].var, NULL);;
    break;}
case 96:
#line 225 "grammatic.y"
{yyval.exp = create_call_method(yyvsp[-5].exp, yyvsp[-3].var, yyvsp[-1].exp_l);;
    break;}
case 97:
#line 226 "grammatic.y"
{yyval.exp = create_call_method(NULL, yyvsp[-2].var, NULL);;
    break;}
case 98:
#line 227 "grammatic.y"
{yyval.exp = create_call_method(NULL, yyvsp[-3].var, yyvsp[-1].exp_l);;
    break;}
case 99:
#line 228 "grammatic.y"
{yyval.exp = create_super_expr(NULL);;
    break;}
case 100:
#line 229 "grammatic.y"
{yyval.exp = create_super_expr(NULL);;
    break;}
case 101:
#line 230 "grammatic.y"
{yyval.exp = create_super_expr(yyvsp[-1].exp_l);;
    break;}
case 102:
#line 231 "grammatic.y"
{yyval.exp=yyvsp[0].exp;;
    break;}
case 103:
#line 232 "grammatic.y"
{yyval.exp = create_call_array_expr(yyvsp[-3].exp,yyvsp[-1].exp);;
    break;}
case 104:
#line 235 "grammatic.y"
{yyval.exp = create_array(yyvsp[-1].exp_l);;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 237 "grammatic.y"


