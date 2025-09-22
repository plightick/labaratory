#include "header2.h"

Matrix* MenuManager::createMatrix(const char* matrixName) {
    int rows, cols;
    std::cout << "Введите количество строк для " << matrixName << ": ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов для " << matrixName << ": ";
    std::cin >> cols;

    if (rows <= 0 || cols <= 0) {
        std::cout << "Ошибка: размеры матрицы должны быть положительными!" << std::endl;
        return nullptr;
    }

    Matrix* matrix = new Matrix(rows, cols);
    matrix->fillRandom();
    std::cout << "Матрица " << matrixName << " создана." << std::endl;
    return matrix;
}

void MenuManager::deleteMatrix(Matrix*& matrix) {
    if (matrix != nullptr) {
        delete matrix;
        matrix = nullptr;
    }
}

void MenuManager::multiplyMatrices() {
    if (matrixA == nullptr || matrixB == nullptr) {
        std::cout << "Ошибка: сначала создайте обе матрицы!" << std::endl;
        return;
    }

    std::cout << "=== УМНОЖЕНИЕ МАТРИЦ ===" << std::endl;
    std::cout << "Матрица A:" << std::endl;
    matrixA->print();
    std::cout << "Матрица B:" << std::endl;
    matrixB->print();

    deleteMatrix(matrixResult);

    Matrix temp = (*matrixA & *matrixB);
    if (temp.getRows() > 0 && temp.getCols() > 0) {
        matrixResult = new Matrix(temp);
        std::cout << "Результат умножения (A & B):" << std::endl;
        matrixResult->print();
    } else {
        std::cout << "Умножение невозможно: несовместимые размеры матриц." << std::endl;
    }
}

void MenuManager::showCurrentMatrices() const {
    std::cout << "=== ТЕКУЩИЕ МАТРИЦЫ ===" << std::endl;

    std::cout << "Матрица A:" << std::endl;
    if (matrixA != nullptr) matrixA->print();
    else std::cout << "Матрица A отсутствует." << std::endl;

    std::cout << "Матрица B:" << std::endl;
    if (matrixB != nullptr) matrixB->print();
    else std::cout << "Матрица B отсутствует." << std::endl;

    std::cout << "Результат:" << std::endl;
    if (matrixResult != nullptr) matrixResult->print();
    else std::cout << "Результат отсутствует." << std::endl;
}

void MenuManager::deleteAllMatrices() {
    deleteMatrix(matrixA);
    deleteMatrix(matrixB);
    deleteMatrix(matrixResult);
    std::cout << "Все матрицы удалены." << std::endl;
}

void MenuManager::showMenu() {
    int choice;
    do {
        std::cout << "\n=== МЕНЮ ===" << std::endl;
        std::cout << "1. Создать матрицу A" << std::endl;
        std::cout << "2. Создать матрицу B" << std::endl;
        std::cout << "3. Умножить A и B" << std::endl;
        std::cout << "4. Показать текущие матрицы" << std::endl;
        std::cout << "5. Удалить все матрицы" << std::endl;
        std::cout << "0. Выход" << std::endl;
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
                multiplyMatrices(); 
                break;
            case 4: 
                showCurrentMatrices(); 
                break;
            case 5: 
                deleteAllMatrices(); 
                break;
            case 0: 
                std::cout << "Выход из программы." << std::endl; 
                break;
            default: 
                std::cout << "Неверный выбор, попробуйте снова." << std::endl;
        }
    } while (choice != 0);
}
