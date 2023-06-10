/*
** EPITECH PROJECT, 2023
** Aliases
** File description:
** ALIASES
*/

#ifndef aliases
    #define aliases

    #include <stddef.h>
    #include <unistd.h>
    #include <stdlib.h>

/*----------------STRUCT-----------------------*/

    typedef struct node_s {
        char *alias;
        char *replace;
        struct node_s *next;
    } node_t;

    typedef struct aliases_s {
        node_t *head;
        node_t *tail;
        unsigned int size;
    } alias_t;

/*------------------------PROTOTYPE------------------------------*/

    alias_t *list_create(void);

    unsigned int add_alias(alias_t *list, char *value, char *replacement);

    char *get_alias(alias_t *list, unsigned int index);

    char *concat_rep(char **cmd);

    void free_alias(alias_t *list);

#endif /* !histro */
