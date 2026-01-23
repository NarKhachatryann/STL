#include <iostream>

#define f(a, b) (a > b) ? a : b

int main() {
    int num1 = 0, num2 = 0;
    std::cout << "Enter 2 numbers to comapre: " << std::endl;
    std::cin >> num1 >> num2;
    int res = f(num1, num2);
    std::cout << res << std::endl;
}