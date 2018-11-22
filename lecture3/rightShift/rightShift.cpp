#include <stdio.h>
unsigned int rightShift(unsigned int, unsigned int);

int main()
{
	return 0;
}

unsigned int rightShift(unsigned int a, unsigned int n)
{
	return (a >> n) | (a << (sizeof(unsigned int) * 8) - n);
}