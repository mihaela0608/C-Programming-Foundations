#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int rows, int cols);
void freeMatrix(int **matrix, int rows);

int main(){
    int **mat = createMatrix(3, 4);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    freeMatrix(mat, 3);
}

int** createMatrix(int rows, int cols){
    int** matrix = (int**) malloc(rows * (cols * sizeof(int)));
    for (int i = 0; i < rows; i++){
        matrix[i] = (int*) malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    
    return matrix;
    
}

void freeMatrix(int **matrix, int rows){
    for (int i = 0; i < rows; i++){
        free(matrix[i]);
    }

    free(matrix);
    
}