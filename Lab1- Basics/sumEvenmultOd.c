#include <stdio.h>

int main(){
    int start;
    int end;

    printf("Enter start number: ");
    scanf("%d", &start);
    printf("Enter end number: ");
    scanf("%d", &end);

    int sum_even = 0;
    int multiplication_odd = 1;

    for (int i = start + 1; i < end; i++){
        if(i % 2 == 0){
            sum_even+=i;
        } else{
            multiplication_odd*=i;
        }
    }
    printf("Sum of the even is: %d\n", sum_even);
    printf("Multiplication of the odd is: %d", multiplication_odd);
}