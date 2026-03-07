/* Uppercase Converter: Read a line of text using getline() 
and convert it entirely to uppercase using a for loop.*/

#include <iostream>
#include <string>

using string = std::string;

int main(){
    
    string line;
    int len;
    

    std::cout<<"Please enter your line: ";
    std::getline(std::cin, line);

    len = line.length();

    for(int i = 0; i< len; i++){
        if(line[i]>='a' && line[i]<='z'){
            line[i] = toupper(line[i]);
        }
    }

    std::cout<<"Uppercase word: " <<line;

    return 0;
}