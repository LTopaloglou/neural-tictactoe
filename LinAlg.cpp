#include "LinAlg.h"

#include <utility>

using namespace std;

vector<float> randVec(int elements) {
    //TODO: Should random values be between 0,1 or -1,1?
    vector<float> vec;
    for (int i = 0; i < elements; ++i) vec.emplace_back(static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
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

Vector::Vector(int size): size{size}, values{randVec(size)} {}

////Kind of a move constructor - vector used to initialize becomes smut
Vector::Vector(std::vector<float> &init): size(init.size()), values{move(init)} {}

void Vector::print() const {
    cout << "--" << size << " ELEMENT VECTOR--" << endl;
    for (auto el : values) cout << el << " ";
    cout << endl;
}

void Vector::setValues(std::vector<float> &newVals) {
    if (newVals.size() != size) throw length_error("Cannot change vec length after initialization.");
    swap(values, newVals);
}