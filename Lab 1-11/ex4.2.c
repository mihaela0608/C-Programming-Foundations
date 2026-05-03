#include <stdio.h>

int main(){
    int numbers[7];

    for (int i = 0; i < 7; i++){
        scanf("%d", &numbers[i]);
    }
    int max = numbers[0];
    for (int i = 1; i < 7; i++){
        if (numbers[i] > max){
            max = numbers[i];
        }
        
    }

    printf("%d", max);
}