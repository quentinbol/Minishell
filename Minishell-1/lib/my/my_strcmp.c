/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** cmp
*/

int string_comp(char const *s1, char const *s2, int count)
{
    int i = 0;
    int k = 0;

    while (s1[i] != '\0') {
        i++;
    }
    i--;
    while (s2[k] != '\0') {
        k++;
    }
    k--;
    if (i > k) {
        count = i;
        return count;
    } else {
        count = k;
        return count;
    }
}

int my_strcmp(char const *s1, char const *s2)
{
    int j = 0;
    int count = 0;
    int dif = 0;

    count = string_comp(s1, s2, count);
    while (j <= count) {
        if (s1[j] != s2[j]) {
            dif = s1[j] - s2[j];
            return 84;
        }
        j++;
    }
    return 0;
}
