#include <stdio.h>

int main(){
    int n;
    printf("Count: ");
    scanf("%d", &n);
    int numbers[n];

    for (int i = 0; i < n; i++){
        int num;
        printf("Number %d: ", i + 1);
        scanf("%d", &num);
        numbers[i] = num;
    }

    for (int i = 0; i < n/2; i++){
        int for_change = numbers[n - i - 1];
        numbers[n - i - 1] = numbers[i];
        numbers[i] = for_change;
    }
    for (int i = 0; i < n; i++){
        int num = numbers[i];
        printf("%d ", num);
    }


}