#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    typedef struct{
        char name[30];
        float price;
        int id;
    }Product;

    typedef struct{
        char address[30];
        int id;
    }Order;
    

    Product *products = (Product *)malloc(5 * sizeof(Product));
    Order *orders = (Order *)malloc(5 * sizeof(Order));
    Order *waiting_list = (Order *)malloc(5 * sizeof(Order));

    int products_count = 0;
    int orders_count = 0;
    int products_capacity = 5;
    int orders_capacity = 5;
    int waiting_orders_capacity = 5;
    int waiting_orders_count= 0;

    char command[20];


    printf("Command:\n");
    scanf("%s", command);

    while (strcmp(command, "END") != 0){

        if (strcmp("Product", command) == 0){
            Product product;
            char name[20];
            float price;
            int id; 
            printf("Name: ");
            scanf("%s", name);
            printf("Price: ");
            scanf("%f", &price);
            printf("Id: ");
            scanf("%d", &id);
            strcpy(product.name, name);
            product.price = price;
            product.id = id;
            
            if (products_capacity <= products_count){
                Product *temp = (Product *) realloc(products, products_capacity * 2 * sizeof(Product));
                products_capacity*=2;
                products = temp;
            }

            products[products_count] = product;
            products_count++;
            
            for (int i = 0; i < waiting_orders_count; i++){
                if (waiting_list[i].id == product.id){
                    printf("Client %s ordered %s\n", waiting_list[i].address, product.name);
                    for (int j = i; j < waiting_orders_count - 1; j++){
                        waiting_list[j] = waiting_list[j + 1];
                    }
                    waiting_orders_count--;
                    i--;
                    
                }
                
            }
            

        } else if (strcmp("Order", command) == 0){
            Order order;
            char address[20];
            int id; 
            printf("Address: ");
            scanf("%s", address);
            printf("Id: ");
            scanf("%d", &id);
            strcpy(order.address, address);
            order.id = id;
            
            if (orders_capacity <= orders_count){
                Order *temp = (Order *) realloc(orders, orders_capacity * 2 * sizeof(Order));
                orders_capacity*=2;
                orders = temp;
            }

            orders[orders_count] = order;
            orders_count++;
            int found = 0;

            for (int i = 0; i < products_count; i++){
                if (order.id == products[i].id){
                    found = 1;
                    printf("Client %s ordered %s\n", order.address, products[i].name);
                }
                
            }
            if (found == 0){
                if (waiting_orders_capacity <= waiting_orders_count){
                    Order *temp = (Order *) realloc(waiting_list, waiting_orders_capacity * 2 * sizeof(Order));
                    waiting_orders_capacity*=2;
                    
                    waiting_list = temp;
                }
                waiting_list[waiting_orders_count] = order;
                waiting_orders_count++;
            }
            
            
            
        }
        
        


        scanf("%s", command);
    }
    
    
}