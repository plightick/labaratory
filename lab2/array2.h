#ifndef ARRAY2_H
#define ARRAY2_H

#include <iostream>

class Matrix {
private:
    int** data;
    int rows;
    int cols;

public:
    Matrix(int numRows, int numCols);
    ~Matrix();
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    void setValue(int i, int j, int value);
    int getValue(int i, int j) const;

    Matrix operator&(const Matrix& other) const;

    void print() const;
    void fillRandom(int min = 0, int max = 10);
    void inputFromKeyboard();
};

#endif