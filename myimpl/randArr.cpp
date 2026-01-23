#include <iostream>
#include <cstdlib>
#include <ctime>

void randomArray(int arr[], int size) {
    srand(time(0));
    for( int i = 0; i < size; ++i) {
        arr[i] = rand() % 100;
    }
}

int findmax(int arr[], int size) {
    int max = arr[0];
    for(int i = 1; i < size; ++i) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findmin(int arr[], int size) {
    int min = arr[0];
    for(int i = 0; i < size; ++i) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int size = 0;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* arr = new int[size];
    randomArray(arr, size);

    for(int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "This is min of this array: " << findmin(arr, size) << std::endl;
    std::cout << "This is max of this array: " << findmax(arr, size) << std::endl;

    delete[] arr;
    return 0;
}