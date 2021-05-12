#include "monty.h"

/**
* push - counts the length of a string
* @head: the buffer pointer
* @line_number: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

void push(stack_t **head, unsigned int line_number)
{
	(void)head;
	if (!globalvar.av[1] || !check_int(globalvar.av[1]))
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		globalvar.end = 1;
		return;
	}

	if (globalvar.format == 0)
		add_dnodeint(&globalvar.head, atoi(globalvar.av[1]));
	else
		add_dnodeint_end(&globalvar.head, atoi(globalvar.av[1]));
}

/**
* pall - counts the length of a string
* @head: the buffer pointer
* @line_number: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

void pall(stack_t **head, unsigned int line_number)
{
	(void)line_number;
	(void)head;
	print_dlistint(globalvar.head);
}

/**
* pint - counts the length of a string
* @head: the buffer pointer
* @line_number: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

void pint(stack_t **head, unsigned int line_number)
{
	(void)head;
	if (!globalvar.head)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		globalvar.end = 1;
		return;
	}
	imprimir_nodo(globalvar.head);
}

/**
* pop - counts the length of a string
* @head: the buffer pointer
* @line_number: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

void pop(stack_t **head, unsigned int line_number)
{
	stack_t *loc;

	(void)head;

	if (!globalvar.head)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		globalvar.end = 1;
		return;
	}
	loc = siguiente(globalvar.head);
	liberar_nodo(remover_de_cadenna(globalvar.head));
	globalvar.head = loc;
}

/**
* swap - counts the length of a string
* @head: the buffer pointer
* @line_number: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

void swap(stack_t **head, unsigned int line_number)
{
	stack_t *loc;

	(void)head;

	if (!globalvar.head || !siguiente(globalvar.head))
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
		globalvar.end = 1;
		return;
	}
	loc = remover_de_cadenna(siguiente(globalvar.head));
	insertar_antes(loc, globalvar.head);
	globalvar.head = loc;
}
