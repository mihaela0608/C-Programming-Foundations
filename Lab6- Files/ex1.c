#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("N: ");
    scanf("%d", &n);
    int numbers[n + 1];

    numbers[0] = n;

    for (int i = 1; i <= n ; i++){
        printf("Number %d: ", i+1);
        scanf("%d", &numbers[i]);
    }


    FILE *pFile = fopen("first.bin", "wb");
    if (pFile == NULL){
        printf("Error has occured");
        return 1;
    }
    
    for (int i = 0; i < n + 1; i++){
        fwrite(&numbers[i], sizeof(int), 1, pFile);
    }
    
    int even = 0;
    int odd = 0;
    for (int i = 0; i < n + 1; i++){
        if (numbers[i] % 2 == 0){
            even++;
        } else{
            odd++;
        }
        
    }

    printf("Even count: %d\n", even);
    printf("Odd count: %d\n", odd);
    

    fclose(pFile);

    FILE *fp = fopen("write.txt", "w");
    FILE *fR = fopen("first.bin", "rb");


    if (fp == NULL || fR == NULL){
        printf("Error has occured");
        return 1;
    }
    int nums[n];
    for (int i = 0; i < n + 1; i++){
        fread(&nums[i], sizeof(int), 1, fR);
    }

    for (int i = 0; i < n; i++){
        if (nums[i + 1] < nums[i]){
            int num = nums[i + 1];
            nums[i + 1] = nums[i];
            nums[i] = num;
        }   
    }
    
    for (int i = 0; i < n + 1; i++){
        fprintf(fp, "%d", nums[i]);
    }
    

    
    

    fclose(fp);
    fclose(fR);

}