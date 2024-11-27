#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100
#define FILE_NAME "C:/Users/SyedA/Desktop/Lab Task 11/books.txt"


typedef struct Book {
    int id;
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int quantity;
    float price;
} Book;

// Function prototypes
void addBook();
void viewBooks();
void searchBook();
void updateBook();
void deleteBook();
void calculateInventoryValue();
int validateUniqueID(int id);

int main() {
    int choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add New Book\n");
        printf("2. View All Books\n");
        printf("3. Search for a Book\n");
        printf("4. Update Book Details\n");
        printf("5. Delete a Book\n");
        printf("6. Calculate Total Inventory Value\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                updateBook();
                break;
            case 5:
                deleteBook();
                break;
            case 6:
                calculateInventoryValue();
                break;
            case 7:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}


void addBook() {
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    Book book;
    printf("Enter Book ID: ");
    scanf("%d", &book.id);
    if (!validateUniqueID(book.id)) {
        printf("Book ID already exists. Cannot add duplicate.\n");
        fclose(file);
        return;
    }

    printf("Enter Title: ");
    getchar(); 
    fgets(book.title, MAX_TITLE_LEN, stdin);
    book.title[strcspn(book.title, "\n")] = '\0'; 
    printf("Enter Author: ");
    fgets(book.author, MAX_AUTHOR_LEN, stdin);
    book.author[strcspn(book.author, "\n")] = '\0'; 
    printf("Enter Quantity: ");
    scanf("%d", &book.quantity);
    if (book.quantity < 0) book.quantity = 0; 
    printf("Enter Price: ");
    scanf("%f", &book.price);
    if (book.price < 0) book.price = 0; 

    fprintf(file, "%d,%s,%s,%d,%.2f\n", book.id, book.title, book.author, book.quantity, book.price);
    printf("Book added successfully.\n");

    fclose(file);
}

// Function to view all books
void viewBooks() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No records found. File missing or empty.\n");
        return;
    }

    Book book;
    printf("\nBook Records:\n");
    printf("ID\tTitle\t\tAuthor\t\tQuantity\tPrice\n");
    while (fscanf(file, "%d,%[^,],%[^,],%d,%f\n", &book.id, book.title, book.author, &book.quantity, &book.price) == 5) {
        printf("%d\t%s\t\t%s\t\t%d\t\t%.2f\n", book.id, book.title, book.author, book.quantity, book.price);
    }

    fclose(file);
}


void searchBook() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No records found. File missing or empty.\n");
        return;
    }

    int searchID;
    char searchTitle[MAX_TITLE_LEN];
    printf("Search by:\n1. Book ID\n2. Title\nEnter your choice: ");
    int choice;
    scanf("%d", &choice);

    Book book;
    int found = 0;
    if (choice == 1) {
        printf("Enter Book ID: ");
        scanf("%d", &searchID);
        while (fscanf(file, "%d,%[^,],%[^,],%d,%f\n", &book.id, book.title, book.author, &book.quantity, &book.price) == 5) {
            if (book.id == searchID) {
                printf("Book Found: ID=%d, Title=%s, Author=%s, Quantity=%d, Price=%.2f\n", book.id, book.title, book.author, book.quantity, book.price);
                found = 1;
                break;
            }
        }
    } else if (choice == 2) {
        printf("Enter Title: ");
        getchar(); 
        fgets(searchTitle, MAX_TITLE_LEN, stdin);
        searchTitle[strcspn(searchTitle, "\n")] = '\0'; 
        while (fscanf(file, "%d,%[^,],%[^,],%d,%f\n", &book.id, book.title, book.author, &book.quantity, &book.price) == 5) {
            if (strcmp(book.title, searchTitle) == 0) {
                printf("Book Found: ID=%d, Title=%s, Author=%s, Quantity=%d, Price=%.2f\n", book.id, book.title, book.author, book.quantity, book.price);
                found = 1;
                break;
            }
        }
    } else {
        printf("Invalid choice.\n");
    }

    if (!found) {
        printf("Book not found.\n");
    }

    fclose(file);
}

// Function to update book details
void updateBook() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No records found. File missing or empty.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }

    int updateID, updatedQuantity;
    float updatedPrice;
    printf("Enter Book ID to update: ");
    scanf("%d", &updateID);

    Book book;
    int found = 0;
    while (fscanf(file, "%d,%[^,],%[^,],%d,%f\n", &book.id, book.title, book.author, &book.quantity, &book.price) == 5) {
        if (book.id == updateID) {
            printf("Enter new Quantity: ");
            scanf("%d", &updatedQuantity);
            printf("Enter new Price: ");
            scanf("%f", &updatedPrice);
            book.quantity = updatedQuantity < 0 ? 0 : updatedQuantity;
            book.price = updatedPrice < 0 ? 0 : updatedPrice;
            found = 1;
        }
        fprintf(tempFile, "%d,%s,%s,%d,%.2f\n", book.id, book.title, book.author, book.quantity, book.price);
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("Book updated successfully.\n");
    } else {
        printf("Book ID not found.\n");
        remove("temp.txt");
    }
}

// Function to delete a book
void deleteBook() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No records found. File missing or empty.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }

    int deleteID;
    printf("Enter Book ID to delete: ");
    scanf("%d", &deleteID);

    Book book;
    int found = 0;
    while (fscanf(file, "%d,%[^,],%[^,],%d,%f\n", &book.id, book.title, book.author, &book.quantity, &book.price) == 5) {
        if (book.id == deleteID) {
            found = 1;
        } else {
            fprintf(tempFile, "%d,%s,%s,%d,%.2f\n", book.id, book.title, book.author, book.quantity, book.price);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("Book deleted successfully.\n");
    } else {
        printf("Book ID not found.\n");
        remove("temp.txt");
    }
}


void calculateInventoryValue() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No records found. File missing or empty.\n");
        return;
    }

    Book book;
    float totalValue = 0;
    while (fscanf(file, "%d,%[^,],%[^,],%d,%f\n", &book.id, book.title, book.author, &book.quantity, &book.price) == 5) {
        totalValue += book.quantity * book.price;
    }

    printf("Total Inventory Value: %.2f\n", totalValue);

    fclose(file);
}


int validateUniqueID(int id) {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        return 1; 
    }

    Book book;
    while (fscanf(file, "%d,%[^,],%[^,],%d,%f\n", &book.id, book.title, book.author, &book.quantity, &book.price) == 5) {
        if (book.id == id) {
            fclose(file);
            return 0; 
        }
    }

    fclose(file);
    return 1; 
}
