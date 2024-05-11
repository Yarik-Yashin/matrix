#include "gauss.h"

Matrix *matrix_gauss(Matrix *m, size_t *indexes) {
    double a;
    const double eps = 0.000001;
    size_t t;
    for (size_t i = 0; i < get_height(m); ++i) {
        for (size_t j = i; j < get_height(m); ++j) {
            if (get_element(m, j, i) > eps) {
                swap_strings(m, i, j);
                t = indexes[i];
                indexes[i] = indexes[j];
                indexes[j] = t;
            }

        }
        a = get_element(m, i, i);
        if (fabs(a) > eps) {
            multiply_string_on_const(m, i, 1 / a);
            for (size_t j = i + 1; j < get_height(m); ++j) {
                add_string_multiplied_on_const(m, j, i, -1 * get_element(m, j, i));

            }

        }


    }
    return m;
}

double *solve_system(Matrix *matrix) {
    size_t *indexes = malloc(sizeof(size_t) * get_height(matrix));
    for (size_t i = 0; i < get_height(matrix); ++i) {
        indexes[i] = i;
    }
    matrix = matrix_gauss(matrix, indexes);
    double *x = malloc(sizeof(double) * get_height(matrix));
    double a = 1;
    const double eps = 0.0001;
    double t;

    for (size_t i = 0; i < get_height(matrix); ++i) {
        a *= get_element(matrix, i, i);
    }
    if (fabs(a) < eps) {
        return NULL;
    }
    for (size_t i = get_height(matrix); i > 0; --i) {
        t = get_element(matrix, i - 1, get_width(matrix) - 1);
        for (size_t j = get_height(matrix); i - 1 < j - 1; j--) {
            t -= get_element(matrix, i - 1, j - 1) * x[indexes[j - 1]];
        }
        x[indexes[i - 1]] = t;
    }
    free(indexes);
    return x;
}

