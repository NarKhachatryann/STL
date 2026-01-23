#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    double num1 = 0, num2 = 0;
    char operation;
    std::string input;
    
    std::cout << "Enter calculation (3 + 4): ";
    std::getline(std::cin, input);

    std::stringstream ss(input);
    ss >> num1 >> operation >> num2;

    switch (operation)
    {
    case '+':
        std::cout << "Result: " << (num1 + num2) << std::endl;
        break;
    case '-':
        std::cout << "Result: " << (num1 - num2) << std::endl;
        break;
    case '*':
        std::cout << "Result: " << (num1 * num2) << std::endl;
        break;
    case '/':
        std::cout << "Result: " << (num1 / num2) << std::endl;
        break;
    default:
        std::cout << "Invalid operation!" << std::endl;
        break;
    }
}