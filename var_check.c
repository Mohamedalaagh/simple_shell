#include "shell.h"

/**
 * check_env - to check the environment
 * @h: 
 * @inid: 
 * @dt: 
 * Return: 
 */
void check_env(r_var **h, char *ind, data_shell *dt)
{
	int row, chr, j, lv;
	char **enviro;

	enviro = dt->_environ;
	for (row = 0; enviro[row]; row++)
	{
		for (j = 1, chr = 0; enviro[row][chr]; chr++)
		{
			if (enviro[row][chr] == '=')
			{
				lv = _strlen(enviro[row] + chr + 1);
				add_rvar_node(h, j, enviro[row] + chr + 1, lv);
				return;
			}

			if (ind[j] == enviro[row][chr])
				j++;
			else
				break;
		}
	}

	for (j = 0; ind[j]; j++)
	{
		if (ind[j] == ' ' || ind[j] == '\t' || ind[j] == ';' || ind[j] == '\n')
			break;
	}

	add_rvar_node(h, j, NULL, 0);
}
/**
 * check_vars - 
 * @h:
 * @ind: 
 * @sat: 
 * @dt: 
 * Return:
 */
int check_vars(r_var **h, char *ind, char *sat, data_shell *dt)
{
	int i, lst, lp;

	lst = _strlen(sat);
	lp = _strlen(dt->pid);

	for (i = 0; ind[i]; i++)
	{
		if (ind[i] == '$')
		{
			if (ind[i + 1] == '?')
				add_rvar_node(h, 2, sat, lst), i++;
			else if (ind[i + 1] == '$')
				add_rvar_node(h, 2, dt->pid, lp), i++;
			else if (ind[i + 1] == '\n')
				add_rvar_node(h, 0, NULL, 0);
			else if (ind[i + 1] == '\0')
				add_rvar_node(h, 0, NULL, 0);
			else if (ind[i + 1] == ' ')
				add_rvar_node(h, 0, NULL, 0);
			else if (ind[i + 1] == '\t')
				add_rvar_node(h, 0, NULL, 0);
			else if (ind[i + 1] == ';')
				add_rvar_node(h, 0, NULL, 0);
			else
				check_env(h, ind + i, dt);
		}
	}

	return (i);
}
/**
 * replaced_input - to replace the input
 *
 * @hd:
 * @in: 
 * @nein: 
 * @nle: 
 * Return: 
 */
char *replaced_input(r_var **hd, char *in, char *nein, int nle)
{
	r_var *ind;
	int i, j, k;

	ind = *hd;
	for (j = i = 0; i < nle; i++)
	{
		if (in[j] == '$')
		{
			if (!(ind->len_var) && !(ind->len_val))
			{
				nein[i] = in[j];
				j++;
			}
			else if (ind->len_var && !(ind->len_val))
			{
				for (k = 0; k < ind->len_var; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < ind->len_val; k++)
				{
					nein[i] = ind->val[k];
					i++;
				}
				j += (ind->len_var);
				i--;
			}
			ind = ind->next;
		}
		else
		{
			nein[i] = in[j];
			j++;
		}
	}

	return (nein);
}
/**
 * rep_var - replace the variable
 *
 * @inpu: 
 * @datash: 
 * Return: 
 */
char *rep_var(char *inpu, data_shell *datash)
{
	r_var *head, *indx;
	char *st, *new_input;
	int olen, nlen;

	st = aux_itoa(datash->status);
	head = NULL;

	olen = check_vars(&head, inpu, st, datash);

	if (head == NULL)
	{
		free(st);
		return (inpu);
	}

	indx = head;
	nlen = 0;

	while (indx != NULL)
	{
		nlen += (indx->len_val - indx->len_var);
		indx = indx->next;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = replaced_input(&head, inpu, new_input, nlen);

	free(inpu);
	free(st);
	free_rvar_list(&head);

	return (new_input);
}

