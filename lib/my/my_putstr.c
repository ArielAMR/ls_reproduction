/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** put an str
*/

#include "my.h"

int my_putstr(char const *str)
{
    int counter = 0;

    while (str[counter] != '\0') {
        my_putchar(str[counter]);
        counter++;
    }
    return counter;
}
