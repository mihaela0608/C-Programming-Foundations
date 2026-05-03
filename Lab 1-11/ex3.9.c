#include <stdio.h>

int main(){
    int a = 5;
    int b = 8;
    int c = 3;

    int* nums[3] = {&a, &b, &c};
    for (int i = 0; i < sizeof(nums) / sizeof(int); i++){
        int num = **(nums + i);
        printf("%d", num);
    }
    
}