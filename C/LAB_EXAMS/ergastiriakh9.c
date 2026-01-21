/*Outlier Detector: Dynamically allocate an array of $N$ integers (user input).

Fill it with random numbers (1-100).

Calculate the average and identify numbers that are more than 2 standard deviations away.*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void fillarr(int *arr, int N);
double average(int *arr, int N);
void deviation(int *arr, int N, double mean);

int main(void){
    int N;
    double mean = 0;

    srand(time(NULL));

    printf("Please enter size of array: ");
    if(scanf("%d", &N) != 1) return 1;

    int *arr = malloc(N * sizeof(int));
    if(!arr){
        printf("Failed to allocate memory\n");
        return 1;
    }

    fillarr(arr, N);
    mean = average(arr, N);
    printf("Mean: %.2f\n", mean);
    
    deviation(arr, N, mean);

    free(arr);
    return 0;
}

void fillarr(int *arr, int N){
    for(int i = 0; i < N; i++){
        arr[i] = (rand() % 100) + 1;
    }  
}

double average(int *arr, int N){
    double sum = 0;
    for(int i = 0; i < N; i++){
        sum += arr[i];
    }
    return sum / N;
}

void deviation(int *arr, int N, double mean){
    double sum = 0;
    for(int i = 0; i < N; i++){
        sum += pow((arr[i] - mean), 2);
    }

    double sigma = sqrt(sum / N);
    printf("Standard Deviation (sigma): %.2f\n", sigma);

    printf("Outliers: ");
    for(int j = 0; j < N; j++){
        if(fabs(arr[j] - mean) > 2 * sigma){
            printf("%d ", arr[j]);
        }
    }   
    printf("\n");
}