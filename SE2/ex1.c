#include <stdio.h>

int bigger_num(int a, int b){
    if (a > b){
        return a;
    } else{
        return b;
    }
}
int smaller_num(int a, int b){
    if (a < b){
        return a;
    } else{
        return b;
    }
}


int main(){
    int curremt_num;
    int biggest_num;
    int smallest_num;
    printf("Write a number: ");
    scanf("%d", &curremt_num);
    biggest_num = curremt_num;
    smallest_num = curremt_num;
    while (curremt_num != 0){
        biggest_num = bigger_num(biggest_num, curremt_num);
        smallest_num = smaller_num(smallest_num, curremt_num);
        printf("Write a number: ");
        scanf("%d", &curremt_num);
    }
    printf("Biggest num is: %d\n", biggest_num);
    printf("Smallest num is: %d", smallest_num);
    
}