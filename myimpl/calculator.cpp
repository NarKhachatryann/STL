#include <iostream>

int main() {
    double num1, num2;
    char operation;
    
    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter operation(+ - * /): ";
    std::cin >> operation;
    
    std::cout << "Enter second number: ";
    std::cin >> num2;

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