#include <stdio.h>
#include <math.h>
int main(){
    double w;
    double h;

    printf("Write size: \n");
    scanf("%lf", &w);
    scanf("%lf", &h);

    double area_work_place = 0.84;
    double corridor = h;
    double occupied_space = corridor + area_work_place * 3;
    
    double free_space = w*h - occupied_space;

    double seats = free_space / area_work_place;
    printf("%lf", round(seats));
}