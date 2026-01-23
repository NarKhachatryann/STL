#include <iostream>

int** creatematrix(int size) {
    int** matrix = new int*[size];
    for(int  i = 0; i < size; ++i) {
        *(matrix + i) = new int[size];
    }

    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            *(*(matrix + i) + j) = 0;
        }
    }

    return matrix;
}

void printmat(int** matrix, int size) {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            std::cout << *(*(matrix + i) + j) << " ";
        }
        std::cout << std::endl;
    }
}

void deletemat(int** matrix, int size) {
    for(int i = 0; i < size; ++i) {
        delete[] *(matrix + i);
    }
    delete[] matrix;

    std::cout << "Deleted!" << std::endl;
}

int main() {
    const int size = 3;
    int** matrix = creatematrix(size);

    printmat(matrix,size);

    deletemat(matrix, size);
}