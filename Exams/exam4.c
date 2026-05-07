#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product{
    char name[20];
    int code;
    char exp_date[11];
    float price;
}Product;

float avrg_by_price(Product* products, int count, float price);
int write_text_file(Product* products, int count, char date[11], float price);
void print_info(char* search_name, int search_code);

int main(){
    int n;
    scanf("%d", &n);
    if (n <= 10 || n >= 30){
        printf("Invalid number");
        exit(-1);
    }

    Product* products = malloc(sizeof(Product) * n);

    if (products == NULL){
        printf("Error occured");
        exit(-1);
    }
    

    for (int i = 0; i < n; i++){
        Product product;
        scanf("%s", product.name);
        scanf("%d", &product.code);
        scanf("%s", product.exp_date);
        scanf("%f", &product.price);
        products[i] = product;
    }
    
    
}

float avrg_by_price(Product* products, int count, float price){
    float sum = 0;
    int count_avg = 0;

    for (int i = 0; i < count; i++){
        if (products[i].price < price){
            sum+=products[i].price;
            count_avg++;
        }
        
    }

    if (count_avg == 0){
        return 0;
    } else{
        return sum / count_avg;
    }
}

int write_text_file(Product* products, int count, char date[11], float price){
    FILE* fp = fopen("products.txt", "w");
    int count_written = 0;
    if (fp == NULL){
        printf("Error occured");
        exit(-1);
    }
    int check_year, check_month, check_day;
    sscanf(date, "%d.%d.%d", &check_year, &check_month, &check_day);
    for (int i = 0; i < count; i++){
        Product product = products[i];
        int year, month, day;
        sscanf(product.exp_date, "%d.%d.%d", &year, &month, &day);
        if ((year < check_year || (year == check_year && month < check_month) || (year == check_year && month == check_month && day < check_day)) && product.price > price){
            fprintf(fp, "%s - %d - %s - %.2f lv.\n", product.name, product.code, product.exp_date, product.price);
            count_written++;
        }
        
    }
    

    fclose(fp);
    return count_written;
}

void print_info(char* search_name, int search_code){
    FILE* fp = fopen("product.bin", "rb");

    if (fp == NULL){
        printf("Error occured");
        exit(-1);
    }
    int found = 0;
    Product product;
    
    while (1) {
        int name_len;
        if (fread(&name_len, sizeof(int), 1, fp) != 1) {
            break;  
        }
        
        char* temp_name = malloc(name_len + 1); 
        if (temp_name == NULL) {
            printf("Memory error!\n");
            break;
        }
        
        if (fread(temp_name, 1, name_len, fp) != (size_t)name_len) {
            free(temp_name);
            break;  
        }
        temp_name[name_len] = '\0';  
        
        strncpy(product.name, temp_name, 19);
        product.name[19] = '\0';
        free(temp_name);
        
        if (fread(&product.code, sizeof(int), 1, fp) != 1) {
            break;
        }
        
        if (fread(product.exp_date, 1, 10, fp) != 10) {
            break;
        }
        product.exp_date[10] = '\0';  
        
        if (fread(&product.price, sizeof(float), 1, fp) != 1) {
            break;
        }
        
        if (strcmp(product.name, search_name) == 0 && product.code == search_code) {
            printf("Product: %s, Expires: %s, Price: %.2f leva\n", 
                   product.name, product.exp_date, product.price);
            found = 1;
            break;
        }
    }
    
    fclose(fp);
    
    if (!found) {
        printf("Product with name '%s' and code %d not found.\n", search_name, search_code);
    }
}