#include <iostream>
#include <vector>

long fib(int n, std::vector<long>& arr) {
    if(arr[n] != -1) return arr[n];
    if(n == 0) return arr[n] = 0;
    if(n == 1) return arr[n] = 1;

    return arr[n] = fib(n - 1, arr) + fib(n - 2, arr);
}

int main() {
    int num = 0;
    std::cout << "Enter number for fibonachi: ";
    std::cin >> num;
    std::vector<long> arr(num + 1, -1);

    std::cout << "Fibonachi result: " << fib(num,arr) << std::endl;
}