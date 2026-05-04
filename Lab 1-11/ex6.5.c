#include <stdio.h>
#include <string.h>

void my_strcpy(char *dest, const char *src);

int main(){
    char dest[20];
    my_strcpy(dest, "Hello");
    printf("%s", dest);
}

void my_strcpy(char *dest, const char *src){
    for (int i = 0; i < strlen(src); i++){
        dest[i] = src[i];
    }
    
}