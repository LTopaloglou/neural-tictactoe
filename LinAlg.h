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
    Matrix operator*(float scalar) const;
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix transpose();
};

class Vector{
    int size;
    std::vector<float> values;
public:
    friend Matrix;
    explicit Vector(int size);
    explicit Vector(float value, int size);
    explicit Vector(std::vector<float> &init);
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other) noexcept;
    void print() const;
    void setValues(std::vector<float> &newVals);
    std::vector<float> getValues();
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(const Vector& other) const;
    Vector operator*(float scalar) const;
    Vector Tanh();
    Matrix outerProduct(const Vector& other) const;
    //TODO: need some way to transpose a vector so can matrix x vec multiply
};

Vector operator*(float scalar, const Vector& other);

#endif //TICTACTOE_LINALG_H
