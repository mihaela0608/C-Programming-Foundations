#include <stdio.h>

int main(){
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    int current_row = 1;
    int count = 1;
    do{
        if (count <= current_row){
           printf("%d", num); 
           count++;
        } else{
            printf("\n");
            current_row++;
            count = 0;
        }
        
    } while (current_row <= num);
}