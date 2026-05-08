#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Course{
    char name[50];
    char date[11];
    int lections;
    float price;
}Course;

void lower_price_by_index(Course* courses, int count, int ind);
int write_courses_by_price(Course* courses, int n, float min, float max);
Course* delete_course(Course* courses, int count, char name[50], char date[11]);

int main(){
    FILE* fp = fopen("courses.bin", "rb");
    if (fp == NULL){
        printf("Error opening file");
        exit(-1);
    }
    int n;
    if (fread(&n, sizeof(int), 1, fp) != 1){
        printf("Error reading file");
        exit(-1);
    }
    Course* courses = malloc(n * sizeof(Course));
    if (fread(courses, sizeof(Course), n, fp) != n){
        printf("Error reading elements");
        exit(-1);
    }
    
    fclose(fp);
}

void lower_price_by_index(Course* courses, int count, int ind){
    if (ind < 0 || ind >= count){
        printf("No such index");
        exit(-1);
    }
    courses[ind].price*=0.9;
    printf("%.2fлв. - %s - %s\n", courses[ind].price, courses[ind].name, courses[ind].date);
    
}

int write_courses_by_price(Course* courses, int n, float min, float max){
    int count = 0;
    FILE* fp = fopen("offer.txt", "w");
    if (fp == NULL){
        printf("Error with file");
        exit(-1);
    }
    
    for (int i = 0; i < n; i++){
        if (courses[i].price >= min && courses[i].price <= max){
            Course course = courses[i];
            fprintf(fp, "%s\n%s\n%d лекции\n%.2fлв.\n", course.name, course.date, course.lections, course.price);
            count++;
        }
        
    }
    
    fclose(fp);
    return count;
}

Course* delete_course(Course* courses, int count, char name[50], char date[11]){
    for (int i = 0; i < count; i++){
        if (strcmp(courses[i].name, name) == 0 && strcmp(courses[i].date, date) == 0){
            for (int j = i; j < count - 1; j++){ 
                courses[j] = courses[j+1];
               
            }
            Course* temp = realloc(courses, (count - 1) * sizeof(Course));
            if (temp == NULL){
                printf("Error with memorry");
                return NULL;
            }
            courses = temp;
        }
    }
    return courses;
}