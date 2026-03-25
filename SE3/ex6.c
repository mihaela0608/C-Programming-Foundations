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
    int biggest_length = 1;
    int length = 1;
    int previous = numbers[0];

    for (int i = 1; i < n; i++){
        if (numbers[i] > previous){
            length++;
        } else{
            if (length > biggest_length){
                biggest_length = length;
            }
            length = 1;
        }
        previous = numbers[i];
    }
    printf("%d", biggest_length);
    
}