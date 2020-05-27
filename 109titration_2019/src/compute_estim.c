/*
** EPITECH PROJECT, 2020
** 109
** File description:
** compute estimation
*/

#include <stdlib.h>
#include "titration.h"

static void compute_after(values_t *v, int i)
{
    double b = 0;
    double a = 0;

    for (double x = v->eq_p; x <= v->tabx[i + 1]; x += 0.1, v->j += 1) {
        v->f[v->j] = x;
        v->j += 1;
        b = (v->tabx[i] * v->sec[i + 1]) - (v->tabx[i + 1] * v->sec[i]);
        b = b / (v->tabx[i] - v->tabx[i + 1]);
        a = (v->sec[i] - v->sec[i + 1]) / (v->tabx[i] - v->tabx[i + 1]);
        a = a * x;
        v->f[v->j] = a + b;
    }
}

static void compute_before(values_t *v, int i)
{
    double b = 0;
    double a = 0;

    for (double x = v->tabx[i - 1]; x <= v->eq_p; x += 0.1, v->j += 1) {
        v->f[v->j] = x;
        v->j += 1;
        b = (v->tabx[i - 1] * v->sec[i]) - (v->tabx[i] * v->sec[i - 1]);
        b = b / (v->tabx[i - 1] - v->tabx[i]);
        a = (v->sec[i - 1] - v->sec[i]) / (v->tabx[i - 1] - v->tabx[i]);
        a = a * x;
        v->f[v->j] = a + b;
    }
}

void compute_estim(values_t *v)
{
    int i = 2;
    double k = 0;

    for (; v->eq_p != v->tabx[i]; i++);
    k = (((v->tabx[i + 1] - v->tabx[i - 1]) * 10) + 1) * 2;
    v->f = malloc(sizeof(double) * k);
    v->j = 0;
    compute_before(v, i);
    v->eq_p += 0.1;
    compute_after(v, i);
}
