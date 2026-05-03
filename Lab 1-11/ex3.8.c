#include <stdio.h>

void swapXor(int *a, int *b);

int main(){
    int a = 5;
    int b = 8;
    swapXor(&a, &b);
    printf("%d %d", a,b);
}

void swapXor(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}