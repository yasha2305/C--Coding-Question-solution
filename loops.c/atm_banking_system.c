#include <stdio.h>
#include <string.h>

#define MAX_TRANSACTIONS 100

struct Account {
    int accountNumber;
    int pin;
    char name[50];
    double balance;
};

struct Account accounts[] = {
    {1001, 1234, "Vedant", 10000.00},
    {1002, 5678, "Rahul", 15000.00},
    {1003, 4321, "Aman", 20000.00}
};

int transactionCount = 0;
char history[MAX_TRANSACTIONS][100];

void recordTransaction(const char *message)
{
    if (transactionCount < MAX_TRANSACTIONS) {
        snprintf(history[transactionCount],
                 sizeof(history[0]), "%s", message);
        transactionCount++;
    }
}

void showHistory(void)
{
    printf("\n--- Transaction History ---\n");

    if (transactionCount == 0) {
        printf("No transactions yet.\n");
        return;
    }

    for (int i = transactionCount - 1; i >= 0; i--) {
        printf("%d. %s\n", transactionCount - i, history[i]);
    }
}

int main(void)
{
    int accountNumber, pin;
    int loggedIn = 0;
    int choice;
    int accountIndex = -1;
    double amount;

    printf("====================================\n");
    printf("       SMART ATM BANKING SYSTEM\n");
    printf("====================================\n");

    printf("Enter account number: ");
    if (scanf("%d", &accountNumber) != 1)
        return 1;

    printf("Enter 4-digit PIN: ");
    if (scanf("%d", &pin) != 1)
        return 1;

    int accountCount = sizeof(accounts) / sizeof(accounts[0]);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber &&
            accounts[i].pin == pin) {
            accountIndex = i;
            loggedIn = 1;
            break;
        }
    }

    if (!loggedIn) {
        printf("\nInvalid account number or PIN!\n");
        return 0;
    }

    printf("\nWelcome, %s!\n", accounts[accountIndex].name);

    do {
        printf("\n========== ATM MENU ==========\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Transfer Money\n");
        printf("5. Transaction History\n");
        printf("6. Account Details\n");
        printf("7. Logout\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        switch (choice) {
        case 1:
            printf("\nAvailable Balance: Rs. %.2f\n",
                   accounts[accountIndex].balance);
            break;

        case 2:
            printf("Enter deposit amount: Rs. ");
            if (scanf("%lf", &amount) != 1)
                return 1;

            if (amount <= 0) {
                printf("Enter a valid positive amount.\n");
            } else {
                accounts[accountIndex].balance += amount;

                char message[100];
                snprintf(message, sizeof(message),
                         "Deposited Rs. %.2f", amount);
                recordTransaction(message);

                printf("Deposit successful!\n");
            }
            break;

        case 3:
            printf("Enter withdrawal amount: Rs. ");
            if (scanf("%lf", &amount) != 1)
                return 1;

            if (amount <= 0) {
                printf("Enter a valid positive amount.\n");
            } else if (amount > accounts[accountIndex].balance) {
                printf("Insufficient balance!\n");
            } else {
                accounts[accountIndex].balance -= amount;

                char message[100];
                snprintf(message, sizeof(message),
                         "Withdrew Rs. %.2f", amount);
                recordTransaction(message);

                printf("Please collect your cash.\n");
            }
            break;

        case 4: {
            int targetNumber;
            int targetIndex = -1;

            printf("Enter receiver account number: ");
            if (scanf("%d", &targetNumber) != 1)
                return 1;

            printf("Enter transfer amount: Rs. ");
            if (scanf("%lf", &amount) != 1)
                return 1;

            for (int i = 0; i < accountCount; i++) {
                if (accounts[i].accountNumber == targetNumber) {
                    targetIndex = i;
                    break;
                }
            }

            if (targetIndex == -1) {
                printf("Receiver account not found.\n");
            } else if (targetIndex == accountIndex) {
                printf("Cannot transfer to your own account.\n");
            } else if (amount <= 0) {
                printf("Enter a valid positive amount.\n");
            } else if (amount > accounts[accountIndex].balance) {
                printf("Insufficient balance!\n");
            } else {
                accounts[accountIndex].balance -= amount;
                accounts[targetIndex].balance += amount;

                char message[100];
                snprintf(message, sizeof(message),
                         "Transferred Rs. %.2f to account %d",
                         amount, targetNumber);
                recordTransaction(message);

                printf("Transfer successful!\n");
            }
            break;
        }

        case 5:
            showHistory();
            break;

        case 6:
            printf("\nAccount Holder: %s\n",
                   accounts[accountIndex].name);
            printf("Account Number: %d\n",
                   accounts[accountIndex].accountNumber);
            printf("Balance: Rs. %.2f\n",
                   accounts[accountIndex].balance);
            break;

        case 7:
            printf("Thank you for using Smart ATM!\n");
            break;

        default:
            printf("Invalid option. Try again.\n");
        }

    } while (choice != 7);

    return 0;
}
