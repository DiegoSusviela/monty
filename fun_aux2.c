#include "principal.h"

/**
* _strlen - counts the length of a string
* @buff: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/
int _strlen(char *buff)
{
	int len;

	if (!buff)
		return (0);
	for (len = 0; buff[len] != '\0'; len++)
		; /* Cursed  */

	return (len);
}

/**
* _strcpy - copies a string
* @src: the source string
*
* Return: A pointer to the copy of str
*/
char *_strcpy(char *src)
{
	int i;
	int src_len = _strlen(src) + 1;
	char *dest;

	dest = malloc(src_len * sizeof(char));
	if (!dest)
		return (NULL);

	for (i = 0; i < (src_len - 1); i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}

/**
 *_strcmp - caracol
 *@s1: *
 *@s2: *
 *
 *Return: *
*/
int _strcmp(char *s1, char *s2)
{
	int i, s1C = _strlen(s1), s2C = _strlen(s2), con = 0, ret = 0;

	if (s1C > s2C)
		con = s1C;
	else
		con = s2C;
	for (i = 0; i < con; i++)
	{
		ret = s1[i] - s2[i];
		if (ret != 0)
			break;
	}
	return (ret);
}

/**
 *_strcon - Concatenate two strings
 *@str1: Str to concatenate
 *@str2: Str to concatenate
 *
 *Return: A pointer that has the concatenation
*/
char *_strcon(char *str1, char *str2)
{
	int i = 0, j = 0, len = 0;
	char *aux;

	len = _strlen(str1) + _strlen(str2);
		aux = malloc((len + 1) * sizeof(char));

	for (i = 0; str1 != NULL && str1[i] != '\0'; i++)
		aux[i] = str1[i];

	for (j = 0; str2 != NULL && str2[j] != '\0'; i++, j++)
		aux[i] = str2[j];
	aux[i] = '\0';

	return (aux);
}

char *_trim(char *str)
{
    int i, j, len_new = 0;
    char *new_str = NULL;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
            len_new++;
        else if (i > 0 && str[i + 1] != '\0' && str[i - 1] != ' ' && str[i + 1] != ' ')
            len_new++;
        else if (i > 0 && str[i + 1] != '\0' && str[i - 1] != ' ' && str[i + 1] == ' ')
            len_new++;
    }

    new_str = malloc((len_new + 1) * sizeof(char));
    if (!new_str)
        return (NULL);
    
    for (i = 0, j = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
            new_str[j++] = str[i];
        else if (i > 0 && str[i + 1] != '\0' && str[i - 1] != ' ' && str[i + 1] != ' ')
            new_str[j++] = str[i];
        else if (i > 0 && str[i + 1] != '\0' && str[i - 1] != ' ' && str[i + 1] == ' ')
            new_str[j++] = str[i];
    }
    new_str[j] = '\0';

    return (new_str);
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
