#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename T>
class Matrix {
private:
    T** m_data; 
    int m_size;

public:
    explicit Matrix(int size = 0);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other) noexcept;
    virtual ~Matrix();

    Matrix& operator=(Matrix other);
    Matrix& operator=(Matrix&& other) noexcept;

    void swap(Matrix& other) noexcept;
    void setElement(int row, int col, T value);
    T getElement(int row, int col) const;
    int getSize() const;
    
    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& obj) {
        for (int i = 0; i < obj.m_size; ++i) {
            for (int j = 0; j < obj.m_size; ++j) {
                os << obj.m_data[i][j] << "\t"; 
            }
            os << "\n";
        }
        return os;
    }
    
private:
    void allocate_memory(int size);
    void deallocate_memory();
    void copy_data(const Matrix& other);
};

#include "matrix_impl.h"

#endif