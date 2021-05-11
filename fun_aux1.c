#include "fun_aux.h"

stack_t *siguiente(const stack_t *loc)
{
	return (loc->next);
}

stack_t *anterior(const stack_t *loc)
{
	return (loc->prev);
}

const stack_t *es_loc_cad(const stack_t *loc)
{
	if (loc)
		return (loc);
	return (NULL);
}


void insertar_antes(stack_t *a_insertar, stack_t *lugar)
{
	a_insertar->next = lugar;
	if (es_loc_cad(anterior(lugar)))
		lugar->prev->next = a_insertar;
	a_insertar->prev = anterior(lugar);
	lugar->prev = a_insertar;
}

void insertar_despues(stack_t *a_insertar, stack_t *lugar)
{
	a_insertar->prev = lugar;
	a_insertar->next = siguiente(lugar);
	if (es_loc_cad(siguiente(lugar)))
		lugar->next->prev = a_insertar;
	lugar->next = a_insertar;
}

int info_dato(stack_t *loc)
{
	return (loc->n);
}

stack_t *crear_nodo(const int n)
{
	stack_t *nodo = malloc(sizeof(stack_t));

	if (!nodo)
		return (NULL);
	nodo->n = n;
	nodo->prev = NULL;
	nodo->next = NULL;

	return (nodo);
}

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *nuevo_nodo = NULL;

	if (!head)
		return (NULL);

	nuevo_nodo = crear_nodo(n);
	if (!nuevo_nodo)
		return (NULL);
	if (es_loc_cad(*head))
		insertar_antes(nuevo_nodo, *head);
	*head = nuevo_nodo;
	return (nuevo_nodo);
}

stack_t *remover_de_cadenna(stack_t *loc)
{
	if (siguiente(loc))
		loc->next->prev = anterior(loc);
	if (anterior(loc))
		loc->prev->next = siguiente(loc);
	loc->next = NULL;
	loc->prev = NULL;

	return (loc);
}

void swap_nodes(stack_t *loc1, stack_t *loc2)
{
	stack_t *holder1 = siguiente(loc1), *holder2 = anterior(loc1);

	if (anterior(loc1))
		loc1->prev->next = loc2;
	if (siguiente(loc1))
		loc1->next->prev = loc2;
	loc1->next = siguiente(loc2);
	loc1->prev = anterior(loc2);

	if (anterior(loc2))
		loc2->prev->next = loc1;
	if (siguiente(loc2))
		loc2->next->prev = loc1;
	loc2->next = holder1;
	loc1->prev = holder2;
}

size_t largo_cadena(const stack_t *h)
{
	if (es_loc_cad(h))
		return (largo_cadena(siguiente(h)) + 1);
	return (0);
}
