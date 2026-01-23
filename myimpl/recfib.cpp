#include <iostream>
#include <vector>

int fib(int n, std::vector<int>& arr) {
    if(n <= 1) {
        arr[n] = n;
        return n;
    }
   if(arr[n] != -1) { 
        return arr[n]; 
    }
    arr[n] = fib(n - 1, arr) + fib(n - 2, arr);
    return arr[n];
}

void printfib(int n) {
    std::vector<int> arr(n + 1, -1);

    fib(n,arr);
    for(int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    int num = 0;
    std::cout << "Enter number for fibonachi" << std::endl;
    std::cin >> num;

    printfib(num);

    return 0;
}