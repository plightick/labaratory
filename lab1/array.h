#ifndef ARRAY_H
#define ARRAY_H

#include <string>

class Array {
private:
    int** firstMatrix;
    int** secondMatrix;
    int rows;
    int cols;
    int* intersectionResult;
    int* unionResult;
    int intersectionSize = 0;
    int unionSize = 0;

    bool findElementInMatrix(int** matrix, int number) const;
    bool containsElement(const int* array, int size, int number) const;
    bool isNumberInTempArray(const int* tempArray, int tempSize, int number) const;

public:
    Array(int row, int col);
    Array(const Array& other);
    Array& operator=(const Array& other) = delete;
    ~Array();

    void calculateIntersection();
    void calculateUnion();
    void printIntersection(const std::string& name) const;
    void printUnion(const std::string& name) const;
    void inputFirstMatrix();
    void inputSecondMatrix();
    int** getFirstMatrix() const;
    int** getSecondMatrix() const;
    int getRows() const;
    int getCols() const;
};

#endif