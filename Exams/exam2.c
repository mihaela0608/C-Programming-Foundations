#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Course{
    char name[50];
    char start_date[13];
    int lections;
    float price;
}Course;

void promotion(Course* courses, int count, int ind);

int main(){
    FILE* fp = fopen("courses.bin", "rb");

    if (fp == NULL){
        printf("Error openning file!");
        exit(-1);
    }

    Course* courses = malloc(5 * sizeof(Course));
    Course course;
    int count = 0;
    int capacity = 5;
    int current_courses = 0;
    while(fread(&course, sizeof(Course), 1, fp)){
        courses[count] = course;
        int year, month, day;
        sscanf(course.start_date, "%d. %d. %d", &year, &month, &day);
        if (year <= 2026 && month <= 5 && day <= 6){
            current_courses++;
        }
        
        
        count++;
        if (count == capacity){
            Course* temp = realloc(courses, capacity * 2 * sizeof(Course));
            capacity*=2;
            if (temp == NULL){
                printf("Error with memorry");
                exit(-1);
            }
            courses = temp;
        }
        
    }

    fclose(fp);
}

void promotion(Course* courses, int count, int ind){
    if (ind < 0 || ind >= count){
        printf("Index not valid");
        return;
    }

    Course course = courses[ind];
    courses[ind].price *= 0.9;

    printf("%.2fлв. - %s - %s\n", courses[ind].price, courses[ind].name, courses[ind].start_date);
    
}

int coursesWithPrice(Course* courses, int count, float minPrice, float maxPrice){
    int ind = 0;
    FILE* fp = fopen("offer.txt", "w");

    if (fp == NULL){
        printf("Error with fopenning file");
        exit(-1);
    }
    

    for (int i = 0; i < count; i++){
        Course course = courses[i];
        if (course.price >= minPrice && course.price <= maxPrice){
            fprintf(fp, "%s\n%s\n%d\n%.2f\n", course.name, course.start_date, course.lections, course.price);
            ind++;
        }
        
    }
    fclose(fp);

    return ind;

}

Course* deleteCourse(Course* courses, int count, char name[50], char date[13]){
    Course* course = NULL;
    for (int i = 0; i < count; i++){
        if (strcmp(courses[i].name, name) == 0 && strcmp(courses[i].start_date, date) == 0){
            for (int j = i; j < count - 1; j++){
                courses[j] = courses[j + 1];
            }
            Course* temp = realloc(courses, (count - 1) * sizeof(Course));
            if (temp == NULL){
                printf("Error with realloc");
                exit(-1);
            }
            courses = temp;
            course = courses;
            break;
        }
        
    }
    return course;
    
}