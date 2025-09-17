#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <locale>
#include <random>

using namespace std;

class Matrix {
    int rows;
    int cols;
    int** data = nullptr;  

public:
    Matrix(int r, int c);
    ~Matrix();
    Matrix(const Matrix& other);
    Matrix(Matrix&& other) noexcept;
    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix&& other) noexcept;

    void fillMatrixManual();
    void fillMatrixAuto(int minVal = 0, int maxVal = 100);
    void printMatrix() const;
    vector<int> getAllElements() const;
    static vector<int> Matr_Intersection(const Matrix& matr1, const Matrix& matr2);
    static vector<int> Matr_Union(const Matrix& matr1, const Matrix& matr2);
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    int getElement(int i, int j) const { return data[i][j]; }
    void setElement(int i, int j, int value) { data[i][j] = value; };

private:
    void clear();
    void copyFrom(const Matrix& other);
};

void handleMatrixCreation(Matrix*& matr1, Matrix*& matr2, bool autoFill);
void handleMatrixDisplay(Matrix* matr1, Matrix* matr2);
void handleMatrixOperation(Matrix* matr1, Matrix* matr2, const string& operation);

#endif