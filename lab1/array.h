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
    int intersectionSize;
    int unionSize;

    bool findElementInMatrix(int** matrix, int number);
    bool containsElement(int* array, int size, int number);

public:
    Array(int row, int col);
    Array(const Array& other);
    ~Array();

    void calculateIntersection();
    void calculateUnion();
    void printIntersection(const std::string& name);
    void printUnion(const std::string& name);
    void inputFirstMatrix();
    void inputSecondMatrix();
    int** getFirstMatrix();
    int** getSecondMatrix();
    int getRows();
    int getCols();
};

#endif