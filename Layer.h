#ifndef TICTACTOE_LAYER_H
#define TICTACTOE_LAYER_H

#include "LinAlg.h"

//TODO: Should be able to read weights/biases from file, or generate random values

class SubsequentLayer;

class InputLayer {
protected:
    int nodeCount;
    Vector values;
public:
    friend SubsequentLayer;
    explicit InputLayer(int nodeCount);
    void setValues(std::vector<float> &newVals);
    int getNodeCount() const;
};

class SubsequentLayer : public InputLayer {
    Matrix weights;
    Vector biases;
public:
    explicit SubsequentLayer(int nodeCount, int prevNodeCount);
    void setValues(const InputLayer& prevLayer);
    Vector& getVector();
};


#endif //TICTACTOE_LAYER_H
