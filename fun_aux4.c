#include "monty.h"

/**
* info_dato - counts the length of a string
* @loc: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

int info_dato(stack_t *loc)
{
	return (loc->n);
}

/**
* crear_nodo - counts the length of a string
* @n: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

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

/**
* add_dnodeint - counts the length of a string
* @head: the buffer pointer
* @n: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/


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


/**
* _calloc - request a space in memory and assign to 0 each one
* @p: pointer to set
* @size: amount of space to reserve
* ----------------------------------------------
* Return: void
*/
void *_calloc(char *p, int size)
{
	int i;

	p = malloc(size);
	if (!p)
		return (NULL);

	for (i = 0; i < size; i++)
		p[i] = 0;

	return (p);
}

/**
* _realloc - re size array
* @ptr: string
* @old_size: int
* @new_size: uns int
* ---------------------------------
* Return: void pointer
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i, cal;
	char *p;
	char *new_ptr;

	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		for (i = 0; i < new_size; i++)
			p[i] = 0;
		return (p);
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size == old_size)
		return (ptr);
	if (new_size > old_size)
		cal = old_size;
	else
		cal = new_size;
	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	new_ptr = ptr;
	for (i = 0; i < cal; i++)
		p[i] = new_ptr[i];
	free(ptr);
	return (p);
}


