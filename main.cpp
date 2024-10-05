//
// Created by lfe on 02/10/2024.
//

#include <iostream>

int main() {
    std::cout << "hello" << std::endl;
    int option;
    std::cout << "input your option:" << std::endl;
    std::cin >> option;
    switch(option) {
        case "find":
            std::cout << "Finding cities" << std::endl;
            return 0;
        case "save":
            std::cout << "Saving cities" << std::endl;
            return 0;
        case "exit":
            std::cout << "Exiting" << std::endl;
            break;
        default:
            break;
    }
}