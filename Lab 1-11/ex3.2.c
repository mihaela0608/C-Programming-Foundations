#include <stdio.h>

void minMax(int arr[], int n,int *min, int *max);

int main(){
    int num;
    int numbers[5];
    int min = 0;
    int max = 0;
    int* pMin = &min;
    int* pMax = &max;
    int count = 0;
    scanf("%d", &num);
    while (num != 0){
        numbers[count] = num;
        count++;
        if (count == 5){
            break;
        }
        
        scanf("%d", &num);
    }
    minMax(numbers, 5,pMin, pMax);
    printf("Max: %d Min: %d", max, min);
}

void minMax(int arr[], int n, int *min, int *max){
    int minN = arr[0];
    int maxN = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] > maxN){
            maxN = arr[i];
        }
        if (arr[i] < minN){
            minN = arr[i];
        }
        
    }

    *min = minN;
    *max = maxN;
}