#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <set>
#include <locale>
#include <random>

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
    void fillMatrixAuto(int minVal, int maxVal);
    void printMatrix() const;
    std::vector<int> getAllElements() const;
    static std::vector<int> Matr_Intersection(const Matrix& matr1, const Matrix& matr2);
    static std::vector<int> Matr_Union(const Matrix& matr1, const Matrix& matr2);
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    int getElement(int i, int j) const { return data[i][j]; }
    void setElement(int i, int j, int value) { data[i][j] = value; };

private:
    void clear();
    void copyFrom(const Matrix& other);
};

#endif