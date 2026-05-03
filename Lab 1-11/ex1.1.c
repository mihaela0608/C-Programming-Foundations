#include <stdio.h>
#include <math.h>
#include <locale.h>   


int main() {
    setlocale(LC_ALL, "bg_BG.UTF-8");
    char ch;
    int num;
    double decimal_num;

    scanf("%c", &ch);
    scanf("%d", &num);
    scanf("%lf", &decimal_num);

    printf("Символът %c съответства на ASCII код %d. Числото %d на квадрат е %d, а реалното число %lf закръглено до 3 знака е %.3lf.", ch, (int) ch, num, num * num, decimal_num, decimal_num);
}