/* 19: Գրել ծրագիր որը մուտքին ստանում է մատրից և շրջում է մատրիցը գլխավոր անկյունագծի առանցքի շուրջ */

#include <iostream>

void transposematrix(int** matrix, int size) {
    for(int i = 0; i < size; ++i) {
        for(int j = i + 1; j < size; ++j) {
            std::swap(matrix[j][i],matrix[i][j]);
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