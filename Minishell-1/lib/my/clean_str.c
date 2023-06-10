/*
** EPITECH PROJECT, 2023
** Solo stumper 1 : Clean str
** File description:
** display word by space
*/

#include <unistd.h>

void my_putchar(char c);

void clean_str2(int space, int i);

int clean_str(char *argv)
{
    int count_space = 0;
    int i = 0;
    for (; argv[i] != '\0'; i++) {
        if (argv[i] == ' ' || argv[i] == '\t') {
            count_space++;
        } else {
            clean_str2(count_space, i);
            my_putchar(argv[i]);
            count_space = 0;
        }
    }
}

void clean_str2(int count_space, int i)
{
    if (i - count_space != 0 && count_space != 0)
        my_putchar(' ');
}
