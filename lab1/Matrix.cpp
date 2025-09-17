#include "Matrix.h"

Matrix::Matrix(int r, int c) : rows(r), cols(c)
{
	data = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		data[i] = new int[cols];
	}
};

Matrix::~Matrix() {
	for (int i = 0; i < rows; i++)
	{
		delete[] data[i];
	}
	delete[] data;
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols)
{
	data = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		data[i] = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			data[i][j] = other.data[i][j];
		}
	}
}


void Matrix::fillMatrixManual() {
	cout << "Заполните массив:" << rows << "x" << cols << endl;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
		{
			cout << "Элемент [" << i << "][" << j << "]:";
			cin >> data[i][j];
		}
	}
}

void Matrix::fillMatrixAuto(int minVal, int maxVal) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(minVal, maxVal);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] = dist(gen);
		}
	}
}

void Matrix::printMatrix() const {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}

vector<int> Matrix::getAllElements() const {
	vector<int> elements;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
		{
			elements.push_back(data[i][j]);
		}
	}
	return elements;
}

vector<int> Matrix::Matr_Intersection(Matrix& matr1, Matrix& matr2) {
	vector<int> elements1 = matr1.getAllElements();
	vector<int> elements2 = matr2.getAllElements();

	set<int> set1(elements1.begin(), elements1.end());
	set<int> set2(elements2.begin(), elements2.end());

	vector<int> intersection;

	for (int num : set1)
	{
		if (set2.find(num) != set2.end()) {
			intersection.push_back(num);
		}
	}

	return intersection;
}

vector<int> Matrix::Matr_Union(Matrix& matr1, Matrix& matr2) {
	vector<int> elements1 = matr1.getAllElements();
	vector<int> elements2 = matr2.getAllElements();

	set<int> unionSet(elements1.begin(), elements1.end());

	unionSet.insert(elements2.begin(), elements2.end());

	vector<int> unionVec(unionSet.begin(), unionSet.end());

	return unionVec;

}



