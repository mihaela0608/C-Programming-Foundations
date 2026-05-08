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

void lower_price(Medicine* medicines, int count, char date[9]);
void write_Bin(Medicine* medicines, int count, int quantity);
void delete_by_code(Medicine* medicines, int count, long code);

int main(){
    FILE* fp = fopen("medicines.txt", "r");
    if (fp == NULL){
        printf("Error openning file");
        exit(-1);
    }
    Medicine* medicines = malloc(5* sizeof(Medicine));
    if (medicines == NULL){
        printf("Error with memorry");
        exit(-1);
    }
    
    int count = 0;
    int capacity = 5;
    Medicine medicine;
    while (fscanf(fp, "%s;%s;%ld;%lf;%d", medicine.name, medicine.date, &medicine.code, &medicine.price, &medicine.quantity) == 5){
        medicines[count] = medicine;
        count++;
        if (count == capacity){
            Medicine* temp = realloc(medicines, capacity * 2 * sizeof(Medicine));
            if (temp == NULL){
                printf("Error with memorry");
                exit(-1);
            }
            medicines = temp;
            capacity = capacity * 2;
        }
        
    }
    

    fclose(fp);
}

void lower_price(Medicine* medicines, int count, char date[9]){
    int month, year;
    int changed = 0;
    sscanf(date, "%d. %d", &month, &year);
    for (int i = 0; i < count; i++){
        Medicine medicine = medicines[i];
        int current_month, current_year;
        sscanf(medicine.date, "%d. %d", &current_month, &current_year);
        if (current_year < year || (current_year == year && current_month < month)){
            double before = medicine.price;
            medicine.price*=0.8;
            medicines[i] = medicine;
            printf("%s - %s - %.2fлева- %.2fлева\n", medicine.name, medicine.date, before, medicine.price);
            changed++;
        }
        
    }
    if (changed == 0){
        printf("No elements changed");
    }
}

void write_Bin(Medicine* medicines, int count, int quantity){
    FILE* fp = fopen("offers.bin", "wb");
    if (fp == NULL){
        printf("Error openning file");
        exit(-1);
    }
    
    for (int i = 0; i < count; i++){
        if (medicines[i].quantity > quantity){
            Medicine med = medicines[i];
            int name_len = strlen(med.name);
            fwrite(&name_len, sizeof(int), 1, fp); 
            fwrite(med.name, strlen(med.name), 1, fp);
            fwrite(med.date, 9, 1, fp);
            fwrite(&med.code, sizeof(long), 1, fp);
            fwrite(&med.price, sizeof(double), 1, fp);
            fwrite(&med.quantity, sizeof(int), 1, fp);
        }
        
    }
    
    fclose(fp);
}

void delete_by_code(Medicine* medicines, int count, long code){
    int found = 0;
    for (int i = 0; i < count; i++){
        if (medicines[i].code == code){
            for (int j = i; j < count - 1; j++){
                medicines[j] = medicines[j+1];
            }
            Medicine* temp = realloc(medicines, (count - 1) * sizeof(Medicine));
            if (temp == NULL){
                printf("Error with memorry allocation");
                exit(-1);
            }
            medicines = temp;
            count--;
            found++;
            break;
        }
        
    }
    if (found == 0){
        printf("No such medicine");
    }
    
}