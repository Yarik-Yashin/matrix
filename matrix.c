#include "matrix.h"

struct Matrix {
    size_t m;
    size_t n;
    double *data;
};

Matrix *matrix_alloc(size_t h, size_t w) {
    Matrix *new_matrix = malloc(sizeof(Matrix));
    double *new_data;
    new_data = malloc(sizeof(double) * h * w);
    if (new_data && new_matrix) {
        new_matrix->m = h;
        new_matrix->n = w;
        new_matrix->data = new_data;
        return new_matrix;
    }
    return NULL;
}

void matrix_free(Matrix *matrix) {
    free(matrix->data);
    free(matrix);
}

double get_element(const Matrix *matrix, size_t i, size_t j) {
    return matrix->data[i * matrix->n + j];
}

void add_element(Matrix *matrix, size_t i, size_t j, double v) {
    matrix->data[i * matrix->n + j] = v;
}

Matrix *fill_with_zeros(Matrix *m) {
    for (size_t i = 0; i < m->m; ++i) {
        for (size_t j = 0; j < m->n; ++j) {
            add_element(m, i, j, 0);
        }
    }
    return m;
}

Matrix *matrix_alloc_zeros(size_t h, size_t w) {
    Matrix *m = matrix_alloc(h, w);
    m = fill_with_zeros(m);
    return m;
}

Matrix *matrix_alloc_square(size_t h) {
    return matrix_alloc(h, h);
}

Matrix *matrix_alloc_square_unit(size_t h) {
    Matrix *m = matrix_alloc_square(h);
    m = fill_with_zeros(m);
    for (size_t i = 0; i < m->m; ++i) {
        add_element(m, i, i, 1);
    }
    return m;
}

Matrix *matrix_clone(const Matrix *m) {
    Matrix *matrix2 = matrix_alloc(m->m, m->n);
    if (matrix2) {
        for (size_t i = 0; i < m->m; ++i) {
            for (size_t j = 0; j < m->n; ++j) {
                add_element(matrix2, i, j, get_element(m, i, j));
            }
        }
        return matrix2;
    }
    return NULL;
}

Matrix *resize_matrix(Matrix *m, size_t h, size_t w) {
    matrix_free(m);
    m = matrix_alloc(h, w);
    return m;
}

void print_matrix(Matrix *m) {
    for (size_t i = 0; i < m->m; ++i) {
        for (size_t j = 0; j < m->n; ++j) {
            printf("%lf ", get_element(m, i, j));
        }
        printf("\n");
    }
}

Matrix *matrix_assign(Matrix *m1, const Matrix *m2) {
    if ((m1->m != m2->m) || (m1->n != m2->n)) {
        return NULL;
    } else {
        for (size_t i = 0; i < m1->m; ++i) {
            for (size_t j = 0; j < m1->n; ++j) {
                add_element(m1, i, j, get_element(m2, i, j));
            }
        }
        return m1;
    }
}

size_t get_height(const Matrix *m1){
    return m1->m;
}
size_t get_width(const Matrix *m1){
    return m1->n;
}