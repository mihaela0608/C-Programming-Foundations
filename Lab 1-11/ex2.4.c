#include <stdio.h>
#include <math.h>
#include <stdbool.h>
void analyzeNumber(int n, int *isEven, int *isPositive, int *digitSum);

int main(){
    int num;
    int isEven;
    int isPositive;
    int digitSum;

    scanf("%d", &num);
    while (num != 0){
        analyzeNumber(num, &isEven, &isPositive, &digitSum);
        printf("Num: %d, Is even: %d, Is positive: %d, Digit sum: %d\n", num, isEven, isPositive, digitSum);
        scanf("%d", &num);
    }
    
}

void analyzeNumber(int n, int *isEven, int *isPositive, int *digitSum){
    if (n % 2 == 0){
       *isEven = 0; 
    } else{
        *isEven = 1;
    }

    if (n >= 0){
        *isPositive = 0;
    } else{
        *isPositive = 1;
    }
    int sum = 0;
    int temp = abs(n);  
    
    while (temp > 0) {
        sum += temp % 10;  
        temp /= 10;         
    }
    
    *digitSum = sum;
}