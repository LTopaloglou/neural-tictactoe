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
    input.setActivations(inputValues);
    layers.at(0).calculateActivations(input);
    for (int i = 1; i < layers.size(); ++i) {
        layers.at(i).calculateActivations(layers.at(i - 1));
    }
    return layers.back().getActivations();
}

void NeuralNet::backProp(float learningRate, std::vector<float> wantedOutput) {
    Vector dC_da = 2 * (layers.back().getActivations() - Vector(wantedOutput));
    for (int i = layers.size() - 1; i > 0; --i) {
        dC_da = layers.at(i).adjustParams(dC_da, layers.at(i-1).getActivations(), learningRate);
    }
    layers.at(0).adjustParams(dC_da, input.getActivations(), learningRate);
}