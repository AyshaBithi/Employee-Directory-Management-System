#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store employee information
struct Employee {
    int empID;
    char firstName[50];
    char lastName[50];
    int age;
    struct Employee* next; // Pointer to the next employee
};

// Function prototypes
void insertEmployee(struct Employee** head);
void deleteEmployee(struct Employee** head, int empID);
void searchEmployee(struct Employee* head, int empID);
void updateEmployee(struct Employee* head, int empID);
void displayEmployees(struct Employee* head);

int main() {
    struct Employee* head = NULL;
    int choice;

    do {
        printf("\nEmployee Directory Menu:\n");
        printf("1. Insert Employee\n");
        printf("2. Delete Employee\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Display Employees\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertEmployee(&head);
                break;
            case 2: {
                int empID;
                printf("Enter Employee ID to delete: ");
                scanf("%d", &empID);
                deleteEmployee(&head, empID);
                break;
            }
            case 3: {
                int empID;
                printf("Enter Employee ID to search: ");
                scanf("%d", &empID);
                searchEmployee(head, empID);
                break;
            }
            case 4: {
                int empID;
                printf("Enter Employee ID to update: ");
                scanf("%d", &empID);
                updateEmployee(head, empID);
                break;
            }
            case 5:
                displayEmployees(head);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    // Free allocated memory before exiting
    struct Employee* current = head;
    struct Employee* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

// Function to insert an employee
void insertEmployee(struct Employee** head) {
    struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));

    if (newEmployee == NULL) {
        printf("Memory allocation failed. Cannot insert employee.\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%d", &newEmployee->empID);
    printf("Enter First Name: ");
    scanf("%s", newEmployee->firstName);
    printf("Enter Last Name: ");
    scanf("%s", newEmployee->lastName);
    printf("Enter Age: ");
    scanf("%d", &newEmployee->age);

    newEmployee->next = *head;
    *head = newEmployee;

    printf("Employee added successfully.\n");
}

// Function to delete an employee
void deleteEmployee(struct Employee** head, int empID) {
    struct Employee* current = *head;
    struct Employee* prev = NULL;

    while (current != NULL && current->empID != empID) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Employee with ID %d not found.\n", empID);
        return;
    }

    if (prev != NULL) {
        prev->next = current->next;
    } else {
        *head = current->next;
    }

    free(current);
    printf("Employee deleted successfully.\n");
}

// Function to search for an employee by ID
void searchEmployee(struct Employee* head, int empID) {
    struct Employee* current = head;
    int found = 0;

    while (current != NULL) {
        if (current->empID == empID) {
            found = 1;
            printf("Employee Found:\n");
            printf("ID: %d\n", current->empID);
            printf("First Name: %s\n", current->firstName);
            printf("Last Name: %s\n", current->lastName);
            printf("Age: %d\n", current->age);
            break;
        }
        current = current->next;
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", empID);
    }
}

// Function to update an employee's information
void updateEmployee(struct Employee* head, int empID) {
    struct Employee* current = head;
    int found = 0;

    while (current != NULL) {
        if (current->empID == empID) {
            found = 1;
            printf("Enter new First Name: ");
            scanf("%s", current->firstName);
            printf("Enter new Last Name: ");
            scanf("%s", current->lastName);
            printf("Enter new Age: ");
            scanf("%d", &current->age);
            printf("Employee information updated successfully.\n");
            break;
        }
        current = current->next;
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", empID);
    }
}

// Function to display all employees
void displayEmployees(struct Employee* head) {
    if (head == NULL) {
        printf("No employees to display.\n");
        return;
    }

    struct Employee* current = head;

    printf("Employee List:\n");
    while (current != NULL) {
        printf("ID: %d\n", current->empID);
        printf("First Name: %s\n", current->firstName);
        printf("Last Name: %s\n", current->lastName);
        printf("Age: %d\n", current->age);
        printf("\n");
        current = current->next;
    }
}