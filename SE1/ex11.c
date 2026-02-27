#include <stdio.h>

int main(){
    int meters;
    printf("Size: ");
    scanf("%d", &meters);

    int size = meters * meters;
    int w;
    printf("W: ");
    scanf("%d", &w);
    int l;
    printf("L: ");
    scanf("%d", &l);

    int m;
    printf("M: ");
    scanf("%d", &m);
    int o;
    printf("O: ");
    scanf("%d", &o);

    int size_pl = w * l;
    int size_b = m * o;
    int pl_count = (size - size_b) / size_pl;

    printf("Count: %d\n", pl_count);
    printf("Time: %f minutes", pl_count * 0.2);
}