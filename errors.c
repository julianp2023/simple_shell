#include "shell.h"

/**
 * _eputs - prints an input string to stderr
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	while (*str)
	{
		_eputchar(*str);
		str++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}

/**
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The file descriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	return (write(fd, &c, 1));
}

/**
 * _putsfd - prints an input string to a given file descriptor
 * @str: the string to be printed
 * @fd: the file descriptor to write to
 *
 * Return: the number of characters written
 */
int _putsfd(char *str, int fd)
{
	int count = 0;

	while (*str)
	{
		count += _putfd(*str, fd);
		str++;
	}
	return (count);
}

