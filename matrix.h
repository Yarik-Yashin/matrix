#ifndef LABA23_MATRIX_H
#define LABA23_MATRIX_H

#include "stdlib.h"
#include "stdio.h"

typedef struct Matrix Matrix;

Matrix *matrix_alloc(size_t h, size_t w);

void matrix_free(Matrix *matrix);

Matrix *matrix_clone(const Matrix *m);

double get_element(const Matrix *matrix, size_t i, size_t j);

void add_element(Matrix *matrix, size_t i, size_t j, double v);

Matrix *fill_with_zeros(Matrix *m);

Matrix *matrix_alloc_zeros(size_t h, size_t w);

void print_matrix(Matrix *m);

Matrix *matrix_alloc_square(size_t h);

Matrix *matrix_alloc_square_unit(size_t h);

Matrix *matrix_assign(Matrix *m1, const Matrix *m2);

size_t get_height(const Matrix *m1);

size_t get_width(const Matrix *m1);

#endif //LABA23_MATRIX_H