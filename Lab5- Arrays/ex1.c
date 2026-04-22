#include <stdio.h>

int main(){
    int n;
    printf("Count: ");
    scanf("%d", &n);
    int numbers[n];
    int sum = 0;

    for (int i = 0; i < n; i++){
        int num;
        printf("Number %d: ", i + 1);
        scanf("%d", &num);
        numbers[i] = num;
        sum+=num;
    }
    
    float average = sum / n;
    int biggest = numbers[0];
    int smallest = numbers[0];

    for (int i = 1; i < n; i++){
        int num = numbers[i];
        if (num > biggest){
            biggest = num;
        } else if(num < smallest){
            smallest = num;
        }
        
    }
    
    printf("Biggest: %d, Smallest: %d, Average: %f", biggest, smallest, average);

}