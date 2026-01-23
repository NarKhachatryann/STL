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

void printMatrix(int** matrix, int size1, int size2) {
    for(int i = 0; i < size1; ++i) {
        for(int j = 0; j < size2; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void randomMatrix(int** matrix, int size1, int size2) {
    srand(time(0));
    for(int i = 0; i < size1; ++i) {
        for(int j = 0; j < size2; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void* operator new(std::size_t size) {
    void* p = nullptr;
    xmalloc(size, p);
    if(p != nullptr) {
        std::cout << "Memory allocated!" << std::endl;
        return p;
    }
    else {
        std::cout << "Memory allocation failed!" << std::endl;
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
        std::cout << "Memory allocated" << std::endl;
        return p;
    }
    else {
        std::cout << "Memory allocation failed!" << std::endl;
        return p;
    }
}

void operator delete[] (void* mem) noexcept {
    xfree(mem);
    std::cout << "Memory deallocated" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Please provide the size of the matrix as an argument\n";
        return 1;
    }

    int** matrix = new int*[argc];
    int y = (*argv[1] - '0');
    for(int i = 0; i < y; ++i) {
        matrix[i] = new int[y];
    }

    randomMatrix(matrix, argc, y);
    std::cout << std::endl;
    printMatrix(matrix, argc, y);


    for(int i = 0 ; i < y; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}