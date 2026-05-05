#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* fp = fopen("numbers.txt", "w");

    if (fp == NULL){
        printf("Error opening file for writing");
        exit(-1);
    }

    fprintf(fp, "%d ", 3);
    fprintf(fp, "%d ", 3);
    fprintf(fp, "%d ", 2);
    fprintf(fp, "%d ", 4);


    fclose(fp);

    FILE* fp_r = fopen("numbers.txt", "r");

    if (fp_r == NULL){
        printf("Error opening file for reading");
        exit(-1);
    }
    

    int count;
    fscanf(fp_r, "%d", &count);
    int count_even = 0;
    int count_odd = 0;
    for (int i = 0; i < count; i++){
        int num;
        fscanf(fp_r, "%d", &num);
        if (num % 2 == 0){
            count_even++;
        }else{
            count_odd++;
        }
        
    }
    
    printf("Even: %d; Odd: %d", count_even, count_odd);

    fclose(fp_r);

    fp_r = fopen("numbers.txt", "r");

    if (fp_r == NULL){
        printf("Error opening file for reading");
        exit(-1);
    }
    fscanf(fp_r, "%d", &count);
    int numbers[count];

    for (int i = 0; i < count; i++){
        fscanf(fp, "%d", &numbers[i]);
    }

    
    for (int j = 0; j < count - 1; j++){
        int swapped = -1;
        for (int i = 0; i < count - j - 1; i++){
            if (numbers[i] > numbers[i + 1]){
                swapped = 0;
                int num = numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i + 1] = num;
            }
        }
        if (swapped == -1){
            break;
        }
        
    }
    fclose(fp_r);

    fp = fopen("sorted.txt", "w");
    for (int i = 0; i < count; i++){
        fprintf(fp, "%d ", numbers[i]);
    }
    

    fclose(fp);
}