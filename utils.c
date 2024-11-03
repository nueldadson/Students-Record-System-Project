#include <stdio.h>
#include "student.h"
#include "utils.h"

void searchByRollNumber(Student students[], int count) {
    int roll;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == roll) {
            printf("Found: %s, Marks: %.2f\n", students[i].name, students[i].marks);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", roll);
}

void calculateAverage(Student students[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += students[i].marks;
    }
    printf("Average marks: %.2f\n", sum / count);
}

int compareMarks(const void *a, const void *b) {
    return ((Student*)a)->marks > ((Student*)b)->marks ? 1 : -1;
}

void sortStudentsByMarks(Student students[], int count) {
    qsort(students, count, sizeof(Student), compareMarks);
    printf("Sorted students by marks.\n");
}
