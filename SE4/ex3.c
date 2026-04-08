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

    int biggest_i = 0;
    int smallest_i = 0;
    int biggest = numbers[0][0];
    int smallest = numbers[0][0];
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int num = numbers[i][j];
            if (num > biggest){
                biggest = num;
                biggest_i = j;
            } 
            if (num < smallest){
                smallest = num;
                smallest_i = j;
            }
        }  
    }
    printf("Biggest num is %d\n", biggest);
    printf("Smallest num is %d\n", smallest);
    for (int i = 0; i < N; i++){
        int r1 = numbers[biggest_i][i];
        numbers[biggest_i][i] = numbers[smallest_i][i];
        numbers[smallest_i][i] = r1;
    }
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
    }


}