#ifndef LABA23_OPERATIONS_H
#define LABA23_OPERATIONS_H

#include "matrix.h"
#include "math.h"

Matrix *matrix_add(Matrix *m1, const Matrix *m2);

Matrix *matrix_sum(Matrix *m, const Matrix *m1, const Matrix *m2);

Matrix *matrix_multiplication(const Matrix *m1, const Matrix *m2);

Matrix *squared_matrix_transposition(Matrix *m1);

Matrix *matrix_transposition(Matrix *m1);

Matrix *swap_strings(Matrix *m1, size_t s1, size_t s2);

Matrix *multiply_string_on_const(Matrix *m1, size_t s1, double a);

Matrix *add_string(Matrix *m1, size_t s1, size_t s2);

Matrix *add_string_multiplied_on_const(Matrix *m1, size_t s1, size_t s2, double a);

double matrix_norm(Matrix *m1);

#endif //LABA23_OPERATIONS_H
