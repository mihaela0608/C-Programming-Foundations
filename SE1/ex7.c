#include <stdio.h>
#include <math.h>

int main(){
    float x1;
    float y1;
    float x2;
    float y2;
    printf("X1: ");
    scanf("%f", &x1);
    printf("Y1: ");
    scanf("%f", &y1);
    printf("X2: ");
    scanf("%f", &x2);
    printf("Y2: ");
    scanf("%f", &y2);

    float a = abs(x2 - x1);
    float b = abs(y1 - y2);

    printf("Area: %.2f", a * b / 2);
}