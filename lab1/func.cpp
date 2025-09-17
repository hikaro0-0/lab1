#include "func.h"

void clearScreen() {
	system("cls");
}

void waitAndClear() {
	cout << "������� Enter ��� �����������...";
	cin.ignore();
	cin.get();
	clearScreen();
}

void printVector(vector<int>& vec, string title) {
	cout << title << ": ";
	if (vec.empty()) {
		cout << "�����";
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
	cout << "           ���� ���������" << endl;
	cout << "====================================" << endl;
	cout << "1. ������ ���� ������" << endl;
	cout << "2. �������������� ���� ������" << endl;
	cout << "3. �������� �������" << endl;
	cout << "4. ����� ����������� ���������" << endl;
	cout << "5. ����� ����������� ���������" << endl;
	cout << "6. �����" << endl;
	cout << "====================================" << endl;
	cout << "�������� �����: ";
}