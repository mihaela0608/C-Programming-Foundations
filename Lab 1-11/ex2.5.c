#include <stdio.h>
#include <math.h>

double power(double base, int exp);
double geometricMean(double a, double b, double c);

int main(){
    double a;
    double b;
    double c;

    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    printf("Result: %.2lf", geometricMean(a, b, c));
    
}

double power(double base, int exp){
    double result = 1;
    for (int i = 0; i < exp; i++){
        result = result * base;
    }
    return result;
}

double geometricMean(double a, double b, double c){
    return pow((a * b * c), 0.33);
}