#include <stdio.h>

void swapPtr(int **a, int **b);

int main(){
    int x=5, y=10;
    int *p1 = &x, *p2 = &y;
    printf("*p1=%d, *p2=%d\n", *p1, *p2); 
    swapPtr(&p1, &p2);
    printf("*p1=%d, *p2=%d\n", *p1, *p2);
}

void swapPtr(int **a, int **b){
    int x = **a;
    int y = **b;
    *a = &y;
    *b = &x;
}