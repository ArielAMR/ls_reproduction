/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** function that concatenates two strings
*/

#include "my.h"
#include <stdlib.h>

char *get_path(char const *dest, char const *src)
{
    char *finale = malloc(sizeof(char) *
        (my_strlen(dest) + my_strlen(src)) + 2);
    int i = 0;
    int j = 0;

    while (dest[i] != '\0') {
        finale[i] = dest[i];
        i++;
    }
    finale[i] = '/';
    i++;
    while (src[j] != '\0') {
        finale[i + j] = src[j];
        j++;
    }
    finale[i + j] = '\0';
    return finale;
}
