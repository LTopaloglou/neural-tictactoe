#include <iostream>
#include <random>
#include <chrono>
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
        } while (!board.playMove(move, Board::PLAYER_TILE));
        board.print(cout);
        if(board.evaluate() == winner::incomplete) {
            cout << "AI Move: " << endl;
            MinMaxNode aiMove(board, true);
            board = aiMove.getBestMove();
        }
    }
    board.print(cout);
}

vector<float> getMinMaxScores(Board board) {
    vector<float> scores(9, 0.0);
    vector<int> possMoves = board.possibleMoves();
    for (int move : possMoves) {
        MinMaxNode minmax(board.aiMove(move), false);
        scores.at(move) = minmax.getCost();
    }
    return scores;
}

void generateTrainingData(int numGames, vector<vector<float>> &boardStates, vector<vector<float>> &moveWeights) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine rng{seed};
    for (int i = 0; i < numGames; ++i) {
        Board board;
        vector<int> moves = board.possibleMoves();
        shuffle(moves.begin(), moves.end(), rng);

        while (board.evaluate() == winner::incomplete) {
            //PLAYER MOVE
            int nextMove = moves.back();
            moves.pop_back();
            board.playMove(nextMove, Board::PLAYER_TILE);

            //SAVE BOARD STATE, MIN_MAX VECTOR HERE
            boardStates.emplace_back(board.getBoardState());
            moveWeights.emplace_back(getMinMaxScores(board));

            //AI MOVE
            if (board.evaluate() == winner::incomplete) {
                nextMove = moves.back();
                moves.pop_back();
                board.playMove(nextMove, Board::AI_TILE);
            }
        }
    }
}

int main() {
    srand((unsigned int)time(NULL));

    vector<vector<float>> boardStates;
    vector<vector<float>> moveWeights;
    generateTrainingData(10, boardStates, moveWeights);

    NeuralNet net(9);
    net.addLayer(9);
    net.addLayer(9);
    net.train(0.1, boardStates, moveWeights);

}
