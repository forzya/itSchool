#include <stdio.h>

size_t mystrlen(const char *str);
char *mystrcat(char *str1, const char *str2);
int mystrcmp(const char *str1, const char *str2);
char *mystrchr(const char *str, int n);
char *mystrcpy(char *str1, const char *str2);

int main()
{
	return 0;
}


size_t mystrlen(const char *str)
{
	int symbol = 0;
	while (*str)
	{
		str++;
		symbol++;
	}
	return symbol;
}

char *mystrcat(char *str1, const char *str2)
{
	while (*str1)
		str1++;

	while (*str2)
	{
		*str1 = *str2;
		str1++;
		str2++;
	}

	return str1;
}

int mystrcmp(const char *str1, const char *str2)
{
	int num = 0;
	while (*str1 == *str2)
	{
		if (*str1 == 0)
			return  0;
		str1++;
		str2++;
	}
	return  *str1 < *str2 ? -1 : 1;
}

char *mystrchr(const char *str, int n)
{
	while (*str)
	{
		if (*str == n)
			return (char*)str;
		str++;
	}
	return NULL;
}

char *mystrcpy(char *str1, const char *str2)
{
	while (*str2)
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return str1;
}