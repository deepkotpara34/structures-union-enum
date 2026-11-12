
// Structures - 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition
typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

// Function to create a student list
Student* create_student_list(int n) {
    if (n <= 0) {
        return NULL;
    }

    Student *studs = malloc(n * sizeof(Student));

    if (studs == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    return studs;
}

// Function to add student details
void add_student(Student *studs, int i,
                 const char *name, int age, float gpa) {

    if (studs == NULL || i < 0 || name == NULL) {
        return;
    }

    snprintf(studs[i].name, sizeof(studs[i].name), "%s", name);

    studs[i].age = age;
    studs[i].gpa = gpa;
}

// Function to display students
void display_students(const Student *students, int size) {
    if (students == NULL) {
        return;
    }

    for (int i = 0; i < size; i++) {
        printf("Name: %s, Age: %d, GPA: %.2f\n",
               students[i].name,
               students[i].age,
               students[i].gpa);
    }
}

// Function to free allocated memory
void free_student_list(Student *students) {
    free(students);
}

// Main function
int main() {
    int number_of_students = 3;

    Student *student_list =
        create_student_list(number_of_students);

    if (student_list == NULL) {
        return 1;
    }

    add_student(student_list, 0, "Aladdin", 20, 3.5);
    add_student(student_list, 1, "Batman", 21, 3.7);
    add_student(student_list, 2, "Catwoman", 22, 3.8);

    printf("Student Details:\n\n");

    display_students(student_list, number_of_students);

    free_student_list(student_list);

    return 0;
}
