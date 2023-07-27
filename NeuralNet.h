#ifndef TICTACTOE_NEURALNET_H
#define TICTACTOE_NEURALNET_H

#include "Layer.h"

class NeuralNet {
    int layerCount;
    int inputCount;
    InputLayer input;
    std::vector<SubsequentLayer> layers;
    void backProp(float learningRate, std::vector<float> wantedOutput);
public:
    explicit NeuralNet(int inputs);
    void addLayer(int nodes);
    Vector fwdProp(std::vector<float> &inputValues);
    void train(float learningRate, std::vector<std::vector<float>> givenInputs, std::vector<std::vector<float>> wantedOutputs);
};


#endif //TICTACTOE_NEURALNET_H
