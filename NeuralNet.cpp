#include "NeuralNet.h"

using namespace std;

NeuralNet::NeuralNet(int inputs): layerCount{1}, inputCount{inputs}, input{InputLayer(inputs)} {}

void NeuralNet::addLayer(int nodes) {
    ++layerCount;
    if (layerCount == 1) layers.emplace_back(SubsequentLayer(nodes, &input));
    else layers.emplace_back(SubsequentLayer(nodes, &layers.back()));
}

Vector& NeuralNet::fwdProp(std::vector<float> &inputValues) {
    if (layerCount < 2) throw logic_error("No output layer to return.");
    input.setValues(inputValues);
    for (auto &layer : layers) layer.setValues();
    return layers.back().getVector();
}