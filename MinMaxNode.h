#ifndef TICTACTOE_MINMAXNODE_H
#define TICTACTOE_MINMAXNODE_H

#include "Board.h"

class MinMaxNode {
    Board board;
    //This represents if its the AI or player's turn to move.
    //It is a max turn when it is the AI's turn to play a move.
    //It is a min turn when it is the player's turn to play a move.
    bool aiTurn;
    //This integer could be 1, 0 or -1.
    //1 represents a winning move.
    //0 represents an even move.
    //-1 represents a losing move.
    int cost;

    //Node for the best possible next move. Note that it is contained in nextmoves as well
    MinMaxNode* bestMove;

    //Generates nextMoves, sets cost and bestMove
    void calculateCost();
public:
    MinMaxNode(Board board, bool aiTurn);
    ~MinMaxNode();
    int getCost() const;
    Board getBestMove() const;
};

#endif //TICTACTOE_MINMAXNODE_H
