#include <iostream>
#include "Board.h"
#include "MinMaxNode.h"

using namespace std;

int main() {
    //TODO: FIX SUB-OPTIMAL PLAY
    //NOTE: AI IS PLAYING FROM 0-9
//    Board test;
//    test.playMove(1, 'X');
//    test.playMove(2, 'O');
//    test.playMove(4, 'X');
//    test.playMove(7, 'O');
//    test.playMove(8, 'X');
//
//    test.print(cout);
//    MinMaxNode testMin(test, true);
//    cout << "Score: " << testMin.getCost() << endl;
//    testMin.getBestMove().print(cout);


    Board board;
    while (board.evaluate() == winner::incomplete) {
        board.print(cout);
        int move;
        do {
            cout << "Choose a tile from 0-8: " << endl;
            cout << ">";
            cin >> move;
        } while (!board.playMove(move, 'X'));
        board.print(cout);
        if(board.evaluate() == winner::incomplete) {
            cout << "AI Move: " << endl;
            MinMaxNode aiMove(board, true);
            board = aiMove.getBestMove();
        }
    }
    board.print(cout);
}
