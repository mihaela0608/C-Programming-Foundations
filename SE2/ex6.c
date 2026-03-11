#include <stdio.h>

int main(){
    int x1;
    int y1;
    int x2;
    int y2;
    int x;
    int y;
    scanf("%d", &x1);
    scanf("%d", &y1);
    scanf("%d", &x2);
    scanf("%d", &y1);
    scanf("%d", &x);
    scanf("%d", &y);

    if(x >= x1 && x <= x2 && y >= y1 && y <= y2){
        printf("Inside");
    } else{
        printf("Outside");
    }
}