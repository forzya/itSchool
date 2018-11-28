//управление происходит через пустое поле, с помощью стрелок можно указать в какую сторону переместить пустое поле.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define size 4 // игра 4 на 4

enum keys { UP, DOWN, LEFT, RIGHT };
int puzzle[size][size];
int difficulty = 10;//сложность игры. более запутаннее делает поле(вызывает функцию myrandom)
int spacex;//координаты незаполненного поля
int spacey;//координаты незаполненного поля 


void mystart();//заполняет поле цифрами (от 1 до 16)
void myprint();//печать поля
void mymove(keys key);//двигает пустое поле в нужное направление
void myrandom();//делает один случайный ход
void mystartgame();//генерирует поле(mystart), вызывает функцию myrandom, печатает поле(myprint)
bool checkWin();//проверка на победу

int main()
{
	char c;
	mystartgame();
	while (!checkWin()) 
	{
		c = _getch();
		switch (c)
		{
		case 72: mymove(UP); break; 
		case 80: mymove(DOWN); break; 
		case 75: mymove(LEFT); break; 
		case 77: mymove(RIGHT); break; 
		}
		myprint(); 
	}
	printf("This is victory\n");
	return 0;
}

void mystart()
{
	int k = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			puzzle[i][j] = ++k;
		}

	puzzle[size - 1][size - 1] = 0;
	spacex = size - 1;
	spacey = size - 1;
}

void myprint()
{
	char c = '0';
	system("cls");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%5d ", puzzle[i][j]);
		}
		printf("\n");
	}
}

void mymove(keys key)
{
	switch (key)
	{
	case UP:
	{
		if (spacex > 0)
		{
			puzzle[spacex][spacey] = puzzle[spacex - 1][spacey];
			puzzle[spacex - 1][spacey] = 0;
			--spacex;
		}
		break;
	}
	case DOWN:
	{
		if (spacex < 3)
		{
			puzzle[spacex][spacey] = puzzle[spacex + 1][spacey];
			puzzle[spacex + 1][spacey] = 0;
			++spacex;
		}
		break;
	}
	case RIGHT:
	{
		if (spacey < 3)
		{
			puzzle[spacex][spacey] = puzzle[spacex][spacey + 1];
			puzzle[spacex][spacey + 1] = 0;
			++spacey;
		}
		break;
	}
	case LEFT:
	{
		if (spacey > 0)
		{
			puzzle[spacex][spacey] = puzzle[spacex][spacey - 1];
			puzzle[spacex][spacey - 1] = 0;
			--spacey;
		}
		break;
	}
	}
}

void myrandom()
{
	int a = rand() % 4;
	switch (a)
	{
	case 0:mymove(UP); break;
	case 1:mymove(DOWN); break;
	case 2:mymove(LEFT); break;
	case 3:mymove(RIGHT); break;
	}
}

void mystartgame()
{
	mystart();
	for (int i = 0; i < difficulty; i++)
		myrandom();
	myprint();
}
bool checkWin()
{
	if (puzzle[size - 1][size - 1] != 0)

	for (int i = 0; i < size*size - 1; i++)
		if (puzzle[i / size][i%size] != i + 1)
			return false;

	return true;
}