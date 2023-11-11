#include "shell.h"

/**
 * _memcpy - to copy the string to another at a givin size
 * @nptr: first string 
 * @ptr: second
 * @size: the size
 *
 * Return: 
 */
void _memcpy(void *nptr, const void *ptr, unsigned int size) {
    char *chptr = (char *)ptr;
    char *chnptr = (char *)nptr;
    unsigned int i;

    for (i = 0; i < size; i++)
        chnptr[i] = chptr[i];
}
/**
 * _realloc -  used for memory reallocation in C
 * @ptr: pointer to string
 * @old_size: 
 * @new_size: 
 *
 * Return: 
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size) {
    void *nptr;

    if (ptr == NULL)
        return (malloc(new_size));

    if (new_size == 0) {
        free(ptr);
        return (NULL);
    }

    if (new_size == old_size)
        return (ptr);

    nptr = malloc(new_size);
    if (nptr == NULL)
        return (NULL);

    if (new_size < old_size)
        _memcpy(nptr, ptr, new_size);
    else
        _memcpy(nptr, ptr, old_size);

    free(ptr);
    return (nptr);
}
/**
 * _reallocdp -  reallocate an array of pointers to strings (char **).
 * @ptr:
 * @old_size: 
 * @new_size: 
 *
 * Return: 
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size) {
    char **nptr;
    unsigned int i;

    if (ptr == NULL)
        return (malloc(sizeof(char *) * new_size));

    if (new_size == old_size)
        return (ptr);

    nptr = malloc(sizeof(char *) * new_size);
    if (nptr == NULL)
        return (NULL);

    for (i = 0; i < old_size; i++)
        nptr[i] = ptr[i];

    free(ptr);

    return (nptr);
}

