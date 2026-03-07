//*Namespace Practice: Create two functions with the same name in different namespaces.

#include <iostream>

namespace Room1{
    void greet(){
        std::cout<<"Welcome to Room 1!"<<std::endl;
    }
}

namespace Room2{
    void greet(){
        std::cout<<"Welcome to Room 2!"<<std::endl;
    }
}

int main(){

    Room1::greet();
    Room2::greet();

    return 0;
}