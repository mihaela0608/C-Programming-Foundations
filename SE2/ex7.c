#include <stdio.h>

double taksi(int km, char period){
    double price = 0.7;
    if (period == 'D'){
        price+= 0.79 * km;
    } else if (period == 'N'){
        price+=0.9 * km;
    }
    return price;
}
double bus(int km){
    double price;
    if (km < 20){
        price = 0;
    } else{
        price = 0.09 * km;
    }
    return price;
}
double train(int km){
    double price;
    if (km < 100){
        price = 0;
    } else{
        price = 0.06 * km;
    }
    return 0;
}

int main(){
    int km;
    char period;

    printf("Km: ");
    scanf("%d", &km);
    printf("Time of the day D/N: ");
    scanf(" %c", &period);


    double taksi_price = taksi(km, period);
    double bus_price = bus(km);
    double train_price = train(km);
    double cheapest;

    if(bus == 0 && train_price == 0){
        cheapest = taksi_price;
    } else if (train_price == 0){
        if (bus_price < taksi_price){
            cheapest = bus_price;
        } else{
            cheapest = taksi_price;
        }
    } else{
        if(train_price < bus_price && train_price < taksi_price){
            cheapest = train_price;
        } else if(bus_price < taksi_price && bus_price < train_price){
            cheapest = bus_price;
        } else{
            cheapest = taksi_price;
        }
    }

    printf("Cheapest is: %lf", cheapest);
    
    

}