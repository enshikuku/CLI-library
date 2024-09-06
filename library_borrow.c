#include <stdio.h>
#include <string.h>

// Struct to store book information
struct Book {
    int id;
    char title[100];
    int available; // 1 if available, 0 if not
};

// Struct to store student information
struct Student {
    char name[100];
    char studentID[20];
};

// Function to display available books
void displayBooks(struct Book books[], int size) {
    printf("\nAvailable Books:\n");
    printf("ID\tTitle\n");
    for (int i = 0; i < size; i++) {
        if (books[i].available == 1) {
            printf("%d\t%s\n", books[i].id, books[i].title);
        }
    }
}

// Function to borrow a book
void borrowBook(struct Book books[], int size, struct Student student) {
    int bookID;
    printf("\nEnter the ID of the book you want to borrow: ");
    scanf("%d", &bookID);

    // Search for the book by ID
    for (int i = 0; i < size; i++) {
        if (books[i].id == bookID) {
            if (books[i].available == 1) {
                printf("\nBook '%s' has been successfully borrowed by %s (ID: %s).\n", 
                    books[i].title, student.name, student.studentID);
                books[i].available = 0; // Mark the book as not available
            } else {
                printf("\nSorry, the book '%s' is currently unavailable.\n", books[i].title);
            }
            return;
        }
    }

    // If book ID not found
    printf("\nInvalid book ID.\n");
}

int main() {
    // Initialize books
    struct Book books[3] = {
        {1, "Introduction to Algorithms", 1},
        {2, "C Programming Language", 1},
        {3, "Operating System Concepts", 1}
    };

    struct Student student;

    // Get student information
    printf("Enter your name: ");
    fgets(student.name, sizeof(student.name), stdin);
    student.name[strcspn(student.name, "\n")] = 0; 

    printf("Enter your student ID: ");
    fgets(student.studentID, sizeof(student.studentID), stdin);
    student.studentID[strcspn(student.studentID, "\n")] = 0; 

    // Display available books and allow the student to borrow
    displayBooks(books, 3);
    borrowBook(books, 3, student);

    return 0;
}

