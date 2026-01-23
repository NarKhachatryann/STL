#include <iostream>

template <typename T>
void xmalloc(size_t size, T*& ptr) {
    ptr = (T*)malloc(size);
    if(ptr == NULL) {
        std::cout << "Memory allocation failed!" << std::endl;
    }
}

template <typename T>
void xfree(T*& ptr) {
    if(ptr != NULL) {
        free(ptr);
    }
    ptr = nullptr;
}

int main() {
    int* ptr = nullptr;
    xmalloc(10, ptr);
    std::cout << "Memory allocated!" << std::endl;

    xfree(ptr);
    std::cout << "Memory freed!" << std::endl;
}