//The Calculator: Perform math using std::cin

#include <iostream>
#include <iomanip>

double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double division(double x, double y);

int main(){
    
    double x, y;
    char choice;
    double result  (0);  
    std::cout<<"Please enter your number: ";
    std::cin>> x;
    std::cout<<"Please enter another number: ";
    std::cin>> y;

    do {
        std::cout << "Select operator (*, /, +, -): ";
        std::cin >> choice;
    } while (choice != '*' && choice != '/' && choice != '+' && choice != '-');

    switch (choice) {
        case '+': result = add(x, y); break;
        case '-': result = subtract(x, y); break;
        case '*': result = multiply(x, y); break;
        case '/': 
            if (y == 0) {
                std::cerr << "Error: Division by zero!" << std::endl;
                return 1;
            }
            result = division(x, y); 
            break;
    }
    
    std::cout << "Your answer is: " << std::fixed << std::setprecision(2) << result << std::endl;;

    return 0;
}

double division(double x, double y){
    return (x/y);
}

double multiply(double x, double y){
    return (x*y);
}

double add(double x, double y){
    return (x+y);
}
double subtract(double x, double y){
    return (x-y);
}

/*
*Things i learned from this:
1.Always use std::endl not '\n'
2.switch case is better instead of nested ifs.
3.C is different to C++ regarding the %f.2 in C++ we use the iomanip library 
and then use std::fixed and std::setprecision(2)
4. For errors we can use std::cerr
That's it rest is similar to C.

Grade for 2nd program : 8/10 *.

*needed some help with ai on 1,3,4


*/