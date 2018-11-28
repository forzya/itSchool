#include <stdio.h>
#include <string.h>

void fileName1(char *str);
char *fileName2(const char *str);

int main()
{
	char *ch;
	char test3[100];

	printf("enter file path\n");

	gets_s(test3);

	ch = fileName2(test3);

	puts(ach);
	fileName1(test3);

	return 0;
}

void fileName1(char *str)
{
	char *ch;
	int index;

	if (ch = strrchr(str, '\\'));
	else if (ch = strrchr(str, '/'));
	else printf("error\n");

	index = ch - str + 1;

	for (int i = index; i < strlen(str); i++)
		printf("%c", str[i]);
	printf("\n");
}

char *fileName2(const char *str)
{
	char *ch;
	int index;

	if (ch = strrchr((char*)str, '\\'));
	else if (ch = strrchr((char*)str, '/'));
	else printf("error\n");

	index = ch - str + 1;

	while (index)
	{
		str++;
		--index;
	}

	return (char*)str;
}