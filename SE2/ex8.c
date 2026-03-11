#include <stdio.h>

int main(){
    double volume;
    double liters1;
    double liters2;
    int hours;
    printf("Volume: ");
    scanf("%lf", &volume);
    printf("Liters1: ");
    scanf("%lf", &liters1);
    printf("Lites2: ");
    scanf("%lf", &liters2);
    printf("Hours: ");
    scanf("%d", &hours);

    volume = volume / 1000;
    double water = liters1 * hours + liters2 * hours;
    if(water < volume){
        printf("The pool is not full yet.");
    } else if(water == volume){
        printf("The pool is full");
    } else{
        printf("The pool is overfloating");
    }


}