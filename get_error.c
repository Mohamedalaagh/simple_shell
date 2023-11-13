#include "shell.h"

/**
 * get_error - to get the standerd error
 * @dtsh: 
 * @ev: 
 * Return: 
 */
int get_error(data_shell *dtsh, int ev)
{
    char *er;

    switch (ev)
    {
    case -1:
        er = error_env(dtsh);
        break;
    case 126:
        er = error_path_126(dtsh);
        break;
    case 127:
        er = error_not_found(dtsh);
        break;
    case 2:
        if (_strcmp("exit", dtsh->args[0]) == 0)
            er = error_exit_shell(dtsh);
        else if (_strcmp("cd", dtsh->args[0]) == 0)
            er = error_get_cd(dtsh);
        break;
    }

    if (er)
    {
        write(STDERR_FILENO, er, _strlen(er));
        free(er);
    }

    dtsh->status = ev;
    return (ev);
}

