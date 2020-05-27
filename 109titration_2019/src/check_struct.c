/*
** EPITECH PROJECT, 2020
** 109titration
** File description:
** check the structure's values
*/

#include <stdio.h>
#include "titration.h"
#include "error_msg.h"

int check_struct(values_t *v)
{
    for (int i = 0; i != v->nb; i++) {
        if (v->tabx[i] == 0 || v->taby[i] == 0) {
            write_error(STR_ERROR_LINE);
            return (TRUE);
            break;
        }
    }
    return (FALSE);
}
