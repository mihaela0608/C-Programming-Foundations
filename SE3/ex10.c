#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int numbers[n];
    for(int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);
        numbers[i] = num;
    }

    int x;
    scanf("%d", &x);
    int count = 0;
    for (int i = 0; i < n; i++){
        if (numbers[i] == x){
            count++;
        }
    }

    printf("%d", count);
    
}