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

			cout << "Введите размер первой матрицы (строки столбцы): ";
			cin >> rows >> cols;
			matr1 = new Matrix(rows, cols);
			matr1->fillMatrixManual();

			cout << "Введите размер второй матрицы (строки столбцы): ";
			cin >> rows >> cols;
			matr2 = new Matrix(rows, cols);
			matr2->fillMatrixManual();

			cout << "Матрицы успешно созданы!" << endl;
			waitAndClear();
			break;
		}

		case 2: {
			if (matr1 != nullptr) delete matr1;
			if (matr2 != nullptr) delete matr2;

			cout << "Введите размер первой матрицы (строки столбцы): ";
			cin >> rows >> cols;
			matr1 = new Matrix(rows, cols);

			cout << "Введите размер второй матрицы (строки столбцы): ";
			cin >> rows >> cols;
			matr2 = new Matrix(rows, cols);

			int minVal;
			int maxVal;
			cout << "Введите минимальное значение: ";
			cin >> minVal;
			cout << "Введите максимальное значение: ";
			cin >> maxVal;

			matr1->fillMatrixAuto(minVal, maxVal);
			matr2->fillMatrixAuto(minVal, maxVal);

			cout << "Матрицы успешно созданы автоматически!" << endl;
			waitAndClear();
			break;
		}

		case 3: {
			if (matr1 != nullptr && matr2 != nullptr) {
				cout << "Первая матрица:" << endl;
				matr1->printMatrix();
				cout << "Вторая матрица: " << endl;
				matr2->printMatrix();
				cout << "Нажмите Enter для возврата в меню...";
				cin.ignore();
				cin.get();
			}
			else {
				cout << "Матрицы не созданы! Сначала выберите опцию 1 или 2." << endl;
				waitAndClear();
			}
			break;
		}

		case 4: {
			if (matr1 != nullptr && matr2 != nullptr) {
				vector<int> intersection = Matrix::Matr_Intersection(*matr1, *matr2);
				printVector(intersection, "Пересечение элементов");
				waitAndClear();
			}
			else {
				cout << "Матрицы не созданы! Сначала выберите опцию 1 или 2." << endl;
				waitAndClear();
			}
			break;
		}

		case 5: {
			if (matr1 != nullptr && matr2 != nullptr) {
				vector<int> union_elements = Matrix::Matr_Union(*matr1, *matr2);
				printVector(union_elements, "Объединение элементов");
				waitAndClear();
			}
			else {
				cout << "Матрицы не созданы! Сначала выберите опцию 1 или 2." << endl;
				waitAndClear();
			}
			break;
		}

		case 6: {
			cout << "Выход из программы..." << endl;
			break;
		}

		default: {
			cout << "Неверный выбор! Попробуйте снова." << endl;
			waitAndClear();
			break;
		}
		}

	} while (choice != 6);

	if (matr1 != nullptr) delete matr1;
	if (matr2 != nullptr) delete matr2;
}
