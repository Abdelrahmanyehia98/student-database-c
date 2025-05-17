#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"

static student students[MAX_STUDENTS];
static uint8 current_size = 0;

//Checks if the database has reached its maximum
bool SDB_IsFull() {
    return current_size >= MAX_STUDENTS;
}
//Returns the current number of students in the database
uint8 SDB_GetUsedSize() {
    return current_size;
}
// to add one more student
bool SDB_AddEntry() {
    if (SDB_IsFull()) {
        printf("Database is full\n");
        return false;
    }

    student new_student ;
    printf("Enter Student ID: ");
    scanf("%u", &new_student.Student_ID);
    if (SDB_IsIdExist(new_student.Student_ID)) {
        printf("Student ID already exists. Cannot add duplicate IDs.\n");
        return false;
    }

    printf("Enter Student Year: ");
    scanf("%u", &new_student.Student_year);
    printf("Enter Course 1 ID: ");
    scanf("%u", &new_student.Course1_ID);
    printf("Enter Course 1 Grade (0-100): ");
    scanf("%u", &new_student.Course1_grade);
    printf("Enter Course 2 ID: ");
    scanf("%u", &new_student.Course2_ID);
    printf("Enter Course 2 Grade (0-100): ");
    scanf("%u", &new_student.Course2_grade);
    printf("Enter Course 3 ID: ");
    scanf("%u", &new_student.Course3_ID);
    printf("Enter Course 3 Grade (0-100): ");
    scanf("%u", &new_student.Course3_grade);
    students[current_size] = new_student;
    current_size++;
    printf("Student added successfully.\n");
    return true;
}
// to delete a student
void SDB_DeleteEntry(uint32 id) {
    for (uint8 i = 0; i < current_size; i++) {
        if (students[i].Student_ID == id) {
            for (uint8 j = i; j < current_size - 1; j++) {
                students[j] = students[j + 1];
            }
            current_size--;
            break;
        }
    }
}

//displays a student's information by ID
bool SDB_ReadEntry(uint32 id) {
    for (uint8 i = 0; i < current_size; i++) {
        if (students[i].Student_ID == id) {
            printf("Student ID: %u\n", students[i].Student_ID);
            printf("Student Year: %u\n", students[i].Student_year);
            printf("Course 1 ID: %u, Grade: %u\n", students[i].Course1_ID, students[i].Course1_grade);
            printf("Course 2 ID: %u, Grade: %u\n", students[i].Course2_ID, students[i].Course2_grade);
            printf("Course 3 ID: %u, Grade: %u\n", students[i].Course3_ID, students[i].Course3_grade);
            return true;
        }
    }
    return false;
}

//a list of all student IDs and the count of students
void SDB_GetList(uint8 *count, uint32 *list) {
    *count = current_size;
    for (uint8 i = 0; i < current_size; i++) {
        list[i] = students[i].Student_ID;
    }
}


//Checks if the given student ID exists in the database
bool SDB_IsIdExist(uint32 id) {
    for (uint8 i = 0; i < current_size; i++) {
        if (students[i].Student_ID == id) {
            return true;
        }
    }
    return false;
}

