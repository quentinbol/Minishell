/*
** EPITECH PROJECT, 2022
** flag_b.c
** File description:
** true
*/

#include<stdarg.h>
#include"prototypes.h"

void flag_b(const char *format, int *a, va_list args, int *result)
{
    if (format[*a] == '%' && format[(*a) + 1] == 'b') {
        my_putnbr_base(va_arg(args,int), "01", result);
        (*a) += 2;
    }
}
