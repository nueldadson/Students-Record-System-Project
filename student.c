#include <stdio.h>
#include "student.h"

void addStudent(Student students[], int *count) {
    printf("Enter student name: ");
    scanf("%s", students[*count].name);
    printf("Enter roll number: ");
    scanf("%d", &students[*count].rollNumber);
    printf("Enter marks: ");
    scanf("%f", &students[*count].marks);
    (*count)++;
}

void displayStudents(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Roll Number: %d, Marks: %.2f\n",
               students[i].name, students[i].rollNumber, students[i].marks);
    }
}
