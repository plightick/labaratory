#include "array.h"
#include "header.h"

int main() {
    int rows;
    int cols;
    
    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;

    Array arr(rows, cols);
    int choice;

    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                arr.inputFirstMatrix();
                arr.inputSecondMatrix();
                std::cout << "Матрицы успешно введены!" << std::endl;
                break;
            case 2:
                break;
            case 3:
                arr.calculateIntersection();
                arr.printIntersection("Пересечение элементов");
                break;
            case 4:
                arr.calculateUnion();
                arr.printUnion("Объединение элементов");
                break;
            case 5:
                std::cout << "Выход из программы..." << std::endl;
                break;
            default:
                std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
                break;
        }
    } while (choice != 5);

    return 0;
}