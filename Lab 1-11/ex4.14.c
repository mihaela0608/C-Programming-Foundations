#include <stdio.h>

int removeDuplicatesSorted(int *arr, int n);

int main() {
    int numbers[10] = {1, 2, 4, 15, 15, 15, 32, 98, 98, 110};  
    
    int size = removeDuplicatesSorted(numbers, 10);
    
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    return 0;
}

int removeDuplicatesSorted(int *arr, int n) {
    if (n == 0) return 0;
    
    int j = 0;  
    
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    
    return j + 1;  
}