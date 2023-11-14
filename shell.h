#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"


extern char **environ;


/**
 * struct data -
 * @av: 
 * @input: 
 * @args:
 * @status: 
 * @counter:
 * @_environ: 
 * @pid: 
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;

/**
 * struct sep_list_s 
 * @separator: ; | &
 * @next: 
 * Description:*/ 
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - 
 * @line: 
 * @next: 
 * Description:  
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - kana zvaka dayi
 * @len_var: 
 * @val: 
 * @len_val: 
 * @next: 
 * Description: 
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - 
 * @name: 
 * @f: 
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

/* a.c */
sep_list *add_sep_node_end(sep_list **hd, char sp);
void free_sep_list(sep_list **hd);
line_list *add_line_node_end(line_list **hd, char *ln);
void free_line_list(line_list **hd);

/* a2.c */
r_var *add_rvar_node(r_var **hd, int lv, char *v, int lvl);
void free_rvar_list(r_var **hd);

/* a */
char *_strcat(char *des, const char *sr);
char *_strcpy(char *des, char *sr);
int _strcmp(char *s, char *r);
char *_strchr(char *ss, char cc);
int _strspn(char *ss, char *ac);

/* ac */
void _memcpy(void *nptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

/* a2.c */
char *_strdup(const char *strin);
int _strlen(const char *strin);
int cmp_chars(char st[], const char *de);
char *_strtok(char st[], const char *de);
int _isdigit(const char *strin);

/* rstring.c */
void rev_string(char *strin);

/* rep.c */
int repeated_char(char *in, int k);
int error_sep_op(char *in, int k, char la);
int first_char(char *in, int *k);
void print_syntax_error(data_shell *dtsh, char *in, int k, int bool);
int check_syntax_error(data_shell *dtsh, char *in);

/* s.c */
char *without_comment(char *input);
void shell_loop(data_shell *dts);

/* r.c */
char *read_line(int *ief);

/* s.c */
char *swap_char(char *in, int bool);
void add_nodes(sep_list **hes, line_list **hel, char *in);
void go_next(sep_list **lis, line_list **lil, data_shell *dtsh);
int split_commands(data_shell *dtsh, char *in);
char **split_line(char *in);

/* var_check.c */
void check_env(r_var **h, char *ind, data_shell *dt);
int check_vars(r_var **h, char *ind, char *sat, data_shell *dt);
char *replaced_input(r_var **hd, char *in, char *nein, int nle);
char *rep_var(char *inpu, data_shell *datash);

/* g.c */
void bring_line(char **lptr, size_t *n, char *buff, size_t i);
ssize_t get_line(char **lptr, size_t *n, FILE *stm);

/* ee */
int exec_line(data_shell *dts);

/* cmd.c */
int is_cdir(char *path, int *k);
char *_which(char *cmd, char **environment);
int is_executable(data_shell *datashell);
int check_error_cmd(char *directory, data_shell *datashell);
int cmd_exec(data_shell *datashell);

/* getinv.c */
char *_getenv(const char *name, char **_environ);
int _env(data_shell *datash);

/* copy_inf.c */
char *copy_info(char *n, char *val);
void set_env(char *n, char *val, data_shell *datash);
int _setenv(data_shell *dtsh);
int _unsetenv(data_shell *dtsh);

/* cdot.c */
void cd_dot(data_shell *dtsh);
void cd_to(data_shell *dtsh);
void cd_previous(data_shell *dtsh);
void cd_to_home(data_shell *dtsh);

/* cd.c */
int cd_shell(data_shell *dtsh);

/* gn */
int (*get_builtin(char *cm))(data_shell *datash);

/* _.c */
int exit_shell(data_shell *dtsh);

/* a.c */
int get_len(int no);
char *aux_itoa(int n);
int _atoi(char *strin);

/* a1.c */
char *strcat_cd(data_shell *dtsh, char *m, char *er, char *ver_str);
char *error_get_cd(data_shell *dtsh);
char *error_not_found(data_shell *dtsh);
char *error_exit_shell(data_shell *dtsh);

/* a2.c */
char *error_get_alias(char **args);
char *error_env(data_shell *dtsh);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path_126(data_shell *dtsh);


/* g.c */
int get_error(data_shell *dtsh, int ev);

/* get sig.c */
void get_sigint(int signt);

/* a.c */
void aux_help_env(void);
void aux_help_setenv(void);
void aux_help_unsetenv(void);
void aux_help_general(void);
void aux_help_exit(void);

/* a2.c */
void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void);

/* get_help.c */
int get_help(data_shell *datashell);

#endif
