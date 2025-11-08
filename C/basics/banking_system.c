#include <stdio.h>

void checkBalance(float balance);
float deposit();
float withdraw(float balance);

int main(){

    int choice = 0;
    float balance = 0.0f;

    printf("\nWelcome to the Banking System!\n");

    do{
        printf("Select an option:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance += deposit();
                break;
            case 3:
                balance -= withdraw(balance);
                break;
            case 4:
                printf("Exiting the Banking System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    
    }while (choice != 4);


    return 0;
}

void checkBalance(float balance){
    printf("Your current balance is: $%.2f\n", balance);
}

float deposit(){

    float amount= 0.0f;

    printf("\nEnter amount to deposit: $");
    scanf("%f", &amount);

    if(amount < 0){
        printf("Invalid amount. Deposit failed.\n");
        return 0.0f;

    }
    else {
        printf("Successfully deposited $%.2f\n", amount);
        return amount;
    }
}

float withdraw(float balance){
    float amount = 0.0f;
    printf("\nEnter amount to withdraw: $");
    scanf("%f", &amount);
    if(amount < 0){
        printf("Invalid amount. Withdrawal failed.\n");
        return 0.0f;
    }
    else if(amount > balance){
        printf("Insufficient funds. Withdrawal failed.\n");
        return 0.0f;
    }
    else{
        printf("Successfully withdrew $%.2f\n", amount);
        return amount;
    }
}

