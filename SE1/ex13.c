#include <stdio.h>

int main(){
    int a;
    int b;
    printf("A: ");
    scanf("%d", &a);
    printf("B: ");
    scanf("%d", &b);

    int radius;
    if (a > b){
        radius = b;
    } else {
        radius = a;
    }
    printf("Radius: %d", radius);
}