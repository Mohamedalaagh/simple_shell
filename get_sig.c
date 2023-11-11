#include "shell.h"

/**
 * get_sigint - 
 * @sig: 
 */
void get_sigint(int signt)
{
	(void)signt;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
