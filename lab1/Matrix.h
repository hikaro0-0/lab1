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
	void printMatrix();
	vector<int> getAllElements();
	static vector<int> Matr_Intersection(Matrix& matr1, Matrix& matr2);
	static vector<int> Matr_Union(Matrix& matr1, Matrix& matr2);
	int getRows() { return rows; }
	int getCols() { return cols; }
	int getElement(int i, int j) { return data[i][j]; }
	void setElement(int i, int j, int value) { data[i][j] = value; };
};
#endif