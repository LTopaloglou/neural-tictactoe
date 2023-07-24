#include "Layer.h"

InputLayer::InputLayer(int nodeCount): nodeCount{nodeCount}, values{Vector(nodeCount)} {}

int InputLayer::getNodeCount() const {return nodeCount;}

void InputLayer::setValues(std::vector<float> &newVals) {values.setValues(newVals);}

SubsequentLayer::SubsequentLayer(int nodeCount, const InputLayer& prevLayer): InputLayer{nodeCount},
                                prevNodeCount{prevLayer.getNodeCount()},
                                weights{Matrix(nodeCount, prevNodeCount)},
                                biases{Vector(nodeCount)} {
    //TODO: since file not specified, random weights/biasess
}