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
    int k;
    scanf("%d", &k);
    int current_biggest = numbers[0];
    for (int i = 0; i < k; i++){
        current_biggest = numbers[0];
        int smallest = numbers[0];
        int ind = 0;
        for (int j = 0; j < n; j++){
            if (numbers[j] > current_biggest){
                current_biggest = numbers[j];
                ind = j;
            }else if(numbers[j] < smallest){
                smallest = numbers[j];
            }
        }
        numbers[ind] = smallest;
        
    }

    printf("%d is %d biggest\n", current_biggest, k);
    
}