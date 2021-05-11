#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#include "struct.h"
#include "fun_aux.h"
#include "opcode.h"

int _getline(char **fill, int *n, int where_read);
char *add_aux_to_fill(char *fill, char *aux, int aux_size);


#endif /* PRINCIPAL_H */