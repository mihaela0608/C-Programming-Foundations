#include <stdio.h> 

int main(){
    int count = 0;
    char text[] = "Something for test";
    char current = text[0];
    while (current != '\0'){
        count++;
        current = text[count];
    }

    printf("Length: %d", count);
    
}