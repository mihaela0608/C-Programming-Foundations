#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));   


    int xa;
    int xb;
    int ya;
    int yb;
    scanf("%d", &xa);
    scanf("%d", &ya);
    scanf("%d", &xb);
    scanf("%d", &yb);
    int matrix1[xa][ya];
    int matrix2[xb][yb];
    

    
    if (xa > xb && ya == yb){
        int new_matrix[xa][ya];
        for (int i = 0; i < xb; i++){
            for (int j = 0; j < ya; j++){
                new_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        for (int i = xb; i < xa; i++){
            for (int j = 0; j < ya; j++){
                new_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }

        for (int i = 0; i < xa; i++){
            for (int j = 0; j < ya; j++){
                printf("%d ", new_matrix[i][j]);
            }
            printf("\n");
        }
        
    } else if(xb > xa && ya == yb){
        int new_matrix[xb][ya];
        for (int i = 0; i < xa; i++){
            for (int j = 0; j < ya; j++){
                new_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        for (int i = xa; i < xb; i++){
            for (int j = 0; j < ya; j++){
                new_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        for (int i = 0; i < xb; i++){
            for (int j = 0; j < ya; j++){
                printf("%d ", new_matrix[i][j]);
            }
            printf("\n");
        }
    } else if(ya > yb && xa == xb){
        int new_matrix[xb][ya];
        for (int i = 0; i < xa; i++){
            for (int j = 0; j < yb; j++){
                new_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        for (int i = 0; i < xa; i++){
            for (int j = yb; j < ya; j++){
                new_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        for (int i = 0; i < xb; i++){
            for (int j = 0; j < ya; j++){
                printf("%d ", new_matrix[i][j]);
            }
            printf("\n");
        }
    } else if(yb > ya && xa == xb){
        int new_matrix[xb][yb];
        for (int i = 0; i < xa; i++){
            for (int j = 0; j < ya; j++){
                new_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        for (int i = 0; i < xa; i++){
            for (int j = ya; j < yb; j++){
                new_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        for (int i = 0; i < xb; i++){
            for (int j = 0; j < yb; j++){
                printf("%d ", new_matrix[i][j]);
            }
            printf("\n");
        }
    } else if(xa > xb && ya > yb){
        int new_matrix[xa][ya];
        for (int i = 0; i < xb; i++){
            for (int j = 0; j < yb; j++){
                new_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        for (int i = xb; i < xa; i++){
            for (int j = yb; j < ya; j++){
                new_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        for (int i = 0; i < xa; i++){
            for (int j = 0; j < ya; j++){
                printf("%d ", new_matrix[i][j]);
            }
            printf("\n");
        }
    } else if(xb > xa && yb > ya){
        int new_matrix[xb][yb];
        for (int i = 0; i < xa; i++){
            for (int j = 0; j < ya; j++){
                new_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        for (int i = xa; i < xb; i++){
            for (int j = ya; j < yb; j++){
                new_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        for (int i = 0; i < xb; i++){
            for (int j = 0; j < yb; j++){
                printf("%d ", new_matrix[i][j]);
            }
            printf("\n");
        }
    } else if(xa < xb && ya > yb){
        int new_matrix[xb][ya];
        for (int i = 0; i < xa; i++){
            for (int j = 0; j < yb; j++){
                new_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        for (int i = xa; i < xb; i++){
            for (int j = yb; j < ya; j++){
                new_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        for (int i = 0; i < xb; i++){
            for (int j = 0; j < ya; j++){
                printf("%d ", new_matrix[i][j]);
            }
            printf("\n");
        }
    } else if(xa > xb && ya < yb){
        int new_matrix[xa][yb];
        for (int i = 0; i < xb; i++){
            for (int j = 0; j < ya; j++){
                new_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        for (int i = xb; i < xa; i++){
            for (int j = ya; j < yb; j++){
                new_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        for (int i = 0; i < xa; i++){
            for (int j = 0; j < yb; j++){
                printf("%d ", new_matrix[i][j]);
            }
            printf("\n");
        }
    } else if(xa > xb && ya > yb){
        int new_matrix[xa][yb];
        for (int i = 0; i < xb; i++){
            for (int j = 0; j < yb; j++){
                new_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        for (int i = xb; i < xa; i++){
            for (int j = yb; j < ya; j++){
                new_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        for (int i = 0; i < xa; i++){
            for (int j = 0; j < yb; j++){
                printf("%d ", new_matrix[i][j]);
            }
            printf("\n");
        }
    } else if(xa < xb && ya < yb){
        int new_matrix[xb][ya];
        for (int i = 0; i < xa; i++){
            for (int j = 0; j < ya; j++){
                new_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        for (int i = xa; i < xb; i++){
            for (int j = ya; j < yb; j++){
                new_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        for (int i = 0; i < xb; i++){
            for (int j = 0; j < ya; j++){
                printf("%d ", new_matrix[i][j]);
            }
            printf("\n");
        }
    } else if(xa == xb && ya == yb){
        int new_matrix[xb][ya];
        for (int i = 0; i < xa; i++){
            for (int j = 0; j < ya; j++){
                new_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        for (int i = 0; i < xb; i++){
            for (int j = 0; j < ya; j++){
                printf("%d ", new_matrix[i][j]);
            }
            printf("\n");
        }
    }
    

    int r = rand(); 
    printf("%d", r);
}

