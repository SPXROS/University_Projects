#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 30

void fillarr(int *arr, int count);
int findMedian(int *arr, int count);

int main(void) {
    srand(time(NULL));

    int *arr = malloc(N * sizeof(int));
    if(!arr) {
        printf("Failed to allocate memory");
        return 1;
    }

    fillarr(arr, N);
    
    int med = findMedian(arr, N);

    int cnt_greater = 0;
    int cnt_positive = 0;

    for(int i = 0; i < N; i++) {
        if(arr[i] > med) {
            cnt_greater++;
        } 
        if(arr[i] > 0) {
            cnt_positive++;
        }
    }

    printf("Median Value: %d\n", med);
    printf("Count of elements > median: %d\n", cnt_greater);
    printf("Total positive numbers percentage: %.2f%%\n", ((float)cnt_positive / N) * 100.0);

    free(arr);
    return 0;
}

void fillarr(int *arr, int count) {
    for(int i = 0; i < count; i++) {
        arr[i] = (rand() % 201) - 100;
    }
}

int findMedian(int *arr, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return (arr[count / 2] + arr[(count / 2) - 1]) / 2;
}