#include < math.h > 
#include <stdio.h>

void printAsBinary(unsigned int);
unsigned int changeBit(unsigned int);

int main()
{
	unsigned int n;
	scanf_s("%d", &n);

	printAsBinary(n);
	changeBit(n);	
	n= changeBit(n);
	printAsBinary(n);

	return 0;
}
void printAsBinary(unsigned int x)
{
	for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; i--)
	{
		unsigned int mask = (1 << i);
		if (x & mask)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}

unsigned int changeBit(unsigned int n)
{
	bool mas[32];

	for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; i--)
	{
		mas[i] = n & (1 << i);
	}

	for (int i = 0; i <= 31; i = i + 2)
	{
		int change;
		change = mas[i];
		mas[i] = mas[i + 1];
		mas[i + 1] = change;
	}

	n = 0;
	for (int i = 0; i <= 31; i++)
	{
		n = mas[i] * pow(2, i) + n;
	}

	return n;
}