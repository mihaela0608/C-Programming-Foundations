#include <stdio.h>
#include <math.h>

int main(){
    int numbers[7];

    for (int i = 0; i < 7; i++){
        scanf("%d", &numbers[i]);
    }
    int sum = 0;
    for (int i = 0; i < 7; i++){
        sum+=numbers[i];
    }
    float average = sum / 7.0;
    float closest = abs(numbers[0] - average);
    int ind = 0;
    for (int i = 1; i < 7; i++){
        if (abs(numbers[i] - average) < closest){
            closest = abs(numbers[i] - average);
            ind = i;
        }
        
    }

    printf("Closest to average is %d at index %d", numbers[ind], ind);
}