#include "NeuralNet.h"

using namespace std;

NeuralNet::NeuralNet(int inputs): layerCount{1}, inputCount{inputs}, input{InputLayer(inputs)} {}

void NeuralNet::addLayer(int nodes) {
    if (layerCount == 1) layers.emplace_back(SubsequentLayer(nodes, input.getNodeCount()));
    else layers.emplace_back(SubsequentLayer(nodes, layers.at(layers.size()-1).getNodeCount()));
    ++layerCount;
}

Vector& NeuralNet::fwdProp(std::vector<float> &inputValues) {
    if (layerCount < 2) throw logic_error("No output layer to return.");
    input.setValues(inputValues);
    layers.at(0).setValues(input);
    for (int i = 1; i < layers.size(); ++i) {
        layers.at(i).setValues(layers.at(i-1));
    }
    return layers.back().getVector();
}