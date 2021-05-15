#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLACK	0
#define RED		1
#define GREEN	2
#define YELLOW	3
#define BLUE	4
#define MAGENTA	5
#define CYAN	6
#define WHITE	7

// written by tommy wilson on an unknown date (most likely April 14, 2021)
// used in TSH for shell colors

void color(int c)
{
	char colorchange[8];
	sprintf(colorchange, "\033[0;3%im", c);
	printf("%s",colorchange);
}

void colreset()
{
	char colorchange[8];
	sprintf(colorchange,"\033[0;3%im",WHITE);
	printf("%s",colorchange);
}

void funprintf(char str[])
{
	for (int loopchar=1; loopchar < strlen(str)+1; loopchar++)
	{
		int newcolor = (loopchar % 7) + 1;
		color(newcolor);
		printf("%c",str[loopchar-1]);
	}
	color(7);
}