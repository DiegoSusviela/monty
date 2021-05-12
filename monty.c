#include "principal.h"

globant globalvar;

int find_instruction(char **av)
{
	int i = 0;
	
	globalvar.av = av;
	instruction_t instructions[] = {{"push", push}, {"sub", sub}, {"pstr", pstr},
					{"div", divi}, {"mul", mul}, {"pall", pall},
					{"pint", pint}, {"nop", nop}, {"pchar", pchar},
					{"mod", mod}, {"pop", pop}, {"swap", swap},
					{"add", add}, {"rotl", rotl},
					{"rotr", rotr}, {"stack", stack}, {"queue", queue},
					{NULL, NULL}};
	while (instructions[i].opcode)
	{
		if (_strcmp(instructions[i].opcode, av[0]) == 0)
		{
			instructions[i].f(&globalvar.head, globalvar.ln);
			break;
		}
		i++;
	}
	if (!instructions[i].opcode)
	{
		fprintf(stderr, "L %i: unknown instruction %s\n", globalvar.ln, av[0]);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int main(int ac, char **av)
{
	int fd, i, bytes_read = 0, bytes_used_read = 0;
	char *input = NULL, *new_line = NULL;
	char **lines = NULL, **space_split = NULL;

	globalvar.av = NULL;
	globalvar.ln = 0;
	globalvar.head = NULL;
	globalvar.format = 0;
	globalvar.end = 0;


	if (ac <= 1)
	{
		_puts2("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		_puts2("Error: Can't open file ");
		_puts2(av[1]);
		_puts2("\n");
		exit(EXIT_FAILURE);
	}

	bytes_read = _getline(&input, &bytes_used_read, fd);
	if (bytes_read == -1)
	{
		free(input);
		return (1);
	}

	lines = _split(input, "\n");
	free(input);

	for (i = 0; lines[i] != NULL; i++)
	{
		globalvar.ln++;

		if (lines[i][0] == '\0')
			continue;

		new_line = _trim(lines[i]);
		if (!new_line)
		{
			printf("Es null\n");
			free_split(lines);
            free(new_line);
			exit(EXIT_FAILURE);
		}

		if (lines[i][0] == '#')
        {
            free(new_line);
			continue;
        }

		space_split = _split(new_line, " ");
		find_instruction(space_split);
		free_split(space_split);
		free(new_line);

		if (globalvar.end)
		{
			free_split(lines);
    		free_dlistint(globalvar.head);
			exit(EXIT_FAILURE);
		}
	}
	free_split(lines);
    free_dlistint(globalvar.head);
	return (0);
}
