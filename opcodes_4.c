#include "monty.h"

/**
* add - counts the length of a string
* @head: the buffer pointer
* @line_number: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

void add(stack_t **head, unsigned int line_number)
{
	if (!globalvar.head || !siguiente(globalvar.head))
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		globalvar.end = 1;
		return;
	}
	globalvar.head->next->n = info_dato(siguiente(*head)) + info_dato(*head);
	delete_dnodeint_at_index(&globalvar.head, 0);
}

/**
* nop - counts the length of a string
* @head: the buffer pointer
* @line_number: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

void nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}
