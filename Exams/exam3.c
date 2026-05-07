#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Car{
    char owner[35];
    char number[9];
    float price_fix;
    int priority;
}Car;

int main(){
    Car* cars = malloc(sizeof(Car) * 5);

}

void addCar(Car** cars, int* count, int* capacity) {
    if (*count >= *capacity) {
        *capacity *= 2;
        Car* temp = realloc(*cars, (*capacity) * sizeof(Car));
        if (temp == NULL) return;
        *cars = temp;
    }
    
    Car new_car;
    printf("Owner: "); scanf("%34s", new_car.owner);
    printf("Reg number: "); scanf("%8s", new_car.number);
    printf("Price: "); scanf("%f", &new_car.price_fix);
    printf("Priority: "); scanf("%d", &new_car.priority);
    
    (*cars)[*count] = new_car;
    (*count)++;
    
    FILE* fp = fopen("autoText.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%d;%s;%s;%.2f;%d\n", 
                (int)strlen(new_car.owner), 
                new_car.owner, new_car.number, 
                new_car.price_fix, new_car.priority);
        fclose(fp);
    }
}

void averagePrice(Car* cars, int count){
    float sum = 0;
    for (int i = 0; i < count; i++){
        sum+=cars[i].price_fix;
    }
    float average = sum / count;
    for (int i = 0; i < count; i++){
        if (cars[i].price_fix > average){
            printf("%s - %.2f\n", cars[i].number, cars[i].price_fix);
        }
        
    }
    
}

void carWithNumber(char number[9]){
    FILE* fp = fopen("auto.bin", "rb");
    if (fp == NULL){
        printf("Error occured");
        exit(-1);
    }
    
    Car car;
    while (fread(&car, sizeof(Car), 1, fp) > 0){
        if (strcmp(car.number, number) == 0){
            printf("%d%s%s%.2f%d", strlen(car.owner), car.owner, car.number, car.price_fix, car.priority);
        }
        
    }
    fclose(fp);
}