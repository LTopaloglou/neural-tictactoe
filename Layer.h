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
    Vector getActivations();
    int getNodeCount() const;
};

class SubsequentLayer : public InputLayer {
    Matrix weights;
    Vector biases;
    Vector states;
public:
    explicit SubsequentLayer(int nodeCount, int prevNodeCount);
    void calculateActivations(const InputLayer& prevLayer);
    Vector adjustParams(Vector dC_da, Vector nextActivations, float learnRate);
};


#endif //TICTACTOE_LAYER_H
