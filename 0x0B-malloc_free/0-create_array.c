#include "main.h"
#include <stdlib.h>
/**
 * create_array - Creates array of the characters.
 * @size: The size of the array.
 * @c: The character to fill in the array.
 *
 * Return: The array filled.
 */
char *create_array(unsigned int size, char c)
{
	char *str;
	unsigned int i;

	str = malloc(sizeof(char) * size);
	if (size == 0 || str == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		str[i] = c;
	return (str);
}
