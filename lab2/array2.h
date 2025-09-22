#ifndef ARRAY2_H
#define ARRAY2_H

#include <iostream>
#include <cstdlib>
#include <ctime>

class Matrix {
private:
    int** data = nullptr;
    int rows = 0;
    int cols = 0;

public:
    Matrix(int numRows = 0, int numCols = 0) : rows(numRows), cols(numCols) {
        if (rows > 0 && cols > 0) {
            data = new int*[rows];
            for (int i = 0; i < rows; ++i) {
                data[i] = new int[cols]();
            }
        }
    }

    ~Matrix() {
        if (data) {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i];
            }
            delete[] data;
        }
    }

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        if (rows > 0 && cols > 0) {
            data = new int*[rows];
            for (int i = 0; i < rows; ++i) {
                data[i] = new int[cols];
                for (int j = 0; j < cols; ++j) {
                    data[i][j] = other.data[i][j];
                }
            }
        }
    }

    Matrix& operator=(const Matrix& other) {
        if (this == &other) return *this;

        if (data) {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i];
            }
            delete[] data;
        }

        rows = other.rows;
        cols = other.cols;

        if (rows > 0 && cols > 0) {
            data = new int*[rows];
            for (int i = 0; i < rows; ++i) {
                data[i] = new int[cols];
                for (int j = 0; j < cols; ++j) {
                    data[i][j] = other.data[i][j];
                }
            }
        } else {
            data = nullptr;
        }
        return *this;
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    void setValue(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            data[i][j] = value;
        }
    }

    int getValue(int i, int j) const {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            return data[i][j];
        }
        return 0;
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void fillRandom(int min = 0, int max = 10) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = min + std::rand() % (max - min + 1);
            }
        }
    }

    void inputFromKeyboard() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "Введите элемент [" << i << "][" << j << "]: ";
                std::cin >> data[i][j];
            }
        }
    }

    friend Matrix operator&(const Matrix& lhs, const Matrix& rhs) {
        if (lhs.cols != rhs.rows) {
            std::cerr << "Ошибка: Умножение матриц невозможно." << std::endl;
            return Matrix(0, 0);
        }

        Matrix result(lhs.rows, rhs.cols);
        for (int i = 0; i < lhs.rows; ++i) {
            for (int j = 0; j < rhs.cols; ++j) {
                int sum = 0;
                for (int k = 0; k < lhs.cols; ++k) {
                    sum += lhs.data[i][k] * rhs.data[k][j];
                }
                result.data[i][j] = sum;
            }
        }
        return result;
    }
};

#endif
