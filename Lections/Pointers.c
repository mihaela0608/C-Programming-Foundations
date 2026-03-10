#include <stdio.h>

void increment(int x){
    x++;
    printf("%d", x);
}



int main(){
    int x = 5;
    int *p = &x;
    // Указател към адреса на х
    // *p(дай ми стойнността на променливата, към която сочи p) -> 5; p -> 200; &p -> 400
    // %p -> спецификатор за адрес
    increment(x);
    printf("%d\n", x);
}