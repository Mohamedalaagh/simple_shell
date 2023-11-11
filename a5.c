#include "shell.h"

/**
 * add_sep_node_end -  add sep node
 * @head: 
 * @sep:  ; | &
 * Return: 
 */
sep_list *add_sep_node_end(sep_list **hd, char sp) {
    sep_list *n, *temp;

    n = malloc(sizeof(sep_list));
    if (n == NULL)
        return NULL;

    n->separator = sp;
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
 * free_sep_list - to free the sep list
 * @hd:
 * Return:
 */

void free_sep_list(sep_list **hd) {
    sep_list *temp;
    sep_list *c;

    if (hd != NULL) {
        c = *hd;
        while ((temp = c) != NULL) {
            c = c->next;
            free(temp);
        }
        *hd = NULL;
    }
}
/**
 * add_line_node_end - to add line node end
 * @hd: 
 * @ln: 
 * Return: 
 */
line_list *add_line_node_end(line_list **hd, char *ln) {
    line_list *n, *temp;

    n = malloc(sizeof(line_list));
    if (n == NULL)
        return NULL;

    n->line = ln;
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
 * free_line_list - to free the line list
 * @hd: 
 * Return: 
 */
void free_line_list(line_list **hd) {
    line_list *tp;
    line_list *c;

    if (hd != NULL) {
        c = *hd;
        while ((tp = c) != NULL) {
            c = c->next;
            free(tp);
        }
        *hd = NULL;
    }
}

