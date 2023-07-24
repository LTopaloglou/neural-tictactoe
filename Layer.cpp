#include "Layer.h"

InputLayer::InputLayer(int nodeCount): nodeCount{nodeCount}, values{Vector(nodeCount)} {}

int InputLayer::getNodeCount() const {return nodeCount;}

void InputLayer::setValues(std::vector<float> &newVals) {values.setValues(newVals);}

//Since a read-in file is not specified, weights and biases are random from -1 to 1
SubsequentLayer::SubsequentLayer(int nodeCount, InputLayer* prev): InputLayer{nodeCount},
                                prevLayer{prev},
                                weights{Matrix(nodeCount, prev->getNodeCount())},
                                biases{Vector(nodeCount)} {
}

void SubsequentLayer::setValues() {
    values = (weights * prevLayer->values + biases);
    values.recLinActivation();
}

Vector& SubsequentLayer::getVector() {
    return values;
}