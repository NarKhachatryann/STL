#include "matrix.h"

template <typename T>
void Matrix<T>::allocate_memory(int size) {
    if(size < 0) {
        std::cout << "Size cannot be negative" << std::endl;
        size = 0;
        return;
    }

    m_size = size > 0 ? size : 0; 
    
    if (m_size == 0) {
        m_data = nullptr;
        return;
    }
    m_data = new T*[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = new T[m_size]();
    }
}

template <typename T>
void Matrix<T>::deallocate_memory() {
    if (m_data) {
        for (int i = 0; i < m_size; ++i) {
            delete[] m_data[i];
        }
        delete[] m_data;
        m_data = nullptr;
    }
    m_size = 0;
}

template <typename T>
void Matrix<T>::copy_data(const Matrix& other) {
    if (this == &other) return;

    deallocate_memory();
    allocate_memory(other.m_size);

    for (int i = 0; i < m_size; ++i)
        for (int j = 0; j < m_size; ++j)
            m_data[i][j] = other.m_data[i][j];
}

template <typename T>
Matrix<T>::Matrix(int size) : m_data(nullptr), m_size(0) {
    allocate_memory(size);
}

template <typename T>
Matrix<T>::Matrix(const Matrix& other) : m_data(nullptr), m_size(0) {
    copy_data(other);
}

template <typename T>
Matrix<T>::~Matrix() {
    deallocate_memory();
}

template <typename T>
void Matrix<T>::swap(Matrix& other) noexcept {
    std::swap(m_data, other.m_data);
    std::swap(m_size, other.m_size);
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(Matrix other) {
    swap(other);
    return *this;
}


template <typename T>
Matrix<T>::Matrix(Matrix&& other) noexcept 
    : m_data(other.m_data), m_size(other.m_size) 
{
    other.m_data = nullptr;
    other.m_size = 0;
}

/* template <typename T>
Matrix<T>& Matrix<T>::operator=(Matrix&& other) noexcept {
    if (this != &other) {
        deallocate_memory();
        
        m_data = other.m_data;
        m_size = other.m_size;

        other.m_data = nullptr;
        other.m_size = 0;
    }
    return *this;
} */

template <typename T>
void Matrix<T>::setElement(int row, int col, T value) {
    if (!m_data) return;
    if (row < 0 || row >= m_size || col < 0 || col >= m_size) return;

    m_data[row][col] = value;
}

template <typename T>
T Matrix<T>::getElement(int row, int col) const {
    if (!m_data) return T();
    if (row < 0 || row >= m_size || col < 0 || col >= m_size) return T();

    return m_data[row][col];
}


template <typename T>
int Matrix<T>::getSize() const {
    return m_size;
}