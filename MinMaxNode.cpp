#include "MinMaxNode.h"

void MinMaxNode::calculateCost() {
    //TODO: CLEAN THIS UP
    vector<int> moves = board.possibleMoves();
    if (aiTurn) {
        cost = -1;
        for (int i : moves) {
            MinMaxNode* move = new MinMaxNode(board.aiMove(i), !aiTurn);
            if(move->getCost() > cost) {
                cost = move->getCost();
                delete bestMove;
                bestMove = move;
            }
        }
    } else {
        cost = 1;
        for (int i : moves) {
            MinMaxNode* move = new MinMaxNode(board.playerMove(i), !aiTurn);
            if (move->getCost() < cost) {
                cost = move->getCost();
                delete bestMove;
                bestMove = move;
            }
        }
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