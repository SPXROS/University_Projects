#include <iostream>
#include <vector>

int main() {
    char answ;
    int inputNum;
    std::vector<int> numlist;

    do {
        std::cout << "Please add a number to the list: ";
        std::cin >> inputNum;

        numlist.push_back(inputNum);

        std::cout << "Want to continue Y/N: ";
        std::cin >> answ;

    } while (answ != 'n' && answ != 'N');

    std::cout << "\nYour list contains " << numlist.size() << " numbers: ";
    for (int n : numlist) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;

}
