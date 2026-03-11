#include <stdio.h>

int main(){
    int hour;
    int minutes;
    int result_hour;
    int result_minutes;
    printf("Current hour: ");
    scanf("%d", &hour);
    printf("Current minutes: ");
    scanf("%d", &minutes);

    result_minutes = minutes + 15;
    if(result_minutes >= 60){
        result_minutes = 15 - (60 - minutes);
        result_hour = hour + 1;
    } else{
        result_hour = hour;
    }

    if (result_hour >= 24){
        result_hour = 0;
    }

    printf("%d:%d", result_hour, result_minutes);
    
}