#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "car.h"

class Matrix {
private:
    car*** m_data;
    int m_size;

public:
    Matrix(int size);
    Matrix(const Matrix& other);
    ~Matrix();

    Matrix& operator=(const Matrix& other);

    void init();
    void print() const;
    void pasteCar(const car& c, int row, int col);
    void startAllEngines();
    void changeColorAll(const std::string& color);
    int getCarCount() const;

    friend std::ostream& operator<<(std::ostream& os, const Matrix& obj);
};

#endif
