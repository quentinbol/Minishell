/*
** EPITECH PROJECT, 2022
** my_put_nombre.c
** File description:
** true
*/

int my_put_nombre(long long nb)
{
    long long int d = 1;
    long long int result = 0;

    if (nb < 0) {
        nb *= -1;
        result++;
    }
    while ((nb / d) >= 10)
        d = d * 10;
    while (d > 0) {
        result++;
        d = d / 10;
    }
    return result;
}
