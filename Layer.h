#ifndef TICTACTOE_LAYER_H
#define TICTACTOE_LAYER_H

#include "LinAlg.h"

//TODO: Should be able to read weights/biases from file, or generate random values

class InputLayer {
protected:
    int nodeCount;
    Vector values;
public:
    explicit InputLayer(int nodeCount);
    void setValues(std::vector<float> &newVals);
    int getNodeCount() const;
};

class SubsequentLayer : public InputLayer {
    int prevNodeCount;
    Matrix weights;
    Vector biases;
public:
    SubsequentLayer(int nodeCount, const InputLayer& prevLayer);
};


#endif //TICTACTOE_LAYER_H
