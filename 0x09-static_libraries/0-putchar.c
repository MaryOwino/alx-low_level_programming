#include <unistd.h>

/**
 * _putchar - Writes the char c to stdout
 * @c: The character to be printed
 *
 * Return: 1 on Success.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
