#include <stdio.h>

int main(){
    int number;
    
    printf("Your number: ");
    scanf("%d", &number);
    double bonus_points = 0;

    if(number <= 100){
        bonus_points+=5;
    } else if (number > 100 && number <= 1000){
        bonus_points = number*0.2;
    } else{
        bonus_points = number*0.1;
    }

    if(number % 2 == 0){
        bonus_points++;
    }
    if(number % 10 == 5){
        bonus_points+=2;
    }

    printf("Bonus points: %lf\n", bonus_points);
    printf("All points: %lf", bonus_points + number);
    
}