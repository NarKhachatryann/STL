#include "matrix.h"
#include <fstream>

int main() {
    std::ofstream outfile("matrix_output.txt", std::ios::app);
    int size = 0;
    std::cout << "Enter size of matrix: ";
    std::cin >> size;

    Matrix mat(size);
    mat.initRandom();
    mat.print();
    mat.savetofile("matrix_output.txt");

    mat = mat * 5;
    std::cout << "Matrix: \n" << mat << std::endl;
    mat.savetofile("matrix_output.txt");
    mat.initfromfile("matrix_output.txt");
    std::cout << "Matrix from file: \n" << mat << std::endl;

    return 0;
}