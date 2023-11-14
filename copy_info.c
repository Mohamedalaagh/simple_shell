#include "shell.h"

/**
 * copy_info - for copying information
 * @n: the name 
 * @val: the value
 *
 * Return: 
 */
char *copy_info(char *n, char *val)
{
    char *new;
    int len_n, len_val, len;

    len_n = _strlen(n);
    len_val = _strlen(val);
    len = len_n + len_val + 2;
    new = malloc(sizeof(char) * (len));
    _strcpy(new, n);
    _strcat(new, "=");
    _strcat(new, val);
    _strcat(new, "\0");

    return (new);
}
/**
 * set_env - to set the invironment
 *
 * @n:
 * @val:
 * @datash:
 * Return:
 */
void set_env(char *n, char *val, data_shell *datash)
{
    int i;
    char *var_inv, *name_env;

    for (i = 0; datash->_environ[i]; i++)
    {
        var_inv = _strdup(datash->_environ[i]);
        name_env = _strtok(var_inv, "=");
        if (_strcmp(name_env, n) == 0)
        {
            free(datash->_environ[i]);
            datash->_environ[i] = copy_info(name_env, val);
            free(var_inv);
            return;
        }
        free(var_inv);
    }

    datash->_environ = _reallocdp(datash->_environ, i, sizeof(char *) * (i + 2));
    datash->_environ[i] = copy_info(n, val);
    datash->_environ[i + 1] = NULL;
}
/**
 * _setenv -
 * @dtsh:
 *
 * Return:
 *
 */
int _setenv(data_shell *dtsh)
{
    if (dtsh->args[1] == NULL || dtsh->args[2] == NULL)
    {
        get_error(dtsh, -1);
        return (1);
    }

    set_env(dtsh->args[1], dtsh->args[2], dtsh);

    return (1);
}
/**
 * _unsetenv -
 *
 * @dtsh:
 *
 * Return:
 */
int _unsetenv(data_shell *dtsh)
{
    char **reallcenv;
    char *var_env, *name_env;
    int i, j, k;

    if (dtsh->args[1] == NULL)
    {
        get_error(dtsh, -1);
        return (1);
    }
    k = -1;
    for (i = 0; dtsh->_environ[i]; i++)
    {
        var_env = _strdup(dtsh->_environ[i]);
        name_env = _strtok(var_env, "=");
        if (_strcmp(name_env, dtsh->args[1]) == 0)
        {
            k = i;
        }
        free(var_env);
    }
    if (k == -1)
    {
        get_error(dtsh, -1);
        return (1);
    }
    reallcenv = malloc(sizeof(char *) * (i));
    for (i = j = 0; dtsh->_environ[i]; i++)
    {
        if (i != k)
        {
            reallcenv[j] = dtsh->_environ[i];
            j++;
        }
    }
    reallcenv[j] = NULL;
    free(dtsh->_environ[k]);
    free(dtsh->_environ);
    dtsh->_environ = reallcenv;
    return (1);
}


