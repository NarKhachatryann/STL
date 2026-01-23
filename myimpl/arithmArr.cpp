#include <iostream>

int arithmeticArray(int arr[], int size) {
    double sum = 0;
    for(int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    sum /= size;
    return sum;
}

void smallerNumbers(int  arr[], double sum, int size) {
    for(int i = 0; i < size; ++i) {
        if(arr[i] < sum) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

void initialArr(int arr[], int size) {
    std::cout << "Enter numbers of array: " << std::endl;
    for(int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
}

int main() {
    double sum = 0;
    int size = 0;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* arr = new int[size];

    initialArr(arr, size);
    sum = arithmeticArray(arr, size);
    smallerNumbers(arr, sum, size);

    delete[] arr;
}