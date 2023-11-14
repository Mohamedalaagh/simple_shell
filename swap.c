#include "shell.h"

/**
 * swap_char - 
 * @in: 
 * @bool: 
 * Return: 
 */
char *swap_char(char *in, int bool)
{
    int k;

    if (bool == 0)
    {
        for (k = 0; in[k]; k++)
        {
            if (in[k] == '|')
            {
                if (in[k + 1] != '|')
                    in[k] = 16;
                else
                    k++;
            }

            if (in[k] == '&')
            {
                if (in[k + 1] != '&')
                    in[k] = 12;
                else
                    k++;
            }
        }
    }
    else
    {
        for (k = 0; in[k]; k++)
        {
            in[k] = (in[k] == 16 ? '|' : in[k]);
            in[k] = (in[k] == 12 ? '&' : in[k]);
        }
    }
    return (in);
}
/**
 * add_nodes - 
 * @hes: 
 * @hel:
 * @in: 
 * Return: 
 */
void add_nodes(sep_list **hes, line_list **hel, char *in)
{
    int k;
    char *lin;

    in = swap_char(in, 0);

    for (k = 0; in[k]; k++)
    {
        if (in[k] == ';')
            add_sep_node_end(hes, in[k]);

        if (in[k] == '|' || in[k] == '&')
        {
            add_sep_node_end(hes, in[k]);
            k++;
        }
    }

    lin = _strtok(in, ";|&");
    do {
        lin = swap_char(lin, 1);
        add_line_node_end(hel, lin);
        lin = _strtok(NULL, ";|&");
    } while (lin != NULL);
}
/**
 * go_next -
 * @lis:
 * @lil:
 * @dtsh:
 * Return:
 */
void go_next(sep_list **lis, line_list **lil, data_shell *dtsh)
{
    int losep;
    sep_list *ls_s;
    line_list *ls_l;

    losep = 1;
    ls_s = *lis;
    ls_l = *lil;

    while (ls_s != NULL && losep)
    {
        if (dtsh->status == 0)
        {
            if (ls_s->separator == '&' || ls_s->separator == ';')
                losep = 0;
            if (ls_s->separator == '|')
                ls_l = ls_l->next, ls_s = ls_s->next;
        }
        else
        {
            if (ls_s->separator == '|' || ls_s->separator == ';')
                losep = 0;
            if (ls_s->separator == '&')
                ls_l = ls_l->next, ls_s = ls_s->next;
        }
        if (ls_s != NULL && !losep)
            ls_s = ls_s->next;
    }

    *lis = ls_s;
    *lil = ls_l;
}
/**
 * split_commands -
 * @dtsh:
 * @in:
 * Return:
 */
int split_commands(data_shell *dtsh, char *in)
{
    sep_list *hes, *lid;
    line_list *hel, *lil;
    int loop;

    hes = NULL;
    hel = NULL;

    add_nodes(&hes, &hel, in);

    lid = hes;
    lil = hel;

    while (lil != NULL)
    {
        dtsh->input = lil->line;
        dtsh->args = split_line(dtsh->input);
        loop = exec_line(dtsh);
        free(dtsh->args);

        if (loop == 0)
            break;

        go_next(&lid, &lil, dtsh);

        if (lil != NULL)
            lil = lil->next;
    }

    free_sep_list(&hes);
    free_line_list(&hel);

    if (loop == 0)
        return (0);
    return (1);
}
/**
 * split_line -
 * @in:
 * Return:
 */
char **split_line(char *in)
{
    size_t bs;
    size_t k;
    char **tokens;
    char *token;

    bs = TOK_BUFSIZE;
    tokens = malloc(sizeof(char *) * (bs));
    if (tokens == NULL)
    {
        write(STDERR_FILENO, ": allocation error\n", 18);
        exit(EXIT_FAILURE);
    }

    token = _strtok(in, TOK_DELIM);
    tokens[0] = token;

    for (k = 1; token != NULL; k++)
    {
        if (k == bs)
        {
            bs += TOK_BUFSIZE;
            tokens = _reallocdp(tokens, k, sizeof(char *) * bs);
            if (tokens == NULL)
            {
                write(STDERR_FILENO, ": allocation error\n", 18);
                exit(EXIT_FAILURE);
            }
        }
        token = _strtok(NULL, TOK_DELIM);
        tokens[k] = token;
    }

    return (tokens);
}

