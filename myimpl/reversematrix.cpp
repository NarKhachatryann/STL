#include <iostream>

void printmat(int** matrix, int size) {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

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

void deletemat(int** matrix, int size) {
    for(int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void initmat(int** matrix,int size) {
    std::cout << "Enter matrix elements` " << std::endl;
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

void reversemat(int** matrix, int size) {
    int* arr = new int[size * size];
    int count = 0;
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            arr[count] = matrix[i][j];
            count++;
        }
    }
    int left = 0, right = (size * size) - 1;
    while(left < right) {
        std::swap(arr[left],arr[right]);
        left++;
        right--;
    }

    count = 0;
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            matrix[i][j] = arr[count];
            count++;
        }
    }

    delete[] arr;
    std::cout << "Reversed!" << std::endl;
}

int main() {
    int size = 0;
    std::cout << "Enter matrix size (NxN): ";
    std::cin >> size;
    if(std::cin.fail() || size <= 0) {
        std::cout << "Invalid input!!" << std::endl;
        return 1;
    }
    int** matrix = creatematrix(size);

    initmat(matrix,size);
    reversemat(matrix,size);
    printmat(matrix,size);

    deletemat(matrix, size);
}