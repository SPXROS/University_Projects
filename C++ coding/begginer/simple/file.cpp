#include <iostream>

namespace first{
    int x = 1;
}

int main(){

    using std::cout;

    int x = 0;

    cout << x;
    cout << first::x;

    return 0;
}

#include <iostream>
#include <vector>

//typedef std::string text_t;
//typedef int number_t;
using text_t = std::string;
using number_t = int;

//typedef std::vector<std::pair<std::string, int>> pairlist_t;

int main(){

    //pairlist_t pairlist;
    text_t firstName = "Spi";
    number_t age = 21;

    std::cout<< firstName<< '\n';
    std::cout<< age<< '\n';


    return 0;
}