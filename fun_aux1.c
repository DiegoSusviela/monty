#include "monty.h"

/**
* siguiente - counts the length of a string
* @loc: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

stack_t *siguiente(stack_t *loc)
{
	return (loc->next);
}

/**
* anterior - counts the length of a string
* @loc: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

stack_t *anterior(stack_t *loc)
{
	return (loc->prev);
}

/**
* es_loc_cad - counts the length of a string
* @loc: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

stack_t *es_loc_cad(stack_t *loc)
{
	if (loc)
		return (loc);
	return (NULL);
}

/**
* insertar_antes - counts the length of a string
* @a_insertar: the buffer pointer
* @lugar: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

void insertar_antes(stack_t *a_insertar, stack_t *lugar)
{
	a_insertar->next = lugar;
	if (es_loc_cad(anterior(lugar)))
		lugar->prev->next = a_insertar;
	a_insertar->prev = anterior(lugar);
	lugar->prev = a_insertar;
}

/**
* insertar_despues - counts the length of a string
* @a_insertar: the buffer pointer
* @lugar: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/

void insertar_despues(stack_t *a_insertar, stack_t *lugar)
{
	a_insertar->prev = lugar;
	a_insertar->next = siguiente(lugar);
	if (es_loc_cad(siguiente(lugar)))
		lugar->next->prev = a_insertar;
	lugar->next = a_insertar;
}
