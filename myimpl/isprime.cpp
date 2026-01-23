#include <iostream>

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int num1 = 0;
    int num2 = 0;

    std::cout << "Enter number range(1 10): ";
    std::cin >> num1 >> num2;

    std::cout << "Prime numbers are: ";
    for(int i = num1; i <= num2; ++i) {
        if(isPrime(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";
}