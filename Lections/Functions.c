#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int main(){

}

void arr_input(int row, int col, int arr[row][col]){
    for (int i = 0; i < row; i++){
       for (int j = 0; j < col; j++){
        scanf("%d", &arr[i][j]);
       } 
    }
}

void print_matrix(int row, int col, int arr[][col]){
    for (int i = 0; i < row; i++){
       for (int j = 0; j < col; j++){
        prinf("%d\t", arr[i][j]);
       } 
       printf("\n");
    }
}

void rotate_matrix(int row, int col, int arr[][col]){
    int min_value = arr[0][0];
    int max_value = arr[0][0];
    int min_index = 0;
    int max_index = 0;

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if(arr[i][j] < min_value){
                min_value = arr[i][j];
                min_index = i;
            } 
            if (arr[i][j] > max_value){
                max_value = arr[i][j];
                max_index = i;
            }
        }
    }
    if(min_index != max_index){
        for (int j = 0; j < col; j++){
            int temp = arr[min_index][j];
            arr[min_index][j] = arr[max_index][j];
            arr[max_index][j] = temp;
        }
    }
}

bool palindrome(char word[]){
    int i = 0;
    int j = strlen(word) - 1;
    while ((i <= j)){
        if(word[i] != word[i]){
            return false;
        }
        i++;
        j--;
    }
    return true;
    
}

