#include <stdio.h>
#include <string.h>

#define MAX 100

struct Transaction {
    char date[20];
    char type[20];
    float amount;
};

struct Account {
    int accNo;
    char name[50];
    char type[20];
    float balance;
    char created[20];
    char lastTxn[20];
    int txnCount;
    struct Transaction history[50];
};

float minBalance(char type[]) {
    if (strcmp(type, "Savings") == 0) return 1000;
    if (strcmp(type, "Current") == 0) return 5000;
    return 10000; // Fixed Deposit
}

float interestRate(char type[]) {
    if (strcmp(type, "Savings") == 0) return 0.04;
    if (strcmp(type, "Fixed") == 0) return 0.07;
    return 0.0;
}

int main() {
    struct Account a[MAX];
    int n, i;

    printf("Enter number of accounts: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details for account %d\n", i + 1);

        printf("Account Number: ");
        scanf("%d", &a[i].accNo);

        printf("Name: ");
        scanf("%s", a[i].name);

        printf("Type (Savings/Current/Fixed): ");
        scanf("%s", a[i].type);

        printf("Opening Balance: ");
        scanf("%f", &a[i].balance);

        printf("Account Creation Date: ");
        scanf("%s", a[i].created);

        a[i].txnCount = 0;
        strcpy(a[i].lastTxn, a[i].created);

        if (a[i].balance < minBalance(a[i].type))
            printf("WARNING: Below minimum balance!\n");

       
        strcpy(a[i].history[0].date, a[i].created);
        strcpy(a[i].history[0].type, "Deposit");
        a[i].history[0].amount = a[i].balance;
        a[i].txnCount = 1;
    }

    printf("\n--- Account Summary ---\n");
    for (i = 0; i < n; i++) {
        printf("\nAccount %d | %s | %s\n", a[i].accNo, a[i].name, a[i].type);
        printf("Balance: %.2f (Interest Rate: %.2f)\n", a[i].balance, interestRate(a[i].type));
        printf("Created: %s | Last Transaction: %s\n", a[i].created, a[i].lastTxn);
    }

    return 0;
}
