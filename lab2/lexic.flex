%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int _int;                   //output int
float _float;               //output float
char tmp[100];              // для перевода числа из двоичной в десятичную систему счисления
int len;                    // strings length
int i;                      // counter
char tmp[100] = "";         // для перевода числа из двоичной в десятичную систему счисления
char comment[10000] = "";   // comment
char text[10000] = "";      // comment
char strings[1000] = "";	// for output
char s[2];
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

"+"     printf("Операция: %s\n", yytext);
"-"	    printf("Операция: %s\n", yytext);	
"*"	    printf("Операция: %s\n", yytext);
"/"	    printf("Операция: %s\n", yytext);
"="	    printf("Операция: %s\n", yytext);
"+="    printf("Операция: %s\n", yytext);
"-="    printf("Операция: %s\n", yytext);
"*="    printf("Операция: %s\n", yytext);
"/="    printf("Операция: %s\n", yytext);
">"     printf("Операция: %s\n", yytext);
">="    printf("Операция: %s\n", yytext);
"<"	    printf("Операция: %s\n", yytext);
"<="    printf("Операция: %s\n", yytext); 
"<=>"   printf("Операция: %s\n", yytext);
"!="    printf("Операция: %s\n", yytext);
"=="    printf("Операция: %s\n", yytext);
"||"    printf("Операция: %s\n", yytext);
"&&"    printf("Операция: %s\n", yytext);
"["     printf("Операция: %s\n", yytext);
"]"	    printf("Операция: %s\n", yytext);
"("     printf("Операция: %s\n", yytext);
")"     printf("Операция: %s\n", yytext);
"{"	    printf("Операция: %s\n", yytext);
"}"	    printf("Операция: %s\n", yytext);
"!"     printf("Операция: %s\n", yytext);
":"     printf("Операция: %s\n", yytext);
","     printf("Операция: %s\n", yytext);
"..."   printf("Операция: %s\n", yytext);
".."    printf("Операция: %s\n", yytext);
"%"     printf("Операция: %s\n", yytext);

[+-]?[1-9]{DIGIT}* printf("Целочисленная константа: %s \n", yytext);

[-+]?{DIGIT}*\.?{DIGIT}+([eE][-+]?{DIGIT}+)? {
	sscanf(yytext, "%g", &_float);
	printf("Дробная константа: %g \n", _float);
}

(0x[0-9a-f]+)|(0X[0-9A-F]+) {
	sscanf(yytext, "%x", &_int);
	printf("Шестнадцатеричная константа: %d \n", _int);
}

0[0-7]* {
	sscanf(yytext, "%o", &_int);
	printf("Восьмеричная константа: %d \n", _int);
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
    printf("Двоичная константа: %d \n", _int);
}

nil         printf("Ключевое слово: %s\n", yytext);
self        printf("Ключевое слово: %s\n", yytext);
false       printf("Ключевое слово: %s\n", yytext);
not	        printf("Ключевое слово: %s\n", yytext);
super       printf("Ключевое слово: %s\n", yytext);
while       printf("Ключевое слово: %s\n", yytext);
until       printf("Ключевое слово: %s\n", yytext);
for	        printf("Ключевое слово: %s\n", yytext);
then        printf("Ключевое слово: %s\n", yytext);
do          printf("Ключевое слово: %s\n", yytext);
if          printf("Ключевое слово: %s\n", yytext);
true        printf("Ключевое слово: %s\n", yytext);
else        printf("Ключевое слово: %s\n", yytext);
elsif       printf("Ключевое слово: %s\n", yytext);
in          printf("Ключевое слово: %s\n", yytext);
array       printf("Ключевое слово: %s\n", yytext);
end	        printf("Ключевое слово: %s\n", yytext);
return      printf("Ключевое слово: %s\n", yytext);
public      printf("Ключевое слово: %s\n", yytext);
private     printf("Ключевое слово: %s\n", yytext);
or          printf("Ключевое слово: %s\n", yytext);
and         printf("Ключевое слово: %s\n", yytext);
protected   printf("Ключевое слово: %s\n", yytext);
break       printf("Ключевое слово : %s\n", yytext);

print	printf("Метод для работы с консолью: %s\n", yytext);
gets    printf("Метод для работы с консолью: %s\n", yytext);
puts    printf("Метод для работы с консолью: %s\n", yytext);
p       printf("Метод для работы с консолью: %s\n", yytext);
printf  printf("Метод для работы с консолью: %s\n", yytext);
putc    printf("Метод для работы с консолью: %s\n", yytext);

"." BEGIN(METHOD); 
<METHOD>{VAR} {
	printf("Метод: %s\n", yytext);
	BEGIN(INITIAL);
}

"def" BEGIN(METHOD_NAME); 
<METHOD_NAME>{VAR} {
    printf("Ключевое слово: def\n");
	printf("Метод: %s\n", yytext);
	BEGIN(INITIAL);
}

{ID} {
	strcpy(text, yytext);
	printf("Константа: %s\n", text);
}

{VAR} {
	strcpy(text, yytext);
	printf("Переменная: %s\n", text);
}

"$"({ID}|{VAR}) {
	strcpy(text, &yytext[1]);
	printf("Глобальная переменная: %s\n", text);
}

"@"({ID}|{VAR}) {
	strcpy(text, &yytext[1]);
	printf("Переменная объекта: %s\n", text);
}

"@@"({ID}|{VAR}) {
	strcpy(text, &yytext[2]);
	printf("Переменная класса: %s\n", text);
}

"=begin" BEGIN(MANY_COMMENTS); 
<MANY_COMMENTS>[^=]{1,} {
	strcat(comment, yytext);
}

<MANY_COMMENTS>"="+"end" {
	strcat(comment,yytext);
	comment[strlen(comment)-4] = 0;
	printf("Многострочный комментарий: %s\n",comment);
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
	printf("Однострочный комментарий: %s",comment);
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
	printf("Строковая константа: %s\n", strings);
    strings[0] = 0;
	BEGIN(INITIAL); 
}

"\"" {
	BEGIN(DIF_STRING); 
}

<DIF_STRING>[^\\\n\"]+ {
	strcat(strings, yytext);
}

<DIF_STRING>\\{DIGIT}{1,3} {
	s[0]=atoi(&*(yytext+1));
	s[1]=0;
	strcat(strings, s);
}

<DIF_STRING>\\n	{
	strcat(strings, "\n");
}
<DIF_STRING>\\\" {
	strcat(strings, "\"");
}
<DIF_STRING>\\\' {
	strcat(strings, "\'");
}
<DIF_STRING>\\t	{
	strcat(strings, "\t");
}
<DIF_STRING>\\v	{
	strcat(strings, "\t");
}
<DIF_STRING>\\r	{
	strcat(strings, "\r");
}
<DIF_STRING>\\f	{
	strcat(strings, "\f");
}
<DIF_STRING>\\b	{
	strcat(strings, "\b");
}
<DIF_STRING>\\a	{
	strcat(strings, "\a");
}
<DIF_STRING>\\\\ {
	strcat(strings, "\\");
}
<DIF_STRING>"\"" {
	printf("Строковая константа: %s\n", strings);
    strings[0] = 0;
	BEGIN(INITIAL);
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