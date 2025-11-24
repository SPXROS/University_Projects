#include <stdio.h>
#define kubos(x) (x*x*x)
#define ABS(x) ((x)>0 ? (x) : (-x))

int elenxos(int x);

int main(){

    int x;
    int res = 0;

    printf("Enter number to check for armstrong number: ");
    scanf("%d", &x);

    res = elenxos(x);

    if(res == x){
        printf("\n%d is an armstrong number.", x);
    }else if(res == 0){
        printf("\nYou entered 0. (NON VALID)");
    }else{
        printf("\n%d is not an armstrong number.", x);
    }
    
    return 0;
}

int elenxos(int x){

    int res = 0;
    int digit;

    x = ABS(x);

    while(x>0){
       digit = x % 10;
       x = x / 10;
       res += kubos(digit);
    }

    return res;
}