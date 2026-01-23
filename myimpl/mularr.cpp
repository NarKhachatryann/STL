#include <iostream>

void printarr(int  arr[], int size) {
    for(int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void initializer(int arr[], int size) {
    std::cout << "Enter array elements: " << std::endl;
    for(int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
}

void printbigger(int arr1[], int arr2[], int size) {
    int mul1 = 1;
    int mul2 = 1;

    for(int i = 0; i < size; ++i) {
        mul1 *= arr1[i];
        mul2 *= arr2[i];
    }
    if(mul1 > mul2) {
        std::cout << "big array is: 1" << std::endl;
        printarr(arr1,size);
    } else if(mul1 < mul2) {
        std::cout << "big array is: 2" << std::endl;
        printarr(arr2,size);
    } else {
        std::cout << "Arrays is equal" <<std::endl;
    }
}

int main() {
    int size = 0;
    std::cout << "Enter arrays size: ";
    std::cin >> size;

    int* arr1 = new int[size];
    int* arr2 = new int[size];

    std::cout << "Array 1" << std::endl;
    initializer(arr1, size);
    std::cout << "Array 2" << std::endl;
    initializer(arr2, size);

    printbigger(arr1, arr2, size);

    delete[] arr1;
    delete[] arr2;
}