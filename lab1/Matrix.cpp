#include "Matrix.h"

Matrix::Matrix(int r, int c) : rows(r), cols(c), data(nullptr)
{
    if (rows > 0 && cols > 0) {
        data = new int* [rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols](); // Инициализация нулями
        }
    }
}

Matrix::~Matrix() {
    clear();
}

// Конструктор копирования
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(nullptr)
{
    copyFrom(other);
}

// Конструктор перемещения
Matrix::Matrix(Matrix&& other) noexcept
    : rows(other.rows), cols(other.cols), data(other.data)
{
    // Обнуляем указатели у исходного объекта
    other.rows = 0;
    other.cols = 0;
    other.data = nullptr;
}

// Оператор присваивания копированием
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        clear();
        rows = other.rows;
        cols = other.cols;
        copyFrom(other);
    }
    return *this;
}

// Оператор присваивания перемещением
Matrix& Matrix::operator=(Matrix&& other) noexcept {
    if (this != &other) {
        clear();
        // Перемещаем ресурсы
        rows = other.rows;
        cols = other.cols;
        data = other.data;

        // Обнуляем исходный объект
        other.rows = 0;
        other.cols = 0;
        other.data = nullptr;
    }
    return *this;
}

void Matrix::clear() {
    if (data != nullptr) {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
    rows = 0;
    cols = 0;
}

void Matrix::copyFrom(const Matrix& other) {
    if (other.data != nullptr && other.rows > 0 && other.cols > 0) {
        data = new int* [other.rows];
        for (int i = 0; i < other.rows; i++)
        {
            data[i] = new int[other.cols];
            for (int j = 0; j < other.cols; j++)
            {
                data[i][j] = other.data[i][j];
            }
        }
    }
    else {
        data = nullptr;
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

vector<int> Matrix::Matr_Intersection(const Matrix& matr1, const Matrix& matr2) {
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

vector<int> Matrix::Matr_Union(const Matrix& matr1, const Matrix& matr2) {
    vector<int> elements1 = matr1.getAllElements();
    vector<int> elements2 = matr2.getAllElements();

    set<int> unionSet(elements1.begin(), elements1.end());

    unionSet.insert(elements2.begin(), elements2.end());

    vector<int> unionVec(unionSet.begin(), unionSet.end());

    return unionVec;
}