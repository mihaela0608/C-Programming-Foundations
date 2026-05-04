#include <stdio.h>
#include <stdlib.h>

int* mergeArrays(int *arr1, int n1, int *arr2, int n2, int *newSize);

int main(){
    int* nums1 = (int*) malloc(3 * sizeof(int));
    nums1[0] = 1;
    nums1[1] = 2;
    nums1[2] = 3;

    int* nums2 = (int*) malloc(2 * sizeof(int));
    nums2[0] = 4;
    nums2[1] = 5;
    int newSize;
    int* concatArr = mergeArrays(nums1, 3, nums2, 2, &newSize);

    for (int i = 0; i < newSize; i++){
        printf("%d ", concatArr[i]);
    }
    
}

int* mergeArrays(int *arr1, int n1, int *arr2, int n2, int *newSize){
    int* newArr = (int*) malloc((n1 + n2) * sizeof(int));
    for (int i = 0; i < n1; i++){
        newArr[i] = arr1[i];
    }
    for (int i = 0; i < n2; i++){
        newArr[n1 + i] = arr2[i];
    }

    *newSize = n1 + n2;
    return newArr;
    
    
}