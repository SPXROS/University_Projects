#include <stdio.h>
#include <stdlib.h>

// Changed to int* to match the flat allocation
int *rowSum(int *arr, int R, int C);

int main(void){
    int R, C;
    printf("Enter The rows and columns: ");
    scanf("%d %d", &R, &C);

    int *arr = (int *)malloc(R * C * sizeof(int));
    if(arr == NULL) return 1;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            arr[i * C + j] = (rand() % 90) + 10;
            printf("%d ", arr[i * C + j]);
        }
        printf("\n");
    }

    int *sums = rowSum(arr, R, C);

    if(sums != NULL) {
        printf("\nRow Sums: ");
        for(int i = 0; i < R; i++) printf("%d ", sums[i]);
        free(sums);
    }

    free(arr); 
    return 0;
}

int *rowSum(int *arr, int R, int C) {
    int *result = malloc(R * sizeof(int)); 
    if(result == NULL) return NULL;

    for(int i = 0; i < R; i++) {
        int current_row_total = 0;
        for(int j = 0; j < C; j++) {
            current_row_total += arr[i * C + j];
        }
        result[i] = current_row_total;
    }

    return result; 
}