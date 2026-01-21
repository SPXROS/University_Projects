#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    float r;
    float theta;
} Polar;

typedef struct {
    float x;
    float y;
    float distance; 
    float r;
    float t;        
} Point;

void addnums(Point *arr, int n);
void calculate_distances(Point *arr, int n);
Polar cart2polar(float x, float y);
int findmax(Point *arr, int n);

int main(void) {
    int n;
    int max = 0;
    srand(time(NULL));

    FILE *fp;

    fp = fopen("max.dat", "a");
    if(!fp){
        printf("Error while opening file\n");
        fclose(fp);
        return 1;
    }
    printf("Please enter the size of the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    Point *arr = (Point *) malloc(n * sizeof(Point));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    addnums(arr, n);

    calculate_distances(arr, n);

    for (int i = 0; i < n; i++) {
        Polar result = cart2polar(arr[i].x, arr[i].y);
        
        arr[i].r = result.r;
        arr[i].t = result.theta;
    }

    printf("\n%-10s %-15s %-15s %-10s\n", "Point", "Coords (x,y)", "Distance", "Polar (r, th°)");
    printf("------------------------------------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("%-10d (%.1f, %.1f)    %-15.2f (%.2f, %.2f°)\n", 
               i + 1, arr[i].x, arr[i].y, arr[i].distance, arr[i].r, arr[i].t);
    }

    max = findmax(arr, n);

    printf("Point with maximum distance is (%.1f, %.1f) : %.2f \n", arr[max].x, arr[max].y, arr[max].distance);

    fprintf(fp,"Point with maximum distance is (%.1f, %.1f) : %.2f \n", arr[max].x, arr[max].y, arr[max].distance);

    free(arr);
    fclose(fp);
    return 0;
}

void addnums(Point *arr, int n) {
    for(int i = 0; i < n; i++) {
        arr[i].x = (float)(rand() % 10) + 1;
        arr[i].y = (float)(rand() % 10);
    }
}

void calculate_distances(Point *arr, int n) {
    for(int i = 0; i < n; i++) {
        arr[i].distance = sqrt(pow(arr[i].x, 2) + pow(arr[i].y, 2));
    }
}

Polar cart2polar(float x, float y) {
    Polar p;
    p.r = sqrt(x*x + y*y);
    
    float radians = atan2(y, x);

    p.theta = radians * (180.0 / M_PI); 
    
    return p;
}

int findmax(Point *arr, int n){

    int max = 0;

    for(int i = 1; i<n; i++){
        if(arr[max].distance < arr[i].distance){
            max = i;
        }
    }

    return max;

}