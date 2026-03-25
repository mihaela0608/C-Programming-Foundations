#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int numbers[n];
    for(int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);
        numbers[i] = num;
    }
    int sum;
    scanf("%d", &sum);

    int start_ind = 0;
    int end_ind = 0;
    int sum_check = 0;
    for (int i = 0; i < n; i++){
        sum_check+=numbers[i];
        if (sum == sum_check){
            end_ind = i;
            break;
        } else if(sum_check > sum){
            sum_check+=numbers[i];
            start_ind=i;
        } 
    }

    for (int i = start_ind; i <= end_ind; i++){
        printf("%d ", numbers[i]);
    }
    
    
}