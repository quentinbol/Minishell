/*
** EPITECH PROJECT, 2023
** check_nbr
** File description:
** nbr
*/

int	num_check(char *argv)
{
    int i = 0;
    if (argv[i] == '-')
        i++;
    for (; argv[i] != '\0';) {
        if (argv[i] >= '0' && argv[i] <= '9')
            i++;
        else {
            return 84;
        }
    }
    return 0;
}
