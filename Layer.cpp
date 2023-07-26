#include "Layer.h"

using namespace std;

InputLayer::InputLayer(int nodeCount): nodeCount{nodeCount}, activations{Vector(nodeCount)} {}

int InputLayer::getNodeCount() const {return nodeCount;}

void InputLayer::setActivations(std::vector<float> &newVals) {activations.setValues(newVals);}

//Since a read-in file is not specified, weights and biases are random from -1 to 1
SubsequentLayer::SubsequentLayer(int nodeCount, int prevNodeCount): InputLayer{nodeCount},
                                weights{Matrix(nodeCount, prevNodeCount)},
                                biases{Vector(nodeCount)},
                                states{Vector(nodeCount)} {
}

void SubsequentLayer::calculateActivations(const InputLayer& prevLayer) {
    states = weights * prevLayer.activations + biases;
    activations = states.Tanh();
}

Vector& SubsequentLayer::getActivations() {
    return activations;
}

Vector SubsequentLayer::adjustParams(Vector dC_da) {
    //1. calculate dC_da for the next layer
    //2. calculate, apply dC_db and dC_dw for this layer
    //3. return dC_da for the next layer
}