#include <stdio.h>
#include <string.h>

void my_strcat(char *dest, const char *src);

int main() {
    char dest[20] = "Hello ";
    my_strcat(dest, "World");
    printf("%s\n", dest);  
    return 0;
}

void my_strcat(char *dest, const char *src) {
    int dest_len = strlen(dest);
    int src_len = strlen(src);
    
    for (int i = 0; i < src_len; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + src_len] = '\0';
}