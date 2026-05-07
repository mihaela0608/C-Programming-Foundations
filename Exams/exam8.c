#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Excursion{
    char destination[30];
    char date[11];
    float price;
    int days;
}Excursion;


int main(){
    int n;
    scanf("%d", &n);
    while (n <= 10 || n >= 30){
        printf("Invalid count");
        scanf("%d", &n);
    }
    Excursion* excursions = malloc(n * sizeof(Excursion));
    for (int i = 0; i < n; i++){
        Excursion exc;
        scanf("%s", exc.destination);
        scanf("%s", exc.date);
        scanf("%f", &exc.price);
        scanf("%d", &exc.days);
        excursions[i] = exc;
    }

    FILE* fp = fopen("excursions.bin", "wb");
    if (fp == NULL){
        printf("Error with file");
        exit(-1);
    }
    
    fwrite(excursions, sizeof(Excursion), n, fp);
    fclose(fp);
}

int writeToFile(Excursion* excursions, int count){
    FILE* fp = fopen("excursions.txt", "w");
    if (fp == NULL){
        printf("Error openning file");
        exit(-1);
    }
    int result = 0;

    for (int i = 0; i < count; i++){
        Excursion exc = excursions[i];
        fprintf(fp, "%s - %s - %.2f leva\n", exc.destination, exc.date, exc.price);
        result++;
    }
    

    fclose(fp);
    return result;
}

void searchByDestination(char destination[30]){
    FILE* fp = fopen("excursions.bin", "rb");
    if (fp == NULL){
        printf("Error occured");
        exit(-1);
    }
    int count = 0;

    Excursion exc;
    int len;
    while (fread(&len, sizeof(int), 1, fp) == 1){
        fread(exc.destination, len, 1, fp);
        exc.destination[len] = '\0';
        fread(exc.date, 10, 1, fp);
        exc.date[10] = '\0';
        fread(&exc.price, sizeof(float), 1, fp);
        fread(&exc.days, sizeof(int), 1, fp);
        if (strcmp(exc.destination, destination) == 0){
            printf("%s - %.2f BGN - %d days\n", exc.date, exc.price, exc.days);
            count++;
        }
        
    }
    

    if (count == 0){
        printf("No results");
    }
    
    fclose(fp);
}