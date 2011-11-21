%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

extern int yyparse(void);

%}

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

"+"     printf("��������: %s\n", yytext);
"."     printf("��������: %s\n", yytext);
"-"	    printf("��������: %s\n", yytext);	
"*"	    printf("��������: %s\n", yytext);
"/"	    printf("��������: %s\n", yytext);
"="	    printf("��������: %s\n", yytext);
"+="    printf("��������: %s\n", yytext);
"-="    printf("��������: %s\n", yytext);
"*="    printf("��������: %s\n", yytext);
"/="    printf("��������: %s\n", yytext);
">"     printf("��������: %s\n", yytext);
">="    printf("��������: %s\n", yytext);
"<"	    printf("��������: %s\n", yytext);
"<="    printf("��������: %s\n", yytext); 
"<=>"   printf("��������: %s\n", yytext);
"!="    printf("��������: %s\n", yytext);
"=="    printf("��������: %s\n", yytext);
"||"    printf("��������: %s\n", yytext);
"&&"    printf("��������: %s\n", yytext);
"["     printf("��������: %s\n", yytext);
"]"	    printf("��������: %s\n", yytext);
"("     printf("��������: %s\n", yytext);
")"     printf("��������: %s\n", yytext);
"{"	    printf("��������: %s\n", yytext);
"}"	    printf("��������: %s\n", yytext);
"!"     printf("��������: %s\n", yytext);
":"     printf("��������: %s\n", yytext);
","     printf("��������: %s\n", yytext);
"..."   printf("��������: %s\n", yytext);
".."    printf("��������: %s\n", yytext);
"%"     printf("��������: %s\n", yytext);

[+-]?[1-9]{DIGIT}* {
	//printf("������������� ���������: %s \n", yytext);
	yylval.int_const  = atoi(yytext);
	return INT;
}

[-+]?{DIGIT}*\.?{DIGIT}+([eE][-+]?{DIGIT}+)? {
	sscanf(yytext, "%g", &_float);
	//printf("������� ���������: %g \n", _float);
	yylval.float_const  = _float;
	return FLOAT;}
}

(0x[0-9a-f]+)|(0X[0-9A-F]+) {
	sscanf(yytext, "%x", &_int);
	//printf("����������������� ���������: %d \n", _int);
	yylval.int_const = _int;
	return INT;}
}

0[0-7]* {
	sscanf(yytext, "%o", &_int);
	//printf("������������ ���������: %d \n", _int);
	yylval.int_const = _int;
	return INT;}
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

nil         printf("�������� �����: %s\n", yytext);
def         printf("�������� �����: %s\n", yytext);
self        printf("�������� �����: %s\n", yytext);
not	        printf("�������� �����: %s\n", yytext);
super       printf("�������� �����: %s\n", yytext);
while       printf("�������� �����: %s\n", yytext);
until       printf("�������� �����: %s\n", yytext);
for	        printf("�������� �����: %s\n", yytext);
then        printf("�������� �����: %s\n", yytext);
do          printf("�������� �����: %s\n", yytext);
if          printf("�������� �����: %s\n", yytext);
else        printf("�������� �����: %s\n", yytext);
elsif       printf("�������� �����: %s\n", yytext);
in          printf("�������� �����: %s\n", yytext);
array       printf("�������� �����: %s\n", yytext);
end	        printf("�������� �����: %s\n", yytext);
return      printf("�������� �����: %s\n", yytext);
public      printf("�������� �����: %s\n", yytext);
private     printf("�������� �����: %s\n", yytext);
or          printf("�������� �����: %s\n", yytext);
and         printf("�������� �����: %s\n", yytext);
protected   printf("�������� �����: %s\n", yytext);
break       printf("�������� ����� : %s\n", yytext);

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

print	printf("����� ��� ������ � ��������: %s\n", yytext);
gets    printf("����� ��� ������ � ��������: %s\n", yytext);
puts    printf("����� ��� ������ � ��������: %s\n", yytext);
p       printf("����� ��� ������ � ��������: %s\n", yytext);
printf  printf("����� ��� ������ � ��������: %s\n", yytext);
putc    printf("����� ��� ������ � ��������: %s\n", yytext);

{ID} {
	//strcpy(text, yytext);
	//printf("���������: %s\n", text);
	tempVar = (struct Name_and_type_var*)malloc(sizeof(struct Name_and_type_var));
	tempVar->name = (char*)malloc(strlen(yytext));
	strcpy(tempVar->name, yytext);		// ���������� ��� ����������
	tempVar->type = CONSTANT;			// ���������� ��� �������
	yylval.Var = tempVar;
	return CONST;
}

{VAR} {
	//strcpy(text, yytext);
	//printf("�������������: %s\n", text);
	tempVar = (struct Name_and_type_var*)malloc(sizeof(struct Name_and_type_var));
	tempVar->name = (char*)malloc(strlen(yytext));
	strcpy(tempVar->name, yytext);		// ���������� ��� ����������
	tempVar->type = LOCALVAR;			// ���������� ��� �������
	yylval.Var = tempVar;
	return ID;
}

"$"({ID}|{VAR}) {
	//strcpy(text, &yytext[1]);
	//printf("���������� ����������: %s\n", text);
	tempVar = (struct Name_and_type_var*)malloc(sizeof(struct Name_and_type_var));
	tempVar->name = (char*)malloc(strlen(yytext));
	strcpy(tempVar->name, yytext);		// ���������� ��� ����������
	tempVar->type = GLOBALVAR;			// ���������� ��� �������
	yylval.Var = tempVar;
	return ID;
}

"@"({ID}|{VAR}) {
	//strcpy(text, &yytext[1]);
	//printf("���������� �������: %s\n", text);
	tempVar = (struct Name_and_type_var*)malloc(sizeof(struct Name_and_type_var));
	tempVar->name = (char*)malloc(strlen(yytext));
	strcpy(tempVar->name, yytext);		// ���������� ��� ����������
	tempVar->type = OBJECTVAR;			// ���������� ��� �������
	yylval.Var = tempVar;
	return ID;
}

"@@"({ID}|{VAR}) {
	//strcpy(text, &yytext[2]);
	//printf("���������� ������: %s\n", text);
	tempVar = (struct Name_and_type_var*)malloc(sizeof(struct Name_and_type_var));
	tempVar->name = (char*)malloc(strlen(yytext));
	strcpy(tempVar->name, yytext);		// ���������� ��� ����������
	tempVar->type = CLASSVAR;			// ���������� ��� �������
	yylval.Var = tempVar;
	return ID;
}

"=begin" BEGIN(MANY_COMMENTS); 
<MANY_COMMENTS>[^=]{1,} {
	strcat(comment, yytext);
}

<MANY_COMMENTS>"="+"end" {
	strcat(comment,yytext);
	comment[strlen(comment)-4] = 0;
	printf("������������� �����������: %s\n",comment);
	comment[0] = 0;
	BEGIN(INITIAL);
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

"#" BEGIN(ONE_COMMENT);
<ONE_COMMENT>.* {
	strcat(comment, yytext); 
	printf("������������ �����������: %s",comment);
	comment[0] = 0;
	BEGIN(INITIAL);
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
	printf("��������� ���������: %s\n", strings);
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
	printf("��������� ���������: %s\n", strings);
	strcpy(yylval.string_const, strings);	// �������� ������������ ��������
	strings[0] = 0;
	BEGIN(INITIAL);
	return STRING;
}

%%

int main(int argc, char* argv[]) {
	setlocale(LC_CTYPE, ".1251");
	yyin = fopen("test.txt", "r");
	yylex();
	fclose(yyin);
	system("pause");
    return 0;
}