#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3, cols = 4;

    int** matrix = malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i + j;
        }
    }

    int** transposed = malloc(cols * sizeof(int*));
    for (int i = 0; i < cols; i++) {
        transposed[i] = malloc(rows * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < cols; i++) {
        free(transposed[i]);
    }
    free(transposed);

    return 0;
}