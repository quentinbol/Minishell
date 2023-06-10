/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** true
*/

#include"prototypes.h"

void my_put_nbr_long(long long nb, int *result)
{
    long long d = 1;
        if (nb < 0) {
            my_putchar_r('-', result);
            nb *= -1;
        }
        while ((nb / d) >= 10)
            d *= 10;
        while (d > 0) {
            my_putchar_r((nb / d) % 10 + '0', result);
            d /= 10;
    }
}
