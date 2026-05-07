#include <stdio.h>
#include <stdlib.h>

typedef struct Course{
    char name[50];
    char start_date[13];
    int lections;
    float price;
}Course;

int main(){
    FILE* fp = fopen("courses.bin", "wb");
    if (fp == NULL){
        exit(-1);
    }
    
    Course courses[3];

    for (int i = 0; i < 3; i++){
        Course course;
        scanf("%s", course.name);
        fgets(course.start_date, 13, stdin);
        scanf("%d", &course.lections);
        scanf("%f", &course.price);
        courses[i] = course;
    }

    fwrite(courses, sizeof(Course), 3, fp);
    fclose(fp);
    
}