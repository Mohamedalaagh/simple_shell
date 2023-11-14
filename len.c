#include "shell.h"

/**
 * get_len - 
 * @no: 
 * Return: 
 */
int get_len(int no)
{
    unsigned int n1;
    int len = 1;

    if (no < 0)
    {
        len++;
        n1 = no * -1;
    }
    else
    {
        n1 = no;
    }
    while (n1 > 9)
    {
        len++;
        n1 = n1 / 10;
    }

    return (len);
}
/**
 * aux_itoa -
 * @no:
 * Return:
 */
char *aux_itoa(int no)
{
    unsigned int n1;
    int len = get_len(no);
    char *buff;

    buff = malloc(sizeof(char) * (len + 1));
    if (buff == 0)
        return (NULL);

    *(buff + len) = '\0';

    if (no < 0)
    {
        n1 = no * -1;
        buff[0] = '-';
    }
    else
    {
        n1 = no;
    }

    len--;
    do {
        *(buff + len) = (n1 % 10) + '0';
        n1 = n1 / 10;
        len--;
    } while (n1 > 0);

    return (buff);
}
/**
 * _atoi - 
 * @sng: 
 * Return: .
 */
int _atoi(char *strin)
{
    unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

    while (*(strin + count) != '\0')
    {
        if (size > 0 && (*(strin + count) < '0' || *(strin + count) > '9'))
            break;

        if (*(strin + count) == '-')
            pn *= -1;

        if ((*(strin + count) >= '0') && (*(strin + count) <= '9'))
        {
            if (size > 0)
                m *= 10;
            size++;
        }
        count++;
    }

    for (i = count - size; i < count; i++)
    {
        oi = oi + ((*(strin + i) - 48) * m);
        m /= 10;
    }
    return (oi * pn);
}

