#include <stdio.h>
#include <string.h>

typedef struct Employee {
    char name[50];
    char dob[15];
    int empID;
    char department[30];
    float salary;
} Employee;

// Function prototypes
void addEmployee(Employee employees[], int *count);
void deleteEmployee(Employee employees[], int *count);
void displayEmployees(Employee employees[], int count);
void menu();

// Main function
int main() {
    Employee employees[100]; 
    int count = 0;                    
    int choice;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &count);
                break;
            case 2:
                deleteEmployee(employees, &count);
                break;
            case 3:
                displayEmployees(employees, count);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void menu() {
    printf("\nEmployee Management System\n");
    printf("1. Add an Employee\n");
    printf("2. Delete an Employee\n");
    printf("3. Display All Employees\n");
    printf("4. Exit\n");
}

// Function to add an employee
void addEmployee(Employee employees[], int *count) {
    if (*count >= 100) {
        printf("Error: Maximum number of employees reached.\n");
        return;
    }

    printf("\nEnter details of the employee:\n");
    printf("Name: ");
    getchar(); 
    fgets(employees[*count].name, 50, stdin);
    employees[*count].name[strcspn(employees[*count].name, "\n")] = 0; 

    printf("Date of Birth (DD/MM/YYYY): ");
    fgets(employees[*count].dob, 15, stdin);
    employees[*count].dob[strcspn(employees[*count].dob, "\n")] = 0; 

    printf("Employee ID: ");
    scanf("%d", &employees[*count].empID);

    printf("Department: ");
    getchar(); 
    fgets(employees[*count].department, 30, stdin);
    employees[*count].department[strcspn(employees[*count].department, "\n")] = 0; 

    printf("Salary: ");
    scanf("%f", &employees[*count].salary);

    (*count)++;
    printf("Employee added successfully.\n");
}


void deleteEmployee(Employee employees[], int *count) {
    if (*count == 0) {
        printf("No employees to delete.\n");
        return;
    }

    int empID, index = -1;
    printf("\nEnter the Employee ID of the employee to delete: ");
    scanf("%d", &empID);

\
    for (int i = 0; i < *count; i++) {
        if (employees[i].empID == empID) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Employee with ID %d not found.\n", empID);
        return;
    }


    for (int i = index; i < *count - 1; i++) {
        employees[i] = employees[i + 1];
    }

    (*count)--;
    printf("Employee with ID %d deleted successfully.\n", empID);
}


void displayEmployees(Employee employees[], int count) {
    if (count == 0) {
        printf("No employees to display.\n");
        return;
    }

    printf("\nEmployee Details:\n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", employees[i].name);
        printf("Date of Birth: %s\n", employees[i].dob);
        printf("Employee ID: %d\n", employees[i].empID);
        printf("Department: %s\n", employees[i].department);
        printf("Salary: %.2f\n", employees[i].salary);
        printf("----------------------------------------------------\n");
    }
}
