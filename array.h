#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include <string>
class Array {
private:
    int** firstMatrix;
    int** secondMatrix;
    int rows;
    int cols;

    bool findElementInMatrix(int** matrix, int number);

public:
    Array(int row, int col);

    void inputFirstMatrix();
    void inputSecondMatrix();
    void printMatrix(int** matrix, const std::string& name);
    std::vector<int> getIntersection();
    std::vector<int> getUnion();

    int** getFirstMatrix();
    int** getSecondMatrix();
    int getRows();
    int getCols();
};

#endif