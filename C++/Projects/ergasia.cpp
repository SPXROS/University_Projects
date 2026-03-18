// A.M. : 25390025

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 10

typedef struct points{
    int x;
    int y;
}Points;

typedef struct pointsReal {
    double x;
    double y;
} PointsReal;

Points& Biggest_point(Points *pin, int num);

PointsReal& Biggest_point(PointsReal *pin, int num);

int main(){
    
    srand(time(NULL));
    Points *pin;
    PointsReal *pin1;
    
    pin = (Points *) malloc(N * sizeof(Points));
    pin1 = (PointsReal *) malloc(N * sizeof(PointsReal));

    if (!pin) {
        std::cout << "Σφαλμα μνημης!" << std::endl;
        return 1;
    }
    if (!pin1) {
        std::cout << "Σφαλμα μνημης!" << std::endl;
        return 1;
    }

    for(int i = 0; i<N; i++){
        pin[i].x = (rand() % 100);
        pin[i].y = (rand() % 100);
    }

    for(int i = 0; i<N; i++){
        pin1[i].x = (double)(rand() % 100) / 100.0 + (rand() % 100);
        pin1[i].y = (double)(rand() % 100) / 100.0 + (rand() % 100);
    }

    Points& biggest_P = Biggest_point(pin, N);
    PointsReal& biggest_RP = Biggest_point(pin1, N);

    std::cout << "Μεγαλυτερο σημειο: " << biggest_P.x << " "<< biggest_P.y << std::endl;
    std::cout << "Μεγαλυτερο πραγματικο σημειο: " << biggest_RP.x << " "<< biggest_RP.y << std::endl;
    

    free(pin);
    free(pin1);

    return 0;
}


Points& Biggest_point(Points *pin, int num){
    int biggest_point = 0;
    int temp;
    int temp_num = 0;
    for(int i = 0; i<num; i++ ){
        temp = sqrt(pow(pin[i].x, 2) + pow(pin[i].y, 2) );
        if(temp > biggest_point){
            biggest_point = temp;
            temp_num = i;
        }
    }
    return pin[temp_num];
}

PointsReal& Biggest_point(PointsReal *pin, int num){
    double biggest_point = 0;
    double temp;
    int temp_num = 0;
    for(int i = 0; i<num; i++ ){
        temp = sqrt(pow(pin[i].x, 2) + pow(pin[i].y, 2) );
        if(temp > biggest_point){
            biggest_point = temp;
            temp_num = i;
        }
    }
    return pin[temp_num];
}
