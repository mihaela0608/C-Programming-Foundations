#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point{
    double x;
    double y;
}Point;

double distance(Point p1, Point p2);

int main(){
    Point points[3];
    Point p1;
    Point p2;
    Point p3;
    p1.x, p1.y = 0;
    p2.x = 3;
    p2.y = 0;
    p3.x = 0;
    p3.y = 4;
    printf("%lf", distance(p1, p2) + distance(p1, p3) + distance(p2, p3));
}

double distance(Point p1, Point p2){
    double distance = sqrt(((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
    return  distance;
}