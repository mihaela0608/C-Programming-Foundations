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
    int biggest_sum = numbers[0][0];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int num = numbers[i][j];
            int sum;
            if ((j - 1 >= 0 && j + 1 <= N - 1) && (i - 1 >= 0 && i + 1 <= M - 1)){
                sum = numbers[i - 1][j + 1] + numbers[i + 1][j - 1];
                if (sum > biggest_sum){
                    biggest_sum = sum;
                } 
            }
            if (j - 1 >= 0 && j + 1 <= N - 1){
                sum = numbers[i][j - 1] + numbers[i][j + 1]; 
                if (sum > biggest_sum){
                    biggest_sum = sum;
                } 
            } 
            if(i - 1 >= 0 && i + 1 <= M - 1){
                sum = numbers[i - 1][j] + numbers[i + 1][j];
                if (sum > biggest_sum){
                    biggest_sum = sum;
                } 
            }
            
            
            
        }
    }

    printf("Biggest sum is: %d", biggest_sum);
}