
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define customer structure
struct customer {
    char name[50];
    int account_number;
    float balance;
};

// Declare global variables
struct customer bank[100];
int customer_count = 0;

// Function to create a new customer account
void create_account() {
    printf("(Enter first name only)");
    printf("Enter customer name: ");
    scanf("%s", bank[customer_count].name);
    printf("Enter account number: ");
    scanf("%d", &bank[customer_count].account_number);
    printf("Enter initial balance: ");
    scanf("%f", &bank[customer_count].balance);
    printf("Account created successfully!\n");
    customer_count++;
}

// Function to deposit money into a customer account
void deposit() {
    int account_number;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for(int i = 0; i < customer_count; i++) {
        if(bank[i].account_number == account_number) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            bank[i].balance += amount;
            printf("Deposit successful!\n");
            return;
        }
    }
    printf("Account not found.\n");
}

// Function to withdraw money from a customer account
void withdraw() {
    int account_number;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for(int i = 0; i < customer_count; i++) {
        if(bank[i].account_number == account_number) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if(amount > bank[i].balance) {
                printf("Insufficient funds.\n");
                return;
            }
            bank[i].balance -= amount;
            printf("Withdrawal successful!\n");
            return;
        }
    }
    printf("Account not found.\n");
}

// Function to view balance for a customer account
void view_balance() {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for(int i = 0; i < customer_count; i++) {
        if(bank[i].account_number == account_number) {
            printf("Account balance for %s: $%.2f\n", bank[i].name, bank[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

// Main function
int main() {
    int choice;
    while(1) {
        printf("*******  Bank Management System  ********\n");
        printf("1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. View balance\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: create_account(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: view_balance(); break;
            case 5: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
