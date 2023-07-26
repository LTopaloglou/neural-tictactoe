#ifndef TICTACTOE_LINALG_H
#define TICTACTOE_LINALG_H

#include <vector>
#include <iostream>

class Vector;

class Matrix{
    int numRows, numCols;
    std::vector<std::vector<float>> values;
public:
    Matrix(int numRows, int numCols);
    explicit Matrix(std::vector<std::vector<float>> &init);
    void print() const;
    Vector operator*(const Vector& vec) const;
    Matrix operator*(const Matrix& other) const;
};

class Vector{
    int size;
    std::vector<float> values;
public:
    friend Matrix;
    explicit Vector(int size);
    explicit Vector(std::vector<float> &init);
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other) noexcept;
    void print() const;
    void setValues(std::vector<float> &newVals);
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(const Vector& other) const;
    Vector Tanh();
    //TODO: need some way to transpose a vector so can matrix x vec multiply
};

#endif //TICTACTOE_LINALG_H
