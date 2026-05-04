#include <stdio.h>
#include <string.h>

int main() {
    char text[] = "Something for test";
    int len = strlen(text);
    int checked[256] = {0};  
    
    for (int i = 0; i < len; i++) {
        char current = text[i];
        
        if (checked[(unsigned char)current] == 1) {
            continue;
        }
        
        int count = 0;
        for (int j = 0; j < len; j++) {
            if (text[j] == current) {
                count++;
            }
        }
        
        printf("%c: %d\n", current, count);
        checked[(unsigned char)current] = 1;  
    }
    
    return 0;
}