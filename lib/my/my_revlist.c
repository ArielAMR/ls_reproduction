/*
** EPITECH PROJECT, 2024
** my_revstr
** File description:
** return reverse of str
*/

#include "my.h"
#include <stdio.h>

static char get_list_len(char **list)
{
    int i = 0;

    while (list[i] != NULL)
        i++;
    return i;
}

char **my_revlist(char **list)
{
    int i = get_list_len(list) - 1;
    int j = 0;
    char *tmp;

    while (j < get_list_len(list) / 2) {
        tmp = list[i];
        list[i] = list[j];
        list[j] = tmp;
        j++;
        i--;
    }
    return list;
}
