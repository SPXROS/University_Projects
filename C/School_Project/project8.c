#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

double mean(int pin[N]);

void sort(int pin[N]);

int main(){

    int pin[N] = {};
    double mean1 = 0;

    srand(time(NULL));

    for(int i = 0; i<100; i++){
        pin[i] = ((rand() % 61) + 20);
    }

    mean1 = mean(pin);

    sort(pin); 

    printf("Your mean is %.2lf\n", mean1);
    printf("Your min is %d\n", pin[0]);
    printf("Your max is %d\n", pin[N-1]);


    return 0;
}

double mean(int pin[N]){

    double sum = 0;

    for(int i = 0; i<N; i++){
        sum += pin[i];
    }

    return sum/N;

}


void sort(int pin[N]){
    int temp;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N-1-i; j++){
            if(pin[j] > pin[j+1]){
                temp = pin[j];
                pin[j] = pin[j+1];
                pin[j+1] = temp;
            }
        }
    }
}
