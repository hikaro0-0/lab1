#include "func.h"

void clearScreen() {
	system("cls");
}

void waitAndClear() {
	std::cout << "Нажмите Enter для продолжения...";
	std::cin.ignore();
	std::cin.get();
	clearScreen();
}

void printVector(const std::vector<int>& vec, const std::string& title) {
	std::cout << title << ": ";
	if (vec.empty()) {
		std::cout << "Пусто";
	}
	else {
		for (int num : vec) {
			std::cout << num << " ";
		}
	}
	std::cout << std::endl;
}

void displayMenu() {
	std::cout << "====================================" << std::endl;
	std::cout << "          МЕНЮ ПРОГРАММЫ" << std::endl;
	std::cout << "====================================" << std::endl;
	std::cout << "1. Ручной ввод матриц" << std::endl;
	std::cout << "2. Автоматический ввод матриц" << std::endl;
	std::cout << "3. Показать матрицы" << std::endl;
	std::cout << "4. Найти пересечение элементов" << std::endl;
	std::cout << "5. Найти объединение элементов" << std::endl;
	std::cout << "6. Выход" << std::endl;
	std::cout << "====================================" << std::endl;
	std::cout << "Выберите опцию: ";
}