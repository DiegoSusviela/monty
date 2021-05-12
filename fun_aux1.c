#include "principal.h"

stack_t *siguiente(stack_t *loc)
{
	return (loc->next);
}

stack_t *anterior(stack_t *loc)
{
	return (loc->prev);
}

stack_t *es_loc_cad(stack_t *loc)
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

stack_t *crear_nodo(int n)
{
	stack_t *nodo = malloc(sizeof(stack_t));

	if (!nodo)
		return (NULL);
	nodo->n = n;
	nodo->prev = NULL;
	nodo->next = NULL;

	return (nodo);
}

stack_t *add_dnodeint(stack_t **head, int n)
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

size_t largo_cadena(stack_t *h)
{
	if (es_loc_cad(h))
		return (largo_cadena(siguiente(h)) + 1);
	return (0);
}


stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *nuevo_nodo = NULL;
	stack_t *aux = *head;

	if (!head)
		return (NULL);

	nuevo_nodo = crear_nodo(n);
	if (!nuevo_nodo)
		return (NULL);
	if (!*head)
	{
		*head = nuevo_nodo;
		return (nuevo_nodo);
	}
	while (siguiente(aux))
		aux = siguiente(aux);
	insertar_despues(nuevo_nodo, aux);
	return (nuevo_nodo);
}

int check_int(char *str)
{
	int i;

	if (str[0] == '\0')
		return (0);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
	}

	return (1);
}