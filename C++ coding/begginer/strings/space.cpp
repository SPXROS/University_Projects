//The Spacer: Take a string and print it with a space between every character.

#include <iostream>
#include <string>
using string = std::string;

int main(){

    int len;

    string phrase;

    std::cout<<"Enter your phrase: ";
    std::getline(std::cin, phrase); // todo: Make sure to always use getline in strings.

    len = phrase.length();

    for(int i = 0; i<len; i++){
        std::cout << phrase[i];
        std::cout<<" ";
    }

    return 0;
}