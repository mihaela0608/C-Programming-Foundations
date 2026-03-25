#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int numbers[n];
    if (n > 100){
        printf("Invalid array size!");
        return 0;
    }
    
    for(int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);
        numbers[i] = num;
    }
    int min_ind = 0;
    int max_ind = 0;
    int max = numbers[0];
    int min = numbers[0];

    for (int i = 0; i < n; i++){
        int num = numbers[i];
        if (num > max){
            max_ind = i;
            max = num;
        } else if(num < min){
            min = num;
            min_ind = i;
        }
        
    }

    printf("Biggest is %d at %d index and smallest is %d at %d index", max, max_ind, min, min_ind);
    
    
}