#include "principal.h"

void push(stack_t **head, unsigned int line_number)
{
	if (!globalvar.av[1] /*|| not_num(av[1])*/)
	{
		fprintf(stderr, "L %i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	add_dnodeint(&globalvar.head, atoi(globalvar.av[1]));
}

void pall(stack_t **head, unsigned int line_number)
{
	print_dlistint(globalvar.head);
}

void pint(stack_t **head, unsigned int line_number)
{
	if (!globalvar.head)
	{
		fprintf(stderr, "L %i: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	imprimir_nodo(globalvar.head);
}

void pop(stack_t **head, unsigned int line_number)
{
	stack_t *loc = siguiente(globalvar.head);

	if (!globalvar.head)
	{
		fprintf(stderr, "L %i: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	remover_de_cadenna(globalvar.head);
	globalvar.head = loc;
}

void swap(stack_t **head, unsigned int line_number)
{
	stack_t *loc;

	if (!globalvar.head || !siguiente(globalvar.head))
	{
		fprintf(stderr, "L %i: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	loc = remover_de_cadenna(siguiente(globalvar.head));
	insertar_antes(loc, globalvar.head);
	/*swap_nodes(globalvar.head, siguiente(globalvar.head));*/
	/*add_dnodeint(globalvar.head);*/
	globalvar.head = loc;
}

void add(stack_t **head, unsigned int line_number)
{
	if (!globalvar.head || !siguiente(globalvar.head))
	{
		fprintf(stderr, "L %i: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	globalvar.head->next->n = info_dato(siguiente(globalvar.head)) + info_dato(globalvar.head);
	delete_dnodeint_at_index(&globalvar.head, 0);
	return;
}

void nop(stack_t **head, unsigned int line_number)
{
	return;
}

void sub(stack_t **head, unsigned int line_number)
{
	if (!globalvar.head || !siguiente(globalvar.head))
	{
		fprintf(stderr, "L %i: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	globalvar.head->next->n = info_dato(siguiente(globalvar.head)) - info_dato(globalvar.head);
	delete_dnodeint_at_index(&globalvar.head, 0);
	return;
}

void divi(stack_t **head, unsigned int line_number)
{
	if (!globalvar.head || !siguiente(globalvar.head))
	{
		fprintf(stderr, "L %i: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	if (globalvar.head->n == 0)
	{
		fprintf(stderr, "L %i: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	globalvar.head->next->n = info_dato(siguiente(globalvar.head)) / info_dato(globalvar.head);
	delete_dnodeint_at_index(&globalvar.head, 0);
	return;
}

void mul(stack_t **head, unsigned int line_number)
{
	if (!globalvar.head || !siguiente(globalvar.head))
	{
		fprintf(stderr, "L %i: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	globalvar.head->next->n = info_dato(siguiente(globalvar.head)) * info_dato(globalvar.head);
	delete_dnodeint_at_index(&globalvar.head, 0);
	return;
}

void mod(stack_t **head, unsigned int line_number)
{
	if (!globalvar.head || !siguiente(globalvar.head))
	{
		fprintf(stderr, "L %i: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (globalvar.head->n == 0)
	{
		fprintf(stderr, "L %i: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	globalvar.head->next->n = info_dato(siguiente(globalvar.head)) % info_dato(globalvar.head);
	delete_dnodeint_at_index(&globalvar.head, 0);
	return;
}

void pchar(stack_t **head, unsigned int line_number)
{
	if (!globalvar.head)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (info_dato(globalvar.head) >= 0 && info_dato(globalvar.head) <= 126)
		_putchar(info_dato(globalvar.head), 1);
	else		
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	return;
}

void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *aux = *head;

	for (; aux && info_dato(aux) != 0;)
	{
		if (info_dato(aux) >= 0 && info_dato(aux) <= 126)
			_putchar(info_dato(aux), 1);

		aux = siguiente(aux);
	}
	_putchar('\n', 1);

	return;
}

void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *loc = globalvar.head;

	if (!(*head && siguiente(*head)))
		return;

	globalvar.head = siguiente(globalvar.head);
	remover_de_cadenna(loc);
	add_dnodeint_end(head, info_dato(loc));
	return;
}

void rotr(stack_t **head, unsigned int line_number)
{
	stack_t *aux = *head;
	
	for (; aux;)
	{
		if (!siguiente(aux))
			add_dnodeint(head, remover_de_cadenna(aux)->n);		

		aux = siguiente(aux);
	}
	
	return;
}

void stack(stack_t **head, unsigned int line_number)
{
	return;
}

void queue(stack_t **head, unsigned int line_number)
{
	return;
}