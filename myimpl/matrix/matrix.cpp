#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "matrix.h"

Matrix::Matrix(int size) : m_size(size) {
    m_data = new int*[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = new int[m_size];
        for (int j = 0; j < m_size; ++j) {
            m_data[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix& other) : m_size(other.m_size) {
    m_data = new int*[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = new int[m_size];
        for (int j = 0; j < m_size; ++j) {
            m_data[i][j] = other.m_data[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < m_size; ++i) {
        delete[] m_data[i];
    }
    delete[] m_data;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        for (int i = 0; i < m_size; ++i) {
            delete[] m_data[i];
        }
        delete[] m_data;

        m_size = other.m_size;
        m_data = new int*[m_size];
        for (int i = 0; i < m_size; ++i) {
            m_data[i] = new int[m_size];
            for (int j = 0; j < m_size; ++j) {
                m_data[i][j] = other.m_data[i][j];
            }
        }
    }
    return *this;
}

Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result(m_size);
    if (m_size != other.m_size) {
        std::cout << "Matrix size doesn't fit!" << std::endl;
        return result;
    }
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            for (int k = 0; k < m_size; ++k) {
                result.m_data[i][j] += m_data[i][k] * other.m_data[k][j];
            }
        }
    }
    return result;
}

Matrix Matrix::operator*(int num) const {
    Matrix result(*this);
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            result.m_data[i][j] = m_data[i][j] * num;
        }
    }
    return result;
}

Matrix Matrix::operator++() {
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            ++m_data[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator++(int) {
    Matrix temp(*this);
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            ++m_data[i][j];
        }
    }
    return temp;
}

void Matrix::init() {
    std::cout << "Enter elements for a " << m_size << "x" << m_size << " matrix:" << std::endl;
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            std::cin >> m_data[i][j];
        }
    }
}

void Matrix::print() const {
    std::cout << "Matrix elements:" << std::endl;
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            std::cout << m_data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Matrix::initRandom() {
    srand(time(0));
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            m_data[i][j] = rand() % 100;
        }
    }
}

void Matrix::pasteValue(int value, int row, int col) {
    m_data[row][col] = value;
}

void Matrix::transpose() {
    for (int i = 0; i < m_size; ++i) {
        for (int j = i + 1; j < m_size; ++j) {
            std::swap(m_data[i][j], m_data[j][i]);
        }
    }
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size / 2; ++j) {
            std::swap(m_data[i][j], m_data[i][m_size - j - 1]);
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Matrix& obj) {
    for (int i = 0; i < obj.m_size; ++i) {
        for (int j = 0; j < obj.m_size; ++j) {
            os << obj.m_data[i][j];
            if (j < obj.m_size - 1) os << " ";
        }
        os << "\n";
    }
    return os;
}

void Matrix::savetofile(const std::string& filename) const {
    std::ofstream outfile(filename, std::ios::app);
    if(outfile.is_open()) {
        outfile << *this << std::endl;
        outfile.close();
    }

    outfile.close();
}

void Matrix::initfromfile(const std::string& filename) {
    std::ifstream infile(filename);
    if(infile.is_open()) {
        for(int i = 0; i < m_size; ++i) {
            for(int j = 0; j < m_size; ++j) {
                infile >> m_data[i][j];
            }
        }
    }
    infile.close();
}