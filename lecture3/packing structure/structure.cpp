#include <stdio.h>

typedef unsigned short datec_t;

typedef enum Month {
	JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG,
	SEP, OCT, NOV, DEC, MONTHS = 12
} Month;

typedef struct Date
{
	int dd;
	Month mm;
	int yy;
} Date;

void printAsBinary(unsigned int x);

datec_t compressDate(Date d);

Date uncompressDate(datec_t dc);

datec_t setDay(datec_t dc, int newDay);

datec_t setMonth(datec_t dc, Month newMonth);

datec_t setYear(datec_t dc, int newYear);

void printDate(Date d);

void printCompressedDate(datec_t d);

int main()
{
	Date d = { 3,DEC,99 };
	printDate(d);

	datec_t dc= compressDate(d);
	printf("packed number %hu\n", dc);
	dc = setDay(dc, 7);
	dc = setMonth(dc, FEB);
	dc = setYear(dc, 11);
	d = uncompressDate(dc);
	printDate(d);
	
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
}

datec_t compressDate(Date d)
{
	unsigned short  res = (((d.yy << 4) | d.mm) << 5) | d.dd;
	return res;
}

datec_t setDay(datec_t dc, int newDay)
{
	dc = dc & 65504;
	dc = dc | newDay;
	return dc;
}

datec_t setMonth(datec_t dc, Month newMonth)
{
	dc = dc & 65055;
	dc = dc | (newMonth << 5);
	return dc;
}

datec_t setYear(datec_t dc, int newYear)
{
	dc = dc & 511;
	dc = dc | (newYear << 9);
	return dc;
}

Date uncompressDate(datec_t dc)
{
	Date d;

	d.dd = dc & 31;
	d.mm = Month((dc >> 5) & 15);
	d.yy = (dc >> 9) & 127;

	return d;
}

void printDate(Date d)
{
	printf("Day %d\n", d.dd);
	printf("Month %d\n", d.mm);
	printf("Year %d\n", d.yy);
}