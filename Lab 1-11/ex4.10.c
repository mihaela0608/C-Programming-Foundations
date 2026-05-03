#include <stdio.h>

void transposeSquare(int n, int mat[n][n]);

int main(){
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
        };
    transposeSquare(3, mat);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void transposeSquare(int n, int mat[n][n]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (j > i){
                int num = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = num;
            }
            
        }
        
    }
    
}