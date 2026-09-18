#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
};

void addEmployee(void)
{
    struct Employee employee;
    FILE *file;

    file = fopen("employees.dat", "ab");

    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }

    printf("\nEnter Employee ID: ");
    scanf("%d", &employee.id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", employee.name);

    printf("Enter Employee Salary: ");
    scanf("%f", &employee.salary);

    fwrite(&employee, sizeof(struct Employee), 1, file);

    fclose(file);

    printf("Employee added successfully.\n");
}

void displayEmployees(void)
{
    struct Employee employee;
    FILE *file;

    file = fopen("employees.dat", "rb");

    if (file == NULL)
    {
        printf("\nNo employee records found.\n");
        return;
    }

    printf("\n========== Employee Records ==========\n");

    while (fread(&employee, sizeof(struct Employee), 1, file) == 1)
    {
        printf("\nEmployee ID     : %d\n", employee.id);
        printf("Employee Name   : %s\n", employee.name);
        printf("Employee Salary : %.2f\n", employee.salary);
    }

    fclose(file);
}

void searchEmployee(void)
{
    struct Employee employee;
    FILE *file;
    int id;
    int found = 0;

    file = fopen("employees.dat", "rb");

    if (file == NULL)
    {
        printf("\nNo employee records found.\n");
        return;
    }

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);

    while (fread(&employee, sizeof(struct Employee), 1, file) == 1)
    {
        if (employee.id == id)
        {
            printf("\nEmployee Found!\n");
            printf("Employee ID     : %d\n", employee.id);
            printf("Employee Name   : %s\n", employee.name);
            printf("Employee Salary : %.2f\n", employee.salary);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Employee with ID %d not found.\n", id);
    }

    fclose(file);
}

int main(void)
{
    int choice;

    while (1)
    {
        printf("\n====================================\n");
        printf("      EMPLOYEE MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Exit\n");
        printf("====================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                printf("Thank you for using the Employee Management System.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
