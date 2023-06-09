#include "main.h"
#include <unistd.h>
/**
* _putchar - writes the character c to stdout.
* @c: char to print.
*
* Return: 1 on success
* On error, -1 is Returned, and errno is set appropriately
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}
