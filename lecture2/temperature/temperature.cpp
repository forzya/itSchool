#include <stdio.h>

void temp();

int main()
{
	temp();
	return 0;
}

void temp()
{
	for (double i = -5; i != 6.25; i = i + 1.25)
	{
		printf("C=%5.2lf | F=%5.2lf | Re=%5.2lf \n", i, (i * (9.0 / 5.0) + 32.0), (i * (4.0 / 5.0)));
	}
}