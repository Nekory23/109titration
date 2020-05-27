/*
** EPITECH PROJECT, 2020
** 109
** File description:
** fill_struct
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "titration.h"
#include "error_msg.h"

static int count_line(char *file)
{
    int nb = 0;

    for (int i = 0; file[i] != '\0'; i++)
        if (file[i] == '\n' || file[i] == ';')
            nb++;
    return (nb);
}

static void recup_values(char *file, values_t *v)
{
    int nb = count_line(file);
    char **split = my_split(file, nb);

    nb = (nb / 2);
    v->nb = nb;
    v->tabx = malloc(sizeof(double) * nb);
    v->taby = malloc(sizeof(double) * nb);
    for (int i = 0, j = 0, k = 0; split[i] != NULL; i++) {
        if (i % 2 == 0) {
            v->tabx[j] = atof(split[i]);
            j++;
        }
        else {
            v->taby[k] = atof(split[i]);
            k++;
        }
    }
    for (int i = 0; split[i] != NULL; i++)
        free(split[i]);
    free(split);
}

static void fill_deriv(values_t *v)
{
    v->dev = malloc(sizeof(double) * v->nb);
    v->sec = malloc(sizeof(double) * v->nb);
    for (int i = 0; i != v->nb; i++) {
        v->dev[i] = (double)0;
        v->sec[i] = 0;
    }
}

void open_file(char **av, values_t *v)
{
    int fd = 0;
    struct stat st;
    char *buffer;

    fd = open(av[1], O_RDONLY);
    stat(av[1], &st);
    buffer = malloc(sizeof(char) * st.st_size + 1);
    read(fd, buffer, st.st_size);
    buffer[st.st_size] = '\0';
    recup_values(buffer, v);
    free(buffer);
    close(fd);
    v->eq_p = 0;
    fill_deriv(v);
}
