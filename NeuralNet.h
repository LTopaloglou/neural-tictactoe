#ifndef TICTACTOE_NEURALNET_H
#define TICTACTOE_NEURALNET_H

#include "Layer.h"

class NeuralNet {
    int layerCount;
    int inputs;
    InputLayer input;
    std::vector<SubsequentLayer> layers;
public:
    NeuralNet(int inputs);
    void addLayer();
    std::vector<float> fwdProp();
    void backProp();
};


#endif //TICTACTOE_NEURALNET_H
