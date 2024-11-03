#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Student structure
typedef struct {
    char name[50];
    int rollNumber;
    float marks;
} Student;

// Function prototypes
void addStudent(Student students[], int *count);
void displayStudents(Student students[], int count);
void saveToFile(Student students[], int count);
void loadFromFile(Student students[], int *count);
void searchByRollNumber(Student students[], int count);
void calculateAverage(Student students[], int count);
void sortStudentsByMarks(Student students[], int count);
int compareMarks(const void *a, const void *b);

// Main function
int main() {
    Student students[100];
    int count = 0;
    int choice;

    while (1) {
        printf("\n1. Add Student\n2. Display Students\n3. Save to File\n4. Load from File\n");
        printf("5. Search by Roll Number\n6. Calculate Average Marks\n7. Sort by Marks\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(students, &count); break;
            case 2: displayStudents(students, count); break;
            case 3: saveToFile(students, count); break;
            case 4: loadFromFile(students, &count); break;
            case 5: searchByRollNumber(students, count); break;
            case 6: calculateAverage(students, count); break;
            case 7: sortStudentsByMarks(students, count); break;
            case 8: return 0;
            default: printf("Invalid choice.\n");
        }
    }
}

// Function to add a new student
void addStudent(Student students[], int *count) {
    printf("Enter student name: ");
    scanf("%s", students[*count].name);
    printf("Enter roll number: ");
    scanf("%d", &students[*count].rollNumber);
    printf("Enter marks: ");
    scanf("%f", &students[*count].marks);
    (*count)++;
}

// Function to display all students
void displayStudents(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Roll Number: %d, Marks: %.2f\n",
               students[i].name, students[i].rollNumber, students[i].marks);
    }
}

// Function to save student data to a file
void saveToFile(Student students[], int count) {
    FILE *file = fopen("students.txt", "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %.2f\n", students[i].name, students[i].rollNumber, students[i].marks);
    }
    fclose(file);
    printf("Data saved successfully.\n");
}

// Function to load student data from a file
void loadFromFile(Student students[], int *count) {
    FILE *file = fopen("students.txt", "r");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }
    *count = 0;
    while (fscanf(file, "%s %d %f", students[*count].name, &students[*count].rollNumber, &students[*count].marks) != EOF) {
        (*count)++;
    }
    fclose(file);
    printf("Data loaded successfully.\n");
}

// Search for a student by roll number
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

// Function to calculate the average marks of all students
void calculateAverage(Student students[], int count) {
    if (count == 0) {
        printf("No students to calculate average.\n");
        return;
    }
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += students[i].marks;
    }
    printf("Average marks: %.2f\n", sum / count);
}

// Compare two students by marks for sorting
int compareMarks(const void *a, const void *b) {
    float diff = ((Student*)a)->marks - ((Student*)b)->marks;
    return (diff > 0) - (diff < 0);
}

// Sort students by marks
void sortStudentsByMarks(Student students[], int count) {
    qsort(students, count, sizeof(Student), compareMarks);
    printf("Students sorted by marks.\n");
}
