/* 18. Գրել ֆունկցիա որը մուտքին ստանում է մատրից և 2 սյան ինդեքս և փոխում է այդ սյուները տեղերով */

#include <iostream>

void matrixswap(int** matrix, int size, int colum1, int colum2) {
    for(int  i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            std::swap(matrix[i][colum1],matrix[i][colum2]);
        }
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
    int colum1 = 0;
    int colum2 = 0;
    int size = 0;
    std::cout << "Enter size for matrix(NxN): ";
    std::cin >> size;

    int** matrix = new int*[size];
    for(int i = 0; i < size; ++i) {
        matrix[i] = new int[size];
    }

    initializer(matrix, size);
    std::cout << "Enter columns for swap matrix:" << std::endl;
    std::cout << "Enter column 1: ";
    std::cin >> colum1;
    std::cout << "Enter column 2: ";
    std::cin >> colum2;

    std::cout << "This is swapped matrix" << std::endl;
    matrixswap(matrix, size, colum1, colum2);
    printmatrix(matrix,size);

    for(int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}