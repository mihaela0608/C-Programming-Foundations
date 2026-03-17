#include <stdio.h>

float sum(float *p_a, float *p_b){
    float sum = (*p_a) + (*p_b);
    return sum;
}
float sub(float *p_a, float *p_b){
    float sub = (*p_a) - (*p_b);
    return sub;
}
float multiply(float *p_a, float *p_b){
    float mul = (*p_a) * (*p_b);
    return mul;
}
float del(float *p_a, float *p_b){
    float del = (*p_a) / (*p_b);
    return del;
}


int main(){
    float num1;
    float num2;
    
    printf("Number 1: ");
    scanf("%f", &num1);
    printf("Number 2: ");
    scanf("%f", &num2);
    float *num1_p = &num1;
    float *num2_p = &num2;

    printf("%.2f\n", sum(num1_p, num2_p));
    printf("%.2f\n", sub(num1_p, num2_p));
    printf("%.2f\n", multiply(num1_p, num2_p));
    printf("%.2f\n", del(num1_p, num2_p));
}