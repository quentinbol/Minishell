/*
** EPITECH PROJECT, 2022
** prototypes.h
** File description:
** true
*/

#include<stdarg.h>

#ifndef PROTO_H_
    #define PROTO_H_

char *clean_string_pipe(char* string);

char *clean_string(char* string);

int number_word_gen_2(char *str, char c, char c2);

char **my_str_to_word_array_gen_2(char *str, char c, char c2);

char *my_strdupn(char const *src, int b);

char *my_strcpyn(char *dest, char const *src);

int is_alpha(char c);

char *my_strcat_rev(char *dest, char *src);

void my_putchar(char c);

char *clean_str(char *argv);

int number_word_gen(char *str, char c);

char **my_str_to_word_array_gen(char *str, char c);

void all_free (char **tab, int count);

int my_strlen_array(char** str);

char** my_copy_char_array(char **source);

char** my_copy_char_array_1(char **original, char **copy);

int number_word_2(char *str);

char **my_str_to_word_array_2(char *str);

int my_strcmp(char const *s1, char const *s2);

int string_comp(char const *s1, char const *s2, int count);

char *my_strdup_shell_back(char const *src);

char *my_strdup_shell(char *src, int opt);

char *my_strdup(char const *src);

char *my_strdup_shell_2(char *src);

char *my_strncpy(char *dest, char const *src, int n);

int	num_check(char *argv);

void my_swap_char(char *a, char *b);

char *my_evil_str(char *str);

int my_intlen(int nb);

char *my_strcat(char *dest, char const *src);

int	my_getnbr(char const *str);

int my_printf(const char *format, ...);

int str_to_int(char *str);

int my_compute_power_it(int nb, int p);

void my_putchar(char c);

void my_putchar_r(char c, int *result);

void my_putstr(char const *str, int *result);

void my_putstr_test(char const *str);

int number_word(char *str);

char **my_str_to_word_array(char *str);

void my_put_nbr(int nb, int *result);

void my_put_nbr_long(long long nb, int *result);

void my_put_nbr_test(int nb);

int my_strlen(char const *str);

int my_put_nombre(long long nb);

int my_putnbr_base(int nbr, char const *base, int *result);

void my_s(int g, int *result);

void script_1(const char *format, int *a, va_list args, int *result);

void script_2(const char *format, int *a, va_list args, int *result);

void script_3(const char *format, int *a, va_list args, int *result);

void script_4(int *a, va_list args, int *result);

void script_5(const char *format, int *a, va_list args, int *result);

void my_putfloat(double nb_d, int *result);

void script_6(const char *format, int *a, va_list args, int *result);

void script_10(const char *format, int *a, va_list args, int *result);

void script_7(const char *format, int *a, va_list args, int *result);

void flag_space_d_i_f(const char *format, int *a, va_list args, int *result);

int if_i(int l, int *result, int *a, int j);

int if_f(double nb, int *result, int *a, int j);

int if_neg(int l, int *result, int *a, int j);

void if_plus(const char *format, int *a, va_list args, int *result);

int if_neg2(double nb, int *result, int *a, int j);

int if_i2(int l, int *result, int *a, int j);

int if_f2(double nb, int *result, int *a, int j);

#endif
