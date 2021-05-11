#ifndef FUN_AUX_H
#define FUN_AUX_H

/* Split */
char **_split(char *s, char *c);
int calc_lines(char *s, char *c);
int check_split_line(char *s, int i, char *c, int *bool_comm, int *type_comm);
void free_split(char **splitted);
void comms_pross(char *s, int *bool, int *i, int *nxComms, int *tComms);

/* fun_aux1 */
stack_t *siguiente(const stack_t *loc);
stack_t *anterior(const stack_t *loc);
const stack_t *es_loc_cad(const stack_t *loc);
void insertar_antes(stack_t *a_insertar, stack_t *lugar);
void insertar_despues(stack_t *a_insertar, stack_t *lugar);
int info_dato(stack_t *loc);
stack_t *crear_nodo(const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *remover_de_cadenna(stack_t *loc);
void swap_nodes(stack_t *loc1, stack_t *loc2);
size_t largo_cadena(const stack_t *h);

/* fun_aux2 */
int _strlen(char *buff);
char *_strcpy(char *src);
int _strcmp(char *s1, char *s2);
char *_strcon(char *str1, char *str2);


/* fun_print */
size_t print_dlistint(const stack_t *h);
int _putchar(char c);
void _puts(char *str);
int print_number(int n);
void imprimir_nodo(const stack_t *loc);
size_t print_dlistint(const stack_t *h);


/* fun_free */
void liberar_nodo(stack_t *a_liberar);
void free_dlistint(stack_t *head);


#endif /* FUN_AUX_H */