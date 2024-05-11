#ifndef LABA23_GAUSS_H
#define LABA23_GAUSS_H

#include "operations.h"

Matrix *matrix_gauss(Matrix *m, size_t *indexes);

double *solve_system(Matrix *matrix);

#endif //LABA23_GAUSS_H
