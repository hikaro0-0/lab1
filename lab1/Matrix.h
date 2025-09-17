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
	int** data;

public:
	Matrix(int r, int c);
	Matrix(const Matrix& other);
	~Matrix();
	void fillMatrixManual();
	void fillMatrixAuto(int minVal = 0, int maxVal = 100);
	void printMatrix() const ;
	vector<int> getAllElements() const;
	static vector<int> Matr_Intersection(const Matrix& matr1, const Matrix& matr2);
	static vector<int> Matr_Union(const Matrix& matr1, const Matrix& matr2);
	int getRows() const { return rows; }
	int getCols() const { return cols; }
	int getElement(int i, int j) const { return data[i][j]; }
	void setElement(int i, int j, int value) { data[i][j] = value; };
};
#endif