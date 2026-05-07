#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Medicine{
    char name[30];
    char date[9];
    long code;
    double price;
    int quantity;

}Medicine;

Medicine* beforeDate(Medicine* medicines, int count, char date[9]);
int writeWithPrice(Medicine* medicines, int count, double start_price, double end_price);

int main(){

    FILE* fp = fopen("medicines.bin", "rb");

    if (fp == NULL){
        printf("Error occured");
        exit(-1);
    }

    Medicine* medicines = malloc(5 * sizeof(Medicine));
    Medicine medicine;
    int capacity = 5;
    int count = 0;
    while (fread(&medicine, sizeof(Medicine), 1, fp) == 1){
        medicines[count] = medicine;
        count++;
        if (count + 1 == capacity){
            Medicine* temp = realloc(medicines, capacity * 2 * sizeof(Medicine));
            if (temp == NULL){
                printf("Error with realloc");
                exit(-1);
            }
            medicines = temp;
            capacity = capacity * 2;
        }

        
    }
    fclose(fp);

    int saved = writeWithPrice(medicines, 3, 6, 10);
    printf("%d", saved);

}

Medicine* beforeDate(Medicine* medicines, int count, char date[9]){
    Medicine* medicine = malloc(5 * sizeof(Medicine));
    int capacity = 5;
    int ind = 0;
    int day;
    int year;
    sscanf(date, "%d. %d", &day, &year);
    for (int i = 0; i < count; i++){
        char current_date[9];
        strcpy(current_date, medicines[i].date);
        int current_day;
        int current_year;
        sscanf(current_date, "%d. %d", &current_day, &current_year);
        int valid = -1;
        if (current_year < year){
            valid = 0;
        }
        if (current_year == year && current_day < day){
            valid = 0;
        }
        
        if (valid == 0){
            medicine[ind] = medicines[i];
            ind++;
            if (ind == capacity){
                Medicine* temp = realloc(medicine, capacity * 2 * sizeof(Medicine));
                capacity*=2;
                if (temp == NULL){
                    printf("Error with memorry");
                    exit(-1);
                }
                medicine = temp;
                
            }
            
        }
    }
    if (ind == 0){
        return NULL;
    } else{
        return medicine;
    }
    
}

int writeWithPrice(Medicine* medicines, int count, double start_price, double end_price){
    FILE* fp = fopen("offer.txt", "w");

    if (fp == NULL){
        printf("Error opening file!");
        exit(-1);
    }
    int saved = 0;
    for (int i = 0; i < count; i++){
        Medicine medicine = medicines[i];
        double price = medicine.price;
        if (price >= start_price && price <= end_price){
            fprintf(fp, "%s\n%s\n%ld\n%d\n%.2lfleva\n\n", medicine.name, medicine.date, medicine.code, medicine.price);
            saved++;
        }
        
    }
    
    fclose(fp);
    return saved;
}

void deleteMedicine(Medicine* medicines, int count, char name[30], char date[9]){
    int found = -1;
    for (int i = 0; i < count; i++){
        Medicine medicine = medicines[i];
        if (strcmp(medicine.name, name) == 0 && strcmp(medicine.date, date) == 0){
            for (int j = i; j < count - 1; j++){
                medicines[j] = medicines[j+1];
            }
            free(&medicines[count - 1]);
            found = 0;
            break;
        }
        
    }

    if (found == -1){
        printf("Not found");
    }
    
    
}