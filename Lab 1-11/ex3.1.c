#include <stdio.h>

void swap(int* a, int* b);

int main(){
    int a;
    int b;
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("A: %d B: %d", a, b);
}

void swap(int* a, int* b){
    int value = *b;
    *b = *a;
    *a = value;
}