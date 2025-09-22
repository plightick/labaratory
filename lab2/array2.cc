#include "array2.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Matrix::Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
    if (rows <= 0 || cols <= 0) {
        std::cerr << "Ошибка: Размеры матрицы должны быть положительными." << std::endl;
        rows = cols = 0;
        data = nullptr;
        return;
    }

    data = new int*[rows];

    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = 0;
        }
    }
}

Matrix::~Matrix() {
    if (data != nullptr) {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    if (other.data == nullptr) {
        data = nullptr;
        return;
    }
    data = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) {
        return *this;
    }

    if (data != nullptr) {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    rows = other.rows;
    cols = other.cols;

    if (other.data == nullptr) {
        data = nullptr;
        return *this;
    }

    data = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
    return *this;
}

void Matrix::setValue(int i, int j, int value) {
    if (i >= 0 && i < rows && j >= 0 && j < cols) {
        data[i][j] = value;
    } else {
        std::cerr << "Ошибка: Индекс выходит за границы матрицы." << std::endl;
    }
}

int Matrix::getValue(int i, int j) const {
    if (i >= 0 && i < rows && j >= 0 && j < cols) {
        return data[i][j];
    } else {
        std::cerr << "Ошибка: Индекс выходит за границы матрицы." << std::endl;
        return 0;
    }
}

Matrix Matrix::operator&(const Matrix& other) const {
    if (cols != other.rows) {
        std::cerr << "Ошибка: Умножение матриц невозможно." << std::endl;
        return Matrix(0, 0);
    }

    Matrix result(rows, other.cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            int sum = 0;
            for (int k = 0; k < cols; ++k) {
                sum += data[i][k] * other.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

void Matrix::print() const {
    if (data == nullptr) {
        std::cout << "Матрица пуста." << std::endl;
        return;
    }
    std::cout << "Матрица " << rows << "x" << cols << ":" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << data[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Matrix::fillRandom(int min, int max) {
    if (data == nullptr) {
        std::cerr << "Ошибка: Матрица не инициализирована." << std::endl;
        return;
    }
    
    srand(time(0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = min + rand() % (max - min + 1);
        }
    }
}

void Matrix::inputFromKeyboard() {
    if (data == nullptr) {
        std::cerr << "Ошибка: Матрица не инициализирована." << std::endl;
        return;
    }
    
    std::cout << "Введите элементы матрицы " << rows << "x" << cols << ":" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Элемент [" << i << "][" << j << "]: ";
            std::cin >> data[i][j];
        }
    }
}