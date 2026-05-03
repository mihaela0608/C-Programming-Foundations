#include <stdio.h>
#include <stdbool.h>

int mergeSorted(int *arr1, int n1, int *arr2, int n2, int *result);

int main(){
    int nums1[3] = {1, 4, 5};
    int nums2[4] = {2, 3, 8, 7};
    int result[7];
    mergeSorted(nums1, 3, nums2, 4, result);
    for (int i = 0; i < 7; i++){
        printf("%d ", result[i]);
    }
}

int mergeSorted(int *arr1, int n1, int *arr2, int n2, int *result){
    int count = 0;
    for (int i = 0; i < n1; i++){
        result[count] = arr1[i];
        count++;
    }
    for (int i = 0; i < n2; i++){
        result[count] = arr2[i];
        count++;
    }
    for (int i = 0; i < count; i++){
        bool swaped = false;
  
        for (int j = 0; j < count - 1; j++){
            if (result[j] > result[j + 1]){
                int temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
                swaped = true;
            }
        }

        if (swaped == false){
            break;
        }
        
    }
  
    
}