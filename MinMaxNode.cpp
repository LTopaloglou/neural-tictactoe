#include "MinMaxNode.h"

void MinMaxNode::calculateCost() {
    //TODO: CLEAN THIS UP
    vector<int> moves = board.possibleMoves();
    if (aiTurn) {
        cost = -1;
        for (int i : moves) {
            MinMaxNode* move = new MinMaxNode(board.aiMove(i), !aiTurn);
            nextMoves.emplace_back(move);
            if(move->getCost() > cost) {
                cost = move->getCost();
                bestMove = move;
            }
        }
    } else {
        cost = 1;
        for (int i : moves) {
            MinMaxNode* move = new MinMaxNode(board.playerMove(i), !aiTurn);
            nextMoves.emplace_back(move);
            if (move->getCost() < cost) {
                cost = move->getCost();
                bestMove = move;
            }
        }
    }
}

MinMaxNode::MinMaxNode(Board board, bool aiTurn): board{board}, aiTurn{aiTurn} {
    switch (board.evaluate()) {
        case winner::player:
            cost = -1;
            break;
        case winner::ai:
            cost = 1;
            break;
        case winner::tie:
            cost = 0;
            break;
        case winner::incomplete:
            calculateCost();
            break;
    }
}

MinMaxNode::~MinMaxNode() {
    for(MinMaxNode* ptr : nextMoves) delete ptr;
}

int MinMaxNode::getCost() {return cost;}