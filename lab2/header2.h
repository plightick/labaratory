#ifndef HEADER2_H
#define HEADER2_H

#include "array2.h"
#include <iostream>
#include <limits>

class MenuManager {
private:
    Matrix* matrixA = nullptr;
    Matrix* matrixB = nullptr;
    Matrix* matrixResult = nullptr;

    MenuManager(const MenuManager&) = delete;
    MenuManager& operator=(const MenuManager&) = delete;

public:
    MenuManager() = default;
    
    ~MenuManager() {
        deleteMatrix(matrixA);
        deleteMatrix(matrixB);
        deleteMatrix(matrixResult);
    }

    Matrix* createMatrix(const char* matrixName);

    void deleteMatrix(Matrix*& matrix) {
        if (matrix != nullptr) {
            delete matrix;
            matrix = nullptr;
        }
    }

    void multiplyMatrices();

    void showCurrentMatrices() const;

    void deleteAllMatrices() {
        deleteMatrix(matrixA);
        deleteMatrix(matrixB);
        deleteMatrix(matrixResult);
        std::cout << "Все матрицы удалены." << std::endl;
    }

    void showMenu();
};

#endif
