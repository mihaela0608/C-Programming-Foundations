#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* fp = fopen("numbers.txt", "w");

    if (fp == NULL){
        printf("Error opening file for writing");
        exit(-1);
    }

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);
        fprintf(fp, "%d ", num);
    }

    fclose(fp);

    fp = fopen("numbers.txt", "r");

    if (fp == NULL){
        printf("Error opening file for reading");
        exit(-1);
    }
    

    int count_even = 0;
    int count_odd = 0;
    int num;
    while (fscanf(fp, "%d", &num) > 0){
        if (num % 2 == 0) {
            count_even++;
        } else{
            count_odd++;
        }
        
    }

    printf("Even: %d; Odd: %d", count_even, count_odd);
    fclose(fp);

    fp = fopen("numbers.txt", "r");
    
    if (fp == NULL){
        printf("Error opening file for reading");
        exit(-1);
    }
    
    int* numbers = malloc(5 * sizeof(int));
    int ind = 0;
    int capacity = 5;
    while (fscanf(fp, "%d", &num) > 0){
        numbers[ind] = num;
        if (ind + 1 == capacity){
            int* temp = realloc(numbers, capacity * 2 * sizeof(int));
            capacity = capacity * 2;
            numbers = temp;
        }
        ind++;
    }

    for (int i = 0; i < ind - 1; i++){
        int swapped = -1;
        for (int j = 0; j < ind - 1 - i; j++){
            int for_change = numbers[j];
            if (for_change > numbers[j + 1]){
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = for_change;
                swapped = 0;
            }
        }

        if (swapped == -1){
            break;
        }
            
    }

    fclose(fp);

    fp = fopen("sorted.txt", "w");

    if (fp == NULL){
        printf("Error fpening file for writing");
        exit(-1);
    }
    
    for (int i = 0; i < ind; i++){
        fprintf(fp, "%d ", numbers[i]);
    }
    
    fclose(fp);
    
}