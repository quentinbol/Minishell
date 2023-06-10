/*
** EPITECH PROJECT, 2022
** myputnbr base
** File description:
** true
*/

#include<stdarg.h>
#include"prototypes.h"

int my_putnbr_base(int nb, char const *base, int *result)
{
    int a;
    int len_str;

    len_str = my_strlen(base);
    a = nb % len_str;
    nb = nb / len_str;
    if (nb > 0) {
        my_putnbr_base(nb, base, result);
    }
    my_putchar_r(base[a], result);
    return *result;
}
