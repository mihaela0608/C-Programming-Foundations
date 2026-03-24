#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void value_check(int* x){
    (*x)++;
    printf("x in value_check: %d\n", *x);
}

int main(){
    // int *p = (int*) malloc(5 * sizeof(int)); -> имаме указател p, сочещ към heap-а
    // указателите винаги са с едни и същи размери
    // --//-- calloc(num, type) -> тук calloc умножава вместо нас
    // --//-- realloc(p, size) -> променя големината на масива(динамични масиви)
    // винаги при тези три функции трябва да проверяваме дали имаме памет if(p == NULL)
    // free(p) -> освобождаване на памет; след това е добре да зададем NULL(адрес, който сме сигурни, че не съществува)
    // char **p -> указател към двумерен масив

    // int nums[10];
    // int* p = nums;

    // int x = 5;
    // int* p_x = &x;
    // value_check(&x);
    // printf("x in main: %d\n", *x);

    // for (int i = 0; i < 10; i++){
    //     *(p + i) = i;
    // }

    // for (int i = 0; i < 10; i++){
    //     printf("%p\n", *(p + i));
    // }
    // printf("%p\n", &nums);
    // printf("%p\n", &nums[0]);

    // char name[] = "Ivan";
    // sizeof(name) -> 5
    // strlen(name) -> 4

    // char second_name[10];
    // !!! second_name = name; не можем така
    // strcpy(second_name, name); -> копираме стринг 

    // strcmp(name, second_name) -> сравняване на стрингове 0 -> еднакви, а при различно от 0 -> различни

    // ДИНАМИЧНА ПАМЕТ

    int* nums_1 = (int*) malloc(sizeof(int) * 5);
    int* nums_2 = (int*) calloc(5, sizeof(int));

    for(int i = 0; i < 5; i ++){
        printf("num_1: %d:%d\n", i + 1, nums_1[i]);
        printf("num_2: %d:%d\n", i + 1, nums_2[i]);
    }
    
    // free(nums_1);
    int* larger_nums = realloc(nums_1, sizeof(int) * 10);


} 