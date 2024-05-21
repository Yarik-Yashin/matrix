#include <stdio.h>
#include "matrix.h"
#include "operations.h"
#include "gauss.h"
#include "exp.h"
#include "inverse.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RU");
    size_t n;
    printf("Введите размер матрицы СЛАУ (без столбца правых частей)\n");
    scanf("%zd", &n);

    Matrix *slau = matrix_alloc(n, n + 1);

    printf("Введите матрицу (со столбцом правых частей)\n");
    double t;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n + 1; ++j) {
            scanf("%lf", &t);
            add_element(slau, i, j, t);
        }
    }
    double *solution = solve_system(slau);
    printf("Решение:");
    for (size_t i = 0; i < n; i++) {
        printf("%lf ", solution[i]);

    }
    free(solution);
    printf("\n");

    matrix_free(slau);

    printf("Введите размер матрицы для матричной экспоненты\n");
    scanf("%zd", &n);
    Matrix *ex = matrix_alloc_square(n);
    printf("Введите матрицу\n");
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            scanf("%lf", &t);
            add_element(ex, i, j, t);
        }
    }
    Matrix *tmp = ex;
    ex = matrix_exp(ex, 0.0001);
    matrix_free(tmp);
    print_matrix(ex);

    matrix_free(ex);

    return 0;
}
