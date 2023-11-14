#include "shell.h"

/**
 * _strdup - 
 * @strin: 
 * Return: 
 */
char *_strdup(const char *strin)
{
    char *n;
    size_t ln;

    ln = _strlen(strin);
    n = malloc(sizeof(char) * (ln + 1));
    if (n == NULL)
        return (NULL);
    _memcpy(n, strin, ln + 1);
    return (n);
}
/**
 * _strlen -
 * @strin:
 * Return:
 */
int _strlen(const char *strin)
{
    int ln;

    for (ln = 0; strin[ln] != 0; ln++)
    {
    }
    return (ln);
}
/**
 * cmp_chars -
 * @st:
 * @de:
 *
 * Return:
 */
int cmp_chars(char st[], const char *de)
{
    unsigned int i, j, k;

    for (i = 0, k = 0; st[i]; i++)
    {
        for (j = 0; de[j]; j++)
        {
            if (st[i] == de[j])
            {
                k++;
                break;
            }
        }
    }
    if (i == k)
        return (1);
    return (0);
}
/**
 * _strtok -
 * @st:
 * @de:
 *
 * Return:
 */
char *_strtok(char st[], const char *de)
{
    static char *splitted, *str_end;
    char *str_start;
    unsigned int i, bool;

    if (st != NULL)
    {
        if (cmp_chars(st, de))
            return (NULL);
        splitted = st;
        i = _strlen(st);
        str_end = &st[i];
    }
    str_start = splitted;
    if (str_start == str_end)
        return (NULL);

    for (bool = 0; *splitted; splitted++)
    {
        if (splitted != str_start)
            if (*splitted && *(splitted - 1) == '\0')
                break;

        for (i = 0; de[i]; i++)
        {
            if (*splitted == de[i])
            {
                *splitted = '\0';
                if (splitted == str_start)
                    str_start++;
                break;
            }
        }
        if (bool == 0 && *splitted)
            bool = 1;
    }
    if (bool == 0)
        return (NULL);
    return (str_start);
}
/**
 * _isdigit -
 *
 * @strin:
 * Return:
 */
int _isdigit(const char *strin)
{
    unsigned int k;

    for (k = 0; strin[k]; k++)
    {
        if (strin[k] < 48 || strin[k] > 57)
            return (0);
    }
    return (1);
}

