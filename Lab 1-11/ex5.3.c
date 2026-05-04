#include <stdio.h>
#include <stdlib.h>

int main(){
    int* numbers = (int*) malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++){
        scanf("%d", &numbers[i]);
    }

    int* temp = realloc(numbers, 10 * sizeof(int));
    if (temp == NULL){
        exit(-1);
    }

    numbers = temp;

    for (int i = 5; i < 10; i++){
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < 10; i++){
        printf("%d ", numbers[i]);
    }
    
}