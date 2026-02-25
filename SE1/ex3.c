#include <stdio.h>

int main(){
    float c;
    printf("Celsius: ");
    scanf("%f", &c);

    printf("\nFarenheit: %.2f", c * 33.8);
}