#include "header2.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Программа для работы с матрицами" << std::endl;
    std::cout << "Оператор & перегружен для умножения матриц" << std::endl;
    
    MenuManager menu;
    menu.showMenu();
    
    return 0;
}