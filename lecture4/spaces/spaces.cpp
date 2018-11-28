#include <stdio.h>
#include<ctype.h>
#include <string.h>

void spaces(char *str);

int main()
{
	char ch[100] = "How            much \t\n\n is               the\t\t\t\tfish";

	puts(ch);
	spaces(ch);
	puts(ch);

	return 0;
}

void spaces(char *str)
{
	int size = strlen(str);
	char tok[100] = " ";
	int counter = 0;
	int index = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		if (!isspace(str[i]))
			counter = 0;
		if (isspace(str[i]))
			++counter;
		if (counter <= 1)
		{
			tok[index] = str[i];
			index++;
		}
	}
	memset(str, ' ', strlen(str));

	for (int i = 0; i < strlen(str); i++)
		str[i] = tok[i];
}