#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

// Function declarations
void addStudent(struct Student s[], int *count);
void displayStudents(struct Student s[], int count);
void sortAscending(struct Student s[], int count);
void sortDescending(struct Student s[], int count);
void swap(struct Student *a, struct Student *b);

int main() {

    struct Student students[100];
    int count = 0;
    int choice;

    while (1) {

        printf("\n===== STUDENT MARKS SORTING SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Sort Ascending\n");
        printf("4. Sort Descending\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(students, &count); break;
            case 2: displayStudents(students, count); break;
            case 3: sortAscending(students, count); break;
            case 4: sortDescending(students, count); break;
            case 5:
                printf("Exiting... Thank you!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

// Add student
void addStudent(struct Student s[], int *count) {

    printf("\nEnter Roll Number: ");
    scanf("%d", &s[*count].roll);

    printf("Enter Name: ");
    scanf("%s", s[*count].name);

    printf("Enter Marks: // Add student
void addStudent(struct Student s[], int *count) {

    printf("\nEnter Roll Number: ");
    scanf("%d", &s[*count].roll);

    printf("Enter Name: ");
    scanf("%s", s[*count].name);

    printf("Enter Marks: ");
    scanf("%f", &s[*count].marks);

    (*count)++;

    printf("Record Added Successfully!\n");
}

// Display students
void displayStudents(struct Student s[], int count) {
    int i;

    printf("\nROLL NO    NAME               MARKS\n");
    printf("---------------------------------------\n");

    for (i = 0; i < count; i++) {
        printf("%d        %-15s %.2f\n", s[i].roll, s[i].name, s[i].marks);
    }
}// Swap function
void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

// Sort Ascending
void sortAscending(struct Student s[], int count) {
    int i, j;

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (s[j].marks > s[j+1].marks) {
                swap(&s[j], &s[j+1]);
            }
        }
    }

    printf("\nSorting Completed (Ascending)!\n");
    displayStudents(s, count);
}

// Sort Descending
void sortDescending(struct Student s[], int count) {
    int i, j;

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (s[j].marks < s[j+1].marks) {
                swap(&s[j], &s[j+1]);
            }
        }
    }

    printf("\nSorting Completed (Descending)!\n");
    displayStudents(s, count);
}
