#include <iostream>
#include <cstdlib>
#include <ctime>

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

void printarr(int arr[], int size) {
    for(int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void randomArray(int arr[], int size) {
    srand(time(0));
    for( int i = 0; i < size; ++i) {
        arr[i] = rand() % 100;
    }
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
    std::cout << "Memory is deallocated!" << std::endl;
}

void* operator new[](std::size_t size) {
    void* p = nullptr;
    xmalloc(size, p);
    if(p != nullptr) {
        std::cout << "Memory is allocated" << std::endl;
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
    int size = 0;
    std::cout << "Enter Size for array: ";
    std::cin >> size;

    int* arr = new int[size];
    randomArray(arr,size);

    printarr(arr, size);

    delete[] arr;

    return 0;
}