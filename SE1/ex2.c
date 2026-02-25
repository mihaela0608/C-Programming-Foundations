#include <stdio.h>

int main(){
    printf("Write inches: ");
    float inches;
    scanf("%f", &inches);
    
    float mm = inches * 25.4;
    float cm = inches * 2.54;
    float dm = cm / 10;
    float m = dm / 10;

    printf("Milimeters: %.2f, Santimeters %.2f, Decimeters %.2f, Meters %.2f", mm, cm, dm, m);

}