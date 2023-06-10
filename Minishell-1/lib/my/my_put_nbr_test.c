/*
** EPITECH PROJECT, 2022
** my_put_nbr_test.c
** File description:
** true
*/

#include"prototypes.h"

void my_put_nbr_test(int nb)
{
    int d = 1;
    if (nb == -2147483648)
        my_putstr_test("-2147483648");
    else {
        if (nb < 0) {
            my_putchar('-');
            nb *= -1;
        }
        while ((nb / d) >= 10)
            d *= 10;
        while (d > 0) {
            my_putchar((nb / d) % 10 + '0');
            d /= 10;
        }
    }
}
