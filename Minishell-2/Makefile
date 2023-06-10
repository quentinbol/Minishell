##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## true
##

NAME = mysh

SRC += src/minishell_2/parsing_minishell_2.c
SRC += src/minishell_2/redirection.c
SRC += src/minishell_2/separator_handling.c
SRC += src/minishell_2/pipe_handling.c
SRC += src/minishell_2/global_function.c


SRC +=	src/commands/setenv_unsetenv/command_unsetenv.c
SRC +=	src/commands/setenv_unsetenv/command_setenv.c
SRC +=	src/commands/setenv_unsetenv/replace_alloc_tab.c

SRC +=	src/signal_handler/signal.c

SRC +=	src/commands/command_cd_bis.c
SRC +=	src/commands/command_program.c
SRC +=	src/commands/command_pwd.c
SRC +=	src/commands/command_cd.c
SRC +=	src/commands/command_not_found.c
SRC +=	src/commands/command_ls.c
SRC +=	src/commands/command_exit_env.c

SRC +=	src/main.c
SRC +=	src/start_shell.c

SRC += 	lib/my/my_trim.c
SRC +=	lib/my/my_is_alpha.c
SRC +=	lib/my/my_str_to_word_gen.c
SRC +=	lib/my/clean.c
SRC +=	lib/my/my_strcmp.c
SRC +=	lib/my/my_strdup.c
SRC +=	lib/my/my_strncpy.c
SRC +=	lib/my/my_num_check.c
SRC +=	lib/my/my_revstr.c
SRC +=	lib/my/int_len.c
SRC +=	lib/my/flag_d_i_s_c.c
SRC +=	lib/my/my_strcat.c
SRC +=	lib/my/my_putnbr_base.c
SRC +=	lib/my/getnbr.c
SRC +=	lib/my/my_str_to_word_array.c
SRC +=	lib/my/my_put_nbr.c
SRC +=	lib/my/flag_space.c
SRC +=	lib/my/my_putchar.c
SRC +=	lib/my/my_putfloat.c
SRC +=	lib/my/my_put_nbr_test.c
SRC +=	lib/my/my_putstr.c
SRC +=	lib/my/my_s.c
SRC +=	lib/my/my_strlen.c
SRC +=	lib/my/my_printf.c
SRC +=	lib/my/my_putchar_r.c
SRC +=	lib/my/my_put_nbr_long.c
SRC +=	lib/my/my_put_nombre.c
SRC +=	lib/my/my_putstr_test.c
SRC +=	lib/my/my_strcpy.c
SRC +=	lib/my/flag_special.c
SRC +=	lib/my/if_neg.c

CFLASG = -W -Wextra -Wall -Wno-pointer-sign -Werror

OBJ = $(SRC:.c=.o)

CC = gcc

all:	$(NAME)

$(NAME):	$(OBJ)
			gcc $(CFLAGS) -o $(NAME) $(SRC) -g
			@ echo "Compiled !"

clean:
	rm -f $(OBJ)
	@ echo "Clean done !"

fclean: clean
	rm -f $(NAME)

re: fclean all

test_clean :
	rm -f *.gcno
	rm -f *.gcda
	rm units_test

.PHONY: clean fclean re test test_clean

.SILENT:
