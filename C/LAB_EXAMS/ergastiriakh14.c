#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int N;
    int sum;
} ResultData;

int powerSum(int *arr, int N);

int main(void) {
    int N = 0;
    srand(time(NULL));

    printf("Please enter the size of the array: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    int *arr = malloc(N * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        arr[i] = (rand() % 10) + 1;
    }

    ResultData data;
    data.N = N;
    data.sum = powerSum(arr, N);

    FILE *fout = fopen("power.dat", "wb");
    if (!fout) {
        printf("Error opening file.\n");
        free(arr);
        return 1;
    }

    fwrite(&data, sizeof(ResultData), 1, fout);

    printf("Success! Saved N=%d and Sum=%d to power.dat\n", data.N, data.sum);

    fclose(fout);
    free(arr);
    return 0;
}

int powerSum(int *arr, int N) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += (arr[i] * arr[i]) + i; 
    }
    return sum;
}