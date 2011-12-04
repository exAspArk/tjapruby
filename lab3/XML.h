#include <stdio.h>


// -------------------------------
// ������� ��� � ��� ����������
// -------------------------------
// char * tag - ��� ����
// char * str - ���������� ����
// -------------------------------
void printTag(char *tag,char *str);

// --------------------------------
// ������� ������ ����������� ���
// --------------------------------
// char * openTag - ��� ����
// --------------------------------
void onlyOpenTag(char *openTag);

// --------------------------------
// ������� ������ ���������� ���
// --------------------------------
// char * closeTag - ��� ����
// --------------------------------
void onlyCloseTag(char *closeTag);

//����� ���� �������� ������, ����������� ����� 
void printTag(char *tag,char *str)
{
	fprintf(stdout,"\n<%s>",tag);
	fprintf(stdout,"\'%s\'",str);
	fprintf(stdout,"</%s>",tag);
}

// ������ ����������� ���
void onlyOpenTag(char *openTag)
{
	fprintf(stdout,"\n<%s>", openTag);
}

// ������ ����������� ���
void onlyCloseTag(char *closeTag)
{
	fprintf(stdout,"\n</%s>",closeTag);
}
