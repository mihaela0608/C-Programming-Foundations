#include <stdio.h>

void sumAndProduct(int a, int b, int *sum, int *product);

int main(){
    int a;
    int b;
    int sum;
    int product;

    scanf("%d", &a);
    scanf("%d", &b);

    sumAndProduct(a, b, &sum, &product);
    printf("Sum: %d, Product: %d", sum, product);
}

void sumAndProduct(int a, int b, int *sum, int *product){
    *sum = a + b;
    *product = a * b;
}