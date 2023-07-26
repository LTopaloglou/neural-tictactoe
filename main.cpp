#include <iostream>
#include "Board.h"
#include "MinMaxNode.h"
#include "NeuralNet.h"

using namespace std;

void playMinMax() {
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

int main() {
    srand((unsigned int)time(NULL));
    vector<float> wantedOutput = {-0.5, 0.5};
    vector<float> input = {0.0, 1.0};
    NeuralNet net(2);
    net.addLayer(2);
    net.addLayer(3);
    net.addLayer(5);
    net.addLayer(2);
    for (int i = 0; i < 50; ++i) {
        net.fwdProp(input);
        net.backProp(0.1, wantedOutput);
    }
    net.fwdProp(input).print();
}
