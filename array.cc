#include "array.h"
#include <iostream>
#include <algorithm>

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

Array::Array(int row, int col) : rows(row), cols(col) {
    firstMatrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        firstMatrix[i] = new int[cols];
    }

    secondMatrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        secondMatrix[i] = new int[cols];
    }
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

void Array::printMatrix(int** matrix, const std::string& name) {
    std::cout << "\n" << name << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

std::vector<int> Array::getIntersection() {
    std::vector<int> resultIntersection;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int number = firstMatrix[i][j];
            
            if (findElementInMatrix(secondMatrix, number) && std::find(resultIntersection.begin(), resultIntersection.end(), number) == resultIntersection.end()) {
                resultIntersection.push_back(number);
            }
        }
    }
    return resultIntersection;
}

std::vector<int> Array::getUnion() {
    std::vector<int> resultUnion;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int number = firstMatrix[i][j];
            if (std::find(resultUnion.begin(), resultUnion.end(), number) == resultUnion.end()) {
                resultUnion.push_back(number);
            }
        }
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int number = secondMatrix[i][j];
            if (std::find(resultUnion.begin(), resultUnion.end(), number) == resultUnion.end()) {
                resultUnion.push_back(number);
            }
        }
    }
    
    return resultUnion;
}

void printVector(const std::vector<int>& vec, const std::string& name) {
    std::cout << "\n" << name << ": ";
    if (vec.empty()) {
        std::cout << "пусто";
    } else {
        for (int num : vec) {
            std::cout << num << " ";
        }
    }
    std::cout << std::endl;
}

int** Array::getFirstMatrix() { return firstMatrix; }
int** Array::getSecondMatrix() { return secondMatrix; }
int Array::getRows() { return rows; }
int Array::getCols() { return cols; }