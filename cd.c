#include "shell.h"

/**
 * cd_shell - 
 * @dtsh: 
 * Return: 
 */
int cd_shell(data_shell *dtsh)
{
    char *directory;
    int ishouse, ishome2, isddash;

    directory = dtsh->args[1];

    if (directory != NULL)
    {
        ishouse = _strcmp("$HOME", directory);
        ishome2 = _strcmp("~", directory);
        isddash = _strcmp("--", directory);
    }

    if (directory == NULL || !ishouse || !ishome2 || !isddash)
    {
        cd_to_home(dtsh);
        return (1);
    }

    if (_strcmp("-", directory) == 0)
    {
        cd_previous(dtsh);
        return (1);
    }

    if (_strcmp(".", directory) == 0 || _strcmp("..", directory) == 0)
    {
        cd_dot(dtsh);
        return (1);
    }

    cd_to(dtsh);

    return (1);
}

