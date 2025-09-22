#ifndef ARRAY2_H
#define ARRAY2_H

#include <iostream>

class Matrix {
private:
    int** data = nullptr;
    int rows = 0;
    int cols = 0;

public:
    Matrix(int numRows, int numCols);
    ~Matrix();
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    void setValue(int i, int j, int value);
    int getValue(int i, int j) const;

    void print() const;
    void fillRandom(int min = 0, int max = 10);
    void inputFromKeyboard();

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
