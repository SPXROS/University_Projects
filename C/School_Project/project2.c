#include <stdio.h>

int algo1(int n);
int algo2(int n);
int checkEquality(int n);

int main() {
    int n;

    printf("Give n: ");
    scanf("%d", &n);

    int result = checkEquality(n);

    if (result == 0) {
        printf("The equality holds for n = %d\n", n);
    } else {
        printf("The equality does NOT hold for n = %d\n", n);
    }

    return 0;
}

int algo1(int n) {
    int res = 0;   // IMPORTANT: initialize!
    for (int i = 1; i <= n; i++) {
        res += i * i;
    }
    return res;
}

int algo2(int n) {
    int res = (n * (n + 1) * (2 * n + 1)) / 6;
    return res;
}

int checkEquality(int n) {
    int res1 = algo1(n);
    int res2 = algo2(n);

    if (res1 == res2)
        return 0;
    else
        return -1;
}