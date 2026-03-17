#include <stdio.h>
#include <math.h>
#include <string.h>
float circle_area(float rad){
    return rad * rad * M_PI;
}
float rectange_area(float a, float b){
    return a * b;
}
float right_triangle(float a, float b){
    return a * b / 2;
}
float random_triangle(float a, float ha){
    return a * ha / 2;
}

int main(){
    printf("Type of figure: ");
    char figure[20];
    scanf("%s", figure);
    if (strlen(figure) == strlen("circle")){
        printf("Radius: ");
        float rad;
        scanf("%f", &rad);
        printf("Area is: %f", circle_area(rad));
    } else if(strlen(figure) == strlen("ractangle")){
        float a;
        float b;

        printf("A: ");
        scanf("%f", &a);
        printf("B: ");
        scanf("%f", &b);

        printf("Area is: %f", rectange_area(a, b));
    } else if(strlen(figure) == strlen("triangle")){
        char type[7];
        printf("Right or random: ");
        scanf("%s", type);
        if (strlen(type) == strlen("right")){
            float a;
            float b;

            printf("A: ");
            scanf("%f", &a);
            printf("B: ");
            scanf("%f", &b);
            printf("Area is: %f", right_triangle(a, b));
        } else if(strlen(type) == strlen("random")){
            float a;
            float ha;
            printf("A: ");
            scanf("%f", &a);
            printf("Ha: ");
            scanf("%f", &ha);

            printf("Area is: %f", random_triangle(a, ha));
        }
    }
}