#include <stdio.h>

int main(){
    int numbers[7];

    for (int i = 0; i < 7; i++){
        scanf("%d", &numbers[i]);
    }
    int sum = 0;
    for (int i = 0; i < 7; i++){
        sum+=numbers[i];
    }

    printf("%d", sum);
}