#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct Results {
    int size;
    float p1;
    float p2;
};

void addarray(int *arr, int N);
float average(int *arr, int N);
float stdev(int *arr, int N, float av);
void percentage(int *arr, int N, float av, float st,float *perc,float *perc1);
void addfile(int N, float perc, float perc1);
void show_record_count();


int main(void){

    int N;
    int *arr;
    float av = 0;
    float st = 0;
    float perc, perc1;

    srand(time(NULL));

    printf("Please enter the size of the array: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Invalid array size\n");
        return 1;
    }

    arr = malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    addarray(arr, N);

    av = average(arr, N);

    st = stdev(arr, N, av);

    percentage(arr, N, av,st, &perc, &perc1);

    addfile(N, perc, perc1);

    show_record_count();

    free(arr);
    return 0;
}

void addarray(int *arr, int N){
    for (int i = 0; i < N; i++) {
        arr[i] = (rand() % 26) + 25;
    }
}

float average(int *arr, int N){
    int sum = 0;

    for(int i = 0; i<N; i++){
        sum += arr[i];
    }
    return (float)sum/(float)N;
}

float stdev(int *arr, int N, float av){
    if (N < 2) return 0.0;

    float sum = 0.0;

    for(int i = 0; i < N; i++){
        float diff = arr[i] - av;
        sum += diff * diff;
    }

    return sqrt(sum / (N - 1));
}

void percentage(int *arr, int N, float av, float st,float *perc,float *perc1){

    float low1  = av - st;
    float high1 = av + st;

    float low2  = av - 2*st;
    float high2 = av + 2*st;

    int cnt1 = 0;
    int cnt2 = 0;

    for(int i = 0; i < N; i++){
        if(arr[i] >= low1 && arr[i] <= high1){
            cnt1++;
        }
        if(arr[i] >= low2 && arr[i] <= high2){
            cnt2++;
        }
    }

    *perc = (cnt1 * 100.0) / N;
    *perc1 = (cnt2 * 100.0) / N;

    printf("average +- stdev: %.2f%%\n", (cnt1 * 100.0) / N);
    printf("average +- 2*stdev: %.2f%%\n", (cnt2 * 100.0) / N);
}

void addfile(int N, float perc, float perc1) {
    FILE *fp = fopen("percent.dat", "a");
    if (!fp) {
        printf("Error while opening file.\n");
        return; 
    }

    struct Results res;
    res.size = N;
    res.p1 = perc;
    res.p2 = perc1;

    fprintf(fp, "Size: %d, P1: %.2f%%, P2: %.2f%%\n", res.size, res.p1, res.p2);

    fclose(fp);
}

void show_record_count() {
    FILE *fp = fopen("percent.dat", "r");
    if (fp == NULL) {
        printf("\nTotal records in file: 0\n");
        return;
    }

    int count = 0;
    char line[200];

    while (fgets(line, sizeof(line), fp) != NULL) {
        count++;
    }

    printf("\nTotal records in file: %d\n", count);

    fclose(fp);
}