#include <stdio.h> 

int main(){
    int count = 0;
    int words = 0;
    char text[] = "Something for test";
    char current = text[0];
    char last = text[0];
    while (current != '\0'){
        count++;
        if (current == ' ' && last != ' '){
            words++;
        }
        
        current = text[count];
        last = text[count-1];
    }

    printf("Words: %d", words + 1);
    
}