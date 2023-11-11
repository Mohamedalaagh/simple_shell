#include "shell.h"

/**
 * bring_line -  handle the allocation and management of a line buffer.
 * @lptr: 
 * @buff: 
 * @n: 
 * @i: 
 */
void bring_line(char **lptr, size_t *n, char *buff, size_t i) {

    if (*lptr == NULL) {
        if (i > BUFSIZE)
            *n = i;
        else
            *n = BUFSIZE;
        *lptr = buff;
    }
    else if (*n < i) {
        if (i > BUFSIZE)
            *n = i;
        else
            *n = BUFSIZE;
        *lptr = buff;
    }
    else {
        _strcpy(*lptr, buff);
        free(buff);
    }
}
/**
 * get_line - to get a specific line from the file
 * @lptr: 
 * @n: 
 * @stm: 
 * Return: 
 */
ssize_t get_line(char **lptr, size_t *n, FILE *stm) {
    int i;
    static ssize_t input;
    ssize_t rval;
    char *buff;
    char t = 'z';

    if (input == 0)
        fflush(stm);
    else
        return (-1);
    input = 0;

    buff = malloc(sizeof(char) * BUFSIZE);
    if (buff == 0)
        return (-1);
    while (t != '\n') {
        i = read(STDIN_FILENO, &t, 1);
        if (i == -1 || (i == 0 && input == 0)) {
            free(buff);
            return (-1);
        }
        if (i == 0 && input != 0) {
            input++;
            break;
        }
        if (input >= BUFSIZE)
            buff = _realloc(buff, input, input + 1);
        buff[input] = t;
        input++;
    }
    buff[input] = '\0';
    bring_line(lptr, n, buff, input);
    rval = input;
    if (i != 0)
        input = 0;
    return (rval);
}

