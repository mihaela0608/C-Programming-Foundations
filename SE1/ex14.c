#include <stdio.h>

int main(){
    int x;
    int y;
    int w;
    printf("X: ");
    scanf("%d", &x);
    printf("Y: ");
    scanf("%d", &y);
    printf("W: ");
    scanf("%d", &w);

    int w_size = x * 2 * w + y* 2 * w;
    printf(w_size);

}