#include "shell.h"

/**
 * repeated_char - 
 * @in: 
 * @k: 
 * Return: 
 */
int repeated_char(char *in, int k)
{
    if (*(in - 1) == *in)
        return (repeated_char(in - 1, k + 1));

    return (k);
}
/**
 * error_sep_op - 
 * @input:
 * @i:
 * @last:
 * Return:
 */
int error_sep_op(char *in, int k, char la)
{
    int coun;

    coun = 0;
    if (*in == '\0')
        return (0);

    if (*in == ' ' || *in == '\t')
        return (error_sep_op(in + 1, k + 1, la));

    if (*in == ';')
        if (la == '|' || la == '&' || la == ';')
            return (k);

    if (*in == '|')
    {
        if (la == ';' || la == '&')
            return (k);

        if (la == '|')
        {
            coun = repeated_char(in, 0);
            if (coun == 0 || coun > 1)
                return (k);
        }
    }

    if (*in == '&')
    {
        if (la == ';' || la == '|')
            return (k);

        if (la == '&')
        {
            coun = repeated_char(in, 0);
            if (coun == 0 || coun > 1)
                return (k);
        }
    }

    return (error_sep_op(in + 1, k + 1, *in));
}
/**
 * first_char -
 * @in:
 * @k:
 * Return:
 */
int first_char(char *in, int *k)
{
    for (*k = 0; in[*k]; *k += 1)
    {
        if (in[*k] == ' ' || in[*k] == '\t')
            continue;

        if (in[*k] == ';' || in[*k] == '|' || in[*k] == '&')
            return (-1);

        break;
    }

    return (0);
}
/**
 * print_syntax_error -
 * @dtsh:
 * @in:
 * @k:
 * @bo:
 * Return:
 */
void print_syntax_error(data_shell *dtsh, char *in, int k, int bool)
{
    char *msg, *msg2, *msg3, *err, *count;
    int len;

    if (in[k] == ';')
    {
        if (bool == 0)
            msg = (in[k + 1] == ';' ? ";;" : ";");
        else
            msg = (in[k - 1] == ';' ? ";;" : ";");
    }

    if (in[k] == '|')
        msg = (in[k + 1] == '|' ? "||" : "|");

    if (in[k] == '&')
        msg = (in[k + 1] == '&' ? "&&" : "&");

    msg2 = ": Syntax error: \"";
    msg3 = "\"unexpected\n";
    count = aux_itoa(dtsh->counter);
    len = _strlen(dtsh->av[0]) + _strlen(count);
    len += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;

    err = malloc(sizeof(char) * (len + 1));
    if (err == 0)
    {
        free(count);
        return;
    }
    _strcpy(err, dtsh->av[0]);
    _strcat(err, ": ");
    _strcat(err, count);
    _strcat(err, msg2);
    _strcat(err, msg);
    _strcat(err, msg3);
    _strcat(err, "\0");

    write(STDERR_FILENO, err, len);
    free(err);
    free(count);
}

/**
 * check_syntax_error - 
 * @dtsh: 
 * @in: 
 * Return: 
 */
int check_syntax_error(data_shell *dtsh, char *in)
{
    int beg = 0;
    int f_char = 0;
    int k = 0;

    f_char = first_char(in, &beg);
    if (f_char == -1)
    {
        print_syntax_error(dtsh, in, beg, 0);
        return (1);
    }

    k = error_sep_op(in + beg, 0, *(in + beg));
    if (k != 0)
    {
        print_syntax_error(dtsh, in, beg + k, 1);
        return (1);
    }

    return (0);
}

