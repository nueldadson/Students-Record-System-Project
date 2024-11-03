#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    char name[50];
    int rollNumber;
    float marks;
} Student;

void addStudent(Student students[], int *count);
void displayStudents(Student students[], int count);

#endif
