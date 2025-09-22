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

    Matrix* createMatrix(const char* matrixName) {
        int rows;
        int cols;
        std::cout << "=== СОЗДАНИЕ МАТРИЦЫ " << matrixName << " ===" << std::endl;
        std::cout << "Введите количество строк: ";
        std::cin >> rows;
        std::cout << "Введите количество столбцов: ";
        std::cin >> cols;
        
        if (rows <= 0 || cols <= 0) {
            std::cout << "Ошибка: Размеры должны быть положительными." << std::endl;
            return nullptr;
        }
        
        auto matrix = new Matrix(rows, cols);
        
        int choice;
        std::cout << "Выберите способ заполнения матрицы:" << std::endl;
        std::cout << "1 - Ввод с клавиатуры" << std::endl;
        std::cout << "2 - Заполнение случайными числами" << std::endl;
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                matrix->inputFromKeyboard();
                break;
            case 2:
                matrix->fillRandom();
                std::cout << "Матрица заполнена случайными числами." << std::endl;
                break;
            default:
                std::cout << "Неверный выбор. Матрица будет заполнена нулями." << std::endl;
                break;
        }
        
        std::cout << "Матрица " << matrixName << " создана успешно!" << std::endl;
        matrix->print();
        return matrix;
    }

    void deleteMatrix(Matrix*& matrix) {
        if (matrix != nullptr) {
            delete matrix;
            matrix = nullptr;
        }
    }

    void multiplyMatrices() {
        if (matrixA == nullptr || matrixB == nullptr) {
            std::cout << "Ошибка: Сначала создайте обе матрицы!" << std::endl;
            return;
        }
        
        std::cout << "=== УМНОЖЕНИЕ МАТРИЦ ===" << std::endl;
        std::cout << "Матрица A:" << std::endl;
        matrixA->print();
        std::cout << "Матрица B:" << std::endl;
        matrixB->print();
        
        deleteMatrix(matrixResult);
        matrixResult = new Matrix(*matrixA & *matrixB);
        
        if (matrixResult->getRows() > 0 && matrixResult->getCols() > 0) {
            std::cout << "Результат умножения (A & B):" << std::endl;
            matrixResult->print();
        } else {
            std::cout << "Умножение не выполнено из-за ошибки размеров." << std::endl;
        }
    }

    void showCurrentMatrices() const {
        std::cout << "=== ТЕКУЩИЕ МАТРИЦЫ ===" << std::endl;
        if (matrixA != nullptr) {
            std::cout << "Матрица A:" << std::endl;
            matrixA->print();
        } else {
            std::cout << "Матрица A не создана." << std::endl;
        }
        
        if (matrixB != nullptr) {
            std::cout << "Матрица B:" << std::endl;
            matrixB->print();
        } else {
            std::cout << "Матрица B не создана." << std::endl;
        }
        
        if (matrixResult != nullptr) {
            std::cout << "Результат умножения:" << std::endl;
            matrixResult->print();
        }
    }

    void deleteAllMatrices() {
        deleteMatrix(matrixA);
        deleteMatrix(matrixB);
        deleteMatrix(matrixResult);
        std::cout << "Все матрицы удалены." << std::endl;
    }

    void showMenu() {
        int choice;
        
        do {
            std::cout << "\n=== ГЛАВНОЕ МЕНЮ ===" << std::endl;
            std::cout << "1 - Создать матрицу A" << std::endl;
            std::cout << "2 - Создать матрицу B" << std::endl;
            std::cout << "3 - Показать матрицы" << std::endl;
            std::cout << "4 - Умножить матрицы (A & B)" << std::endl;
            std::cout << "5 - Удалить все матрицы" << std::endl;
            std::cout << "0 - Выход" << std::endl;
            std::cout << "Выберите действие: ";
            std::cin >> choice;
            
            switch (choice) {
                case 1:
                    deleteMatrix(matrixA);
                    matrixA = createMatrix("A");
                    break;
                    
                case 2:
                    deleteMatrix(matrixB);
                    matrixB = createMatrix("B");
                    break;
                    
                case 3:
                    showCurrentMatrices();
                    break;
                    
                case 4:
                    multiplyMatrices();
                    break;
                    
                case 5:
                    deleteAllMatrices();
                    break;
                    
                case 0:
                    std::cout << "Выход из программы..." << std::endl;
                    break;
                    
                default:
                    std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
                    break;
            }
            
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
        } while (choice != 0);
    }
};


#endif