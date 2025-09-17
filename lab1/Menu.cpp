#include "Matrix.h"
#include "func.h"

void menu() {
	setlocale(0, "rus");

	int choice;
	int rows;
	int cols;
	Matrix* matr1 = nullptr;
	Matrix* matr2 = nullptr;

	do {
		displayMenu();
		cin >> choice;

		switch (choice) {
		case 1: {
			if (matr1 != nullptr) delete matr1;
			if (matr2 != nullptr) delete matr2;

			cout << "������� ������ ������ ������� (������ �������): ";
			cin >> rows >> cols;
			matr1 = new Matrix(rows, cols);
			matr1->fillMatrixManual();

			cout << "������� ������ ������ ������� (������ �������): ";
			cin >> rows >> cols;
			matr2 = new Matrix(rows, cols);
			matr2->fillMatrixManual();

			cout << "������� ������� �������!" << endl;
			waitAndClear();
			break;
		}

		case 2: {
			if (matr1 != nullptr) delete matr1;
			if (matr2 != nullptr) delete matr2;

			cout << "������� ������ ������ ������� (������ �������): ";
			cin >> rows >> cols;
			matr1 = new Matrix(rows, cols);

			cout << "������� ������ ������ ������� (������ �������): ";
			cin >> rows >> cols;
			matr2 = new Matrix(rows, cols);

			int minVal;
			int maxVal;
			cout << "������� ����������� ��������: ";
			cin >> minVal;
			cout << "������� ������������ ��������: ";
			cin >> maxVal;

			matr1->fillMatrixAuto(minVal, maxVal);
			matr2->fillMatrixAuto(minVal, maxVal);

			cout << "������� ������� ������� �������������!" << endl;
			waitAndClear();
			break;
		}

		case 3: {
			if (matr1 != nullptr && matr2 != nullptr) {
				cout << "������ �������:" << endl;
				matr1->printMatrix();
				cout << "������ �������: " << endl;
				matr2->printMatrix();
				cout << "������� Enter ��� �������� � ����...";
				cin.ignore();
				cin.get();
			}
			else {
				cout << "������� �� �������! ������� �������� ����� 1 ��� 2." << endl;
				waitAndClear();
			}
			break;
		}

		case 4: {
			if (matr1 != nullptr && matr2 != nullptr) {
				vector<int> intersection = Matrix::Matr_Intersection(*matr1, *matr2);
				printVector(intersection, "����������� ���������");
				waitAndClear();
			}
			else {
				cout << "������� �� �������! ������� �������� ����� 1 ��� 2." << endl;
				waitAndClear();
			}
			break;
		}

		case 5: {
			if (matr1 != nullptr && matr2 != nullptr) {
				vector<int> union_elements = Matrix::Matr_Union(*matr1, *matr2);
				printVector(union_elements, "����������� ���������");
				waitAndClear();
			}
			else {
				cout << "������� �� �������! ������� �������� ����� 1 ��� 2." << endl;
				waitAndClear();
			}
			break;
		}

		case 6: {
			cout << "����� �� ���������..." << endl;
			break;
		}

		default: {
			cout << "�������� �����! ���������� �����." << endl;
			waitAndClear();
			break;
		}
		}

	} while (choice != 6);

	if (matr1 != nullptr) delete matr1;
	if (matr2 != nullptr) delete matr2;
}
