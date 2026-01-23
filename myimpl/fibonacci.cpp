#include <iostream>

template<int N>
class fib {
    public:
        constexpr static unsigned long long val = fib<N - 1>::val + fib<N - 2>::val;
};

template<>
class fib<0> {
    public:
        constexpr static unsigned long long val = 0;
};

template<>
class fib<1> {
    public:
        constexpr static unsigned long long val = 1;
};

int main() {
    const int num = 15;
    std::cout << "Fibonacci of " << num << " is " << fib<num>::val << std::endl;
    return 0;
}