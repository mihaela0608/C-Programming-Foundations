#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int numbers[n];
    for(int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);
        numbers[i] = num;
    }
    for(int i = 0; i < n; i++){
        printf("%d ", numbers[i]);
    }
    printf("\n");
    for (int i = n - 1; i >= n / 2; i--){
        int current = numbers[i];
        int for_change = numbers[n - i - 1];
        numbers[i] = for_change;
        numbers[n - i - 1] = current;
    }
    for(int i = 0; i < n; i++){
        printf("%d ", numbers[i]);
    }

    
}