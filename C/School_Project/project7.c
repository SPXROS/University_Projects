#include <stdio.h>
#define e 1e-6
#define ABS(x) ((x) > 0 ? (x) : -(x))

double mysqrt(double a);

int main() {
    double a;
    double res = 0;

    printf("Enter your number to find the sqrt: ");
    scanf("%lf", &a);

    res = mysqrt(a);

    printf("\nThe sqrt of %lf is %.6lf\n", a, res);

    return 0;
}

double mysqrt(double a) {
    double x0 = a;
    double x1;

    while(1){
        x1 = 0.5 * (x0 + a / x0);

        if(ABS(x1 - x0) < e) {
            break;
        }

        x0 = x1;
    }

    return x1;
}
