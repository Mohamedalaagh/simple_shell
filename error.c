#include "shell.h"

/**
 * error_env - to env the error
 * @dtsh: 
 * Return: 
 */
char *er_env(data_shell *dtsh)
{
    int lg;
    char *er;
    char *ver_str;
    char *m;

    ver_str = aux_itoa(dtsh->counter);
    m = ": Unable to add/remove from environment\n";
    lg = _strlen(dtsh->av[0]) + _strlen(ver_str);
    lg += _strlen(dtsh->args[0]) + _strlen(m) + 4;
    er = malloc(sizeof(char) * (lg + 1));
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
    _strcat(er, m);
    _strcat(er, "\0");
    free(ver_str);

    return (er);
}
/**
 * error_path_126 - to give the path of the error
 * @dtsh: 
 *
 * Return: 
 */
char *er_path_126(data_shell *dtsh)
{
    int ln;
    char *ver_str;
    char *er;

    ver_str = aux_itoa(dtsh->counter);
    ln = _strlen(dtsh->av[0]) + _strlen(ver_str);
    ln += _strlen(dtsh->args[0]) + 24;
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
    _strcat(er, ": Permission denied\n");
    _strcat(er, "\0");
    free(ver_str);
    return (er);
}

