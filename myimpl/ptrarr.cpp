#include <iostream>
#include <cstdlib>
#include <ctime>

void randomArray(int arr[], int size) {
    srand(time(0));
    for( int i = 0; i < size; ++i) {
        *(arr + i) = rand() % 100;
    }
}

int arithmeticArray(int* arr, int size) {
    double sum = 0;
    for(int i = 0; i < size; ++i) {
        sum += *(arr + i);
    }
    sum /= size;
    return sum;
}

int* createArr(int size) {
    int* arr = new int[size];
    return arr;
}

void dealloc(int* arr, int size) {
    delete[] arr;
}

void printarr(int  arr[], int size) {
    for(int i = 0; i < size; ++i) {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    int size = 0;
    std::cout << "Enter size of array: ";
    std::cin >> size;

    int* arr = createArr(size);
    randomArray(arr, size);
    printarr(arr, size);
    auto res = arithmeticArray(arr, size);
    std::cout << "Result is: " << res << std::endl;
    dealloc(arr,size);
}