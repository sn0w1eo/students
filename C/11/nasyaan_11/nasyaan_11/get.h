#pragma once
#pragma warning (disable : 4996)

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

void getInt(int* x, int min, int max)
{
	*x = 0;
	char ch = ' ';
	int skip, st = 0;
	int b = 0, i;
	do
	{
		st = i = skip = 0;
		for (; b = ((ch = getchar()) != '\n'); i++)
		{
			if (ch == EOF) return;
			if ((atoi(&ch)) == 0 && ch != '0') skip = 1;
			else if (b && !skip) { *x *= 10; *x += atoi(&ch); }
			if (*x < min || *x > max) skip = 1;
			if (skip) { *x = 0; st++; }
		}
		if (!b && !i) skip = 1;
	} while (skip || b);
}

void getanyInt(int* x)
{
	*x = 0;
	char ch = ' ';
	int skip, sgn = 0;
	do
	{
		skip = 0;
		for (int i = 0; (ch = getchar()) != '\n'; i++)
		{
			if (ch == EOF) return;
			if (ch == '-') sgn = -1;
			else if ((atoi(&ch)) == 0 && ch != '0') { skip = 1; }
			else { *x *= 10; *x += atoi(&ch); }
			if (skip) *x = 0;
		}
	} while (skip != 0);
	if (sgn == -1) *x = *x * -1;
}

void mingetInt(int* x, int min)
{
	*x = 0;
	char ch = ' ';
	int skip = 1;
	do
	{
		if (skip) *x = 0;
		skip = 0;
		for (int i = 0; (ch = getchar()) != '\n'; i++)
		{
			if (ch == EOF) exit(0);
			if (((atoi(&ch)) == 0 && ch == '0' && i == 0) || (atoi(&ch)) == 0 && ch != '0') { skip = 1; }
			else { *x *= 10; *x += atoi(&ch); }
			if (skip) *x = min - 1;

		}

	} while (*x < min);
}


char* getStr() {
	size_t size = 1;
	char* str;
	int ch;
	size_t len = 0;
	str = realloc(NULL, sizeof(char) * size);
	if (!str)return str;
	while (EOF != (ch = fgetc(stdin)) && ch != '\n') {
		str[len++] = ch;
		if (len == size) {
			str = realloc(str, sizeof(char) * (size += 16));
			if (!str)return str;
		}
	}
	str[len++] = '\0';

	return realloc(str, sizeof(char) * len);
}