/*
** EPITECH PROJECT, 2020
** 109titration
** File description:
** display the values
*/

#include <stdio.h>
#include "titration.h"

void display_derivative(values_t *v)
{
    printf("Derivative:\n");
    for (int i = 1; i != v->nb - 1; i++)
        printf("%.1f ml -> %.2f\n", v->tabx[i], v->dev[i]);
    printf("\n");
}

void display_sec_derivative(values_t *v)
{
    printf("\nSecond derivative:\n");
    for (int i = 2; i != v->nb - 2; i++)
        printf("%.1f ml -> %.2f\n", v->tabx[i], v->sec[i]);
    printf("\n");
}

void display_sec_derivative_esti(values_t *v)
{
    printf("Second derivative estimated:\n");
    for (int i = 1; i <= v->j; i += 2)
        printf("%.1f ml -> %.2f\n", v->f[i - 1], v->f[i]);
    printf("\n");
}

void display_equivalence(values_t *v)
{
    printf("Equivalence point at %.1f ml\n", v->eq_p);
}
