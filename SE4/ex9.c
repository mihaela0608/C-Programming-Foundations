#include <stdio.h>

int main(){
    int numbers[4][5];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &numbers[i][j]);
        }
    }

    int sum = 0;
    int biggest_sum = sum;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            sum+= numbers[i][j];
        }
        if (sum > biggest_sum){
            biggest_sum = sum;
        }
        
    }

    printf("Biggest sum: %d", biggest_sum);
    
}