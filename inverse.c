#include "inverse.h"

Matrix *inverse(Matrix *matrix) {
    if (get_height(matrix) != get_height(matrix))
        return NULL;

    Matrix *temp = matrix_clone(matrix);
    Matrix *inv = matrix_alloc_square_unit(get_height(matrix));

    for (size_t i = 0; i < get_width(temp); ++i)
        for (size_t j = 0; j < get_height(temp); ++j)
            if (i != j) {
                if (get_element(temp, i, i) == 0)
                    return NULL;

                double factor = get_element(temp, j, i) / get_element(temp, i, i);
                for (size_t k = 0; k < get_width(temp); ++k) {
                    add_element(temp, j, k, get_element(temp, j, k) - get_element(temp, i, k) * factor);
                    add_element(inv, j, k, get_element(inv, j, k) - get_element(inv, i, k) * factor);
                }
            }

    for (size_t i = 0; i < get_height(temp); i++) {
        double factor = get_element(temp, i, i);
        for (size_t j = 0; j < get_width(temp); j++)
            add_element(inv, i, j, get_element(inv, i, j) / factor);
    }

    matrix_free(temp);

    return inv;
}