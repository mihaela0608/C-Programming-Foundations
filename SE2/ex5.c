#include <stdio.h>

int main(){
    int first;
    int second;
    int third;
    printf("Write times:\n");
    scanf("%d", &first);
    scanf("%d", &second);
    scanf("%d", &third);

    int seconds = first + second + third;

    if (seconds > 59){
        int minutes = seconds / 60;
        int seconds2 = seconds - minutes * 60;
        if (seconds2 < 10){
            printf("%d:0%d", minutes, seconds2);
        } else{
            printf("%d:%d", minutes, seconds2);
        }  
    }
    else{
        if (seconds < 10){
            printf("0:0%d", seconds);
        } else{
            printf("0:%d", seconds);
        }
    }
}