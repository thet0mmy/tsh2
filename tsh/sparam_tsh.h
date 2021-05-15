/*
 *	LIBSPARAM.H
 *	(sparam.h)
 *
 *	libsparam is a library for C/C++ that allows a user to
 *	extract a string as a parameter from another. For example:
 *
 *	pgetbase("hello world\n"); >> would return "hello"
 *	pgetparam("hello world\n"); >> would return "world\n".
 */

/*
 *	This file was edited for use in Tommy's Shell (TSH).
 *	This is used in the TSH project to read the configuration file.
 */

#pragma once
#include <string.h>

#define MAXPARAMSIZE 512
#define PFAIL -1

// define a type to allow us to return
// a string (array of char) from a function.
struct sparam_t
{
	char string[MAXPARAMSIZE];
};

// define a function to find a character in a string.
// this will be used to find the starting position to
// then take a substring.
int findChar(char s[], char f)
{
	for (int sc = 0; sc < strlen(s) + 1; sc++)
	{
		if (s[sc] == f)
		{
			return sc;
		}
	}
	return PFAIL;
}

// define a function to get a substring from a string
// this will be handy because we won't have to repeat ourselves
// when writing the other methods/routines.
struct sparam_t psubstr(char s[], int st, int end)
{
	char rs[MAXPARAMSIZE];
	int cpos = 0;
	struct sparam_t r;
	
	for (int sp = st; sp < end + 1; sp++)
	{
		rs[cpos] = s[sp];
		cpos++;
	}
	
	strcpy(r.string, rs);
	return r;
}

// define a function to get everything from the left of the space;
// the base of the parameter.
struct sparam_t pgetbase(char s[])
{
	return psubstr(s, 0, findChar(s, '=') - 1);
}

// define a function to get everything after the space;
// the parameter of the string.
struct sparam_t pgetparam(char s[])
{
	return psubstr(s,findChar(s, '=') + 1, strlen(s));	
}
