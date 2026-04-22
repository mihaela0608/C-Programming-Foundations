#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    int guests = 0;
    printf("Number of guests: ");
    scanf("%d", &guests);
    int chairs = 0;
    int tables = 0;
    int cups = 0;
    int dishes = 0;
    float price = 0;

    char product[20];
    scanf("%s", product);

    while(strcmp(product, "PARTY!") != 0){
        
        if (strcmp(product, "Table") == 0){
            tables++;
        } else if(strcmp(product, "Chair") == 0){
            chairs++;
        } else if(strcmp(product, "Cups") == 0){
            cups++;
        } else if(strcmp(product, "Dishes") == 0){
            dishes++;
        }
        
        scanf("%s", product);

    }

    price+=chairs*13.99;
    price+=tables*42.00;
    price+=cups*5.98;
    price+=dishes*21.02;

    printf("Price is: %.2f\n", price);

    if (chairs < guests){
        printf("You need %d more chairs\n", guests - chairs);
    } 
    if (tables * 8 < guests){
        printf("You need %d more tables\n", (int)ceil((guests - tables * 8) / 8.0));
    } 
    if (cups * 6 < guests){
        printf("You need %d more cups\n", (int)ceil((guests - cups * 6) / 6.0));
    }
    if (dishes * 6 < guests){
        printf("You need %d more dishes\n", (int)ceil((guests - dishes * 6) / 6.0));
    }
    
    
    
}