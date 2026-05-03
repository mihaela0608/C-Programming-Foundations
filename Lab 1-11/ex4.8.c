#include <stdio.h>

int duplicateOdds(int *src, int *dst, int n);

int main(){
    int nums[10] = {1, 2, 3, 4, 5, 6, 8, 10, 12, 88};
    int dsc[20];
    int new_size = duplicateOdds(nums, dsc, 10);

    for (int i = 0; i < new_size; i++){
        printf("%d ", dsc[i]);
    }
}

int duplicateOdds(int *src, int *dst, int n){
    int count = 0;
    for (int i = 0; i < n; i++){
        if (src[i] % 2 == 0){
            dst[count] = src[i];
            count++;
        }  else{
            dst[count] = src[i];
            count++;
            dst[count] = src[i];
            count++;
        }
        
    }
    return count;
}