#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int computer();

char result(char ch, char ch1);

int main(){

    char ch, ch1;
    int x;
    char res;

    srand(time(NULL));

    printf("--- WELCOME TO ROCK PAPER SCISSORS ---\n");
    printf("Choose one of the following:\n(R) Rock\n(P) Paper\n(S) Scissors\n");

    do{

        printf("*ENTER A VALID LETTER FROM R or P or S: \n");
        
        ch = getchar();

        ch = toupper(ch);

        while (getchar() != '\n');



        switch(ch){
            case 'R':
                printf("You chose Rock.\n"); break;
            case 'P':
                printf("You chose Paper.\n"); break;
            case 'S':
                printf("You chose Scissors.\n"); break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }while (ch != 'R' && ch != 'P' && ch != 'S');

    x = computer();

    if(x == 1){
        ch1 = 'R';
        printf("Computer chose Rock\n");
    } else if(x == 2){
        ch1 = 'P';
        printf("Computer chose Paper\n");
    } else{
        ch1 = 'S';
        printf("Computer chose Scissors\n");
    }


    result(ch, ch1);
    

    return 0;
}

int computer(){
    int x;

    x = ((rand() % 3) + 1);

    return x;
}

char result(char ch, char ch1) {
    if (ch == ch1) {
        printf("It's a draw!\n");
        return 'D';
    }

    if ((ch == 'R' && ch1 == 'S') ||
        (ch == 'P' && ch1 == 'R') ||
        (ch == 'S' && ch1 == 'P')) {
        printf("YOU WON!!!\n");
        return 'W';
    }

    printf("You lost! Better luck next time!\n");
    return 'L';
}
