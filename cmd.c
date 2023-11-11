#include "shell.h"

/**
 * is_cdir - part of a routine that works with a string path representing 
 * a sequence of directories separated by colons (':').
 * @path: 
 * @k: 
 * Return: 
 */
int is_cdir(char *path, int *k) {
    if (path[*k] == ':')
        return (1);

    while (path[*k] != ':' && path[*k]) {
        *k += 1;
    }

    if (path[*k])
        *k += 1;

    return (0);
}
/**
 * _which -  locate the executable file associated with the given command in the user's environment
 * @cmd: 
 * @environment: 
 * Return: 
 */
char *_which(char *cmd, char **environment)
{
    char *path, *ptr_path, *token_path, *directory;
    int len_dir, len_cmd, i;
    struct stat fst;

    path = _getenv("PATH", environment);
    if (path)
    {
        ptr_path = _strdup(path);
        len_cmd = _strlen(cmd);
        token_path = _strtok(ptr_path, ":");
        i = 0;
        while (token_path != NULL)
        {
            if (is_cdir(path, &i))
                if (stat(cmd, &fst) == 0)
                    return cmd;

            len_dir = _strlen(token_path);
            directory = malloc(len_dir + len_cmd + 2);
            _strcpy(directory, token_path);
            _strcat(directory, "/");
            _strcat(directory, cmd);
            _strcat(directory, "\0");

            if (stat(directory, &fst) == 0)
            {
                free(ptr_path);
                return directory;
            }

            free(directory);
            token_path = _strtok(NULL, ":");
        }
        free(ptr_path);

        if (stat(cmd, &fst) == 0)
            return cmd;

        return NULL;
    }

    if (cmd[0] == '/')
        if (stat(cmd, &fst) == 0)
            return cmd;

    return NULL;
}
/**
 * is_executable - excute the file
 * @datashell: 
 * Return: 
 */
int is_executable(data_shell *datashell)
{
    struct stat st;
    int k;
    char *input;

    input = datashell->args[0];
    for (k = 0; input[k]; k++)
    {
        if (input[k] == '.')
        {
            if (input[k + 1] == '.')
                return 0;
            if (input[k + 1] == '/')
                continue;
            else
                break;
        }
        else if (input[k] == '/' && k != 0)
        {
            if (input[k + 1] == '.')
                continue;
            k++;
            break;
        }
        else
            break;
    }
    if (k == 0)
        return 0;

    if (stat(input + k, &st) == 0)
    {
        return k;
    }
    get_error(datashell, 127);
    return -1;
}
/**
 * check_error_cmd - handle error conditions related to command execution.
 * @directory: 
 * @datashell: 
 * Return: 
 */
int check_error_cmd(char *directory, data_shell *datashell)
{
    if (directory == NULL)
    {
        get_error(datashell, 127);
        return 1;
    }

    if (_strcmp(datashell->args[0], directory) != 0)
    {
        if (access(directory, X_OK) == -1)
        {
            get_error(datashell, 126);
            free(directory);
            return 1;
        }
        free(directory);
    }
    else
    {
        if (access(datashell->args[0], X_OK) == -1)
        {
            get_error(datashell, 126);
            return 1;
        }
    }

    return 0;
}
/**
 * cmd_exec - 
 * @datashell: 
 * Return: 
 */
int cmd_exec(data_shell *datashell)
{
    pid_t pd;
    pid_t wpd;
    int st;
    int exe;
    char *directory;
    (void) wpd;

    exe = is_executable(datashell);
    if (exe == -1)
        return 1;
    if (exe == 0)
    {
        directory = _which(datashell->args[0], datashell->_environ);
        if (check_error_cmd(directory, datashell) == 1)
            return 1;
    }

    pd = fork();
    if (pd == 0)
    {
        if (exe == 0)
            directory = _which(datashell->args[0], datashell->_environ);
        else
            directory = datashell->args[0];
        execve(directory + exe, datashell->args, datashell->_environ);
    }
    else if (pd < 0)
    {
        perror(datashell->av[0]);
        return 1;
    }
    else
    {
        do {
            wpd = waitpid(pd, &st, WUNTRACED);
        } while (!WIFEXITED(st) && !WIFSIGNALED(st));
    }

    datashell->status = st / 256;
    return 1;
}

