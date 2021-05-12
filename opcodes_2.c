#include "monty.h"

/**
* pstr - counts the length of a string
* @head: the buffer pointer
* @line_number: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *aux = *head;
	(void)line_number;

	for (; aux && info_dato(aux) != 0;)
	{
		if (info_dato(aux) >= 0 && info_dato(aux) <= 126)
			_putchar(info_dato(aux), 1);

		aux = siguiente(aux);
	}
	_putchar('\n', 1);
}

/**
* rotl - counts the length of a string
* @head: the buffer pointer
* @line_number: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *loc = globalvar.head;
	(void)line_number;

	if (!(*head && siguiente(*head)))
		return;
	globalvar.head = siguiente(globalvar.head);
	remover_de_cadenna(loc);
	add_dnodeint_end(head, info_dato(loc));
	liberar_nodo(loc);
}

/**
* rotr - counts the length of a string
* @head: the buffer pointer
* @line_number: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

void rotr(stack_t **head, unsigned int line_number)
{
	stack_t *aux = *head;
	(void)line_number;

	for (; aux;)
	{
		if (!siguiente(aux))
		{
			add_dnodeint(head, remover_de_cadenna(aux)->n);
			liberar_nodo(aux);
		}

		aux = siguiente(aux);
	}
}

/**
* stack - counts the length of a string
* @head: the buffer pointer
* @line_number: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

void stack(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	globalvar.format = 0;
}

/**
* queue - counts the length of a string
* @head: the buffer pointer
* @line_number: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

void queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	globalvar.format = 1;
}