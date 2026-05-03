#include <stdio.h>

int filterEven(int *src, int *dst, int n);

int main(){
    int nums[10] = {1, 2, 3, 4, 5, 6, 8, 10, 12, 88};
    int even_nums[10];
    int new_size = filterEven(nums, even_nums, 10);

    for (int i = 0; i < new_size; i++){
        printf("%d ", even_nums[i]);
    }
    

}

int filterEven(int *src, int *dst, int n){
    int count = 0;
    for (int i = 0; i < n; i++){
        if (src[i] % 2 == 0){
            dst[count] = src[i];
            count++;
        }
    }

    return count;
    
}