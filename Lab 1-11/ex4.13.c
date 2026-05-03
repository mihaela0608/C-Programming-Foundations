#include <stdio.h>

int longestIncreasingRun(int *arr, int n);

int main(){
    int numbers[10] = {1, 2, 4, 9, 8, 5, 3, 2, 9, 1};
    printf("%d", longestIncreasingRun(numbers, 10));
}

int longestIncreasingRun(int *arr, int n){
    int count = 1;
    int biggest_count = 1;
    int last = arr[0];
    for (int i = 1; i < n; i++){
        int num = arr[i];
        if(num > last){
            count++;
        } else{
            if(count > biggest_count){
                biggest_count = count;
            }
            count = 1;
        }
        last = num;
    }
    return biggest_count;
}