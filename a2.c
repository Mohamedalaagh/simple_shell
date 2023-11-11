#include "shell.h"

/**
 * aux_help - Displays information about the help command
 * Return: nothing
 */
void aux_help(void)
{
    char *hp = "help: help [-dms] [pattern ...]\n";

    write(STDOUT_FILENO, hp, _strlen(hp));
    hp = "\tDisplay information about builtin commands.\n ";
    write(STDOUT_FILENO, hp, _strlen(hp));
    hp = "Displays brief summaries of builtin commands.\n";
    write(STDOUT_FILENO, hp, _strlen(hp));
}
/**
 * aux_help_alias - Displays information about the alias command.
 * Return: nothing
 */
void aux_help_alias(void)
{
    char *hp = "alias: alias [-p] [name[=value]...]\n";

    write(STDOUT_FILENO, hp, _strlen(hp));
    hp = "\tDefine or display aliases.\n ";
    write(STDOUT_FILENO, hp, _strlen(hp));
}
/**
 * aux_help_cd - Displays information about the cd command
 * Return: nothing
 */
void aux_help_cd(void)
{
    char *hp = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

    write(STDOUT_FILENO, hp, _strlen(hp));
    hp = "\tChange the shell working directory.\n ";
    write(STDOUT_FILENO, hp, _strlen(hp));
}
