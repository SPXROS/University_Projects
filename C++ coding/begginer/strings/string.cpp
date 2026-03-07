//String Reverser: Use std::string and its built-in methods to reverse a word.

#include <iostream>
#include <string>

int main(){

    int len;

    std::string word;

    std::cout<<"Please enter your word: ";
    std::cin>>word;
    len = word.length();
    for(int i = 0; i < len / 2; i++) {
        char temp = word[i];
        word[i] = word[len - 1 - i];
        word[len - 1 - i] = temp;
    }
    std::cout<<"Reversed word: "<<word<<std::endl;

}