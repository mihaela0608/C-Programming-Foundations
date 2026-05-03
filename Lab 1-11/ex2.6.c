#include <stdio.h>

double f(double x);
double sumF(double a, double b, double step);

int main(){
    double a;
    double b;
    double step;

    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &step);

    printf("Sum is: %.2lf", sumF(a, b, step));
}

double f(double x){
    return x*x - 4;
}

double sumF(double a, double b, double step){
    double sum = 0;
    for (double i = a; i <= b; i+=step){
        sum+=f(i);
    }
    return sum;
}