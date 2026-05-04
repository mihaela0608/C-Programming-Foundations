#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int* numbers = malloc(5 * sizeof(int));
    int count = 0;
    int size = 5 * sizeof(int);
    scanf("%d", &n);
    while (n != 0){
        numbers[count] = n;
        count++;

        if (count + 1 == size / sizeof(int)){
           int* temp = (int*) realloc(numbers, size * 2); 
           if (temp == NULL){
                exit(-1);
           }
           numbers = temp; 
           size = size * 2;
        }
        scanf("%d", &n);
    }
    int newCount = 0;  
    
    for (int i = 0; i < count; i++) {
        if (numbers[i] % 2 != 0) {  
            numbers[newCount] = numbers[i];
            newCount++;
        }
    }

    int* temp = realloc(numbers, newCount * sizeof(int));
    if (temp == NULL){
        exit(-1);
    }

    numbers = temp;
    for (int i = 0; i < count; i++){
        printf("%d ", numbers[i]);
    }
    
    
    
    
}