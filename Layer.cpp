#include "Layer.h"

Layer::Layer(int nodeCount): nodeCount{nodeCount}, values{Vector(nodeCount)} {}

int Layer::getNodeCount() const {return nodeCount;}

SubsequentLayer::SubsequentLayer(int nodeCount, Layer prevLayer): Layer{nodeCount},
                                weights{Matrix(nodeCount, prevLayer.getNodeCount())},
                                biases{Vector(nodeCount)} {
    //TODO: since file not specified, random weights/biasess
}