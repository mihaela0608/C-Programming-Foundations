#include <stdio.h>

int main(){
    int days;
    printf("Days: ");
    scanf("%d", &days);

    float dollars;
    printf("Dollars per day: ");
    scanf("%f", &dollars);

    float money_per_month = days * dollars;
    float bonus = money_per_month * 2.5;
    float money = money_per_month * 12 + bonus - (money_per_month * 12 * 0.25);

    float levs = money / 1.59;
    printf("%f", levs / (days * 12));
}