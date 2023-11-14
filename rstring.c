#include "shell.h"

/**
 * rev_string - 
 * @strin: 
 * Return: 
 */
void rev_string(char *strin)
{
    int coun = 0, k, j;
    char *str, temp;

    while (coun >= 0)
    {
        if (strin[coun] == '\0')
            break;
        coun++;
    }
    str = strin;

    for (k = 0; k < (coun - 1); k++)
    {
        for (j = k + 1; j > 0; j--)
        {
            temp = *(str + j);
            *(str + j) = *(str + (j - 1));
            *(str + (j - 1)) = temp;
        }
    }
}

