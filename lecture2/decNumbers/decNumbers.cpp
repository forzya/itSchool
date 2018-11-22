#include <stdio.h>

void decnumbers(int);
;
int main()
{
	decnumbers(12345);
	decnumbers(123);

	return 0;
}

void decnumbers(int number)
{
	int i = 0;

	while (number)
	{
		number /= 10;
		++i;
	}
	printf("number of decimal digits = %d \n", i);
}