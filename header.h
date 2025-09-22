#include <iostream>
#include <vector>

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

void showMenu() {
    std::cout << "\n=== МЕНЮ ===" << std::endl;
    std::cout << "1. Ввести матрицы" << std::endl;
    std::cout << "2. Показать матрицы" << std::endl;
    std::cout << "3. Найти пересечение" << std::endl;
    std::cout << "4. Найти объединение" << std::endl;
    std::cout << "5. Выйти" << std::endl;
    std::cout << "Выберите опцию: ";
}