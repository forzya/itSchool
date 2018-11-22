#include <stdio.h>

void cross(int);
void filledDiamond(int);
void hollowDiamond(int);

int main()
{
	int key;
	int size;
	bool stop = true;

	while (stop)
	{
		printf("1-cross \n");
		printf("2-hollow diamond \n");
		printf("3-filled diamond \n");
		printf("4-exit \n");

		scanf_s("%d", &key);
		switch (key)
		{
		case 1:
			printf("size of a figure ");
			scanf_s(" %d", &size);
			cross(size);
			break;
		case 2:
			printf("size of a figure ");
			scanf_s(" %d", &size);
			hollowDiamond(size);
			break;
		case 3:
			printf("size of a figure ");
			scanf_s(" %d", &size);
			filledDiamond(size);
			break;
		case 4:
			stop = false;
			break;

		default:
			printf("Error! \n");
			break;
		}
	}
	return 0;
}

void hollowDiamond(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{	
			if (j == n/2 + i|| ((n%2==0)?j == n/2 - i - 1: j == n/2 - i))
				printf("*");
			else if (j == n/2 + n - i - 1 || j == i - n/2)
				printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}

void cross(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				printf("*");
			else if ((i + j == n - 1) && (i != j))
				printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}

void filledDiamond(int n)
{
	for (int i = 0; i < n/2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j <= n/2 + i && ((n % 2 == 0) ? j >= n/2 - i - 1 : j >= n/2 - i ))
				printf("*");
			else printf(" ");
		}
		printf("\n");
	}

	for (int i = n/2; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j <= n/2 + n - i - 1 && j >= i - n/2)
				printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}