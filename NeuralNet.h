#ifndef TICTACTOE_NEURALNET_H
#define TICTACTOE_NEURALNET_H

#include "Layer.h"

class NeuralNet {
    int layerCount;
    int inputCount;
    InputLayer input;
    std::vector<SubsequentLayer> layers;
public:
    explicit NeuralNet(int inputs);
    void addLayer(int nodes);
    Vector& fwdProp(std::vector<float> &inputValues);
    void backProp(float learningRate);
};


#endif //TICTACTOE_NEURALNET_H
