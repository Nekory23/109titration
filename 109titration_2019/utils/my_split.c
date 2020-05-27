/*
** EPITECH PROJECT, 2020
** 109
** File description:
** my_split
*/

#include <stdlib.h>
#include "titration.h"

static char **my_split_alloc(char *src, char **str, int nb)
{
    int i = 0;
    int k = 0;

    for (int j = 0; src[i] != '\0'; i++, k++) {
        if (src[i] == ';' || src[i] == '\n') {
            str[j] = malloc(sizeof(char) * (k + 1));
            k = 0;
            j++;
        }
    }
    str[nb] = malloc(sizeof(char) * 1);
    return (str);
}

char **my_split(char *src, int nb)
{
    char **str = malloc(sizeof(char *) * (nb + 1));
    int i = 0;
    int m = 0;
    int k = 0;

    str = my_split_alloc(src, str, nb);
    for (int j = 0; src[j] != '\0'; m++, j++);
    m++;
    for (int j = 0; i != m; i++, k++) {
        if (src[i] == ';' || src[i] == '\n') {
            str[j][k] = '\0';
            j++;
            i++;
            k = 0;
        }
        str[j][k] = src[i];
    }
    free(str[nb]);
    str[nb] = NULL;
    return (str);
}
