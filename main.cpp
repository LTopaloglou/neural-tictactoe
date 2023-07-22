#include <iostream>
#include "Board.h"

using namespace std;

int main() {
    Board board;
    board.print(cout);
    cout << "Winner: " << board.evaluate() << endl;
    board.playMove(0, 'O');
    board.playMove(1, 'X');
    board.playMove(2, 'O');
    board.playMove(3, 'O');
    board.playMove(4, 'X');
    board.playMove(5, 'X');
    board.playMove(6, 'X');
    board.playMove(7, 'O');
    board.playMove(8, 'O');

    board.print(cout);
    cout << "Winner: " << board.evaluate() << endl;
}
