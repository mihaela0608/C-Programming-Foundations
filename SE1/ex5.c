#include <stdio.h>

int main(){
    float levs;
    printf("Levs: ");
    scanf("%f", &levs);
    printf("Dolars: %.2f\n", levs * 0.6);
    printf("Euro: %.2f\n", levs / 1.95583);
    printf("Pounds: %.2f\n", levs * 0.44);
}