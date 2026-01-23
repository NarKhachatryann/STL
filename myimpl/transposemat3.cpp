/* 20: Գրել ծրագիր որը մուտքին ստանում է մատրից և տեղեոր փոխում է երկորդական և առաջնային անկյունակգծերը*/

#include <iostream>

void transposematrix(int** matrix, int size) {
    for(int i = 0; i < size; ++i) {
        std::swap(matrix[i][i], matrix[i][size - 1 - i]);
    }
}

void initializer(int** matrix, int size) {
    std::cout << "Enter matrix elements: " << std::endl;
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

void printmatrix(int** matrix, int size) {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    int size = 0;
    std::cout << "Enter size for matrix(NxN): ";
    std::cin >> size;

    int** matrix = new int*[size];
    for(int i = 0; i < size; ++i) {
        matrix[i] = new int[size];
    }

    initializer(matrix,size);
    transposematrix(matrix,size);
    std::cout << "Transformated matrix" << std::endl;
    printmatrix(matrix,size);

    for(int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}