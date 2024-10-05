#include "add.h" //
#include <iostream>
#include <string>

int main() {
    std::cout << "hello" << std::endl;

    char option;
    std::cout << "input your option:" << std::endl;
    std::cin >> option;

    switch(option) {
        case 'f':
            std::cout << "Finding cities" << std::endl;
            return 0;
        case 's':
            std::cout << "Saving cities" << std::endl;
            return 0;
        case 'e':
            std::cout << "Exiting" << std::endl;
            break;
        case 'a':
            std::cout << "the sum of 3 and 4 is " << add(3,4) <<  '\n' <<  std::endl;
            return 0;
        default:
            break;
    }
}