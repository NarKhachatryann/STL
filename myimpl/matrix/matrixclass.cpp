#include <iostream>
#include <cstdlib>
#include <ctime>

class Matrix {
    private:
    int** m_data;
    int m_size;

    public:
    Matrix(int size) : m_size(size) {
        m_data = new int*[m_size];
        for(int i = 0; i < m_size; ++i) {
            m_data[i] = new int[m_size];
            for(int j = 0; j < m_size; ++j) {
                m_data[i][j] = 0;
            }
        }
    }

    Matrix(const Matrix& other) : m_size(other.m_size) {
        m_data = new int*[m_size];
        for(int i = 0; i < m_size; ++i) {
            m_data[i] = new int[m_size];
            for(int j = 0; j < m_size; ++j) {
                m_data[i][j] = other.m_data[i][j];
            }
        }
    }

    Matrix& operator= (const Matrix& other) {
        if(this != &other) {
            for(int i = 0; i < m_size; ++i) {
                delete[] m_data[i];
            }
            delete[] m_data;

            m_size = other.m_size;
            m_data = new int*[m_size];
            for(int i = 0; i < m_size; ++i) {
                m_data[i] = new int[m_size];
                for(int j = 0; j < m_size; ++j) {
                    m_data[i][j] = other.m_data[i][j];
                }
            }
        }

        return *this;
    }

    Matrix operator* (const Matrix& other) const {
        Matrix count(m_size);
        if(this->m_size != other.m_size) {
            std::cout << "Matrix size doesn't fit!" << std::endl;
            return count;
        }
        for(int i = 0; i < m_size; ++i) {
            for(int j = 0; j < m_size; ++j) {
                for(int k = 0; k < m_size; ++k) {
                    count.m_data[i][j] += m_data[i][k] * other.m_data[k][j];
                }
            }
        }
        return count;
    }

    Matrix operator* (int num) const {
        Matrix count(*this);
        for(int i = 0; i < m_size; ++i) {
            for(int j = 0; j < m_size; ++j) {
                count.m_data[i][j] = m_data[i][j] * num;
            }
        }

        return count;
    }

    Matrix operator++() {
        for(int i = 0; i < m_size; ++i) {
            for(int j = 0; j < m_size; ++j) {
                ++m_data[i][j];
            }
        }
        return *this;
    }

    Matrix operator++(int) {
        Matrix temp(*this);
        for(int i = 0; i < m_size; ++i) {
            for(int j = 0; j < m_size; ++j) {
                ++m_data[i][j];
            }
        }
        return temp;
    }

    void init(){
        std::cout << "Enter elements for a " << m_size << "x" << m_size << " matrix:" << std::endl;
        for(int i = 0; i < m_size; ++i) {
            for(int j = 0; j < m_size; ++j) {
                std::cin >> m_data[i][j];
            }
        }
    }

    void print() const {
        std::cout << "Matrix elements:" <<std::endl;
        for(int i = 0; i < m_size; ++i) {
            for(int j = 0; j < m_size; ++j) {
                std::cout << m_data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void initRandom() {
        srand(time(0));
        for(int i = 0; i < m_size; ++i) {
            for(int j = 0; j < m_size; ++j) {
                m_data[i][j] = rand() % 100;
            }
        }
    }

    void pasteValue(int value, int row, int col) {
        m_data[row][col] = value;
    }

    void transpose() {
        for(int i = 0; i < m_size; ++i) {
            for(int j = i + 1; j < m_size; ++j) {
                std::swap(m_data[i][j], m_data[j][i]);
            }
        }
        
        for(int i = 0; i < m_size; ++i) {
            for(int j = 0; j < m_size / 2; ++j) {
                std::swap(m_data[i][j], m_data[i][m_size - j - 1]);
            }
        }
    }

    ~Matrix() {
        for(int i = 0; i < m_size; ++i) {
            delete[] m_data[i];
        }
        delete[] m_data;
    }

    friend std::ostream& operator<< (std::ostream& os, const Matrix& obj);
};


std::ostream& operator<< (std::ostream& os, const Matrix& obj) {
    for(int i = 0; i < obj.m_size; ++i) {
        for(int j = 0; j < obj.m_size; ++j) {
            os << obj.m_data[i][j];

            if(j < obj.m_size - 1) {
                os << " ";
            }
        }
        os << "\n";
    }
    return os;
} 

int main() {
    int size = 0;
    std::cout << "Enter size of matrix: ";
    std::cin >> size;

    Matrix mat(size);
    mat.initRandom();
    mat.print();

    mat = mat * 5;
    std::cout << "Matrix: \n" << mat << std::endl; 

    return 0;
}