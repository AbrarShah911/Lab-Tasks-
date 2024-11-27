#include <stdio.h>
#include <ctype.h>

int main(){

    FILE *file1, *file2;
    char ch;


    file1 = fopen("C:/Users/SyedA/Desktop/Lab Task 11/file1.txt", "r");
    if (file1 == NULL) {
        printf("Error: Cannot open file 1.");
        printf("\n");
        return 1;
    }


    file2 = fopen("C:/Users/SyedA/Desktop/Lab Task 11/file2.txt", "w");
    if (file2 == NULL) {
        printf("Error: Cannot open file 2");
        printf("\n");
        fclose(file1); 
        return 1;
    }

    while ((ch = fgetc(file1)) != EOF) {
        fputc(toupper(ch), file2); 
    }

    // Close both files
    fclose(file1);
    fclose(file2);

    printf("File copied successfully with all lowercase letters converted to uppercase.\n");

    return 0;
}