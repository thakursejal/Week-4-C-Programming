#include <stdio.h>

struct Student
{
    char name[50];
    int age;
    float marks;
};

int main(void)
{
    struct Student student;
    struct Student storedStudent;
    FILE *file;

    printf("Enter student name: ");
    scanf(" %[^\n]", student.name);

    printf("Enter age: ");
    scanf("%d", &student.age);

    printf("Enter marks: ");
    scanf("%f", &student.marks);

    /* Write structure data to file */
    file = fopen("student.txt", "w");

    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    fprintf(file, "%s\n%d\n%.2f\n",
            student.name,
            student.age,
            student.marks);

    fclose(file);

    /* Read structure data from file */
    file = fopen("student.txt", "r");

    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    fscanf(file, " %[^\n]", storedStudent.name);
    fscanf(file, "%d", &storedStudent.age);
    fscanf(file, "%f", &storedStudent.marks);

    fclose(file);

    printf("\n--- Student Details Read From File ---\n");
    printf("Name  : %s\n", storedStudent.name);
    printf("Age   : %d\n", storedStudent.age);
    printf("Marks : %.2f\n", storedStudent.marks);

    return 0;
}
