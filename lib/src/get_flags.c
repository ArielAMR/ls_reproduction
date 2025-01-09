/*
** EPITECH PROJECT, 2024
** get_flags.c
** File description:
** get flags
*/

#include "my.h"

static void is_a_flag(duo_flag_t list[], char const *flag, int i)
{
    for (int j = 0; j < 6; j++)
        if (flag[i] == list[j].c)
            list[j].is_passed = 1;
}

void get_flags(duo_flag_t list[], char const *flag)
{
    if (*flag != '-')
        return;
    flag++;
    for (int i = 0; flag[i] != '\0'; i++)
        is_a_flag(list, flag, i);
}
