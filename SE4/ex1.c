#include <stdio.h>
#include <stdbool.h>

int main()
{
    int N, M;

    printf("Please enter the number of columns: ");
    scanf("%d", &N);

    printf("Please enter the number of rows: ");
    scanf("%d", &M);

    int array1[M][N];

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &array1[i][j]);
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", array1[i][j]);
        }
        printf("\n");
    }

    bool word_row = true;
    for (int i = 0; i < M; i++) {
        for (int j = 1; j < N; j++) {
            if (array1[i][j-1] >= array1[i][j]) {
                word_row = false;
            }
        }
    }

    bool valid_column = true;
    for (int j = 0; j < N; j++) {
        for (int i = 1; i < M; i++) {
            if (array1[i-1][j] <= array1[i][j]) {
                valid_column = false;
            }
        }
    }

    
    if (word_row && valid_column) {
        printf("The matrix is valid.");
    } else {
        printf("The matrix is invalid.");
    }

    return 0;
}