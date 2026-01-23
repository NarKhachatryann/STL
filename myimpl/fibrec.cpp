#include <iostream>

int fib(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib(n - 2) + fib(n - 1);
}

int main() {
    int num = 0;
    std::cout << "Enter number for fibonachi: ";
    std::cin >> num;

    std::cout << "Fibonachi result: " << fib(num) << std::endl;
}