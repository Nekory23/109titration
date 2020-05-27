/*
** EPITECH PROJECT, 2020
** navy
** File description:
** write on the error output
*/

#include <unistd.h>
#include "error_msg.h"

int my_strlen(char const *str);

void write_error(char const *str)
{
    write(2, str, my_strlen(str));
    write(2, STR_HELP, my_strlen(STR_HELP));
}
