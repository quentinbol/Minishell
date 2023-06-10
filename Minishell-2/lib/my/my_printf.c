/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** true
*/

#include<stdarg.h>
#include"prototypes.h"

int my_printf(const char *format, ...)
{
    int result = 0;
    va_list args;
    va_start(args, *format);
    for (int a = 0; a < my_strlen(format); a++) {
        script_1(format, &a, args, &result);
        script_2(format, &a, args, &result);
        script_3(format, &a, args, &result);
        script_7(format, &a, args, &result);
        flag_space_d_i_f(format, &a, args, &result);
        script_5(format, &a, args, &result);
        script_6(format, &a, args, &result);
        script_10(format, &a, args, &result);
        if (a < my_strlen(format))
            my_putchar_r(format[a], &result);
    }
    va_end(args);
    return result;
}

/*int main(void)
{
    int result;
    int nb = 42;
    char *str = "T6to";

    my_printf("%S", str);
}
*/
