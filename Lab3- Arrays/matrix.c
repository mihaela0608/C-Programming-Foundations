#include <stdio.h>

void main_diagonal(int size, int matrix[][size]);
void second_diagonal(int size, int matrix[][size]);
void elements_above(int size, int matrix[][size]);
void elements_under(int size, int matriz[][size]);

int main(){
    int size;
    printf("Enetr matrix size: ");
    scanf("%d", &size);
    int matrix[size][size];
    for(int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            int num;
            printf("Number [%d][%d]: ", i, j);
            scanf("%d", &num);
            matrix[i][j] = num;
        }
    }

    for(int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    char operation[10];
    printf("Choose type of operation: main diagonal[md]; second diagonal[sd]; elements above main diagonal[ead]; elements under main diagonal[eud]: ");
    scanf("%s", operation);
    if (operation[0] == 'm'){
        main_diagonal(size, matrix);
    } else if(operation[0] == 's'){
        second_diagonal(size, matrix);
    } else if(operation[0] == 'e'){
        if(operation[1] == 'a'){
            elements_above(size, matrix);
        } else{
            elements_under(size, matrix);
        }
    }
    

}

void main_diagonal(int size, int matrix[][size]){
    for (int i = 0; i < size; i++){
        printf("%d ", matrix[i][i]);
    } 
}
void second_diagonal(int size, int matrix[][size]){
    for(int i = 0; i < size; i++){
        printf("%d ", matrix[i][size - i - 1]);
    }
}

void elements_above(int size, int matrix[][size]){
    for (int i = 0; i < size; i++){
        for (int j = i + 1; j < size; j++){
            printf("%d ", matrix[i][j]);
        }
    }
}

void elements_under(int size, int matriz[][size]){
    for (int i = size - 1; i > 0; i--){
        for (int j = i - 1; j >= 0; j--){
            printf("%d ", matriz[i][j]);
        }
    }    
}