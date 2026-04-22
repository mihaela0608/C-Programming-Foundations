#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int* numbers = malloc(4 * sizeof(int));
    int capacity = 4;
    int count = 0;
    while (n!=0){
        count++;
        if (count == capacity){
           int* temp = (int*) realloc(numbers, capacity * sizeof(int) * 2);
           capacity = count * 2;
           if (temp!= 0){
            numbers = temp;
           }
           
        }
        numbers[count - 1] = n;
        
        scanf("%d", &n);
    }

    for (int i = 0; i < count; i++){
        int num;
        printf("%d ", numbers[i]);
    }
    
}