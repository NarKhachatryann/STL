#include <iostream>

int main() {
    int n;
    int res = 1;
    std::cout << "Enter a non negative integer: ";
    std::cin >> n;

    if(n < 0) {
        std::cout << "Invalid input!!";
    }

    while (n > 0) {
        res *= n;
        n--;
    }

    std::cout << "Factorial: " << res << std::endl;
}