/*
** EPITECH PROJECT, 2023
** inhibitors.c
** File description:
** manage inibitors in 42sh
*/

#include "minishell.h"

inhibitors_t set_inhibitors(const char *input)
{
    inhibitors_t inhibitors = {0};

    inhibitors.num_tokens = 0;
    inhibitors.capacity = 10;
    inhibitors.tokens = malloc(inhibitors.capacity * sizeof(char *));
    inhibitors.input_length = strlen(input);
    inhibitors.start = 0;
    inhibitors.in_single_quote = false;
    inhibitors.in_double_quote = false;
    inhibitors.escaped = false;
    inhibitors.backslash_count = 0;
    inhibitors.length = 0;
    return inhibitors;
}

int check_inhibitors(const char *input, inhibitors_t *inhibitors, int i)
{
    if (input[i] == '\\' && !inhibitors->escaped) {
        inhibitors->escaped = true;
        inhibitors->backslash_count++;
        return 0;
    }
    if (input[i] == '\'' && !inhibitors->escaped &&
        !inhibitors->in_double_quote) {
        inhibitors->in_single_quote = !inhibitors->in_single_quote;
        return 0;
    }
    if (input[i] == '\"' && !inhibitors->escaped &&
        !inhibitors->in_single_quote) {
        inhibitors->in_double_quote = !inhibitors->in_double_quote;
        return 0;
    }
    return 1;
}

void cut_loop(inhibitors_t *inhibitors)
{
    inhibitors->tokens[inhibitors->num_tokens][inhibitors->length] = '\0';
    inhibitors->num_tokens++;
    if (inhibitors->num_tokens >= inhibitors->capacity) {
        inhibitors->capacity *= 2;
        inhibitors->tokens = realloc(inhibitors->tokens,
            inhibitors->capacity * sizeof(char *));
    }
}

void loop_inhibitors(const char *input, inhibitors_t *inhibitors, int *i)
{
    int token_index = 0;

    if ((*i) == inhibitors->input_length - 1)
        (*i)++;
    inhibitors->length = (*i) -
        inhibitors->start - inhibitors->backslash_count;
    inhibitors->tokens[inhibitors->num_tokens] =
        malloc((inhibitors->length + 1) * sizeof(char));
    for (int j = inhibitors->start; j < (*i); j++) {
        if (input[j] != '\\') {
            inhibitors->tokens[inhibitors->num_tokens][token_index++] =
                input[j];
        }
    }
    cut_loop(inhibitors);
}

void inhibitors(const char *input, inhibitors_t inhibitors)
{
    inhibitors = set_inhibitors(input);

    for (int i = 0; i < inhibitors.input_length; i++) {
        if (check_inhibitors(input, &inhibitors, i) == 0)
            continue;
        if ((input[i] == ' ' || i == inhibitors.input_length - 1) &&
            !inhibitors.escaped && !inhibitors.in_single_quote &&
            !inhibitors.in_double_quote) {
            loop_inhibitors(input, &inhibitors, &i);
            inhibitors.start = i + 1;
            inhibitors.backslash_count = 0;
        }
        inhibitors.escaped = false;
    }
    inhibitors.tokens[inhibitors.num_tokens] = NULL;
    exe_inhibitors(inhibitors);
}
