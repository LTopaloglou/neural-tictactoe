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
    explicit Matrix(std::vector<std::vector<float>> init);
    void print() const;
    Vector operator*(const Vector& vec) const;
};

class Vector{
    int size;
    std::vector<float> values;
public:
    friend Matrix;
    Vector(int size);
    explicit Vector(std::vector<float> init);
    void print() const;
};

#endif //TICTACTOE_LINALG_H
