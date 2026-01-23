#include "matrix.h"

Matrix::Matrix(int size) : m_size(size) {
    m_data = new car**[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = new car*[m_size];
        for (int j = 0; j < m_size; ++j) {
            m_data[i][j] = nullptr;
        }
    }
}

Matrix::Matrix(const Matrix& other) : m_size(other.m_size) {
    m_data = new car**[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = new car*[m_size];
        for (int j = 0; j < m_size; ++j) {
            if (other.m_data[i][j]) {
                m_data[i][j] = new car(*other.m_data[i][j]);
            } else {
                m_data[i][j] = nullptr;
            }
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            delete m_data[i][j];
        }
        delete[] m_data[i];
    }
    delete[] m_data;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        for (int i = 0; i < m_size; ++i) {
            for (int j = 0; j < m_size; ++j) {
                delete m_data[i][j];
            }
            delete[] m_data[i];
        }
        delete[] m_data;

        m_size = other.m_size;
        m_data = new car**[m_size];
        for (int i = 0; i < m_size; ++i) {
            m_data[i] = new car*[m_size];
            for (int j = 0; j < m_size; ++j) {
                if (other.m_data[i][j]) {
                    m_data[i][j] = new car(*other.m_data[i][j]);
                } else {
                    m_data[i][j] = nullptr;
                }
            }
        }
    }
    return *this;
}

int Matrix::getCarCount() const {
    return car::get_count();
}

void Matrix::pasteCar(const car& c, int row, int col) {
    if (row >= 0 && row < m_size && col >= 0 && col < m_size) {
        delete m_data[row][col];
        m_data[row][col] = new car(c);
    }
}

void Matrix::init() {
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            std::string model = "Model_" + std::to_string(i) + std::to_string(j);
            m_data[i][j] = new car(model, "4", "RWD", "Black", "Benzine");
        }
    }
}

void Matrix::print() const {
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            std::cout << "Car at [" << i << "][" << j << "]:" << std::endl;
            if (m_data[i][j]) {
                m_data[i][j]->print();
            } else {
                std::cout << "Empty slot" << std::endl;
            }
            std::cout << "------------------------" << std::endl;
        }
    }
}

void Matrix::startAllEngines() {
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            if (m_data[i][j]) {
                m_data[i][j]->engine(true);
            }
        }
    }
}

void Matrix::changeColorAll(const std::string& color) {
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            if (m_data[i][j]) {
                m_data[i][j]->change_color(color);
            }
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Matrix& obj) {
    for (int i = 0; i < obj.m_size; ++i) {
        for (int j = 0; j < obj.m_size; ++j) {
            os << "[" << i << "][" << j << "]: ";
            if (obj.m_data[i][j]) {
                os << obj.m_data[i][j]->get_model();
            } else {
                os << "Empty";
            }
            os << "\n";
        }
    }
    return os;
}