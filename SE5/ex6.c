#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isAnagram(char first[20], char second[20]);

int main(){
    char first[20];
    char second[20];

    scanf("%s", first);
    scanf("%s", second);

    if (isAnagram(first, second)){
        printf("Is anagram");
    } else{
        printf("Is not");
    }

    return 0;
}

bool isAnagram(char first[20], char second[20]){
    
    if (strlen(first) != strlen(second)){
        return false;
    }

    bool used[20] = {false};

    for (int i = 0; i < strlen(first); i++){
        bool current = false;

        for (int j = 0; j < strlen(second); j++){
            if(first[i] == second[j] && !used[j]){
                used[j] = true;
                current = true;
                break;
            }
        }

        if (!current){
            return false;
        }
    }

    return true;
}