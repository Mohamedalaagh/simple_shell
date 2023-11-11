#include "shell.h"

/**
 * aux_help_env - provide a brief help message or description for the env command.
 *  The env command in Unix-like operating systems is used to display the environment variables of the shell.
 * Return: nothing
 */
void aux_help_env(void) {
    char *hp = "env: env [option] [name=value] [command [args]]\n\t";

    write(STDOUT_FILENO, hp, _strlen(hp));

    hp = "Print the environment of the shell.\n";

    write(STDOUT_FILENO, hp, _strlen(hp));
}

/**
 * aux_help_setenv - provide a brief help message or description for the setenv function
 * Return: nothing
 */
void aux_help_setenv(void) {
    char *hp = "setenv: setenv (const char *name, const char *value,";

    write(STDOUT_FILENO, hp, _strlen(hp));

    hp = "int replace)\n\t";

    write(STDOUT_FILENO, hp, _strlen(hp));

    hp = "Add a new definition to the environment\n";

    write(STDOUT_FILENO, hp, _strlen(hp));
}

/**
 * aux_help_unsetenv - provide a brief help message or description for the unsetenv function
 * Return: nothing
 */
void aux_help_unsetenv(void) {
    char *hp = "unsetenv: unsetenv (const char *name)\n\t";

    write(STDOUT_FILENO, hp, _strlen(hp));

    hp = "Remove an entry completely from the environment\n";

    write(STDOUT_FILENO, hp, _strlen(hp));
}


/**
 * aux_help_general - to provide a general help message or description for a shell program 
 * Return: nothing
 */
void aux_help_general(void) {
    char *hp = "^-^ bash, version 1.0(1)-release\n";

    write(STDOUT_FILENO, hp, _strlen(hp));

    hp = "These commands are defined internally. Type 'help' to see the list";
    write(STDOUT_FILENO, hp, _strlen(hp));

    hp = "Type 'help name' to find out more about the function 'name'.\n\n ";
    write(STDOUT_FILENO, hp, _strlen(hp));

    hp = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
    write(STDOUT_FILENO, hp, _strlen(hp));

    hp = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
    write(STDOUT_FILENO, hp, _strlen(hp));

    hp = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
    write(STDOUT_FILENO, hp, _strlen(hp));

    hp = "unsetenv [variable]\n";
    write(STDOUT_FILENO, hp, _strlen(hp));
}
/**
 * aux_help_exit -
 * Return: nothing
 */
void aux_help_exit(void) {
    char *h = "exit: exit [n]\n Exit shell.\n";

    write(STDOUT_FILENO, h, _strlen(h));

    h = "Exits the shell with a status of N. If N is omitted, the exit";
    write(STDOUT_FILENO, h, _strlen(h));

    h = "status is that of the last command executed\n";
    write(STDOUT_FILENO, h, _strlen(h));
}

