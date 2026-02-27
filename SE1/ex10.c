#include <stdio.h>

int main(){
    float priceN;
    float priceM;
    printf("Price for vegetables: ");
    scanf("%f", &priceN);
    printf("Price for froots:");
    scanf("%f", &priceM);

    float kgN;
    float kgM;
    printf("Kgs vegetables: ");
    scanf("%f", &kgN);
    printf("Kgs froots:");
    scanf("%f", &kgM);

    float price_levs = priceN * kgN + priceM * kgM;
    float euro = price_levs / 1.95;

    printf("Price is %.2f euro", euro);
}