/*
** EPITECH PROJECT, 2023
** epi
** File description:
** true
*/

int my_strlen(char const *str);

void my_swap_char(char *a, char *b)
{
    char temp = *a;

    *a = *b;
    *b = temp;
}

char *my_evil_str(char *str)
{
    int size = my_strlen(str) - 1;

    for (int i = 0; i < (my_strlen(str) / 2) ; i++) {
        my_swap_char(str + i, str + size - i);
    }
    return str;
}
