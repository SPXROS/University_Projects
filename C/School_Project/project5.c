#include <stdio.h>
#define ABS(x) ((x)>0 ? (x) : (-x))

int Sum(int num);

int main(){

    int num;
    int sum = 0;

    printf("Enter your number: ");
    scanf("%d", &num);
    
    sum = Sum(num);

    printf("Your sum is %d", sum);

    return 0;
}

int Sum(int num){
    int sum = 0;

    num = ABS(num);

    while (num > 0) {
        int digit = num % 10;
        num = num / 10;
        sum += digit;
    }
    return sum;
}