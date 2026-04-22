#include <stdio.h>
#include <stdlib.h>

char* read_line() {
    int capacity = 4;
    int size = 0;

    char* str = malloc(capacity * sizeof(char));

    char c;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (size + 1 >= capacity) {
            capacity *= 2;
            str = realloc(str, capacity);
        }
        str[size++] = c;
    }

    str[size] = '\0';
    return str;
}

int main() {
    printf("Enter text: ");
    char* text = read_line();

    printf("You wrote: %s\n", text);

    free(text);
    return 0;
}