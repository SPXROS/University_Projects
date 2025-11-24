#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define N 6

int main(){

    int pin[N];
    int i, j, num;
    bool unique;

    srand(time(NULL));

     for(i = 0; i < N; i++) {
        do {
            unique = true;
            num = rand() % 49 + 1;

            for(j = 0; j < i; j++) {
                if(pin[j] == num) {
                    unique = false;
                    break;
                }
            }
        } while(!unique);

        pin[i] = num;
    }

    for(i = 0; i < 3; i++) {
        printf("|%2d| ", pin[i]);
    }

    printf("\n---------------\n");

    for(i = 3; i < N; i++) {
        printf("|%2d| ", pin[i]);
    }
    
    printf("\n---------------");

    return 0;
}