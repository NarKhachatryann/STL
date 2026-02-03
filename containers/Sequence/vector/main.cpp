#include <iostream>
#include <stdexcept>
#include "vector.hpp"
#include "../../../except.hpp"

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Front element: " << vec.front() << std::endl;
    std::cout << "Back element: " << vec.back() << std::endl;

    try {
        int index = 10;
        
        if (index < 0 || index >= static_cast<int>(vec.size())) {
            throw CustomException("Error: Index out of range!");
        }
        
        std::cout << "Element at " << index << " is " << vec[index] << std::endl;
    }
        catch (const CustomException& e) {
            std::cerr << "Caught CustomException: " << e.what() << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Caught std::exception: " << e.what() << std::endl;
        }

    return 0;
}