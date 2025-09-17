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
        case 1:
            handleMatrixCreation(matr1, matr2, false);
            break;

        case 2:
            handleMatrixCreation(matr1, matr2, true);
            break;

        case 3:
            handleMatrixDisplay(matr1, matr2);
            break;

        case 4:
            handleMatrixOperation(matr1, matr2, "intersection");
            break;

        case 5:
            handleMatrixOperation(matr1, matr2, "union");
            break;

        case 6:
            cout << "����� �� ���������..." << endl;
            break;

        default:
            cout << "�������� �����! ���������� �����." << endl;
            waitAndClear();
            break;
        }

    } while (choice != 6);

    if (matr1 != nullptr) delete matr1;
    if (matr2 != nullptr) delete matr2;
}

// Helper functions
void handleMatrixCreation(Matrix*& matr1, Matrix*& matr2, bool autoFill) {
    if (matr1 != nullptr) delete matr1;
    if (matr2 != nullptr) delete matr2;

    int rows, cols;
    cout << "������� ������ ������ ������� (������ �������): ";
    cin >> rows >> cols;
    matr1 = new Matrix(rows, cols);

    cout << "������� ������ ������ ������� (������ �������): ";
    cin >> rows >> cols;
    matr2 = new Matrix(rows, cols);

    if (autoFill) {
        int minVal, maxVal;
        cout << "������� ����������� ��������: ";
        cin >> minVal;
        cout << "������� ������������ ��������: ";
        cin >> maxVal;

        matr1->fillMatrixAuto(minVal, maxVal);
        matr2->fillMatrixAuto(minVal, maxVal);
        cout << "������� ������� ������� �������������!" << endl;
    }
    else {
        matr1->fillMatrixManual();
        matr2->fillMatrixManual();
        cout << "������� ������� �������!" << endl;
    }

    waitAndClear();
}

void handleMatrixDisplay(Matrix* matr1, Matrix* matr2) {
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
}

void handleMatrixOperation(Matrix* matr1, Matrix* matr2, const string& operation) {
    if (matr1 != nullptr && matr2 != nullptr) {
        vector<int> result;
        if (operation == "intersection") {
            result = Matrix::Matr_Intersection(*matr1, *matr2);
            printVector(result, "����������� ���������");
        }
        else if (operation == "union") {
            result = Matrix::Matr_Union(*matr1, *matr2);
            printVector(result, "����������� ���������");
        }
        waitAndClear();
    }
    else {
        cout << "������� �� �������! ������� �������� ����� 1 ��� 2." << endl;
        waitAndClear();
    }
}