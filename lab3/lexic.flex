%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include "grammatic_struct.h"
#include "grammatic.tab.h"
#include "treePrint.h"

extern char* yytext;
extern int yylineno;
extern int yyparse(void);
void yyerror(char *err);
FILE* tree;
%}
%option yylineno
%option noyywrap
%option never-interactive

DIGIT [0-9]
VAR   [a-z_][a-zA-Z0-9_]*
ID    [A-Z][a-zA-Z0-9_]*

%x ONE_COMMENT
%x MANY_COMMENTS
%x SIMPLE_STRING
%x DIF_STRING
%x METHOD
%x METHOD_NAME

%%

%{

int _int;                   //output int
float _float;               //output float
int len;                    // strings length
int i;                      // counter
char tmp[100] = "";         // ��� �������� ����� �� �������� � ���������� ������� ���������
char comment[10000] = "";   // comment
char text[10000] = "";      // comment
char strings[1000] = "";	// for output
char s[2];
struct Name_and_type_var *tempVar;	// ���������� ��� ������ ����������� ����������

%}
\n {
	return NL;
}
	
"+" {    
	//printf("��������: %s\n", yytext);
	return '+';
}
"." {
	//printf("��������: %s\n", yytext);
	return '.';
}
"-" {
    //printf("��������: %s\n", yytext);
	return '-';
}
"*" {
    //printf("��������: %s\n", yytext);
	return '*';
}
"/" {
    //printf("��������: %s\n", yytext);
	return '/';
}
"=" {
    //printf("��������: %s\n", yytext);
	return '=';
}
"+=" {
    //printf("��������: %s\n", yytext);
	return ADDASSIGN;
}
"-=" {
    //printf("��������: %s\n", yytext);
	return SUBASSIGN;
}
"*=" {
    //printf("��������: %s\n", yytext);
	return MULASSIGN;
}
"/=" {
    //printf("��������: %s\n", yytext);
	return DIVASSIGN;
}
">" {
     //printf("��������: %s\n", yytext);
	 return '>';
}
">=" {
    //printf("��������: %s\n", yytext);
	return MOREEQ;
}
"<" {
    //printf("��������: %s\n", yytext);
	return '<';
}
"<=" {
	//printf("��������: %s\n", yytext);
	return LESSEQ;
}
"<=>" {
	//printf("��������: %s\n", yytext);
	return LESSMORE;
}
"!=" {
	//printf("��������: %s\n", yytext);
	return NEQ;
}
"==" {
	//printf("��������: %s\n", yytext);
	return EQ;
}
"||" {
	//printf("��������: %s\n", yytext);
	return ORWORD;
}
"&&" {
	//printf("��������: %s\n", yytext);
	return ANDWORD;
}
"[" {
    //printf("��������: %s\n", yytext);
	return '[';
}
"]"	{
    //printf("��������: %s\n", yytext);
	return ']';
}
"(" {
    //printf("��������: %s\n", yytext);
	return '(';
}
")" {
    //printf("��������: %s\n", yytext);
	return ')';
}
"{"	{
    //printf("��������: %s\n", yytext);
	return '{';
}
"}"	{
    //printf("��������: %s\n", yytext);
	return '}';
}
"!" {
    //printf("��������: %s\n", yytext);
	return '!';
}
":" {
    //printf("��������: %s\n", yytext);
	return ':';
}
"," {
    //printf("��������: %s\n", yytext);
	return ',';
}
"..." {
	//printf("��������: %s\n", yytext);
	return THREEPOINT;
}
".." {
	//printf("��������: %s\n", yytext);
	return TWOPOINT;
}
 
0 {
	yylval.int_const = atoi("0");
	return INT;
}

[+-]?[1-9]{DIGIT}* {
	//printf("������������� ���������: %s \n", yytext);
	yylval.int_const  = atoi(yytext);
	return INT;
}

[-+]?{DIGIT}*\.{DIGIT}+([eE][-+]?{DIGIT}+)? {
	sscanf(yytext, "%g", &_float);
	//printf("������� ���������: %g \n", _float);
	yylval.float_const  = _float;
	return FLOAT;
}

(0x[0-9a-f]+)|(0X[0-9A-F]+) {
	sscanf(yytext, "%x", &_int);
	//printf("����������������� ���������: %d \n", _int);
	yylval.int_const = _int;
	return INT;
}

0[0-7]* {
	sscanf(yytext, "%o", &_int);
	//printf("������������ ���������: %d \n", _int);
	yylval.int_const = _int;
	return INT;
}

0b[0-1]+ {
	tmp[0] = 0;
	_int= 0;

    strcat(tmp, &yytext[2]);
    len = strlen(tmp);
    for(i = 0; i < len; i++) {
    	if(tmp[i] == '1') {
    		_int += 1 << len -1 -i;
        }
    }
    //printf("�������� ���������: %d \n", _int);
	yylval.int_const = _int;
	return INT;
}

nil {
    //printf("�������� �����: %s\n", yytext);
	return NIL;
}
def {
    //printf("�������� �����: %s\n", yytext);
	return DEF;
}
self {
    //printf("�������� �����: %s\n", yytext);
	return SELF;
}
not	{
    //printf("�������� �����: %s\n", yytext);
	return NOT;
}
super {
    printf("�������� �����: %s\n", yytext);
	return SUPER;
}
while {
    //printf("�������� �����: %s\n", yytext);
	return WHILE;
}
until {
    //printf("�������� �����: %s\n", yytext);
	return UNTIL;
}
for	{
    //printf("�������� �����: %s\n", yytext);
	return FOR;
}
then {
    //printf("�������� �����: %s\n", yytext);
	return THEN;
}
do {
    //printf("�������� �����: %s\n", yytext);
	return DO;
}
if {
    //printf("�������� �����: %s\n", yytext);
	return IF;
}
else {
    //printf("�������� �����: %s\n", yytext);
	return ELSE;
}
in {
    //printf("�������� �����: %s\n", yytext);
	return IN;
}
end	{
    //printf("�������� �����: %s\n", yytext);
	return END;
}
return {
    //printf("�������� �����: %s\n", yytext);
	return RETURN;
}
public  {
    //printf("�������� �����: %s\n", yytext);
	return PUBLIC;
}
private {
    //printf("�������� �����: %s\n", yytext);
	return PRIVATE;
}
or {
    //printf("�������� �����: %s\n", yytext);
	return ORWORD;
}
and {
    //printf("�������� �����: %s\n", yytext);
	return ANDWORD;
}
protected {
    //printf("�������� �����: %s\n", yytext);
	return PROTECTED;
}
break {
    //printf("�������� �����: %s\n", yytext);
	return BREAK;
}
class {
    return CLASS;
}

false {
	//printf("�������� �����: %s\n", yytext);
	yylval.bool_const = 0;
	return BOOL;
}
true {
	//printf("�������� �����: %s\n", yytext);
	yylval.bool_const = 1;
	return BOOL;
}

print {
	//printf("����� ��� ������ � ��������: %s\n", yytext);
	return PRINT;
}

p  {
	//printf("����� ��� ������ � ��������: %s\n", yytext);
	return P;
}

{ID} {
	//strcpy(text, yytext);
	//printf("���������: %s\n", text);
	tempVar = (struct Name_and_type_var*)malloc(sizeof(struct Name_and_type_var));
	tempVar->name_var = (char*)malloc(strlen(yytext));
	strcpy(tempVar->name_var, yytext);		// ���������� ��� ����������
	tempVar->type = CONSTANT;			// ���������� ��� �������
	yylval.var = tempVar;
	return CONST;
}

{VAR} {
	//strcpy(text, yytext);
	//printf("�������������: %s\n", text);
	tempVar = (struct Name_and_type_var*)malloc(sizeof(struct Name_and_type_var));
	tempVar->name_var = (char*)malloc(strlen(yytext));
	strcpy(tempVar->name_var, yytext);		// ���������� ��� ����������
	tempVar->type = LOCALVAR;			// ���������� ��� �������
	yylval.var = tempVar;
	return ID;
}

"$"({ID}|{VAR}) {
	//strcpy(text, &yytext[1]);
	//printf("���������� ����������: %s\n", text);
	tempVar = (struct Name_and_type_var*)malloc(sizeof(struct Name_and_type_var));
	tempVar->name_var = (char*)malloc(strlen(yytext));
	strcpy(tempVar->name_var, yytext);		// ���������� ��� ����������
	tempVar->type = GLOBALVAR;			// ���������� ��� �������
	yylval.var = tempVar;
	return ID;
}

"@"({ID}|{VAR}) {
	//strcpy(text, &yytext[1]);
	//printf("���������� �������: %s\n", text);
	tempVar = (struct Name_and_type_var*)malloc(sizeof(struct Name_and_type_var));
	tempVar->name_var = (char*)malloc(strlen(yytext));
	strcpy(tempVar->name_var, yytext);		// ���������� ��� ����������
	tempVar->type = OBJECTVAR;			// ���������� ��� �������
	yylval.var = tempVar;
	return ID;
}

"@@"({ID}|{VAR}) {
	//strcpy(text, &yytext[2]);
	//printf("���������� ������: %s\n", text);
	tempVar = (struct Name_and_type_var*)malloc(sizeof(struct Name_and_type_var));
	tempVar->name_var = (char*)malloc(strlen(yytext));
	strcpy(tempVar->name_var, yytext);		// ���������� ��� ����������
	tempVar->type = CLASSVAR;			// ���������� ��� �������
	yylval.var = tempVar;
	return ID;
}

"=begin" BEGIN(MANY_COMMENTS);

<MANY_COMMENTS>[^=]{1,} {
	strcat(comment, yytext);
}

<MANY_COMMENTS>"="+[^e][.\n]* {
    strcat(comment, yytext);
}

<MANY_COMMENTS>"="+"e"[^n][.\n]* {
    strcat(comment, yytext);
}

<MANY_COMMENTS>"="+"e""n"[^d][.\n]* {
    strcat(comment, yytext);
}

<MANY_COMMENTS>"="+"end" {
	strcat(comment,yytext);
	comment[strlen(comment)-4] = 0;
	//printf("������������� �����������: %s\n",comment);
    yylval.string_const = (char*)malloc(sizeof(char)*strlen(comment));
	strcpy(yylval.string_const, comment);
	comment[0] = 0;
	BEGIN(INITIAL);
	return STRING;
}

"#" BEGIN(ONE_COMMENT);

<ONE_COMMENT>.* {
	strcat(comment, yytext); 
	//printf("������������ �����������: %s",comment);
    yylval.string_const = (char*)malloc(sizeof(char)*strlen(comment));
	strcpy(yylval.string_const, comment);
	comment[0] = 0;
	BEGIN(INITIAL);
	return STRING;
}

"'"	{
	BEGIN(SIMPLE_STRING);
}

<SIMPLE_STRING>[^\\'\\]+ {
    strcat(strings, yytext);
}

<SIMPLE_STRING>\\' {
	strcat(strings, "'");
}
	
<SIMPLE_STRING>\\\\	{
    strcat(strings, "\\");
}

<SIMPLE_STRING>"'" {
	//printf("��������� ���������: %s\n", strings);
    yylval.string_const = (char*)malloc(sizeof(char)*strlen(strings));
	strcpy(yylval.string_const,strings);	// �������� ������������ ��������
	strings[0] = 0;
	BEGIN(INITIAL); 
	return STRING;
}

"\"" {
	BEGIN(DIF_STRING); 
}

<DIF_STRING>[^\\\n\"]+ {
	strcat(strings, yytext);
}

<DIF_STRING>\\[0-7]{1,3} {
    sscanf(yytext+1,"%o",s);
	strcat(strings, s);
}

<DIF_STRING>\\(0x[0-9a-f]{1,2})|(0X[0-9A-F]{1,2}) {
    sscanf(yytext+1,"%x",s);
	strcat(strings, s);
}

<DIF_STRING>\\n	{
	strcat(strings, yytext);
}
<DIF_STRING>\\\" {
	strcat(strings, yytext);
}
<DIF_STRING>\\\' {
	strcat(strings, yytext);
}
<DIF_STRING>\\t	{
	strcat(strings, yytext);
}
<DIF_STRING>\\v	{
	strcat(strings, yytext);
}
<DIF_STRING>\\r	{
	strcat(strings, yytext);
}
<DIF_STRING>\\f	{
	strcat(strings, yytext);
}
<DIF_STRING>\\b	{
	strcat(strings, yytext);
}
<DIF_STRING>\\a	{
	strcat(strings, yytext);
}
<DIF_STRING>\\\\ {
	strcat(strings, yytext);
}
<DIF_STRING>"\"" {
	//printf("��������� ���������: %s\n", strings);
    yylval.string_const = (char*)malloc(sizeof(char)*strlen(strings));
	strcpy(yylval.string_const, strings);	// �������� ������������ ��������
	strings[0] = 0;
	BEGIN(INITIAL);
	return STRING;
}
"::" {	
	return DOUBLECOLON;
}

%%

void yyerror(char *err) {
   printf("%s on line %d - %s\n", err, yylineno, yytext);
}

int main(int argc, char* argv[]) {
    char str[100] = "";
	setlocale(LC_CTYPE, ".1251");
    
    yyin = fopen("test.rb", "r+");
	fseek(yyin, -1, SEEK_END);
    fscanf(yyin, "%s", str);
    if(strcmp(str, "")) {
        fprintf(yyin, "\n");
    }
    fclose(yyin);

    yyin = fopen("test.rb", "r");
	yyparse();
	tree=freopen("codetree.xml","w",stdout);
	tree_print();
	fclose(tree);
	fclose(yyin);
	system("pause");
    return 0;
}