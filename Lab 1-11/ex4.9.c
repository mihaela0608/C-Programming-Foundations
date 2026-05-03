#include <stdio.h>

void diagonalSums(int n, int mat[n][n], int *mainDiag, int *secDiag);

int main(){
    int mat[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
    };
    int mainSum, secSum;
    diagonalSums(3, mat, &mainSum, &secSum);
    printf("Main: %d, Second: %d", mainSum, secSum);
}

void diagonalSums(int n, int mat[n][n], int *mainDiag, int *secDiag){
    int mainSum = 0;
    int secSum = 0;
    for (int i = 0; i < n; i++){
        mainSum+=mat[i][i];
    }
    for (int i = n-1 ; i >= 0; i--){
        secSum+=mat[n - i - 1][i];
    }
    *mainDiag = mainSum;
    *secDiag = secSum;
    
}