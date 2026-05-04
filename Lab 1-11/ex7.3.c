#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int facultyNumber;
    double grade;
}Student;

void readStudent(Student *s);

void printStudent(Student s);
double averageGrade(Student arr[], int n);
void updateGrade(Student *s, double newGrade);

int main(){
    Student student1;
    Student student2;
    Student student3;

    readStudent(&student1);
    readStudent(&student2);
    readStudent(&student3);
    updateGrade(&student3, 5);
    
    Student students[3];
    students[0] = student1;
    students[1] = student2;
    students[2] = student3;
   

    printf("%.2lf", averageGrade(students, 3));
}

void updateGrade(Student *s, double newGrade){
    s->grade = newGrade;
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

void printStudent(Student s){
    printf("%s %d %.2lf\n", s.name, s.facultyNumber, s.grade);
}

double averageGrade(Student arr[], int n){
    double sum;
    for (int i = 0; i < n; i++){
        sum+=arr[i].grade;
    }
    return sum / n;
}