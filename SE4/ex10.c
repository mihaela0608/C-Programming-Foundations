#include <stdio.h>

int main(){
    int N, M;

    printf("Please enter the number of columns: ");
    scanf("%d", &N);

    printf("Please enter the number of rows: ");
    scanf("%d", &M);

    int numbers[M][N];

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &numbers[i][j]);
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            sum+=numbers[j][i];
        }
        printf("Sum {%d} is %d\n", i, sum);
        sum = 0;
    }
}