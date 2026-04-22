#include <stdio.h>
#include <stdlib.h>

void push_back(int **arr, size_t *size, int value) {
    *arr = realloc(*arr, (*size + 1) * sizeof(int));

    (*arr)[*size] = value;
    (*size)++;
}

int main() {
    int* arr = NULL;
    size_t size = 0;

    push_back(&arr, &size, 10);
    push_back(&arr, &size, 20);
    push_back(&arr, &size, 30);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}