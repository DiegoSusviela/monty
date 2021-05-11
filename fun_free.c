#include "fun_aux.h"

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
