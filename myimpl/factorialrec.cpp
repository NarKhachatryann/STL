#include <iostream>

int fact(int n) {
    if(n <= 1) return 1;

    return n * fact(n - 1);
}

int main() {
    int num = 0;

    std::cout << "Enter your number for factorial: ";
    std::cin >> num;

    std::cout << "Result is: " << fact(num) << std::endl;

    return 0;
}