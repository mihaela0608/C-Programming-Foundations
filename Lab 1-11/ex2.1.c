#include <stdio.h>

float square();
float rectangle();
float triangle();

int main(){
    int code;
    scanf("%d", &code);
    float area = 0;

    switch (code){
    case 1:
        area = square();
        break;
    case 2:
        area = rectangle();
        break;
    case 3:
        area = triangle();
        break;
    default:
        printf("Invalid code!\n");
        break;
    }

    printf("Area: %f", area);
}

float square(){
    float a;
    printf("A: ");
    scanf("%f", &a);

    return a * a;
}

float rectangle(){
    float a;
    printf("A: ");
    scanf("%f", &a);
    float b;
    printf("B: ");
    scanf("%f", &b);

    return a * b;
}

float triangle(){
    float a;
    printf("A: ");
    scanf("%f", &a);
    float b;
    printf("B: ");
    scanf("%f", &b);

    return (a * b) / 2;
}