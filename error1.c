#include "shell.h"

/**
 * strcat_cd - to make a sting cat
 * @datash: 
 * @msg: 
 * @error: 
 * @ver_str: 
 * Return: 
 */
char *strcat_cd(data_shell *dtsh, char *m, char *er, char *ver_str)
{
    char *i_f;

    _strcpy(er, dtsh->av[0]);
    _strcat(er, ": ");
    _strcat(er, ver_str);
    _strcat(er, ": ");
    _strcat(er, dtsh->args[0]);
    _strcat(er, m);
    if (dtsh->args[1][0] == '-')
    {
        i_f = malloc(3);
        i_f[0] = '-';
        i_f[1] = dtsh->args[1][1];
        i_f[2] = '\0';
        _strcat(er, i_f);
        free(i_f);
    }
    else
    {
        _strcat(er, dtsh->args[1]);
    }

    _strcat(er, "\n");
    _strcat(er, "\0");
    return (er);
}
/**
 * error_get_cd - to get the error in the command line
 * @dtsh:
 * Return:
 */
char *error_get_cd(data_shell *dtsh)
{
    int ln, len_id;
    char *er, *ver_str, *m;

    ver_str = aux_itoa(dtsh->counter);
    if (dtsh->args[1][0] == '-')
    {
        m = ": Illegal option ";
        len_id = 2;
    }
    else
    {
        m = ": can't cd to ";
        len_id = _strlen(dtsh->args[1]);
    }

    ln = _strlen(dtsh->av[0]) + _strlen(dtsh->args[0]);
    ln += _strlen(ver_str) + _strlen(m) + len_id + 5;
    er = malloc(sizeof(char) * (ln + 1));

    if (er == 0)
    {
        free(ver_str);
        return (NULL);
    }

    er = strcat_cd(dtsh, m, er, ver_str);

    free(ver_str);

    return (er);
}
/**
 * error_not_found - validate if there is an error or not
 * @dtshsh:
 * Return:
 */
char *error_not_found(data_shell *dtsh)
{
    int ln;
    char *er;
    char *ver_str;

    ver_str = aux_itoa(dtsh->counter);
    ln = _strlen(dtsh->av[0]) + _strlen(ver_str);
    ln += _strlen(dtsh->args[0]) + 16;
    er = malloc(sizeof(char) * (ln + 1));
    if (er == 0)
    {
        free(er);
        free(ver_str);
        return (NULL);
    }
    _strcpy(er, dtsh->av[0]);
    _strcat(er, ": ");
    _strcat(er, ver_str);
    _strcat(er, ": ");
    _strcat(er, dtsh->args[0]);
    _strcat(er, ": not found\n");
    _strcat(er, "\0");
    free(ver_str);
    return (er);
}
/**
 * error_exit_shell - exit the shell while the error
 * @dtsh:
 *
 * Return:
 */
char *error_exit_shell(data_shell *dtsh)
{
    int ln;
    char *er;
    char *ver_str;

    ver_str = aux_itoa(dtsh->counter);
    ln = _strlen(dtsh->av[0]) + _strlen(ver_str);
    ln += _strlen(dtsh->args[0]) + _strlen(dtsh->args[1]) + 23;
    er = malloc(sizeof(char) * (ln + 1));
    if (er == 0)
    {
        free(ver_str);
        return (NULL);
    }
    _strcpy(er, dtsh->av[0]);
    _strcat(er, ": ");
    _strcat(er, ver_str);
    _strcat(er, ": ");
    _strcat(er, dtsh->args[0]);
    _strcat(er, ": Illegal number: ");
    _strcat(er, dtsh->args[1]);
    _strcat(er, "\n\0");
    free(ver_str);

    return (er);
}

