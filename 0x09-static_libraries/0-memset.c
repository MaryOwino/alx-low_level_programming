#include "main.h"
/**
 * _memset - Fill the block of memory with specific value
 * @s: start addess of the memory to be filled
 * @b: desired value
 * @n: the number of bytes to be changed
 *
 * Return: changed array with new value for n bytes
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
