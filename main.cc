#include "array.h"
#include "header.h"

int main() {
    int rows;
    int cols;

    Array* array = nullptr;
    int choice;
    
    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;

    array = new Array(rows, cols);

    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                array->inputFirstMatrix();
                array->inputSecondMatrix();
                std::cout << "Матрицы успешно введены!" << std::endl;
                break;
            case 2:
                array->printMatrix(array->getFirstMatrix(), "Первая матрица");
                array->printMatrix(array->getSecondMatrix(), "Вторая матрица");
                break;
            case 3: {
                std::vector<int> intersection = array->getIntersection();
                printVector(intersection, "Пересечение элементов");
                break;
            }
            case 4: {
                std::vector<int> unionResult = array->getUnion();
                printVector(unionResult, "Объединение элементов");
                break;
            }
            case 5:
                std::cout << "Выход из программы..." << std::endl;
                break;
            default:
                std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
                break;
        }
    } while (choice != 5);

    delete array;

    return 0;
}
