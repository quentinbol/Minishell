##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile Minishell
##

CC = gcc

SRC = 	src/main.c 								\
		src/init_minishell.c 					\
		src/minishell.c							\
		src/get_env.c       					\
		src/utils.c								\
		src/pipes/pipes.c 						\
		src/pipes/loop_pipes.c 					\
		src/sig_handler.c 						\
		src/inhibitors.c						\
		src/have_inhibitors.c					\
		src/commands/built_in_cmds.c 			\
		src/commands/built_out_cmds.c			\
		src/commands/execute.c        			\
		src/commands/aliases/alias_list.c 		\
		src/commands/aliases/alias.c 			\
		src/commands/aliases/create_alias.c 	\
		src/commands/aliases/free_alias.c 		\
		src/commands/aliases/replace_aliases.c 	\
		src/commands/built_in/cmd_cd.c     		\
		src/commands/built_in/cmd_exit.c     	\
		src/commands/built_in/cmd_setenv.c  	\
		src/commands/built_in/cmd_unsetenv.c    \
		src/commands/built_in/cmd_env.c     	\
		src/commands/history/history.c			\
		src/commands/history/init_histo.c		\
		src/commands/history/update_change_history.c	\
		src/commands/history/utils_histo.c		\
		src/commands/history/duplicate_history.c	\
		src/commands/history/exclamation_point.c	\
		src/commands/where_which/where.c	\
		src/commands/where_which/which.c	\
		src/commands/where_which/check_if_builtin.c	\
		src/commands/globbing/globbing_binairy.c	\
		src/commands/history/find_from_index.c		\
		src/commands/history/find_from_word.c		\

LIB	=	-L lib/my/ -lmy

OBJ	=	$(SRC:.c=.o)

NAME = 42sh

HEAD_FILE = includes/

CFLAGS = -Wall -Wextra -I includes/ -g

all: $(OBJ)
	$(MAKE) -C lib/my/
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

clean:
	$(MAKE) -C lib/my/ clean
	rm -f $(OBJ)
	rm -fr $(SRC_FILES)/$(OBJ)

fclean: clean
	$(MAKE) -C lib/my/ fclean
	rm -f $(NAME)
	rm -f unit_tests

re: fclean all
