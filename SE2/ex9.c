#include <stdio.h>

int main(){
    int area;
    int kg_grapes;
    int liters;

    printf("Area: ");
    scanf("%d", &area);
    printf("Kg grapes: ");
    scanf("%d", &kg_grapes);
    printf("Liters: ");
    scanf("%d", &liters);

    int all_grapes = area * kg_grapes;
    int all_liters = 2.5 * all_grapes;

    if(all_liters < liters){
        printf("Not enough vine");
    } else{
        printf("The vine is enough");
    }
}