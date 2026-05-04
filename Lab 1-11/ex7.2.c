#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point{
    double x;
    double y;
}Point;


typedef struct Rectangle{
    Point topLeft;
    Point bottomRight;
}Rectangle;

double area(Rectangle r);

int main(){
    Rectangle rectangle;
    Point tL;
    Point bR;
    tL.x = 0;
    tL.y = 4;
    bR.x = 5;
    bR.y = 0;
    rectangle.topLeft = tL;
    rectangle.bottomRight = bR;

    printf("%lf", area(rectangle));
}

double area(Rectangle r){
    return r.topLeft.y * r.bottomRight.x;
}