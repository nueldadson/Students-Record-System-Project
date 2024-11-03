#include <stdio.h>
#include "student.h"
#include "file_operations.h"

void saveToFile(Student students[], int count) {
    FILE *file = fopen("students.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %.2f\n", students[i].name, students[i].rollNumber, students[i].marks);
    }
    fclose(file);
}

void loadFromFile(Student students[], int *count) {
    FILE *file = fopen("students.txt", "r");
    *count = 0;
    while (fscanf(file, "%s %d %f", students[*count].name, &students[*count].rollNumber, &students[*count].marks) != EOF) {
        (*count)++;
    }
    fclose(file);
}
