#include <stdio.h>

int main(){
    float deg;
    printf("Degrees: ");
    scanf("%f", &deg);

    printf("Radians: %.2f", deg * 0.017);
}