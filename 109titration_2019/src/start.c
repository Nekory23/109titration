/*
** EPITECH PROJECT, 2020
** start
** File description:
** project
*/

#include <unistd.h>
#include <stdlib.h>
#include "titration.h"
#include "error_msg.h"

void free_struct(values_t *v)
{
    free(v->tabx);
    free(v->taby);
    free(v->dev);
    free(v->sec);
    free(v->f);
    free(v);
}

int start(int ac, char **av, values_t *v)
{
    if (ac != 2) {
        write_error(STR_ERROR_ARG);
        return (ERROR);
    }
    if (my_strcmp(av[1], "-h"))
        return (display_help());
    if (error_handling(av[1]))
        return (ERROR);
    v = malloc(sizeof(values_t));
    open_file(av, v);
    if (check_struct(v))
        return (ERROR);
    titration(v);
    free_struct(v);
    return (SUCCESS);
}
