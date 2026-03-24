#include <stdio.h>
#include <stdbool.h>

bool is_number(char ch);

int main(){
    char text[150] = {};
    printf("Write a text: ");
    fgets(text, sizeof(text), stdin);
    char last_symbol = ' ';
    int words = 0;
    for (int i = 0; i < 150; i++){
        char current_symbol = text[i];
        if (current_symbol == ' '){
            if (!is_number(last_symbol)){
                words++;
            }
        } 
        last_symbol = current_symbol;
    }
    if (!is_number(last_symbol)){
        words++;
    }
    
    printf("Words: %d", words);
}

bool is_number(char ch){
    bool is_num = false;
    switch (ch){
    case '1':
        is_num = true;
        break;
    case '2':
        is_num = true;
        break;
    case '3':
        is_num = true;
        break;
    case '4':
        is_num = true;
        break;
    case '5':
        is_num = true;
        break;
    case '6':
        is_num = true;
        break;
    case '7':
        is_num = true;
        break;
    case '8':
        is_num = true;
        break;
    case '9':
        is_num = true;
        break;
    case '0':
        is_num = true;
        break;
    }

    return is_num;
}