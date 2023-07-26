#ifndef TICTACTOE_LAYER_H
#define TICTACTOE_LAYER_H

#include "LinAlg.h"

//TODO: Should be able to read weights/biases from file, or generate random activations

class SubsequentLayer;

class InputLayer {
protected:
    int nodeCount;
    Vector activations;
public:
    friend SubsequentLayer;
    explicit InputLayer(int nodeCount);
    void setActivations(std::vector<float> &newVals);
    int getNodeCount() const;
};

class SubsequentLayer : public InputLayer {
    Matrix weights;
    Vector biases;
    Vector states;
public:
    explicit SubsequentLayer(int nodeCount, int prevNodeCount);
    void calculateActivations(const InputLayer& prevLayer);
    Vector& getActivations();
};


#endif //TICTACTOE_LAYER_H
