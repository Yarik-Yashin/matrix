#include "exp.h"

Matrix *matrix_exp(Matrix *m, double eps) {
    Matrix *matr_exp = matrix_alloc_square_unit(get_height(m));
    Matrix *add = matrix_alloc_square_unit(get_height(m));
    size_t n = 1;
    while (matrix_norm(add) > eps) {
        Matrix *tmp = add;
        add = matrix_multiplication(add, m);
        matrix_free(tmp);
        for (size_t t = 0; t < get_height(m); ++t) {
            add = multiply_string_on_const(add, t, 1.0 / (double) n);
        }
        matrix_add(matr_exp, add);
        n++;
    }
    matrix_free(add);
    return matr_exp;
}