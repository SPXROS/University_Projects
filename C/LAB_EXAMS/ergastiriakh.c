#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void readArray(double *arr, int N, double A, double B);
void multiplyRandom(double *arr, int N);
void multiplyAll(double *arr, int N);
void printArray(double *arr, int N);

int main(void) {

    srand(time(NULL));

    int N;
    double A, B;
    double *arr;

    do {
        printf("Enter A and B (B > A): ");
        scanf("%lf %lf", &A, &B);
    } while (B <= A);

    do {
        printf("Enter N (N > 10): ");
        scanf("%d", &N);
    } while (N <= 10);

    arr = malloc(N * sizeof(double));
    if (!arr) {
        printf("Memory allocation failed\n");
        return 1;
    }

    readArray(arr, N, A, B);
    multiplyRandom(arr, N);
    multiplyAll(arr, N);
    printArray(arr, N);

    free(arr);
    return 0;
}

void readArray(double *arr, int N, double A, double B) {
    for (int i = 0; i < N; i++) {
        do {
            printf("Enter number %d: ", i + 1);
            scanf("%lf", &arr[i]);
        } while (arr[i] < A || arr[i] > B);
    }
}

void multiplyRandom(double *arr, int N) {

    int used[N];
    for (int i = 0; i < N; i++)
        used[i] = 0;

    int count = 0;

    while (count < N / 2) {
        int idx = rand() % N;
        if (!used[idx]) {
            arr[idx] *= 2;
            used[idx] = 1;
            count++;
        }
    }
}

void multiplyAll(double *arr, int N) {
    for (int i = 0; i < N; i++)
        arr[i] *= 2;
}

void printArray(double *arr, int N) {

    double min = arr[0], max = arr[0];

    printf("\nArray elements:\n");
    for (int i = 0; i < N; i++) {
        printf("%6.2lf\n", arr[i]);
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    printf("\nMinimum: %.2lf\nMaximum: %.2lf\n", min, max);
}
