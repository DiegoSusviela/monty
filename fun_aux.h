#ifndef FUN_AUX_H
#define FUN_AUX_H

/* Split */
char **_split(char *s, char *c);
int calc_lines(char *s, char *c);
int check_split_line(char *s, int i, char *c, int *bool_comm, int *type_comm);
void free_split(char **splitted);
void comms_pross(char *s, int *bool, int *i, int *nxComms, int *tComms);

/* fun_aux1 */
stack_t *siguiente(stack_t *loc);
stack_t *anterior(stack_t *loc);
stack_t *es_loc_cad(stack_t *loc);
void insertar_antes(stack_t *a_insertar, stack_t *lugar);
void insertar_despues(stack_t *a_insertar, stack_t *lugar);
int info_dato(stack_t *loc);
stack_t *crear_nodo(int n);
stack_t *add_dnodeint(stack_t **head, int n);
stack_t *remover_de_cadenna(stack_t *loc);
void swap_nodes(stack_t *loc1, stack_t *loc2);
size_t largo_cadena(stack_t *h);
stack_t *add_dnodeint_end(stack_t **head, const int n);
int check_int(char *str);

/* fun_aux2 */
int _strlen(char *buff);
char *_strcpy(char *src);
int _strcmp(char *s1, char *s2);
char *_strcon(char *str1, char *str2);
char *_trim(char *str);
void *_calloc(char *p, int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* fun_print */
size_t print_dlistint(stack_t *h);
int _putchar(char c, int fd);
void _puts(char *str);
void _puts2(char *str);
int print_number(int n);
void imprimir_nodo(stack_t *loc);

/* fun_free */
void liberar_nodo(stack_t *a_liberar);
void free_dlistint(stack_t *head);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);


#endif /* FUN_AUX_H */
