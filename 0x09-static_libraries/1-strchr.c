#include "main.h"
#include <stddef.h>

/**
 * _strchr - entry point
 * @n: the input
 * @c: the input
 * Return: Always 0 (Success)
 */
char *_strchr(char *, char c)
{
	int i = 0;

	for (; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (0);
}
