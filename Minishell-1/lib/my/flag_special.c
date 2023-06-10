/*
** EPITECH PROJECT, 2022
** flag_special.c
** File description:
** true
*/

#include<stdarg.h>
#include"prototypes.h"

void script_5(const char *format, int *a, va_list args, int *result)
{
    if (format[*a] == '%' && format[(*a) + 2] == 'o') {
        int t = va_arg(args,int);
        if (t != 0 && format[(*a) + 1] == '#')
            my_putchar_r('0', result);
        my_putnbr_base(t, "01234567", result);
        (*a) += 3;
    }
    if (format[*a] == '%' && format[(*a) + 1] == 'u') {
        my_putnbr_base(va_arg(args,int), "0123456789", result);
        (*a) += 2;
    }
}

void script_6(const char *format, int *a, va_list args, int *result)
{
    if (format[*a] == '%' && format[(*a) + 2] == 'x') {
        int t = va_arg(args,int);
        if (t != 0 && format[(*a) + 1] == '#')
            my_putstr("0x", result);
        my_putnbr_base(t, "0123456789abcdef", result);
        (*a) += 3;
    }
    if (format[*a] == '%' && format[(*a) + 2] == 'X') {
        int t = va_arg(args,int);
        if (t != 0 && format[(*a) + 1] == '#')
            my_putstr("0X", result);
        my_putnbr_base(t, "0123456789ABCDEF", result);
        (*a) += 3;
    }
}

int if_i(int l, int *result, int *a, int j)
{
    if (l > 0)
        my_putchar_r('+', result);
    my_put_nbr(l, result);
    (*a) = j + 1;
}

int if_f(double nb, int *result, int *a, int j)
{
    if (nb > 0)
        my_putchar_r('+', result);
    my_putfloat(nb, result);
    (*a) = j + 1;
}

void script_7(const char *format, int *a, va_list args, int *result)
{
    int l = 0;
    double nb;
    int j = 0;
    if (format[*a] == '%' && format[(*a) + 1] == '+') {
        j = (*a) + 1;
        while (format[j] == '+' || format[j] == ' ')
            j++;
        if (format[j] == 'i' || format[j] == 'd') {
            l = va_arg(args, int);
            if_i(l, result, a, j);
        }
        if (format[j] == 'f') {
            nb = va_arg(args, double);
            if_f(nb, result, a, j);
        }
    }
}
