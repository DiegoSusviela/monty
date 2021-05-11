#include "principal.h"

void liberar_nodo(stack_t *a_liberar)
{
	free(a_liberar);
}

void free_dlistint(stack_t *head)
{
	stack_t *loc = head;

	if (!loc)
		return;
	loc = siguiente(loc);
	liberar_nodo(head);
	free_dlistint(loc);
}

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
