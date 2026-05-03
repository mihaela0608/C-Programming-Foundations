#include <stdio.h>

void change(int* a, int* b);

int main(){
    int a;
    int b;

    scanf("%d", &a);
    scanf("%d", &b);

    int* pa = &a;
    int* pb = &b;

    change(pa, pb);

    printf("%d %d", a, b);
}

void change(int* a, int* b){
    int value = *b;
    *b = *a;
    *a = value;
}