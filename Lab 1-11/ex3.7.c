#include <stdio.h>

void safePrint(int *ptr);

int main(){
    int num = 5;
    safePrint(&num);
    safePrint(NULL);
}

void safePrint(int *ptr){
    if (ptr == NULL){
        printf("Is null\n");
    } else{
        printf("Not null\n");
    }
    
}