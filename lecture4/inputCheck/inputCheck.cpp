#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h> 

int inputСheck(char *str);

int main()
{
	char str[100];

	printf("insert the number\n");
	gets_s(str);
	printf("%d\n", inputСheck(str));

	return 0;
}

int inputСheck(char *str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (!isdigit(str[i]))
			return 0;
	}

	return atoi(str);
}

