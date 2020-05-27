/*
** EPITECH PROJECT, 2020
** 109titration
** File description:
** compute
*/

#include "titration.h"

static void search_value_around_zero(values_t *v)
{
    for (int i = 1; i <= v->j; i += 2)
        if (v->f[i] < 0)
            v->f[i] = v->f[i] * -1;
    v->eq_p = v->f[1];
    for (int i = 1; i <= v->j - 2; i += 2) {
        if (v->f[i] > v->f[i + 2])
            v->eq_p = v->f[i + 1];
    }
}

static void find_eq_point(values_t *v)
{
    v->eq_p = v->tabx[1];
    for (int i = 0; i != v->nb - 1; i++) {
        if (v->dev[i] < v->dev[i + 1])
            v->eq_p = v->tabx[i + 1];
    }
}

void titration(values_t *v)
{
    compute_derivate(v);
    display_derivative(v);
    find_eq_point(v);
    display_equivalence(v);
    compute_sec_derivative(v);
    display_sec_derivative(v);
    compute_estim(v);
    display_sec_derivative_esti(v);
    search_value_around_zero(v);
    display_equivalence(v);
}
