#include "shell.h"

/**
 * _strcat -
 * @des: 
 * @sr: 
 * Return: 
 */
char *_strcat(char *des, const char *sr)
{
    int k;
    int j;

    for (k = 0; des[k] != '\0'; k++)
        ;

    for (j = 0; sr[j] != '\0'; j++)
    {
        des[k] = sr[j];
        k++;
    }

    des[k] = '\0';
    return (des);
}
/**
 * *_strcpy - 
 * @des: 
 * @sr:
 * Return: 
 */
char *_strcpy(char *des, char *sr)
{
    size_t a;

    for (a = 0; sr[a] != '\0'; a++)
    {
        des[a] = sr[a];
    }
    des[a] = '\0';

    return (des);
}
/**
 * _strcmp - 
 * @s: 
 * @r:
 * Return: 
 */
int _strcmp(char *s, char *r)
{
    int i;

    for (i = 0; s[i] == r[i] && s[i]; i++)
        ;

    if (s[i] > r[i])
        return (1);
    if (s[i] < r[i])
        return (-1);
    return (0);
}
/**
 * _strchr - 
 * @ss: 
 * @cc: 
 * Return: 
 */
char *_strchr(char *ss, char cc)
{
    unsigned int i = 0;

    for (; *(ss + i) != '\0'; i++)
        if (*(ss + i) == cc)
            return (ss + i);
    if (*(ss + i) == cc)
        return (ss + i);
    return ('\0');
}
/**
 * _strspn -
 * @ss: 
 * @ac: 
 * Return: 
 */
int _strspn(char *ss, char *ac)
{
    int i, j, bool;

    for (i = 0; *(ss + i) != '\0'; i++)
    {
        bool = 1;
        for (j = 0; *(ac + j) != '\0'; j++)
        {
            if (*(ss + i) == *(ac + j))
            {
                bool = 0;
                break;
            }
        }
        if (bool == 1)
            break;
    }
    return (i);
}

