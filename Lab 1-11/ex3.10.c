#include <stdio.h>

void divide(int a, int b, int *quotient, int *remainder);

int main(){
    int a = 8;
    int b = 3;
    int quotient;
    int remainder;
    divide(a, b, &quotient, &remainder);

    printf("%d %d", quotient, remainder);
}

void divide(int a, int b, int *quotient, int *remainder){
    if (b == 0){
        *quotient = 0;
        *remainder = 0;
        return;
    }

    *quotient = a / b;
    *remainder = a % b;
    
}