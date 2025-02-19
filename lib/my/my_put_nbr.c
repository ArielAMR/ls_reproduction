/*
** EPITECH PROJECT, 2024
** my_put_nbr.c
** File description:
** my_put_nbr
*/

#include "my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    if (nb < 10) {
        my_putchar(nb + '0');
        return 0;
    }
    my_put_nbr(nb / 10);
    my_putchar(nb % 10 + '0');
}
