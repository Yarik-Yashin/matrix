#include <stdio.h>
#include "matrix.h"
#include "operations.h"
#include "gauss.h"
#include "exp.h"
#include "inverse.h"

int main() {
    Matrix *m = matrix_alloc_square_unit(3);
    add_element(m, 1, 0, 1);
    Matrix *m1 = inverse(m);

    print_matrix(m1);
    return 0;
}
