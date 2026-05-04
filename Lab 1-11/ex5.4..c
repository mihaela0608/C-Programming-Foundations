#include <stdio.h>
#include <stdlib.h>

int* filterEven(int *arr, int n, int *newSize);

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int newSize;
    int *evenArr = filterEven(arr, 10, &newSize);
    for (int i = 0; i < newSize; i++){
        printf("%d ", evenArr[i]);
    }
    
    free(evenArr);
}

int* filterEven(int *arr, int n, int *newSize){
    int count = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] % 2 == 0){
            count++;
        }
    }
    int* newArr = malloc(count * sizeof(int));
    count = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] % 2 == 0){
            newArr[count] = arr[i];
            count++;
        }
    }

    *newSize = count;
     arr = newArr;
    
}