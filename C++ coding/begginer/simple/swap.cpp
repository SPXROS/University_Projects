#include <iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10;
    int y = 5;

    std::cout << "first: x = " << x << ", y = " << y << std::endl;
    swap(x, y);

    std::cout << "after: x = " << x << ", y = " << y << std::endl;

    return 0;
}