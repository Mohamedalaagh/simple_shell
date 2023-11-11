#include "shell.h"

/**
 * exec_line - execute a command provided in the data_shell structure.
 *
 * @datash: 
 * Return: 
 */
int exec_line(data_shell *dts) {
    int (*builtin)(data_shell *dts);

    if (dts->args[0] == NULL)
        return 1;

    builtin = get_builtin(dts->args[0]);

    if (builtin != NULL)
        return builtin(dts);

    return cmd_exec(dts);
}

