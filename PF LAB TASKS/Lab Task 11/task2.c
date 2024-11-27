#include <stdio.h>

int main() {
    FILE *file = fopen("C:/Users/SyedA/Desktop/Lab Task 11/file.txt", "r"); 
    if (file == NULL) {
        printf("Error: Unable to open the file.\n");
        return 1; 
    }

    char line[1000]; 
    int i = 1;


    while (fgets(line, sizeof(line), file)) {
        printf("Line %d contains: %s", i, line);
        i++;
    }

    fclose(file); 
    return 0;
}
