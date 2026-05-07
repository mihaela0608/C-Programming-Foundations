#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Medicine{
    char name[30];
    char date[9];
    long code;
    float price;
    int quantity;
}Medicine;

void lowerByDate(Medicine* medicines, int count, char date[9]);
void writeBin(Medicine* medicines, int count, int quantity);
void deleteByCode(Medicine* medicines, int count, long code);

int main(){
    FILE* fp = fopen("medicines.txt", "r");

    if (fp == NULL){
        printf("Error has occured");
        exit(-1);
    }
    Medicine* medicines = malloc(5 * sizeof(Medicine));
    int count = 0;
    int capacity = 5;
    Medicine medicine;
    while (fscanf(fp, "%s ; %s ; %ld; %f; %d \n", medicine.name, medicine.date, &medicine.code, &medicine.price, &medicine.quantity) == 5){
        medicines[count] = medicine;
        count++;
        if (count == capacity){
            Medicine* temp = realloc(medicines, capacity * 2 * sizeof(Medicine));
            if (temp == NULL){
                printf("Error with reallocation");
                exit(-1);
            }
            capacity = capacity * 2;
            medicines = temp;
        }
        
    }
     
    fclose(fp);
    free(medicines);
}


void lowerByDate(Medicine* medicines, int count, char date[9]){
    int month_Check, year_Check;
    sscanf(date, "%d. %d", &month_Check, &year_Check);
    int valid = 0;
    for (int i = 0; i < count; i++){
        Medicine medicine = medicines[i];
        int month, year;
        sscanf(medicine.date, "%d. %d", &month, &year);
        if (year < year_Check || (year == year_Check && month < month_Check)){
            float before = medicine.price;
            medicine.price*=0.8;
            medicines[i] = medicine;
            printf("%s - %s - %.2fлева - %.2f лева\n", medicine.name, medicine.date, before, medicine.price);
            valid++;
        }
    }
    if (valid == 0){
        printf("Nothing changed");
    }
    
}

void writeBin(Medicine* medicines, int count, int quantity){
    FILE* fp = fopen("offer.bin", "wb");

    if (fp == NULL){
        printf("Error opening file");
        exit(-1);
    }
    
    for (int i = 0; i < count; i++){
        Medicine medicine = medicines[i];
        if (medicine.quantity > quantity){
            fwrite(strlen(medicine.name), sizeof(int), 1, fp);
            fwrite(medicine.name, strlen(medicine.name), 1, fp);
            fwrite(medicine.date, 9, 1, fp);
            fwrite(&medicine.code, sizeof(long), 1, fp);
            fwrite(&medicine.price, sizeof(float), 1, fp);
            fwrite(&medicine.quantity, sizeof(int), 1, fp);
        }
        
    }

    fclose(fp);
}

void deleteByCode(Medicine* medicines, int count, long code){
    int deleted = -1;
    for (int i = 0; i < count; i++){
        if (medicines[i].code == code){
            for (int j = i; j < count - 1; j++){
                medicines[j] = medicines[j + 1];
            }
            Medicine* temp = realloc(medicines, (count - 1) * sizeof(Medicine));
            if (temp == NULL){
                printf("Error with realloc");
                exit(-1);
            }
            medicines = temp;
            deleted++;
        }
        
    }
    if (deleted == -1){
        printf("No such element");
    }
    
    
}