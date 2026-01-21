#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x;
    float y;
    float z;
} Vector;

// Function prototype
void check_magnitude(Vector *point, int N, float threshold);

int main(void) {
    Vector *point = NULL;
    int N;
    float threshold;

    printf("Please enter number of vectors: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Invalid number of vectors.\n");
        return 1;
    }

    point = (Vector *)malloc(N * sizeof(Vector));
    if (point == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        printf("Enter x, y, z for vector %d: ", i + 1);
        scanf("%f %f %f", &point[i].x, &point[i].y, &point[i].z);
    }

    printf("Enter a threshold for the magnitude: ");
    scanf("%f", &threshold);

    check_magnitude(point, N, threshold);

    free(point);
    return 0;
}

void check_magnitude(Vector *point, int N, float threshold) {
    for (int i = 0; i < N; i++) {
        float m = sqrt(pow(point[i].x, 2) + pow(point[i].y, 2) + pow(point[i].z, 2));
        if (m > threshold) {
            printf("Vector (%.2f, %.2f, %.2f) has magnitude %.2f (Exceeds %.2f)\n", 
                    point[i].x, point[i].y, point[i].z, m, threshold);
        }
    }
}