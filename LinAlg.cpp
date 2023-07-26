#include "LinAlg.h"

#include <utility>
#include <math.h>

using namespace std;

vector<float> randVec(int elements) {
    vector<float> vec;
    for (int i = 0; i < elements; ++i) vec.emplace_back(2 * (static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) - 1);
    return vec;
}

Matrix::Matrix(int numRows, int numCols): numRows{numRows}, numCols{numCols} {
    for (int i = 0; i < numRows; ++i) values.emplace_back(randVec(numCols));
}

//Kind of a move constructor - vector used to initialize becomes smut
//Assume init has at least 1 row, and # of elements in every row is the same
Matrix::Matrix(std::vector<std::vector<float>> &init): numRows{static_cast<int>(init.size())}, numCols{static_cast<int>(init.at(0).size())}, values{move(init)} {}

void Matrix::print() const {
    cout << "--" << numRows << "x" << numCols << " MATRIX--" << endl;
    for (auto vec : values) {
        for (auto el : vec) {
            cout << el << " ";
        }
        cout << endl;
    }
}

Vector Matrix::operator*(const Vector &vec) const {
    if (numCols != vec.size) throw length_error("Cannot multiply vec and matrix of these dimensions.");
    vector<float> resultant;
    for (auto row : values) {
        float val = 0;
        for (int i = 0; i < numCols; ++i) val += row.at(i) * vec.values.at(i);
        resultant.push_back(val);
    }
    return Vector(resultant);
}

Matrix Matrix::operator*(const Matrix &other) const {
    if (numCols != other.numRows) throw length_error("Cannot multiply matrices of these dimensions.");
    vector<vector<float>> resultant;
    for (int m = 0; m < numRows; ++m) {
        vector<float> singleRow;
        for (int n = 0; n < other.numCols; ++n) {
            float entry = 0;
            for (int i = 0; i < numCols; ++i) entry += values.at(m).at(i) * other.values.at(i).at(n);
            singleRow.emplace_back(entry);
        }
        resultant.emplace_back(singleRow);
    }
    return Matrix(resultant);
}

Vector::Vector(int size): size{size}, values{randVec(size)} {}

////Kind of a move constructor - vector used to initialize becomes smut
Vector::Vector(std::vector<float> &init): size(init.size()), values{move(init)} {
}

//Copy Ctor
Vector::Vector(const Vector &other): size{other.size}, values{other.values} {}

//Copy assignment
Vector& Vector::operator=(const Vector &other) {
    Vector temp(other);
    swap(size, temp.size);
    swap(values, temp.values);
    return *this;
}

//Move assignment
Vector& Vector::operator=(Vector &&other)  noexcept {
    swap(size, other.size);
    swap(values, other.values);
    return *this;
}

void Vector::print() const {
    cout << "--" << size << " ELEMENT VECTOR--" << endl;
    for (auto el : values) cout << el << " ";
    cout << endl;
}

void Vector::setValues(std::vector<float> &newVals) {
    if (newVals.size() != size) throw length_error("Number of elements in vector do not match");
    swap(values, newVals);
}

Vector Vector::operator+(const Vector &other) const {
    if (size != other.size) throw length_error("Cannot add two vectors of different lengths");
    vector<float> resultant;
    for (int i = 0; i < size; ++i) resultant.push_back(values.at(i) + other.values.at(i));
    return Vector(resultant);
}

Vector Vector::operator-(const Vector &other) const {
    if (size != other.size) throw length_error("Cannot add two vectors of different lengths");
    vector<float> resultant;
    for (int i = 0; i < size; ++i) resultant.push_back(values.at(i) - other.values.at(i));
    return Vector(resultant);
}

Vector Vector::operator*(const Vector &other) const {
    if (size != other.size) throw length_error("Cannot add two vectors of different lengths");
    vector<float> resultant;
    for (int i = 0; i < size; ++i) resultant.push_back(values.at(i) * other.values.at(i));
    return Vector(resultant);
}

Vector Vector::operator*(float scalar) const {
    vector<float> resultant;
    for (int i = 0; i < size; ++i) resultant.push_back(values.at(i) * scalar);
    return Vector(resultant);
}

Vector operator*(float scalar, const Vector& other) {
    return other * scalar;
}

Vector Vector::Tanh() {
    vector<float> resultant;
    for (float el : values) resultant.push_back(tanh(el));
    return Vector(resultant);
}