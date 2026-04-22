#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    printf("Count: ");
    scanf("%d", &n);
    int sum = 0;

    int* numbers = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        int num;
        printf("Number %d: ", i + 1);
        scanf("%d", &num);
        numbers[i] = num;
        sum+=num;
    }

    printf("Sum is: %d", sum);
    free(numbers);


}