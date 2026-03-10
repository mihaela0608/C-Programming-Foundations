#include <stdio.h>

int main(){
    int start;
    int end;

    printf("Enter start number: ");
    scanf("%d", &start);
    printf("Enter end number: ");
    scanf("%d", &end);

    for(int i = start + 1; i < end; i++){
        printf("Result of the function for %d is %d\n", i, i*i-4);
    }
}