#include <stdio.h>

int main(){
    int a;
    int b;
    int c;
    printf("Write 3 numbers: ");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    if (a == b && a == c){
        printf("Yes!");
    } else{
        printf("No!");
    }
    
}