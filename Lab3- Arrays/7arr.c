#include <stdio.h>
#include <math.h>

int main(){
    int numbers[7] = {};
    int sum = 0;
    printf("All numbers shoud be between -5000 and 5000\n");
    for(int i = 0; i < 7; i++){
        int num;
        scanf("%d", &num);
        sum+=num;
        numbers[i] = num;
    }
    float average = sum / 7;
    float min_diff = numbers[0];
    int ind = 0;
    for (int i = 0; i < 7; i++){
        float current_diff = abs(average - numbers[i]);
        if (current_diff < min_diff){
            min_diff = current_diff;
            ind = i;
        }
    }
    
    printf("Average value: %.2f; Closest to average: %d at %d index\n", average, numbers[ind], ind);
    
}