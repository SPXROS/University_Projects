#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));

    int guess = 0;
    int tries = 0;
    int min = 1;
    int max = 100;
    int answer = (rand() % (max-min +1)) + min;

    printf("Welcome to the Guessing Game!\n");

    do{ 
        printf("Guess a number between %d and %d: ", min, max);
        scanf("%d", &guess);
        tries++;
        if(guess < answer){
            printf("Too low! Try again.\n");
        } else if(guess > answer){
            printf("Too high! Try again.\n");
        }
        else{
            printf("Congratulations! You guessed the correct number.\n");
        }

    }while (guess != answer);

    printf("The answer is %d\n:", answer);
    printf("You guessed it in %d tries\n", tries);

    return 0;


}
