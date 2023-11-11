#include "shell.h"

/**
 * without_comment -to remove comments from a string by truncating
 * the string at the position of a '#' character, 
 * @input: the input string 
 * Return: modified version of the input string
 */
char *without_comment(char *input)
{
	int i, j;
	j = 0;

	for (i = 0; input[i]; i++) {
        if (input[i] == '#') {
            if (i == 0) {
                free(input);
                return NULL;
            }
            if (input[i - 1] == ' ' || input[i - 1] == '\t' || input[i - 1] == ';')
                j = i;
        }
    }

    if (j != 0) {
        input = _realloc(input, i, j + 1);
        input[j] = '\0';
    }

    return input;
}

/**
 * shell_loop -represents a basic shell loop that continuously prompts the user for input,
 *  reads the input, processes it, and executes commands until an end-of-file 
 *  condition is encountered or until the user decides to exit the shell 
 * @dts:the string 
 *
 * Return: nothing
 */
void shell_loop(data_shell *dts) {
    int lp, ief;
    char *in;

    lp = 1;

    while (lp == 1) {
        write(STDIN_FILENO, "^-^ ", 4);
        in = read_line(&ief);

        if (ief != -1) {
            in = without_comment(in);

            if (in == NULL)
                continue;

            if (check_syntax_error(dts, in) == 1) {
                dts->status = 2;
                free(in);
                continue;
            }

            in = rep_var(in, dts);
            lp = split_commands(dts, in);
            dts->counter += 1;
            free(in);
        } else {
            lp = 0;
            free(in);
        }
    }
}
