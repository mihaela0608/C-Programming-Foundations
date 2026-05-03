#include <stdio.h>

void concat(int *arr1, int n1, int *arr2, int n2, int *result);

int main(){
    int nums1[3] = {1, 2, 3};
    int nums2[4] = {4, 5, 6, 7};
    int result[7];
    concat(nums1, 3, nums2, 4, result);
    for (int i = 0; i < 7; i++){
        printf("%d ", result[i]);
    }
    
}

void concat(int *arr1, int n1, int *arr2, int n2, int *result){
    int count = 0;
    for (int i = 0; i < n1; i++){
        result[count] = arr1[i];
        count++;
    }
    for (int i = 0; i < n2; i++){
        result[count] = arr2[i];
        count++;
    }
    
    
}