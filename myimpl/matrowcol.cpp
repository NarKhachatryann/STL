#include <iostream>
#include <cstdlib>
#include <ctime>

int** creatematrix(int size) {
    int** matrix = new int*[size];
    for(int  i = 0; i < size; ++i) {
        matrix[i] = new int[size];
    }

    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            matrix[i][j] = 0;
        }
    }

    return matrix;
}

int findbigger(int** matrix, int size) {
    int max = matrix[0][0];
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            if(matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

void deletemat(int** matrix, int size) {
    for(int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int matrixchecker(int** matrix, int size, int target) {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            if(matrix[i][j] == target) {
                return (i * size) + j;
            }
        }
    }
    return -1;
}

void printmat(int** matrix, int size) {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void printmat(int** matrix, int size, int targ1, int targ2) {
    std::cout << std::endl;
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            if(i == targ1 || j == targ2) {
                std::cout << matrix[i][j] << " ";
            }
            else {
                std::cout << " . ";
            }
        }
        std::cout << std::endl;
    }
}

void randmat(int** matrix, int size) {
    srand(time(0));
    for( int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void decoder(int** matrix, int size, int target) {
    if(target < 0) {
        std::cout << "Wrong target please try again!!" << std::endl;
        return;
    }
    int row = target / size;
    int col = target % size;

    printmat(matrix, size, row, col);
}

int main() {
    int target = 0;
    int size = 0;
    std::cout << "Enter matrix size NxN: ";
    std::cin >> size;
    int** matrix = creatematrix(size);

    randmat(matrix, size);
    printmat(matrix, size);
    target = findbigger(matrix, size);
    decoder(matrix, size, matrixchecker(matrix, size, target));

    deletemat(matrix, size);
}