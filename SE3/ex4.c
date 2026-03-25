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
    int numbers2[n];
    for(int i = 0; i < n; i++){
        numbers2[i] = numbers[i];
    }
    int k;
    scanf("%d", &k);
    int next_num_k = 0;
    for(int i = 0; i < n; i++){
        printf("%d ", numbers[i]);
    }
    for (int i = 0; i < n - k; i++){
        numbers[i + k] = numbers2[i];
    }

    for (int i = 0; i < n - k - 1; i++){
        numbers[i] = numbers2[n - k - i];
    }
    numbers[k - 1] = numbers2[n - 1];
    

    for(int i = 0; i < n; i++){
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
}

