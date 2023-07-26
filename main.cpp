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
//    vector<float> input = {0.0, 1.0};
//    NeuralNet net(2);
//    net.addLayer(2);
//    net.addLayer(3);
//    net.addLayer(5);
//    net.addLayer(2);
//    net.fwdProp(input).print();

    vector<vector<float>> temp1;
    temp1.emplace_back(vector<float>{1, 2, 3});
    temp1.emplace_back(vector<float>{4, 5, 6});
    vector<vector<float>> temp2;
    temp2.emplace_back(vector<float>{7});
    temp2.emplace_back(vector<float>{8});
    temp2.emplace_back(vector<float>{9});
    Matrix mat1(temp1);
    Matrix mat2(temp2);
    Matrix mat3 = mat1*mat2;
    mat1.print();
    mat2.print();
    mat3.print();
    Vector floats(1.5, 10);
    floats.print();
    Matrix mat4 = mat1.transpose();
    mat1.print();
    mat4.print();
    vector<float> temp3{1, 2, 3};
    vector<float> temp4{4, 5, 6};
    Vector vec1(temp3);
    Vector vec2(temp4);
    vec1.print();
    vec2.print();
    Matrix mat5 = vec1.outerProduct(vec2);
    mat5.print();
    Matrix mat6 = vec2.outerProduct(vec1);
    mat6.print();

}
