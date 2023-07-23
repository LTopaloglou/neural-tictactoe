#ifndef TICTACTOE_LAYER_H
#define TICTACTOE_LAYER_H

#include "LinAlg.h"

//TODO: Should be able to read weights/biases from file, or generate random values

class Layer {
protected:
    int nodeCount;
    Vector values;
public:
    Layer(int nodeCount);
    virtual ~Layer() = 0;
    int getNodeCount() const;
};

class InputLayer : public Layer {
};

//TODO: BETTER NAME
class SubsequentLayer : public Layer {
    int prevNodeCount;
    Matrix weights;
    Vector biases;
public:
    SubsequentLayer(int nodeCount, Layer prevLayer);
};


#endif //TICTACTOE_LAYER_H
