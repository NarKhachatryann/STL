/* 10. Գրել ծրագիր որում կլինի ֆունկցիա որը կոնսոլում կտպի մեր կողմից տված զանգվածը */
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

int main() {
    int size;
    std::cout << "Enter array size: ";
    std::cin >> size;

    int* arr = new int[size];
    initializer(arr, size);
    printarr(arr,size);

    delete[] arr;

    return 0;
}