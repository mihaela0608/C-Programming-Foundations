#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int facultyNumber;
    double grade;
}Student;

void readStudent(Student *s);

int main(){
    int n;
    scanf("%d", &n);
    Student* students = (Student*) malloc(n * sizeof(Student));

    for (int i = 0; i < n; i++){
        Student student;
        readStudent(&student);
        students[i] = student;
    }
    double highestGrade = students[0].grade;
    for (int i = 1; i < n; i++){
        if (students[i].grade > highestGrade){
            highestGrade = students[i].grade;
        }
    }
    printf("%.2lf", highestGrade);

    free(students);
    
}

void readStudent(Student *s){
    char name[50];
    scanf("%s", name);
    strcpy(s->name, name);
    int fn;
    scanf("%d", &fn);
    s->facultyNumber = fn;
    double grade;
    scanf("%lf", &grade);
    s->grade = grade;
}