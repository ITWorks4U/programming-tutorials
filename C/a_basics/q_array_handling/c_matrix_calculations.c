/*
* Some mathematical operaions to calculate
* with matrices.
*/

#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void add_matrix(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtract_matrix(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void print_matrix(int (*m)[COLS]) {
    for (int i = 0; i < ROWS; i++) {
        printf("|");

        for (int j = 0; j < COLS; j++) {
            printf("%2d ", m[i][j]);
        }
        printf("|\n");
    }
}

int main(void) {
    int matrix_a[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matrix_b[ROWS][COLS] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int result[ROWS][COLS];

    add_matrix(matrix_a, matrix_b, result);

    printf("A + B:\n");
    print_matrix(result);

    subtract_matrix(matrix_a, matrix_b, result);
    printf("\nA - B:\n");
    print_matrix(result);

    return EXIT_SUCCESS;
}