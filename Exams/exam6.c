#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct IceCream{
    char code[3];
    char name[20];
    int quantity;
    float price;
}IceCream;


int main(){
    int n;
    scanf("%d", &n);
    while (n <= 5 || n >= 15){
        printf("Invalid count\n");
        scanf("%d", &n);
    }
    IceCream* icecreams = malloc(n * sizeof(IceCream));
    if (icecreams == NULL){
        printf("Error with memorry allocation");
        exit(-1);
    }
    
    for (int i = 0; i < n; i++){
        IceCream icecream;
        scanf("%s", icecream.code);
        getchar();
        fgets(icecream.name, 20, stdin);
        scanf("%d", &icecream.quantity);
        scanf("%f", &icecream.price);
        icecreams[i] = icecream;
    }
    
}

float priceWithC(IceCream* icecreams, int count, char c){
    float sum = 0;
    for (int i = 0; i < count; i++){
        if (tolower(icecreams[i].name[0]) == tolower(c)){
            sum+=icecreams[i].price;
        }
    }
    return sum;
}

int writeToFile(IceCream* icecreams, int count, float price, int quantity){
    FILE* fp = fopen("info.txt", "w");

    if (fp == NULL){
        printf("Error occured");
        exit(-1);
    }
    int written = 0;
    for (int i = 0; i < count; i++){
        IceCream icecream = icecreams[i];
        if (icecream.price < price && icecream.quantity > quantity){
            fprintf(fp, "%s; %s; %d;%.2f lv\n", icecream.code, icecream.name, icecream.quantity, icecream.price);
            written++;
        }
        
    }
    
    fclose(fp);
    return written;
}

void checkCode(char code[3]){
    FILE* fp = fopen("icecream.bin", "rb");

    if (fp == NULL){
        printf("Error with file");
        exit(-1);
    }
    int valid = 0;
    char codeFromFile[3];
    while(fread(codeFromFile, 3, 1, fp) == 1){
        IceCream icecream;
        strcpy(icecream.code, codeFromFile);
        int len;
        fread(&len, sizeof(int), 1, fp);
        fread(icecream.name, len, 1, fp);
        icecream.name[len] = '\0';
        fread(&icecream.quantity, sizeof(int), 1, fp);
        fread(&icecream.price, sizeof(float), 1, fp);
        if (strcmp(code, icecream.code) == 0){
            valid++;
            printf("%s with code %s for %.2flv with quantity: %d\n", icecream.name, icecream.code, icecream.price, icecream.quantity);
            break;
        }
        
    }
    if (valid == 0){
        printf("No such product\n");
    }
    
    fclose(fp);
}