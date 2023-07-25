#include "Layer.h"

using namespace std;

InputLayer::InputLayer(int nodeCount): nodeCount{nodeCount}, values{Vector(nodeCount)} {}

int InputLayer::getNodeCount() const {return nodeCount;}

void InputLayer::setValues(std::vector<float> &newVals) {values.setValues(newVals);}

//Since a read-in file is not specified, weights and biases are random from -1 to 1
SubsequentLayer::SubsequentLayer(int nodeCount, int prevNodeCount): InputLayer{nodeCount},
                                weights{Matrix(nodeCount, prevNodeCount)},
                                biases{Vector(nodeCount)} {
}

void SubsequentLayer::setValues(const InputLayer& prevLayer) {
    values = weights * prevLayer.values + biases;
    values.applyTanh();
}

Vector& SubsequentLayer::getVector() {
    return values;
}