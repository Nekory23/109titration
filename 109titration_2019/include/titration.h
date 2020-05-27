/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef _TITRATION_H_
#define _TITRATION_H_

// ~~~~~~~~~~~~~~~~~ //
//      STRUCT       //
// ~~~~~~~~~~~~~~~~~ //
typedef struct values_s
{
    double *tabx;
    double *taby;
    double *dev;
    double *sec;
    double *f;
    double eq_p;
    int nb;
    int j;
    double h;
    double hprime;
} values_t;

// ~~~~~~~~~~~~~~~~~ //
//     COMPUTING     //
// ~~~~~~~~~~~~~~~~~ //
int start(int ac, char **av, values_t *v);
void titration(values_t *v);
void compute_derivate(values_t *v);
void compute_sec_derivative(values_t *v);
void compute_estim(values_t *v);
void free_struct(values_t *v);

// ~~~~~~~~~~~~~~~~~ //
//      DISPLAY      //
// ~~~~~~~~~~~~~~~~~ //
void display_derivative(values_t *v);
void display_sec_derivative(values_t *v);
void display_sec_derivative_esti(values_t *v);
void display_equivalence(values_t *v);

// ~~~~~~~~~~~~~~~~~ //
// HELP - ERROR HAND //
// ~~~~~~~~~~~~~~~~~ //
int display_help(void);
int error_handling(char *file);
int check_struct(values_t *v);
void open_file(char **av, values_t *v);

// ~~~~~~~~~~~~~~~~~ //
//   UTIL FUNCTION   //
// ~~~~~~~~~~~~~~~~~ //
void write_error(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *str1, char const *str2);
char **my_split(char *src, int nb);

// ~~~~~~~~~~~~~~~~~ //
//      MACROS       //
// ~~~~~~~~~~~~~~~~~ //
static const int SUCCESS = 0;
static const int ERROR = 84;
static const int TRUE = 1;
static const int FALSE = 0;

#endif /* _TITRATION_H_ */
