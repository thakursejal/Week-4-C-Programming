#include <stdio.h>

int main(void)
{
    FILE *file;
    char data[200];

    printf("Enter data to append to the file: ");
    fgets(data, sizeof(data), stdin);

    file = fopen("data.txt", "a");

    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    fprintf(file, "%s", data);

    fclose(file);

    printf("Data appended successfully.\n");

    return 0;
}
