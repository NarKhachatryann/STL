#include <iostream>

void fibonacci(int& num) {
    if(num == 0) {
        num = 0;
        return;
    }
    if(num == 1) {
        num = 1;
        return;
    }

    int first = 0;
    int second = 1;

    for(int i = 1; i <= num; ++i) {
        int res = second + first;
        first = second;
        second = res;
    }
    num = first;
}

int main() {
    int num = 0;
    std::cout << "Enter number for calculate fibonacci number: ";
    std::cin >> num;

    fibonacci(num);
    std::cout << "Result is:" << num << std::endl;

    return 0;
}