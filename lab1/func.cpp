#include "func.h"

void clearScreen() {
	system("cls");
}

void waitAndClear() {
	cout << "Нажмите Enter для продолжения...";
	cin.ignore();
	cin.get();
	clearScreen();
}

void printVector(vector<int>& vec, string title) {
	cout << title << ": ";
	if (vec.empty()) {
		cout << "Пусто";
	}
	else {
		for (int num : vec) {
			cout << num << " ";
		}
	}
	cout << endl;
}

void displayMenu() {
	cout << "====================================" << endl;
	cout << "           МЕНЮ ПРОГРАММЫ" << endl;
	cout << "====================================" << endl;
	cout << "1. Ручной ввод матриц" << endl;
	cout << "2. Автоматический ввод матриц" << endl;
	cout << "3. Показать матрицы" << endl;
	cout << "4. Найти пересечение элементов" << endl;
	cout << "5. Найти объединение элементов" << endl;
	cout << "6. Выход" << endl;
	cout << "====================================" << endl;
	cout << "Выберите опцию: ";
}