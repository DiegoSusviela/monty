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
	if (!*head)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		globalvar.end = 1;
		return;
	}
	if (isascii(info_dato(*head)))
		printf("%c\n", info_dato(*head));
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		globalvar.end = 1;
		return;
	}
}
