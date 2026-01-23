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

void* operator new(std::size_t size) {
    void* p = nullptr;
    xmalloc(size, p);
    if(p != nullptr) {
        std::cout << "The memory has allocated!" << std::endl;
        return p;
    }
    else {
        std::cout << "Memory don't allocated!" << std::endl;
        return p;
    }
}

void operator delete(void* mem) noexcept {
    xfree(mem);
    std::cout << "Memory deallocated!" << std::endl;
}

void* operator new[](std::size_t size) {
    void* p = nullptr;
    xmalloc(size, p);
    if(p != nullptr) {
        std::cout << "The memory has allocated!" << std::endl;
        return p;
    }
    else {
        std::cout << "Memory allocate is failed!" << std::endl;
        return p;
    }
}

void operator delete[] (void* mem) noexcept {
    xfree(mem);
    std::cout << "Memory are deallocated" << std::endl;
}

int main() {
    int* mem = new int[5];
    delete[] mem;

    mem = nullptr;
    mem = new int;
    delete mem;

    return 0;
}