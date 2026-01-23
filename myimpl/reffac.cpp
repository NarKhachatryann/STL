#include <iostream>

void factorial(int& num) {
    int count = 1;
    for(int i = 1; i <= num; ++i) {
        count *= i;
    }
    num = count;
}

int main() {
    int num = 0;
    std::cout << "Enter number for calculate factorial: ";
    std::cin >> num;

    factorial(num);
    std::cout << "Result is: " << num << std::endl;
}