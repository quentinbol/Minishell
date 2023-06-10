/*
** EPITECH PROJECT, 2022
** flag_s.c
** File description:
** true
*/

#include<stdarg.h>
#include"prototypes.h"

void script_4(int *a, va_list args, int *result)
{
    int m = 0;
    char *k = va_arg(args,char *);
    while (m < my_strlen(k)) {
        int g = k[m];
        if (k[m] < 32 || k[m] >= 127) {
            my_putchar_r('\\', result);
            my_s(g, result);
            m++;
            my_putnbr_base(g, "01234567", result);
        }
        my_putchar_r(k[m], result);
        m++;
    }
    (*a) += 2;
}

void flag_ss(const char* format ,int *a, va_list args, int *result)
{
    if (format[*a] == '%' && format[(*a) + 1] == 'S')
            script_4(a, args,  result);
}
