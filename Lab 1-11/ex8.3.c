#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Car{
    char brand[20];
    char model[20];
    double engine_volume;
    double price;
    char registration;
}Car;

int main(){
    int n;
    scanf("%d", &n);
    Car cars[n+1];

    for (int i = 0; i < n; i++){
        Car car;
        scanf("%s", car.brand);
        scanf("%s", car.model);
        scanf("%lf", &car.engine_volume);
        scanf("%lf", &car.price);
        scanf(" %c", &car.registration);
        cars[i] = car;
    }

    FILE* fp_t = fopen("cars.txt", "w");
    FILE* fp_b = fopen("cars.bin", "wb");

    if (fp_t == NULL) {
        printf("Error\n");
        return 1;
    }
    if (fp_b == NULL) {
        printf("Error\n");
        return 1;
    }

    for (int i = 0; i < n; i++){
        Car car = cars[i];
        fprintf(fp_t, "%s,%s,%.2lf,%.2lf,%c\n", 
                cars[i].brand, cars[i].model, 
                cars[i].engine_volume, cars[i].price, 
                cars[i].registration);
    }

    fwrite(cars, sizeof(Car), n, fp_b);
    
    

    fclose(fp_t);
    fclose(fp_b);

    fp_t = fopen("cars.txt", "a");
    fp_b = fopen("cars.bin", "ab");

    if (fp_t == NULL) {
        printf("Error\n");
        return 1;
    }
    if (fp_b == NULL) {
        printf("Error\n");
        return 1;
    }

    Car car;
    scanf("%s", car.brand);
    scanf("%s", car.model);
    scanf("%lf", &car.engine_volume);
    scanf("%lf", &car.price);
    scanf(" %c", &car.registration);
    
    fprintf(fp_t, "%s,%s,%.2lf,%.2lf,%c\n", 
                car.brand, car.model, 
                car.engine_volume, car.price, 
                car.registration);

    fwrite(&car, sizeof(car), 1, fp_b);
    
    fclose(fp_b);
    fclose(fp_t);

    fp_t = fopen("cars.txt", "r");
    fp_b = fopen("cars.bin", "rb");

    if (fp_t == NULL) {
        printf("Error\n");
        return 1;
    }
    if (fp_b == NULL) {
        printf("Error\n");
        return 1;
    }

    fread(cars, sizeof(Car), n + 1, fp_b);
    int count = 0;
    while (fscanf(fp_t, "%s,%s,%.2lf,%.2lf,%c\n", 
                car.brand, car.model, 
                car.engine_volume, car.price, 
                car.registration) > 0){
            
        printf("%s,%s,%.2lf,%.2lf,%c\n", 
                car.brand, car.model, 
                car.engine_volume, car.price, 
                car.registration);
        printf("%s,%s,%.2lf,%.2lf,%c\n", 
                cars[count].brand, cars[count].model, 
                cars[count].engine_volume, cars[count].price, 
                cars[count].registration);
        count++;
    }
    


    fclose(fp_b);
    fclose(fp_t);
    
}