#include <iostream>

template<typename T, typename... Args>
void print(const T& first, const Args&... args) {
    std::cout << first;
    if constexpr (sizeof...(args) > 0) {
        std::cout << " ";
        print(args...);
    } else {
        std::cout << std::endl;
    }
}

int main() {
    print("Hello,", "this", "is", "a", "test", 123, 45.67);
    print("Single argument test");
    print(42);
    return 0;
}