#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Treatment{
    int id;
    char date[11];
    char name[30];
    char diagnose[50];
}Treatment;

int count_treatment(Treatment* history, int n, char name[30], char diagnose[50]);
Treatment* add_new_treatment(Treatment* history, int count);
int write_text_file(Treatment* history, int n, char diagnose[50]);

int main(){
    FILE* fp = fopen("history.bin", "rb");

    if (fp == NULL){
        printf("Error opening file");
        exit(-1);
    }
    int n;
    if (fread(&n, sizeof(int), 1, fp) != 1){
        printf("Error reading count");
        fclose(fp);
        return 1;
    }
    
    Treatment* history = malloc(n * sizeof(Treatment));
    if (history == NULL){
        printf("Error with memorry allocation");
        exit(-1);
    }

    if (fread(history, sizeof(Treatment), n, fp) != n){
        printf("Error with reading treatments");
        return 1;
    }
    
    
    
    fclose(fp);
}

int count_treatment(Treatment* history, int n, char name[30], char diagnose[50]){
    int count = 0;
    for (int i = 0; i < n; i++){
        if (strcmp(history[i].diagnose, diagnose) == 0 && strcmp(history->name, name) == 0){
            count++;
        }
        
    }
    
    return count;
}

Treatment* add_new_treatment(Treatment* history, int count){
    Treatment* temp = realloc(history, (count + 1) * sizeof(Treatment));
    if(temp == NULL){
        printf("Error with memory");
        return NULL;
    }
    history = temp;

    Treatment treatment;
    scanf("%d", &treatment.id);
    while (getchar() != '\n');
    scanf("%s", treatment.date);
    fgets(treatment.name, sizeof(treatment.name), stdin);
    fgets(treatment.diagnose, sizeof(treatment.diagnose), stdin);
    history[count] = treatment;

    return history;
}

int write_text_file(Treatment* history, int n, char diagnose[50]){
    FILE* fp = fopen("illness.txt", "w");
    if (fp == NULL){
        printf("Error with file");
        exit(-1);
    }
    int count = 0;
    for (int i = 0; i < n; i++){
        if (strcmp(history[i].diagnose, diagnose) == 0){
            Treatment treatment = history[i];
            count++;
            fprintf(fp, "Болничен престой на %s\nза лечение на %s:\n%s\n", treatment.name, treatment.diagnose, treatment.date);
        }
        
    }
    

    fclose(fp);
    return count;
}