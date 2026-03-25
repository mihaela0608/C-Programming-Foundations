#include <stdio.h>

int main(){
    int numbers[20];
    for(int i = 0; i < 10; i++){
        int num;
        scanf("%d", &num);
        numbers[i] = num;
    }
    int k = 10;
    for (int i = 0; i < 10; i++){
        int ind;
        printf("Index: ");
        scanf("%d", &ind);
        if (ind == 0){
            break;
        }
        int num;
        k++;
        scanf("%d", &num);
        int previous = numbers[ind];
        numbers[ind] = num;
        
        for (int i = ind + 1; i < 19; i++){
            numbers[i] = previous;
            previous = numbers[i + 1];
        }
        
    }
    for(int i = 0; i < k; i++){
        printf("%d ", numbers[i]);
    }
    
}