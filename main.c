#include <stdio.h>
#include "student.h"
#include "file_operations.h"
#include "utils.h"

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
