#include <iostream>
#include <cstdlib>
#include <ctime>

void rowprint(int** matrix, int size,  int row) {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            if(i > row) {
                std::cout << matrix[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void randomArray(int** matrix, int size) {
    srand(time(0));
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }
}

int main() {
    int row = 0;
    int size = 0;
    std::cout << "Enter size for matrix (NxN): " << std::endl;
    std::cin >> size;

    int** matrix = new int*[size];
    for(int i = 0; i < size; ++i) {
        matrix[i] = new int[size];
    }

    std::cout << "Enter the Row" << std::endl;
    std::cin >> row;
    std::cout << std::endl;
    
    randomArray(matrix,size);
    rowprint(matrix, size, row);

    for(int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}