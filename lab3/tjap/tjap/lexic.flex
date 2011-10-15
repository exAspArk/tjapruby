%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int i;
char comment[10000];			// ��������
char tmp[100];						// ��� �������� ����� �� �������� � ���������� ������� ���������
char strings[1000];					// ��� ������ �����
int _int;					// ��� ������ �������� ���� int
float _float;				// ��� ������ �������� ���� float
char text[1000];				// �������� ������ ��������� �����

%}
%option noyywrap
%option never-interactive

DIGIT [0-9]
VAR [a-z_][a-zA-Z0-9_]*
ID [A-Z][a-zA-Z0-9_]*

%x ONE_COMMENT
%x MANY_COMMENTS
%x SIMPLE_STRING
%x DIF_STRING

%%

"+"	printf( "��������: %s\n", yytext );

"-"	printf( "��������: %s\n", yytext );	

"*"	printf( "��������: %s\n", yytext );

"/"	printf( "��������: %s\n", yytext );

"="	printf( "��������: %s\n", yytext );

"+=" printf( "��������: %s\n", yytext );

"-=" printf( "��������: %s\n", yytext );

"*=" printf( "��������: %s\n", yytext );

"/=" printf( "��������: %s\n", yytext );

">" printf( "��������: %s\n", yytext );
	
">=" printf( "��������: %s\n", yytext );

"<"	printf( "�������� : %s\n", yytext );

"<=" printf( "��������: %s\n", yytext ); 

"<=>" printf( "��������: %s\n", yytext );

"!=" printf( "��������: %s\n", yytext );

"==" printf( "��������: %s\n", yytext );

"||"	printf( "��������: %s\n", yytext );

"&&" printf( "��������: %s\n", yytext );

"[" printf( "��������: %s\n", yytext );

"]"	printf( "��������: %s\n", yytext );

"(" printf( "��������: %s\n", yytext );

")" printf( "��������: %s\n", yytext );

"{"	printf( "��������: %s\n", yytext );

"}"	printf( "��������: %s\n", yytext );

"."	 printf( "��������: %s\n", yytext );

"!" printf( "��������: %s\n", yytext );
	
":" printf( "��������: %s\n", yytext );

"," printf( "��������: %s\n", yytext );

"..." printf( "��������: %s\n", yytext );

".." printf( "��������: %s\n", yytext );

"%" printf( "��������: %s\n", yytext );

[+-]?[1-9]{DIGIT}* 
{
	int int_const = atoi(yytext);
	printf("������������� ���������: %d \n", int_const);
	yyval.int_const = int_const;
	return INT;
}

[-+]?{DIGIT}*\.?{DIGIT}+([eE][-+]?{DIGIT}+)? {
	// ��� �������� 
	float __float;
	sscanf(yytext, "%g", &__float);
	printf("������� ���������: %g \n", __float);
}
(0x[0-9a-f]+)|(0X[0-9A-F]+) {
	sscanf(yytext, "%x", &_int);
	printf("����������������� ���������: %d \n", _int);
}

0[0-7]* {
	sscanf(yytext, "%o", &_int);
	printf("������������ ���������: %d \n", _int);
}

0b[0-1]+ {
	int len =0;
	tmp[0] = 0;
	_int= 0;
	strcat(tmp, &yytext[2]);

	len = strlen(tmp);
	for(i=0; i<len; i++)
		if(tmp[i] == '1')
			_int += 1 << len -1 -i;
	printf("�������� ���������: %d \n", _int);
}

superclass printf("�������� ����� %s\n", yytext);

class printf("�������� ����� %s\n", yytext);

nil printf("�������� ����� %s\n", yytext);

self printf("�������� ����� %s\n", yytext);

def printf("�������� ����� %s\n", yytext);

false printf("�������� ����� %s\n", yytext);

not	printf("�������� ����� %s\n", yytext);

while printf("�������� ����� %s\n", yytext);

until printf("�������� ����� %s\n", yytext);

for	printf("�������� �����: %s\n", yytext);

then printf("�������� �����: %s\n", yytext);

do printf("�������� �����: %s\n", yytext);

if printf("�������� �����: %s\n", yytext);

true printf("�������� �����: %s\n", yytext);

else printf("�������� �����: %s\n", yytext);

elsif printf("�������� �����: %s\n", yytext);

in printf("�������� �����: %s\n", yytext);

array printf("�������� �����: %s\n", yytext);

end	printf("�������� �����: %s\n", yytext);

return printf("�������� �����: %s\n", yytext);

public printf("�������� �����: %s\n", yytext);

private printf("�������� �����: %s\n", yytext);

protected printf("�������� �����: %s\n", yytext);

or printf("�������� �����: %s\n", yytext);

and printf("�������� �����: %s\n", yytext);

print	printf("�������: %s\n", yytext);

gets printf("�������: %s\n", yytext);

puts printf("�������: %s\n", yytext);

break printf("�������� ����� : %s\n", yytext);

{ID} {
	text[0] = 0;
	strcpy(text, yytext);
	printf("���������: %s\n", text);
}

{VAR} { 
	text[0] = 0;
	strcpy(text, yytext);
	printf("����������: %s\n", text);
}

"$"({ID}|{VAR}) {
	text[0] = 0 ;
	strcpy(text, &yytext[1]);
	printf("���������� ����������: %s\n", text);
}
"@"({ID}|{VAR}) {
	text[0] = 0;
	strcpy(text, &yytext[1]);
	printf("���������� �������: %s\n", text);
}

"@@"({ID}|{VAR}) {
	text[0] = 0;
	strcpy(text, &yytext[2]);
	printf("���������� ������: %s\n", text);
}

"=begin" BEGIN(MANY_COMMENTS); 
<MANY_COMMENTS>[^=]{1,} {
	strcat(comment, yytext);
}
<MANY_COMMENTS>"="+"end" { 
	strcat(comment,yytext);
	comment[strlen(comment)-4]=0;
	printf("������������� �����������: %s\n",comment);
	comment[0]=0;
	BEGIN(INITIAL);
}
<MANY_COMMENTS>"="+[^e][.\n]* strcat(comment, yytext);
<MANY_COMMENTS>"="+"e"[^n][.\n]* strcat(comment, yytext);
<MANY_COMMENTS>"="+"e""n"[^d][.\n]* strcat(comment, yytext);

"#" BEGIN(ONE_COMMENT);
<ONE_COMMENT>.* {
	strcat(comment, yytext); 
	printf("������������ �����������: %s",comment);
	comment[0]=0;
	BEGIN(INITIAL);
}


"'"	{
	BEGIN(SIMPLE_STRING);
	strings[0]=0;
}
<SIMPLE_STRING>[^\\'\\]+	strcat(strings, yytext);
<SIMPLE_STRING>\\'		strcat(strings, "'");
<SIMPLE_STRING>\\\\		strcat(strings, "\\");
<SIMPLE_STRING>"'" {
	printf("������� ������: %s\n", strings);
	BEGIN(INITIAL); 
}

"\""	{
	strings[0]=0;
	BEGIN(DIF_STRING); 
}

<DIF_STRING>[^\\\n\"]+	{
	
	strcat(strings, yytext);
}
<DIF_STRING>\\{DIGIT}{1,3} {
	char s[2];
	s[0]=atoi(&*(yytext+1));
	s[1]=0;
	strcat(strings, s);
}
<DIF_STRING>\\n			strcat(strings, "\n");
<DIF_STRING>\\\"		strcat(strings, "\"");
<DIF_STRING>\\\'		strcat(strings, "\'");
<DIF_STRING>\\t			strcat(strings, "\t");
<DIF_STRING>\\v			strcat(strings, "\t");
<DIF_STRING>\\r			strcat(strings, "\r");
<DIF_STRING>\\f			strcat(strings, "\f");
<DIF_STRING>\\b			strcat(strings, "\b");
<DIF_STRING>\\a			strcat(strings, "\a");

<DIF_STRING>\\\\		strcat(strings, "\\");
<DIF_STRING>"\""		{
	printf("������� ������: %s\n", strings);
	BEGIN(INITIAL);
}

%%
void main(int argc, char* argv[])
{
	setlocale(LC_CTYPE, ".1251");
	yyin = fopen("test.txt", "r");
	yylex();
	fclose(yyin);
	system("pause");
}