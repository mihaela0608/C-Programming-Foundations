#include <stdio.h>

int main(){
    float x1;
    float y1;
    float x2;
    float y2;
    float x3;
    float y3;
    printf("X1: ");
    scanf("%f", &x1);
    printf("Y1: ");
    scanf("%f", &y1);
    printf("X2: ");
    scanf("%f", &x2);
    printf("Y2: ");
    scanf("%f", &y2);
    printf("X3: ");
    scanf("%f", &x3);
    printf("Y3: ");
    scanf("%f", &y3);

    float area = (x1*(y2 - y3) + y1*(x2-x3) + (x2*y3 - y2* x3)) / 2;

    printf("%.2f");
}