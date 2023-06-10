/*
** EPITECH PROJECT, 2022
** if_neg
** File description:
** if_neg
*/

#include<stdarg.h>
#include"prototypes.h"

int if_neg(int l, int *result, int *a, int j)
{
    if (l > 0)
        my_putchar_r(' ', result);
    my_put_nbr(l, result);
    (*a) = j + 1;
}
