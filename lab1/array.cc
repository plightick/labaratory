#include "array.h"
#include <iostream>

Array::Array(int row, int col) : rows(row), cols(col), intersectionResult(nullptr), unionResult(nullptr), intersectionSize(0), unionSize(0) {
    firstMatrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        firstMatrix[i] = new int[cols];
    }

    secondMatrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        secondMatrix[i] = new int[cols];
    }
}

Array::Array(const Array& other) : rows(other.rows), cols(other.cols), intersectionSize(other.intersectionSize), unionSize(other.unionSize) {
    firstMatrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        firstMatrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            firstMatrix[i][j] = other.firstMatrix[i][j];
        }
    }

    secondMatrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        secondMatrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            secondMatrix[i][j] = other.secondMatrix[i][j];
        }
    }

    if (other.intersectionResult && intersectionSize > 0) {
        intersectionResult = new int[intersectionSize];
        for (int i = 0; i < intersectionSize; i++) {
            intersectionResult[i] = other.intersectionResult[i];
        }
    } else {
        intersectionResult = nullptr;
    }

    if (other.unionResult && unionSize > 0) {
        unionResult = new int[unionSize];
        for (int i = 0; i < unionSize; i++) {
            unionResult[i] = other.unionResult[i];
        }
    } else {
        unionResult = nullptr;
    }
}

Array::~Array() {
    for (int i = 0; i < rows; i++) {
        delete[] firstMatrix[i];
    }
    delete[] firstMatrix;

    for (int i = 0; i < rows; i++) {
        delete[] secondMatrix[i];
    }
    delete[] secondMatrix;

    delete[] intersectionResult;
    delete[] unionResult;
}

bool Array::findElementInMatrix(int** matrix, int number) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == number) {
                return true;
            }
        }
    }
    return false;
}

bool Array::containsElement(int* array, int size, int number) {
    for (int i = 0; i < size; i++) {
        if (array[i] == number) {
            return true;
        }
    }
    return false;
}

void Array::calculateIntersection() {
    delete[] intersectionResult;
    intersectionSize = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int number = firstMatrix[i][j];
            if (findElementInMatrix(secondMatrix, number) && 
                !containsElement(intersectionResult, intersectionSize, number)) {
                intersectionSize++;
            }
        }
    }

    if (intersectionSize > 0) {
        intersectionResult = new int[intersectionSize];
        int index = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int number = firstMatrix[i][j];
                if (findElementInMatrix(secondMatrix, number) && 
                    !containsElement(intersectionResult, index, number)) {
                    intersectionResult[index++] = number;
                }
            }
        }
    } else {
        intersectionResult = nullptr;
    }
}

void Array::calculateUnion() {
    delete[] unionResult;
    unionSize = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int number = firstMatrix[i][j];
            if (!containsElement(unionResult, unionSize, number)) {
                unionSize++;
            }
        }
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int number = secondMatrix[i][j];
            if (!containsElement(unionResult, unionSize, number)) {
                unionSize++;
            }
        }
    }

    if (unionSize > 0) {
        unionResult = new int[unionSize];
        int index = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int number = firstMatrix[i][j];
                if (!containsElement(unionResult, index, number)) {
                    unionResult[index++] = number;
                }
            }
        }
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int number = secondMatrix[i][j];
                if (!containsElement(unionResult, index, number)) {
                    unionResult[index++] = number;
                }
            }
        }
    } else {
        unionResult = nullptr;
    }
}

void Array::printIntersection(const std::string& name) {
    std::cout << "\n" << name << ": ";
    if (intersectionSize == 0) {
        std::cout << "пусто";
    } else {
        for (int i = 0; i < intersectionSize; i++) {
            std::cout << intersectionResult[i] << " ";
        }
    }
    std::cout << std::endl;
}

void Array::printUnion(const std::string& name) {
    std::cout << "\n" << name << ": ";
    if (unionSize == 0) {
        std::cout << "пусто";
    } else {
        for (int i = 0; i < unionSize; i++) {
            std::cout << unionResult[i] << " ";
        }
    }
    std::cout << std::endl;
}

void Array::inputFirstMatrix() {
    std::cout << "Введите элементы первой матрицы " << rows << "x" << cols << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "Элемент [" << i << "][" << j << "]: ";
            std::cin >> firstMatrix[i][j];
        }
    }
}

void Array::inputSecondMatrix() {
    std::cout << "Введите элементы второй матрицы " << rows << "x" << cols << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "Элемент [" << i << "][" << j << "]: ";
            std::cin >> secondMatrix[i][j];
        }
    }
}

int** Array::getFirstMatrix() { return firstMatrix; }
int** Array::getSecondMatrix() { return secondMatrix; }
int Array::getRows() { return rows; }
int Array::getCols() { return cols; }