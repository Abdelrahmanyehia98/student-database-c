#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"

void SDB_action(uint8 choice);

void SDB_APP() {
    uint8 choice;
    do {
        printf("\n--- Student Database Menu ---\n");
        printf("1. To add student, enter 1\n");
        printf("2. To get the size in database, enter 2\n");
        printf("3. To read student data, enter 3\n");
        printf("4. To get the list of all student IDs, enter 4\n");
        printf("5. To check if ID exists, enter 5\n");
        printf("6. To delete student data, enter 6\n");
        printf("7. To check if database is full, enter 7\n");
        printf("0. To exit, enter 0\n");
        printf("Enter your choice: ");
        scanf("%u", &choice);
         SDB_action(choice);
        }while(choice !=0);

    }

void SDB_action(uint8 choice) {
    uint32 id;
    uint8 count;
    uint32 list[MAX_STUDENTS];
    bool result;

    switch (choice) {
        case 1:
            SDB_AddEntry();
            break; //to add a new student.
        case 2:
            count = SDB_GetUsedSize();
            printf("Current used size in database: %u\n", count);
            break; //displays the current used size of the database.
        case 3:
            printf("Enter Student ID to read data: ");
            scanf("%u", &id);
            SDB_ReadEntry(id);
            break; // displays student ID and the student's data if found
        case 4:
            SDB_GetList(&count, list);
            if (count == 0) {
                printf("Database is empty.\n");
            } else {
                printf("List of Student IDs:\n");
                for (uint8 i = 0; i < count; i++) {
                    printf("%u\n", list[i]);
                }//displays a list of all student IDs.
            }
            break;
        case 5:
            printf("Enter Student ID to check existence: ");
            scanf("%u", &id);
            result = SDB_IsIdExist(id);
            if (result) {
                printf("Student ID %u exists in the database.\n", id);
            } else {
                printf("Student ID %u does not exist in the database.\n", id);
            }//Checks if the given student ID exists in the database
            break;
        case 6:
            printf("Enter Student ID to delete: ");
            scanf("%u", &id);
            SDB_DeleteEntry(id);
            break; // Deletes a student record by ID
        case 7:
            result = SDB_IsFull();
            if (result) {
                printf("The database is full.\n");
            } else {
                printf("The database is not full.\n");
            } //Checks if the database is full
            break;
        case 0:
            printf("exit");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
    }
}
