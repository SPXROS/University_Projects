#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int N;
    float max;
    float min;
    float diff;
}data;

float range(float *arr, int N, float *max, float *min);

int main(void){

    int N;
    float max,min;
    srand(time(NULL));

    do {
        printf("Please enter a size for the array (5-50): ");
        if (scanf("%d", &N) != 1) {
            while(getchar() != '\n');
            continue;
        }
    } while (N > 50 || N < 5);

    float *arr = malloc(N * sizeof(float));
    
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    for(int i = 0; i<N; i++){
        arr[i] = (float)(rand() % 100) * ((float)(rand()%100) / 100.0);
    }

    float diff = range( arr , N, &max, &min);

    data log;
    log.N = N;
    log.max = max;
    log.min = min;
    log.diff = diff;

    FILE *fp;
    fp = fopen("log.dat" , "a");
    if(!fp){
        return 1;
    }

    fprintf(fp, "N: %2d | Max: %7.2f | Min: %7.2f | Diff: %7.2f\n", log.N, log.max, log.min, log.diff);

    fclose(fp);
    free(arr);
    return 0;
}

float range(float *arr, int N, float *max, float *min) {
    *max = arr[0];
    *min = arr[0];

    for (int i = 1; i < N; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
    return (*max - *min);
}