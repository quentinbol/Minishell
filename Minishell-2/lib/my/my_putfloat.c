/*
** EPITECH PROJECT, 2022
** my_put_float
** File description:
** put_float
*/
#include<stdarg.h>
#include"prototypes.h"

double verif(long long ap_v, double nb_d, long long av_virgule, int *result)
{
    int i = 0;
    int n = 10;
    int d = my_put_nombre(ap_v);

    ap_v = (nb_d - av_virgule);
    while (i <= d && n < 1000000) {
        ap_v = ((nb_d - av_virgule)*n);
        n *= 10;
        i++;
        if (ap_v == 0)
            my_put_nbr_long(0, result);
    }
}

void my_putfloat(double nb_d, int *result)
{
    unsigned long long apres_virgule2;
    unsigned long long av_virgule;
    unsigned long long ap_v;

    if (nb_d < 0){
        my_putchar_r('-', result);
        nb_d *= -1;
    }
    av_virgule = nb_d;
    my_put_nbr_long(av_virgule, result);
    my_putchar_r('.', result);
    verif(ap_v, nb_d, av_virgule, result);
    apres_virgule2 = ((nb_d - av_virgule) * 1000000 + 0.5);
    my_put_nbr_long(apres_virgule2, result);
}
