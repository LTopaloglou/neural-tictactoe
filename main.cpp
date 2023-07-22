#include <iostream>
#include "Board.h"

using namespace std;

int main() {
    Board board;
    board.playMove(0, 'O');
    board.playMove(1, 'X');
    board.playMove(2, 'O');
    board.print(cout);
    cout << "Winner: " << board.evaluate() << endl;
    cout << endl;

    cout << "Board from move ctor" << endl;
    Board board2 = board.playerMove(3);
    board2.print(cout);
    board2.playMove(4, 'O');
    board2.print(cout);
    cout << endl;

    cout << "initial board" << endl;
    board.print(cout);
}
