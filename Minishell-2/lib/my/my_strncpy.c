/*
** EPITECH PROJECT, 2023
** my_strcnpy
** File description:
** cnpy
*/

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    while (i != n) {
        dest[i] = src[i];
        i++;
    }
    dest[n + 1] = '\0';
    return dest;
}
