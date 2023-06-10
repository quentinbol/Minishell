/*
** EPITECH PROJECT, 2022
** flag space
** File description:
** add a space before the value
*/

#include<stdarg.h>
#include"prototypes.h"

int if_neg2(double nb, int *result, int *a, int j)
{
    if (nb > 0)
        my_putchar_r(' ', result);
    my_putfloat(nb, result);
    (*a) = j + 1;
}

void flag_space_d_i_f(const char *format, int *a, va_list args, int *result)
{
    double nb = 0;
    int l = 0;
    int j = 0;

    if (format[*a] == '%' && format[(*a) + 1] == ' ') {
        j = (*a) + 1;
        while (format[j] == ' ')
            j++;
        if (format[j] == '+')
            if_plus(format, a, args, result);
        if (format[j] == 'i' || format[j] == 'd') {
            l = va_arg(args, int);
            if_neg(l, result, a, j);
        }
        if (format[j] == 'f') {
            nb = va_arg(args, double);
            if_neg2(nb, result, a, j);
        }
    }
}

void if_plus(const char *format, int *a, va_list args, int *result)
{
    int j = (*a) + 1;
    int l = 0;
    double nb;
    while (format[j] == '+' || format[j] == ' ')
        j++;
        if (format[j] == 'i' || format[j] == 'd') {
            l = va_arg(args, int);
            if_i2(l, result, a, j);
        }
        if (format[j] == 'f') {
            nb = va_arg(args, double);
            if_f2(nb, result, a, j);
        }
}

int if_i2(int l, int *result, int *a, int j)
{
    if (l > 0)
        my_putchar_r('+', result);
    my_put_nbr(l, result);
    (*a) = j + 1;
}

int if_f2(double nb, int *result, int *a, int j)
{
    if (nb > 0)
        my_putchar_r('+', result);
    my_putfloat(nb, result);
    (*a) = j + 1;
}
