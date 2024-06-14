#include "MyStrLen.h"

int myStrLen(const char ch[])
{
	int counter = 0;

	while (ch[counter] != '\0')
	{
		counter++;
	}

	return counter;
}
