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
    int length = 1;
    int last_num = numbers[0];
    int biggest_length = 1;
    int length_num = numbers[0];
    for (int i = 1; i < n; i++){
        int current_num = numbers[i];
        if (last_num == current_num){
            length++;
            length_num = numbers[i];
        } else{ 
            if (length > biggest_length){
                biggest_length = length;
            }
            length = 1;
            
        }
        
        last_num = current_num;
    }

    for (int i = 0; i < biggest_length; i++){
        printf("%d ", length_num);
    }
    

}