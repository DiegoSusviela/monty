
/*
instruction_t instructions[] = {{"push", push}, {"sub", sub}, {"pstr", pstr},
								{"div", divi}, {"mul", mul}, {"pall", pall},
								{"pint", pint}, {"nop", nop}, {"pchar", pchar},
								{"mod", mod}, {"pop", pop}, {"swap", sw},
								{"add", add}, {"rotl", rotl}, 
								{"rotr", rotr}, {NULL, NULL}};
*/
int main(int ac, char *av)
{
    int fd, sz;
    char *c = NULL;

    if (ac < 1)
    {
        _puts2("USAGE: monty file");
        exit(EXIT_FAILURE);
    }

    fd = open(av[1], O_RDONLY);
	if (!fd)
	{
		_puts2("Error: Can't open file <file>");
		exit(EXIT_FAILURE);
	}

    sz = read(fd, &c, 124);

    _puts(sz);

	return (0);
}