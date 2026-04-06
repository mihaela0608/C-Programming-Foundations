#include <stdio.h>
#include <string.h>

int main(){
    struct Product{
        char name[30];
        char brand[20];
        double price;
    };
    struct Store{
        char name[20];
        char url[20];
        char owner[20];
        struct Product products[10];
    };
    
    
    
}