#include "Layer.h"

using namespace std;

InputLayer::InputLayer(int nodeCount): nodeCount{nodeCount}, activations{Vector(nodeCount)} {}

int InputLayer::getNodeCount() const {return nodeCount;}

Vector InputLayer::getActivations() {return activations;}

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

Vector SubsequentLayer::adjustParams(Vector dC_da, Vector nextActivations, float learnRate) {
    Vector dC_dz = dC_da * (Vector(1.0, nodeCount) - (states.Tanh())*(states.Tanh()));
    //1. calculate dC_da for the next layer
    Vector dC_da_next = (weights.transpose()) * (dC_dz);
    //2. calculate, apply dC_db and dC_dw for this layer
    Vector dC_db = dC_dz; //SHOULD I EVEN CALCULATE THIS?
    Matrix dC_dw = dC_dz.outerProduct(nextActivations);
    biases = biases - (dC_db * learnRate);
    weights = weights - (dC_dw * learnRate);
    //3. return dC_da for the next layer
    return dC_da_next;
}