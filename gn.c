#include "shell.h"

/**
 * get_builtin - 
 * @cm: 
 * Return: 
 */
int (*get_builtin(char *cm))(data_shell *)
{
    builtin_t builtin[] = {
        { "env", _env },
        { "exit", exit_shell },
        { "setenv", _setenv },
        { "unsetenv", _unsetenv },
        { "cd", cd_shell },
        { "help", get_help },
        { NULL, NULL }
    };
    int i;

    for (i = 0; builtin[i].name; i++)
    {
        if (_strcmp(builtin[i].name, cm) == 0)
            break;
    }
    return (builtin[i].f);
}

