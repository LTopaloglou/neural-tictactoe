#include "MinMaxNode.h"

void MinMaxNode::calculateCost() {
    for (int i : board.possibleMoves()) {
        MinMaxNode* move = (aiTurn) ? new MinMaxNode(board.aiMove(i), !aiTurn)
                : new MinMaxNode(board.playerMove(i), !aiTurn);
        if (bestMove == nullptr || (aiTurn && move->getCost() > cost) || (!aiTurn && move->getCost() < cost)) {
            delete bestMove;
            cost = move->getCost();
            bestMove = move;
        } else delete move;
    }
}

MinMaxNode::MinMaxNode(Board board, bool aiTurn): board{board}, aiTurn{aiTurn}, bestMove{nullptr} {
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
   delete bestMove;
}

int MinMaxNode::getCost() const {return cost;}

Board MinMaxNode::getBestMove() const {return bestMove->board;}