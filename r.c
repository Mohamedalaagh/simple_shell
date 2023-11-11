#include "shell.h"

/**
 * read_line - to read the line 
 *
 * @ief: 
 * Return: 
 */
char *read_line(int *ief) {
    char *input = NULL;
    size_t bsize = 0;

    *ief = getline(&input, &bsize, stdin);

    return input;
}

