#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int code;
    char title[100];
    char author[100];
    int pages;
    int is_borrowed;  /* 0 for available, 1 for borrowed */
};

int main() {
    int choice;
    FILE *file;
    FILE *temp;
    char line[256];
    struct Book book;
    struct Book newBook;
    int borrowed = 0;
    int bookCode;
    char title[100];

    printf("\n\t\tWelcome to the National Library System\n");
    printf("\t....................................................");

    while (1) {
        printf("\n\nServices provided by the system\n 1.Add Book\n 2.Display Books\n 3.Search Book by Title\n 4.Borrow Book\n 5.Return Book\n 6.Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 
		
        if (choice == 1) {
		
            int found = 0;
            file = fopen("LibraryMS.txt", "a+");
            if (file == NULL) {
                printf("Error opening file!\n");
                return 1;
            }

            printf("Enter book code: ");
            scanf("%d", &newBook.code);
            getchar(); 

            while (fgets(line, sizeof(line), file)) {
                sscanf(line, "%d,%[^,],%[^,],%d,%d", &book.code, book.title, book.author, &book.pages, &book.is_borrowed);
                if (book.code == newBook.code) {
                    printf("The book code is already taken.\n");
                    found = 1;
                    break;
                }
            }

            if (found=0) {
                fclose(file);
                continue;
            }

            printf("Enter the book title: ");
            fgets(newBook.title, sizeof(newBook.title), stdin);
            newBook.title[strcspn(newBook.title, "\n")] = 0;

            printf("Enter the author: ");
            fgets(newBook.author, sizeof(newBook.author), stdin);
            newBook.author[strcspn(newBook.author, "\n")] = 0;

            printf("Enter the pages of the book: ");
            scanf("%d", &newBook.pages);

            newBook.is_borrowed = 0;  
            fprintf(file, "%d,%s,%s,%d,%d\n", newBook.code, newBook.title, newBook.author, newBook.pages, newBook.is_borrowed);
            fclose(file);
            printf("Book added successfully!\n");
        }
		
        else if (choice == 2) {
		
            file = fopen("libraryMS.txt", "r");
            if (file == NULL) {
                printf("No books found!\n");
                continue;
            }

            printf("\nList of Books:\n");
            printf("Code\tTitle\t\t\tAuthor\t\t\t\tPages\tStatus\n");
            printf("-----------------------------------------------------------------------------------\n");

            while (fgets(line, sizeof(line), file)) {
                sscanf(line, "%d,%[^,],%[^,],%d,%d", &book.code, book.title, book.author, &book.pages, &book.is_borrowed);
                printf("%d\t%-20s\t%-15s\t\t%d\t%s\n", book.code, book.title, book.author, book.pages, book.is_borrowed ? "Borrowed" : "Available");
            }
            fclose(file);
        }
		
        else if (choice == 3) {
            int found = 0;
            printf("Enter book title to search: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0;  
            file = fopen("libraryMS.txt", "r");
            if (file == NULL) {
                printf("No books found!\n");
                continue;
            }

           
            printf("\nBooks with title '%s':\n", title);
            printf("Code\tTitle\t\t\tAuthor\t\t\tPages\tStatus\n");
            printf("--------------------------------------------------------------------------------\n");

            while (fgets(line, sizeof(line), file)) {
                sscanf(line, "%d,%[^,],%[^,],%d,%d", &book.code, book.title, book.author, &book.pages, &book.is_borrowed);
				if (strstr(book.title, title) != NULL) {
                    printf("%d\t%-20s\t%-15s\t%d\t%s\n", book.code, book.title, book.author, book.pages, book.is_borrowed ? "Borrowed" : "Available");
                    found = 1;
                }
            }
            if (!found) {
                printf("No book found with given title '%s'.\n", title);
            }
            fclose(file);
        }
		
        else if (choice == 4) {
		
            int found = 0;
            printf("Enter book code to borrow: ");
            scanf("%d", &bookCode);

            file = fopen("libraryMS.txt", "r+");
            if (file == NULL) {
                printf("No books available.\n");
                continue;
            }

            temp = fopen("temp1.txt", "w");
            while (fgets(line, sizeof(line), file)) {
                sscanf(line, "%d,%[^,],%[^,],%d,%d", &book.code, book.title, book.author, &book.pages, &book.is_borrowed);
				if (book.code == bookCode && book.is_borrowed == 0) {
                    book.is_borrowed = 1; 
                    found = 1;
                }

                fprintf(temp, "%d,%s,%s,%d,%d\n", book.code, book.title, book.author, book.pages, book.is_borrowed);
            }

            fclose(file);
            fclose(temp);
            remove("libraryMS.txt");
            rename("temp1.txt", "libraryMS.txt");

            if (found) {
                printf("Book borrowed successfully.\n");
            } else {
                printf("The book is already borrowed.\n");
            }
        }
		
        else if (choice == 5) {
		
            int found = 0;
            printf("Enter book code to return: ");
            scanf("%d", &bookCode);

            file = fopen("libraryMS.txt", "r+");
            if (file == NULL) {
                printf("No books available.\n");
                continue;
            }

            temp = fopen("temp1.txt", "w");
            while (fgets(line, sizeof(line), file)) {
                sscanf(line, "%d,%[^,],%[^,],%d,%d", &book.code, book.title, book.author, &book.pages, &book.is_borrowed);
				if (book.code == bookCode && book.is_borrowed == 1) {
                    book.is_borrowed = 0; 
                    found = 1;
                }

                fprintf(temp, "%d,%s,%s,%d,%d\n", book.code, book.title, book.author, book.pages, book.is_borrowed);
            }

            fclose(file);
            fclose(temp);
            remove("libraryMS.txt");
            rename("temp1.txt", "libraryMS.txt");

            if (found) {
                printf("Book returned successfully.\n");
            } else {
                printf("Book not found or not borrowed.\n");
            }
        }
		
        else if (choice == 6) {
            printf("User logged out successfully...\n");
            exit(0);
        }
		
        else {
            printf("Invalid choice! Please try again.\n");
        }
		
    }

    return 0;
}

