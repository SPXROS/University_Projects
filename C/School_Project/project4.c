#include <stdio.h>
#include <math.h>

float diakrinousa(int a, int b, int c);

float luseis1(float D, int a, int b);

float luseis2(float D, int a, int b);

int main(){

    int a, b, c;
    float D, x1, x2;

    printf("Enter the coefficients a, b, c for ax^2 + bx + c:\n");
    scanf("%d %d %d", &a, &b, &c);

    if (a == 0) {
        printf("This is NOT a quadratic equation (a = 0).\n");
        return -1;
    }

    D = diakrinousa(a,b,c);
    
    if (D > 0) {
        x1 = luseis1(D,a,b);
        x2 = luseis2(D,a,b);
    } else if (D == 0) {
        x1 = luseis1(D,a,b);
        x2 = x1;
    } else {
        printf("Den uparxoun times x1 x2\n");
    }
    
    return 0;
}


float diakrinousa(int a, int b, int c){

    float res = 0;

    res = (float)(b*b) - (4*(float)a*(float)c);

    return res;
}


float luseis1(float D, int a, int b){
    float res;

    res = (-b + sqrt(D))/ (2*a);

    return res;

}

float luseis2(float D, int a, int b){
    
    float res;

    res = (-b - sqrt(D))/ (2*a);

    return res;

}