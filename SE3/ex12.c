#include <stdio.h>

int main(){
    int m;
    int n;
    scanf("%d", &m);
    scanf("%d", &n);
    int numbers[n];
    for (int i = 0; i < n; i++){
        numbers[i] = (i + 1) * m;
    }

    for(int i = 0; i < n; i++){
        printf("%d ", numbers[i]);
    }
    
}