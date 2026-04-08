#include <stdio.h>
#include <stdbool.h>

int main(){
    int N;

    printf("Please enter the size: ");
    scanf("%d", &N);

    int numbers[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &numbers[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
    }
    bool is_negative = false;
    for (int i = 0; i < N; i++){
        if (numbers[N - 1][i] < 0){
            is_negative = true;
        }
    }
    int B[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = numbers[i][j];
        }
        printf("\n");
    }
    if (is_negative){
        for (int i = 0; i < N; i++){
            B[i][i] = 1;
        }
    } else{
        for (int i = N - 1; i >= 0; i--){
            B[N - i - 1][i] = -1;
        }
        
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
}