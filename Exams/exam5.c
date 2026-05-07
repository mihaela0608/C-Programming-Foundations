#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Picture{
    int code;
    char painter[30];
    char picture_name[30];
    float price;
}Picture;

float averageWithPrice(Picture* pictures, int count, float price);
int writeWithLetter(Picture* pictures, int count, char c);
void searchByPainter(char painter[30]);
void writeInBin(Picture* pictures, int count);

int main(){
    int n;
    scanf("%d", &n);


    while (n <= 3 || n >= 30){
        printf("Invalid count\n");
        scanf("%d", &n);
    }
    
    Picture* pictures = calloc(n, sizeof(Picture));

    if (pictures == NULL){
        printf("Error with memorry allocation");
        exit(-1);
    }
    

    for (int i = 0; i < n; i++){
        Picture picture;
        scanf("%d", &picture.code);
        fgets(picture.painter, sizeof(picture.painter), stdin);
        scanf("%s", picture.picture_name);
        scanf("%f", &picture.price);

        pictures[i] = picture;
    }
    
}

float averageWithPrice(Picture* pictures, int count, float price){
    float sum = 0;
    int count_avg = 0;
    for (int i = 0; i < count; i++){
        if (pictures[i].price > price){
            sum+=pictures[i].price;
            count_avg++;
        }
        
    }

    if (count_avg == 0){
        return 0;
    } else{
        return sum / count_avg;
    }
    
}

int writeWithLetter(Picture* pictures, int count, char c){
    FILE* fp = fopen("info.txt", "w");

    if (fp == NULL){
        printf("Error with file");
        exit(-1);
    }
    int written = 0;
    for (int i = 0; i < count; i++){
        if (tolower(pictures[i].painter[0]) == tolower(c)){
            fprintf(fp, "%d; %s; %.2fleva\n", pictures[i].code, pictures[i].picture_name, pictures[i].price);
            written++;
        }
    }
    
    fclose(fp);
    return written;
}

void searchByPainter(char painter[30]){
    FILE* fp = fopen("picture.bin", "rb");

    if (fp == NULL){
        printf("Error occured");
        exit(-1);
    }
    int count = 0;
    int code;
    while(fread(&code, sizeof(int), 1, fp) == 1){
        Picture picture;
        picture.code = code;
        int len;
        fread(&len, sizeof(int), 1, fp);
        fread(picture.painter, len, 1, fp);
        picture.painter[len] = '\0';
        fread(&len, sizeof(int), 1, fp);
        fread(picture.picture_name, len, 1, fp);
        picture.picture_name[len] = '\0';
        fread(&picture.price, sizeof(float), 1, fp);

        if (strcmp(picture.painter, painter) == 0){
            printf("Picture: %s for %.2f with code %d\n", picture.picture_name, picture.price, picture.code);
            count++;
        }
        
    }
    if (count == 0){
        printf("No such painter");
    }
    
    fclose(fp);
}

void writeInBin(Picture* pictures, int count){
    FILE* fp = fopen("picture.bin", "wb");

    if (fp == NULL){
        printf("Error");
        exit(-1);
    }
    
    for (int i = 0; i < count; i++){
        Picture picture = pictures[i];
        fwrite(&picture.code, sizeof(int), 1, fp);
        fwrite(strlen(picture.painter), sizeof(int), 1, fp);
        fwrite(picture.painter, strlen(picture.painter), 1, fp);
        fwrite(strlen(picture.picture_name), sizeof(int), 1, fp);
        fwrite(picture.picture_name, strlen(picture.picture_name), 1, fp);
        fwrite(&picture.price, sizeof(float), 1, fp);
    }
    

    fclose(fp);
}