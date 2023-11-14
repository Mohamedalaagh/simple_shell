#include "shell.h"

/**
 * cmp_env_name - 
 * @nen: 
 * @n: 
 *
 * Return: .
 */
int cmp_env_name(const char *nen, const char *n)
{
    int k;

    for (k = 0; nen[k] != '='; k++)
    {
        if (nen[k] != n[k])
        {
            return (0);
        }
    }

    return (k + 1);
}
/**
 * _getenv -
 * @name: 
 * @_environ:
 *
 * Return: 
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	/* Init ptr_env val */
	ptr_env = NULL;
	mov = 0;
	/* */
	/*  */
	for (i = 0; _environ[i]; i++)
	{
		/* comments here */
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * _env -
 *
 * @datash: 
 * Return: 
 */
int _env(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->_environ[i]; i++)
	{

		for (j = 0; datash->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
