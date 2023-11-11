#include "shell.h"

/**
 * add_rvar_node - add a new node to a linked list of r_var
 * @hd: 
 * @lv: 
 * @v: 
 * @lvl: 
 * Return: 
 */
r_var *add_rvar_node(r_var **hd, int lv, char *v, int lvl) {
    r_var *n, *temp;

    n = malloc(sizeof(r_var));
    if (n == NULL)
        return NULL;

    n->len_var = lv;
    n->val = v;
    n->len_val = lvl;

    n->next = NULL;
    temp = *hd;

    if (temp == NULL) {
        *hd = n;
    } else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = n;
    }

    return *hd;
}
/**
 * free_rvar_list - to free the list
 * @hd: 
 * Return: 
 */
void free_rvar_list(r_var **hd) {
    r_var *temp;
    r_var *c;

    if (hd != NULL) {
        c = *hd;
        while ((temp = c) != NULL) {
            c = c->next;
            free(temp);
        }
        *hd = NULL;
    }
}

