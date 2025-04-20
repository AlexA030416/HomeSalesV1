#include <stdio.h>
#include <string.h>

#define MAX_SALESPEOPLE 100
#define MAX_NAME_LENGTH 50

int main() {
    char names[MAX_SALESPEOPLE][MAX_NAME_LENGTH];
    int sales[MAX_SALESPEOPLE];
    int count = 0;
    int grandTotal = 0;
    int maxSale = 0;
    char topSalesperson[MAX_NAME_LENGTH] = "";

    while (1) {
        char name[MAX_NAME_LENGTH];
        int sale;

        printf("Enter the name of the salesperson (or type 'done' to finish): ");
        scanf("%s", name);

        // Check if the user wants to stop entering data
        if (strcmp(name, "done") == 0) {
            break;
        }

        // Error handling for invalid salesperson name "O"
        if (strcmp(name, "O") == 0) {
            printf("Error: 'O' is not a valid salesperson name. Please try again.\n");
            continue; // Skip this iteration and prompt for the next entry
        }

        printf("Enter the sales amount for %s: ", name);
        scanf("%d", &sale);

        // Store the data
        strcpy(names[count], name);
        sales[count] = sale;
        count++;

        // Update the grand total and check for the highest sale
        grandTotal += sale;
        if (sale > maxSale) {
            maxSale = sale;
            strcpy(topSalesperson, name);
        }
    }

    // Display results
    printf("\nGrand Total of Sales: %d\n", grandTotal);
    if (count > 0) {
        printf("Top Salesperson: %s with %d\n", topSalesperson, maxSale);
    } else {
        printf("No valid sales data entered.\n");
    }

    return 0;
}