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


extern YYSTYPE yylval;
