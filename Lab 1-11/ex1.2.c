#include <stdio.h>

int main(){
    char ch;
    int count;

    scanf(" %c %d", &ch, &count);
    for(int i = 0; i < count; i++){
        printf("%c", ch + i);
    }
}