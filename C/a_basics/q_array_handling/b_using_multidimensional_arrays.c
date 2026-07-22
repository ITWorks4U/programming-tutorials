/*
*   Multidimensional arrays are also easy to use, but
*   those are also easy to fail.
*/

#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void print_multidimensional_arrays_correct(int m[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        printf("{");

        for(int j = 0; j < COLS; j++) {
            printf("%2d ", m[i][j]);
        }

        printf("}\n");
    } 
}

#if false
//  Neither int **m, nor int *m[COLS] works => this leads to an
//  undefined behavior and crashes the application
void print_multidimensional_arrays_wrong(/*int **m*/int *m[COLS]) {
    for(int i = 0; i < ROWS; i++) {
        printf("{");

        for(int j = 0; j < COLS; j++) {
            printf("%2d ", m[i][j]);
        }

        printf("}\n");
    }
}
#endif

int main(void) {
    int matrix[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    #if false
    //  In contrast to a one dimensional array, this instruction
    //  below won't print the number of elements. This just returns
    //  the number of elements of the first row only. This could be
    //  "fixed" by multiplying with ROWS or COLS, depending on the
    //  correctly used choice.
    size_t elements = sizeof(matrix) / sizeof(matrix[0]);
    printf("%llu\n", elements);
    #endif

    print_multidimensional_arrays_correct(matrix);

    #if false
    print_multidimensional_arrays_correct(matrix);
    print_multidimensional_arrays_wrong((int **)matrix);
    #endif

    return EXIT_SUCCESS;
}