#include <stdio.h>


// -------------------------------
// ¬ыводит тег и его содержимое
// -------------------------------
// char * tag - им€ тега
// char * str - содержимое тега
// -------------------------------
void printTag(char *tag,char *str);

// --------------------------------
// ¬ыводит только открывающий тег
// --------------------------------
// char * openTag - им€ тега
// --------------------------------
void onlyOpenTag(char *openTag);

// --------------------------------
// ¬ыводит только закрывающи тег
// --------------------------------
// char * closeTag - им€ тега
// --------------------------------
void onlyCloseTag(char *closeTag);

//«десь надо выводить дерево, построенное после 
void printTag(char *tag,char *str)
{
	fprintf(stdout,"\n<%s>",tag);
	fprintf(stdout,"\'%s\'",str);
	fprintf(stdout,"</%s>",tag);
}

// “олько открывающий тег
void onlyOpenTag(char *openTag)
{
	fprintf(stdout,"\n<%s>", openTag);
}

// “олько закрывающий тег
void onlyCloseTag(char *closeTag)
{
	fprintf(stdout,"\n</%s>",closeTag);
}
