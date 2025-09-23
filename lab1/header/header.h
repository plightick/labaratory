#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <algorithm>
#include <string>

void showMenu() {
    std::cout << "\n=== МЕНЮ ===" << std::endl;
    std::cout << "1. Ввести матрицы" << std::endl;
    std::cout << "2. Показать матрицы" << std::endl;
    std::cout << "3. Найти пересечение" << std::endl;
    std::cout << "4. Найти объединение" << std::endl;
    std::cout << "5. Выйти" << std::endl;
    std::cout << "Выберите опцию: ";
}

#endif