
//Greeting: Prompt for a name and say hello using cin and cout

#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;

    cout << "Please enter your full name: ";
    
    getline(cin, name); 
    
    cout << "Hello, " << name << "!" << endl;

    return 0;
}