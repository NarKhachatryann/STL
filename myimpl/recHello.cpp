#include <iostream>

int print(int num) {
    if(num == 0) return 0;

    std::cout << "Hello World!" << std::endl;
    --num;
    print(num);
    return 0;
}

int main() {
    int num = 0;
    std::cout << "Enter how many times must program printing: ";
    std::cin >> num;

    print(num);
}