//
// Created by Yaroslav on 04.05.2024.
//

#include "operations.h"

Matrix *matrix_add(Matrix *m1, const Matrix *m2) {
    if ((get_height(m1) != get_height(m2)) || (get_width(m1) != get_width(m2))) {
        return NULL;
    } else {
        for (size_t i = 0; i < get_height(m1); ++i) {
            for (size_t j = 0; j < get_width(m1); ++j) {
                add_element(m1, i, j, get_element(m1, i, j) + get_element(m2, i, j));
            }
        }
        return m1;
    }
}

Matrix *matrix_sum(Matrix *m, const Matrix *m1, const Matrix *m2) {
    m = fill_with_zeros(m);
    if ((get_height(m1) != get_height(m2)) || (get_width(m1) != get_width(m2)) || (get_height(m1) != get_height(m)) ||
        (get_width(m1) != get_width(m))) {
        return NULL;
    } else {
        for (size_t i = 0; i < get_height(m1); ++i) {
            for (size_t j = 0; j < get_width(m1); ++j) {
                add_element(m, i, j, get_element(m1, i, j) + get_element(m2, i, j));
            }
        }
        return m;
    }
}

Matrix *matrix_multiplication(const Matrix *m1, const Matrix *m2) {
    if (get_width(m1) != get_height(m2)) {
        return NULL;
    } else {
        Matrix *m = matrix_alloc(get_width(m1), get_height(m2));
        double a;
        for (size_t i = 0; i < get_height(m1); ++i) {
            for (size_t j = 0; j < get_width(m2); ++j) {
                a = 0;
                for (size_t k = 0; k < get_height(m1); ++k) {
                    a += get_element(m1, i, k) * get_element(m2, k, j);
                }
                add_element(m, i, j, a);
            }
        }
        return m;
    }

}

Matrix *squared_matrix_transposition(Matrix *m1) {
    double t;
    for (size_t i = 0; i < get_height(m1); ++i) {
        for (size_t j = 0; j < i; ++j) {
            t = get_element(m1, i, j);
            add_element(m1, i, j, get_element(m1, j, i));
            add_element(m1, j, i, t);
        }
    }
    return m1;
}

Matrix *matrix_transposition(Matrix *m1) {
    Matrix *m2 = matrix_alloc(get_width(m1), get_height(m1));
    for (size_t i = 0; i < get_height(m1); ++i) {
        for (size_t j = 0; j < get_width(m1); ++j) {
            add_element(m2, j, i, get_element(m1, i, j));
        }
    }
    return m2;
}

Matrix *swap_strings(Matrix *m1, size_t s1, size_t s2) {
    double t;
    for (size_t i = 0; i < get_width(m1); ++i) {
        t = get_element(m1, s1, i);
        add_element(m1, s1, i, get_element(m1, s2, i));
        add_element(m1, s2, i, t);

    }
    return m1;
}

Matrix *multiply_string_on_const(Matrix *m1, size_t s1, double a) {
    for (size_t i = 0; i < get_width(m1); ++i) {
        add_element(m1, s1, i, get_element(m1, s1, i) * a);
    }
    return m1;
}

Matrix *add_string(Matrix *m1, size_t s1, size_t s2) {
    for (size_t i = 0; i < get_width(m1); ++i) {
        add_element(m1, s1, i, get_element(m1, s1, i) + get_element(m1, s2, i));
    }
}
Matrix *add_string_multiplied_on_const(Matrix *m1, size_t s1, size_t s2, double a){
    for (size_t i = 0; i < get_width(m1); ++i) {
        add_element(m1, s1, i, get_element(m1, s1, i) + a * get_element(m1, s2, i));
    }
}

double matrix_norm(Matrix *m1) {
    double a = -1.0 / 0.0;
    double c = 0;

    for (size_t i = 0; i < get_height(m1); ++i) {
        c = 0;
        for (size_t j = 0; j < get_width(m1); ++j) {
            c += fabs(get_element(m1, i, j));
        }
        if (c > a) {
            a = c;
        }

    }
    return a;
}
