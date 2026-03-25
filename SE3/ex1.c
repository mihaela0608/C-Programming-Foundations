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

    for (int i = 0; i < n - 1; i++){
        int current_n = numbers[i];
        for (int j = i + 1; j < n; j++){
            int next_n = numbers[j];
            current_n = numbers[i];
            if(next_n < current_n){
                numbers[j] = current_n;
                numbers[i] = next_n;
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d ", numbers[i]);
    }
    printf("\n");

    int start_index = 0;
    int length = 1;
    int last_num = numbers[0];
    int biggest_length = 1;
    for (int i = 1; i < n; i++){
        int current_num = numbers[i];
        if (last_num == current_num){
            length++;
        } else{ 
            if (length > biggest_length){
                biggest_length = length;
                start_index = i - length;
            }
            length = 1;
        }
        
        last_num = current_num;
    }

    printf("Biggest with length: %d; starting at: %d\n", biggest_length, start_index);
    
}