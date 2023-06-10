/*
** EPITECH PROJECT, 2023
** epi
** File description:
** tech
*/

int my_intlen(int nb)
{
    int len = 0;

    if (nb == 0)
        return (1);
    while (nb != 0) {
        len++;
        nb /= 10;
    }
    return (len);
}
