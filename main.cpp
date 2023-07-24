#include <iostream>
#include "Board.h"
#include "MinMaxNode.h"
#include "LinAlg.h"

using namespace std;

int main() {
    Matrix mat(3, 4);
    mat.print();
    std::vector<float> init {0.1, 0.2, 0.3, 0.4};
    Vector vec(init);
    vec.print();
    cout << "Multiplying these together gives: " << endl;
    Vector resultant = mat * vec;
    resultant.print();

//    Board board;
//    while (board.evaluate() == winner::incomplete) {
//        board.print(cout);
//        int move;
//        do {
//            cout << "Choose a tile from 0-8: " << endl;
//            cout << ">";
//            cin >> move;
//        } while (!board.playMove(move, 'X'));
//        board.print(cout);
//        if(board.evaluate() == winner::incomplete) {
//            cout << "AI Move: " << endl;
//            MinMaxNode aiMove(board, true);
//            board = aiMove.getBestMove();
//        }
//    }
//    board.print(cout);
}
