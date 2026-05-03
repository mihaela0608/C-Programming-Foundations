#include <stdio.h>

void reverseArray(int *arr, int n);

int main(){
    int nums[5] = {1, 2, 3, 4, 5};
    reverseArray(nums, 5);
    for (int i = 0; i < 5; i++){
        printf("%d ", nums[i]);
    }
    
}

void reverseArray(int *arr, int n){
    for (int i = 0; i < n / 2; i++){
        int value = *(arr + (n - 1 -i));
        *(arr + (n - 1 -i)) = *(arr + i);
        *(arr + i) = value;
    }
    
}