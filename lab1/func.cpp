#include "func.h"

void clearScreen() {
	system("cls");
}

void waitAndClear() {
	std::cout << "������� Enter ��� �����������...";
	std::cin.ignore();
	std::cin.get();
	clearScreen();
}

void printVector(const std::vector<int>& vec, const std::string& title) {
	std::cout << title << ": ";
	if (vec.empty()) {
		std::cout << "�����";
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
	std::cout << "          ���� ���������" << std::endl;
	std::cout << "====================================" << std::endl;
	std::cout << "1. ������ ���� ������" << std::endl;
	std::cout << "2. �������������� ���� ������" << std::endl;
	std::cout << "3. �������� �������" << std::endl;
	std::cout << "4. ����� ����������� ���������" << std::endl;
	std::cout << "5. ����� ����������� ���������" << std::endl;
	std::cout << "6. �����" << std::endl;
	std::cout << "====================================" << std::endl;
	std::cout << "�������� �����: ";
}