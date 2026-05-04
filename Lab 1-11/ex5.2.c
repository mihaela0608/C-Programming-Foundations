#include <stdio.h>
#include <stdlib.h>

int main(){
    double* numbers_C = (double*) calloc(10, sizeof(double));
    double* numbers_M = (double*) malloc(10 * sizeof(double));

    for (int i = 0; i < 10; i++){
        printf("c: %lf m: %lf\n", numbers_C[i], numbers_M[i]);
    }
    
}