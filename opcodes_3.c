#include "monty.h"


/**
* sub - counts the length of a string
* @head: the buffer pointer
* @line_number: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

void sub(stack_t **head, unsigned int line_number)
{
	if (!globalvar.head || !siguiente(globalvar.head))
	{
		fprintf(stderr, "L%i: can't sub, stack too short\n", line_number);
		globalvar.end = 1;
		return;
	}
	globalvar.head->next->n = info_dato(siguiente(*head)) - info_dato(*head);
	delete_dnodeint_at_index(&globalvar.head, 0);
}


/**
* divi - counts the length of a string
* @head: the buffer pointer
* @line_number: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/


void divi(stack_t **head, unsigned int line_number)
{
	(void)head;
	if (!globalvar.head || !siguiente(globalvar.head))
	{
		fprintf(stderr, "L%i: can't div, stack too short\n", line_number);
		globalvar.end = 1;
		return;
	}

	if (globalvar.head->n == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", line_number);
		globalvar.end = 1;
		return;
	}

	globalvar.head->next->n = info_dato(siguiente(*head)) / info_dato(*head);
	delete_dnodeint_at_index(&globalvar.head, 0);
}

/**
* mul - counts the length of a string
* @head: the buffer pointer
* @line_number: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

void mul(stack_t **head, unsigned int line_number)
{
	(void)head;
	if (!globalvar.head || !siguiente(globalvar.head))
	{
		fprintf(stderr, "L%i: can't mul, stack too short\n", line_number);
		globalvar.end = 1;
		return;
	}
	globalvar.head->next->n = info_dato(siguiente(*head)) * info_dato(*head);
	delete_dnodeint_at_index(&globalvar.head, 0);
}

/**
* mod - counts the length of a string
* @head: the buffer pointer
* @line_number: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

void mod(stack_t **head, unsigned int line_number)
{
	(void)head;
	if (!globalvar.head || !siguiente(globalvar.head))
	{
		fprintf(stderr, "L%i: can't mod, stack too short\n", line_number);
		globalvar.end = 1;
		return;
	}

	if (globalvar.head->n == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", line_number);
		globalvar.end = 1;
		return;
	}

	globalvar.head->next->n = info_dato(siguiente(*head)) % info_dato(*head);
	delete_dnodeint_at_index(&globalvar.head, 0);
}

/**
* pchar - counts the length of a string
* @head: the buffer pointer
* @line_number: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

void pchar(stack_t **head, unsigned int line_number)
{
	(void)head;
	if (!globalvar.head)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		globalvar.end = 1;
		return;
	}
	if (info_dato(globalvar.head) >= 0 && info_dato(globalvar.head) <= 126)
	{
		_putchar(info_dato(globalvar.head), 1);
		printf("\n");
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		globalvar.end = 1;
		return;
	}
}
