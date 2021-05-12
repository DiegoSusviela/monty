#include "monty.h"

/**
 * print_dlistint - writes the character c to stdout
 * @h: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

size_t print_dlistint(stack_t *h)
{
	if (es_loc_cad(h))
	{
		imprimir_nodo(h);
		return (print_dlistint(siguiente(h)) + 1);
	}
	return (0);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
 
int _putchar(char c, int fd)
{
	return (write(fd, &c, 1));
}

/**
 * _puts2 - Entry point
 * @str: string top print
 *
 * Description: prints a string
 * Return: Always 0 (Success)
 */

void _puts2(char *str)
{
	int marker = 0;

	while (*(str + marker))
	{
		_putchar(*(str + marker), 2);
		marker++;
	}
}


/**
 * _puts - Entry point
 * @str: string top print
 *
 * Description: prints a string
 * Return: Always 0 (Success)
 */

void _puts(char *str)
{
	int marker = 0;

	while (*(str + marker))
	{
		_putchar(*(str + marker), 1);
		marker++;
	}
}

int print_number(int n)
{
	int largo = 0;
	unsigned int num;

	if (n < 0)
	{
		_putchar('-', 1);
		num = -n;
	}
	else
		num = n;
	if (num / 10 != 0)
		largo = print_number(num / 10);
	_putchar('0' + (num % 10), 1);

	largo++;
	return (largo);
}


void imprimir_nodo(stack_t *loc)
{
	print_number(info_dato(loc));
	_putchar('\n', 1);
}

