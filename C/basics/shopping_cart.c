/*
 * File: shopping_cart.c
 * Description: Simple shopping cart program that calculates total price
 * Language: C
 */

#include <stdio.h>
#include <string.h>

int main(void) {

    //Shopping Cart Program

    char item[50] = "";
    float price = 0.0;
    int quantity = 0;
    char currency = '$';
    float total = 0.0f;

    printf("Enter the item you would like to purchase: ");
    fgets(item, sizeof(item), stdin);
    item[strlen(item) - 1] = '\0';  // Remove newline character

    printf("What is the price for each item? ");
    scanf("%f", &price);

    printf("How many items would you like to purchase? ");
    scanf("%d", &quantity);

    total = price * quantity;

    printf("\nYou have purchased: %d %s/s\n", quantity, item);
    printf("Your total is: %c%.2f", currency, total);

    return 0;
}
