#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000

void bubbleSort(int pin[], int n);

void selectionSort(int pin[], int n);

int main(){
    int pin1[N], pin2[N];

    srand(time(NULL));

    for(int i = 0; i < N; i++){
        pin1[i] = rand() % 10000;
        pin2[i] = pin1[i];
    }

    clock_t start = clock();
    bubbleSort(pin1, N);
    clock_t end = clock();
    float bubbleTime = (float)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    selectionSort(pin2, N);
    end = clock();
    float selectionTime = (float)(end - start) / CLOCKS_PER_SEC;

    printf("Bubble Sort Time: %f seconds\n", bubbleTime);
    printf("Selection Sort Time: %f seconds\n", selectionTime);

    return 0;
}

void selectionSort(int pin[], int n){
    int min, temp;
    for(int i = 0; i < n-1; i++){
        min = i;
        for(int j = i+1; j < n; j++){
            if(pin[j] < pin[min]){
                min = j;
            }
        }
        temp = pin[i];
        pin[i] = pin[min];
        pin[min] = temp;
    }
}

void bubbleSort(int pin[], int n) {
    int temp;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(pin[j] > pin[j+1]){
                temp = pin[j];
                pin[j] = pin[j+1];
                pin[j+1] = temp;
            }
        }
    }
}