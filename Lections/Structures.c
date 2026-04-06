#include <stdio.h>
#include <string.h>

int main(){
    struct Student{
        char name[20]; // или char* name, което е по-добре в професионална среда
        char fac_num[20];
        int age;
        double grade;
    };// или typedef преди struct + Student след }; или students[10]

    struct Student student;
    strcpy(student.name, "Ivan");
    student.age = 19;
    // ако имаме оказател към стурктура нямаме *, а имаме ->

    // при char* name
    // student.name = (char*)malloc(20);

    //Student *studentP = &student;
    // studentP->grade = 6.00;

    //Масиви
    struct Student students[3];
    // създаваме и записваме 3 студента


    // Записване във файл
    FILE* fp = fopen("students.bin", "wb");
    if (fp == NULL){
        exit(1);
    }
    for(int i = 0; i < 3; i++){
        fwrite(&students[i], sizeof(struct Student), 1, fp);
    }
    
    
    fclose(fp);

    fp = fopen("students.bin", "rb");
    struct Student students_from_file[3];
    for(int i = 0; i < 3; i++){
        fread(&students_from_file[i], sizeof(struct Student), 1, fp);
    }


    // или

    fread(students_from_file, sizeof(struct Student), 3, fp);
    
}