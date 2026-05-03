#include <stdio.h>

void countDigits(int n, int *count);

int main(){
    int num;
    scanf("%d", &num);
    while (num != 0){
        int count;
        countDigits(num, &count);
        printf("%d digits\n", count);
        scanf("%d", &num);
    }
    
}

void countDigits(int n, int *count){
    int countD = 0;
    while (n / 10 > 0){
        n = n / 10;
        countD++;
    }
    *count = countD + 1;
    
}