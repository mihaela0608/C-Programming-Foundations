#include <stdio.h>

void rotateRight(int *arr, int n, int k);

int main(){
    int nums[5] = {1, 2, 3, 4, 5};
    rotateRight(nums, 5, 7);
    for (int i = 0; i < 5; i++){
        printf("%d ", nums[i]);
    }
}

void rotateRight(int *arr, int n, int k){
    
    for (int i = 0; i < k; i++){
        int first_n = arr[n-1];
        int last = arr[0];
        for (int i = 0; i < n - 1; i++){
            int temp = arr[i + 1];
            arr[i + 1] = last;
            last = temp;
        }
        arr[0] = first_n; 
    }
    
}