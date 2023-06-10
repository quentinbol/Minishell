/*
** EPITECH PROJECT, 2023
** aplha
** File description:
** k
*/

int is_alpha(char c)
{

    if (c >= 'a' && c <= 'z') {
        return 1;
    }
    if (c >= 'A' && c <= 'Z') {
        return 1;
    }
    if (c == '_')
        return 1;
    return 0;
}