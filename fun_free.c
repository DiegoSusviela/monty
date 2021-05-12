#include "monty.h"

/**
* liberar_nodo - counts the length of a string
* @a_liberar: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

void liberar_nodo(stack_t *a_liberar)
{
	free(a_liberar);
}

/**
* free_dlistint - counts the length of a string
* @head: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

void free_dlistint(stack_t *head)
{
	stack_t *loc = head;

	if (!loc)
		return;
	loc = siguiente(loc);
	liberar_nodo(head);
	free_dlistint(loc);
}

/**
* delete_dnodeint_at_index - counts the length of a string
* @head: the buffer pointer
* @index: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *aux = *head;

	if (!head || !*head)
		return (-1);

	if (!index)
	{
		*head = siguiente(aux);
		if (siguiente(aux))
			aux->next->prev = NULL;
		liberar_nodo(aux);
		return (1);
	}

	while (aux && index > 0)
	{
		aux = siguiente(aux);
		index--;
	}
	if (aux)
	{
		aux->prev->next = siguiente(aux);
		if (siguiente(aux))
			aux->next->prev = anterior(aux);
		liberar_nodo(aux);
		return (1);
	}
	return (-1);
}

/**
* imprimir_nodo - counts the length of a string
* @loc: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

void imprimir_nodo(stack_t *loc)
{
	print_number(info_dato(loc));
	_putchar('\n', 1);
}
