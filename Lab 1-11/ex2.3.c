#include <stdio.h>
#include <stdbool.h>

bool is_even(int a);

int main(){
    int a;
    scanf("%d", &a);

    if (is_even(a)){
        printf("Is even");
    } else{
        printf("Is odd");
    }
    
}

bool is_even(int a){
    return a % 2 == 0;
}