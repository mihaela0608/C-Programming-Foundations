#include <stdio.h>

int main(){
    int start;
    int end;
    printf("Enter start number: ");
    scanf("%d", &start);
    printf("Enter end number: ");
    scanf("%d", &end);
    int sum = 0;
    for (int i = start +1; i < end; i++){
        sum+=i;
    }
    printf("Sum is: %d", sum);
}