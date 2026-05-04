#include <stdio.h>
#include <string.h> 
#include <stdbool.h>

int main(){
    char str1[] = "One";
    char str2[] = "On7";
    bool valid = true;
    if (strlen(str1) != strlen(str2)){
        valid = false;
    } else{
        for (int i = 0; i < strlen(str1); i++){
        if (str1[i] != str2[i]){
            valid = false;
        }
        }
    }
    
    if (valid){
        printf("Same text");
    } else{
        printf("Different text");
    }
    
    
}