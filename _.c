#include "shell.h"

/**
 * exit_shell - 
 *
 * @datash: 
 * Return: 
 */
int exit_shell(data_shell *dtsh) {
    unsigned int us;
    int is_digit;
    int strln;
    int bnum;

    if (dtsh->args[1] != NULL) {
        us = _atoi(dtsh->args[1]);
        is_digit = _isdigit(dtsh->args[1]);
        strln = _strlen(dtsh->args[1]);
        bnum = us > (unsigned int)INT_MAX;
        if (!is_digit || strln > 10 || bnum) {
            get_error(dtsh, 2);
            dtsh->status = 2;
            return (1);
        }
        dtsh->status = (us % 256);
    }
    return (0);
}

