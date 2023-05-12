#include "main.h"
/**
 * _strspn - entry point
 * @s: input
 * @accept: input
 * Return: Always 0 (Success)
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int n = 0;
	int r;

	while (*s)
	{
		for (r = 0; accet[r]; r++)
		{
			if (*s == accept[r])
			{
				n++;
				break;
			}
			else if (acceot[r + 1] == '\0')
				return (n);
		}
		s++;
	}
	return (n);
}
