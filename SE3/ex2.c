#include <stdio.h>
#include <stdbool.h>

int main(){
    int n;
    scanf("%d", &n);
    int numbers[n];
    for(int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);
        numbers[i] = num;
    }
    int p = 0;
    bool is_valid = true;
    for (int i = 0; i < n - 1; i++){
        int current = numbers[i];
        int next = numbers[i + 1];
        if (p == 0){
            if (current > next){
                is_valid = false;
            }
            p = 1;
        } else {
            if (current < next){
                is_valid = false;
            }
            p = 0;
        }
        
    }

    if (is_valid){
        printf("Is valid!");
    } else{
        printf("Is not valid");
    }
    
    
}