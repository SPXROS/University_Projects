/*
* Double Trouble: Input two doubles and print their product with exactly 2 decimal places using 
* std::fixed and setprecision
*/

#include <iostream>
#include <iomanip>

int main(){

    double num,num1;

    std::cout<<"Please enter your number: ";
    std::cin>>num;
    std::cout<<"Please enter another number: ";
    std::cin>>num1;

    std::cout<<"Your number is: "<<std::fixed << std::setprecision(2) << num;
    std::cout<<" & "<<std::fixed << std::setprecision(2) << num1<<std::endl;


    return 0;
}
