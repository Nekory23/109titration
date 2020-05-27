/*
** EPITECH PROJECT, 2020
** 109titration
** File description:
** compute the first derivative
*/

#include <stdlib.h>
#include "titration.h"

static double compute_forward(values_t *v, int i)
{
    double res = 0;

    v->h = (v->tabx[i + 1] - v->tabx[i]);
    if (v->h == 0) {
        free_struct(v);
        exit(ERROR);
    }
    res = (v->taby[i + 1] - v->taby[i]) / v->h;
    return (res);
}

static double compute_backward(values_t *v, int i)
{
    double res = 0;

    v->hprime = (v->tabx[i] - v->tabx[i - 1]);
    if (v->hprime == 0) {
        free_struct(v);
        exit(ERROR);
    }
    res = (v->taby[i] - v->taby[i - 1]) / v->hprime;
    return (res);
}

void compute_derivate(values_t *v)
{
    double stk = 0;
    double stk1 = 0;

    for (int i = 1; i != v->nb - 1; i++) {
        stk = compute_forward(v, i);
        stk1 = compute_backward(v, i);
        if ((v->h + v->hprime) == 0) {
            free_struct(v);
            exit(ERROR);
        }
        v->dev[i] = ((stk * v->hprime) + (stk1 * v->h)) / (v->h + v->hprime);
    }
}
