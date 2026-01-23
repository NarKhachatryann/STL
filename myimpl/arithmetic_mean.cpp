#include <iostream>

double arithmetic_mean(double a, double b, double c) {
    return (a + b + c) / 3.0;
}

int main() {
    double a, b, c;
    std::cout << "Enter three numbers for arithmetic mean: " << std::endl;
    std::cin >> a >> b >> c;
    std::cout << "Arithmetic mean: " << arithmetic_mean(a, b, c) << std::endl;

    return 0;
}