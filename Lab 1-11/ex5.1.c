#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);

    int* numbers = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++){
        scanf("%d", &numbers[i]);
    }

    for (int i = n-1; i >= 0; i--){
        printf("%d ", numbers[i]);
    }
    
    free(numbers);
    
}