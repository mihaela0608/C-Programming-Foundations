#include <stdio.h>

int main(){
    int count;
    printf("Count numbers: ");
    scanf("%d", &count);

    int count_p1 = 0;
    int count_p2 = 0;
    int count_p3 = 0;
    int count_p4 = 0;
    int count_p5 = 0;

    for(int i = 0; i < count; i++){
        int number;
        scanf("%d", &number);
        if (number < 200){
            count_p1++;
        } else if(number <= 399){
            count_p2++;
        } else if(number <= 599){
            count_p3++;
        } else if(number <= 799){
            p4++;
        } else{
            count_p5++;
        }
    }

    float p1 = count_p1 / count;
    float p2 = count_p2 / count;
    float p3 = count_p3 / count;
    float p4 = count_p4 / count;
    float p5 = count_p5 / count;

    printf("P1: %f, P2: %f, P3: %f, P4: %f, P5: %f", p1, p2, p3, p4, p5);
}