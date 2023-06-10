/*
** EPITECH PROJECT, 2022
** flag_d_i_s_c.c
** File description:
** true
*/

#include<stdarg.h>
#include"prototypes.h"

void script_1(const char *format, int *a, va_list args, int *result)
{
    int l = 0;
    if (format[*a] == '%' && format[(*a) + 1] == 'd') {
        l = va_arg(args,int);
        my_put_nbr(l, result);
        (*a) += 2;
    }
    if (format[*a] == '%' && format[(*a) + 1] == 'i') {
        l = va_arg(args,int);
        my_put_nbr(l, result);
        (*a) += 2;
    }
}

void script_10(const char *format, int *a, va_list args, int *result)
{
    if (format[*a] == '%' && format[(*a) + 1] == 'c') {
        my_putchar_r(va_arg(args,int), result);
        (*a) += 2;
    }
    if (format[*a] == '%' && format[(*a) + 1] == 's') {
        my_putstr(va_arg(args,char *), result);
        (*a) += 2;
    }
    if (format[*a] == '%' && format[(*a) + 1] == '%') {
        (*a)++;
        *result--;
    }
}

void script_2(const char *format, int *a, va_list args, int *result)
{
    if (format[*a] == '%' && format[(*a) + 1] == 'o') {
        my_putnbr_base(va_arg(args,int), "01234567", result);
        (*a) += 2;
    }
    if (format[*a] == '%' && format[(*a) + 1] == 'u') {
        my_putnbr_base(va_arg(args,int), "0123456789", result);
        (*a) += 2;
    }
    if (format[*a] == '%' && format[(*a) + 1] == 'x') {
        my_putnbr_base(va_arg(args,int), "0123456789abcdef", result);
        (*a) += 2;
    }
    if (format[*a] == '%' && format[(*a) + 1] == 'X') {
        my_putnbr_base(va_arg(args,int), "0123456789ABCDEF", result);
        (*a) += 2;
    }
}

void script_3(const char *format, int *a, va_list args, int *result)
{
    if (format[*a] == '%' && format[(*a) + 1] == 'n') {
        *va_arg(args,int *) = *result;
        (*a) += 2;
    }
    if (format[*a] == '%' && format[(*a) + 1] == 'f') {
        my_putfloat(va_arg(args,double), result);
        (*a) += 2;
    }
}
