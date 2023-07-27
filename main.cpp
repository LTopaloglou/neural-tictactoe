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

void generateFirstTurnTrainingData(int numGames, vector<vector<float>> &boardStates, vector<vector<float>> &moveWeights) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine rng{seed};
    for (int i = 0; i < numGames; ++i) {
        Board board;
        vector<int> moves = board.possibleMoves();
        shuffle(moves.begin(), moves.end(), rng);

        //PLAYER MOVE
        int nextMove = moves.back();
        moves.pop_back();
        board.playMove(nextMove, Board::PLAYER_TILE);

        //SAVE BOARD STATE, MIN_MAX VECTOR HERE
        boardStates.emplace_back(board.getBoardState());
        moveWeights.emplace_back(getMinMaxScores(board));
    }
}

void playNeuralNet(NeuralNet& net) {
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
            vector<float> state = board.getBoardState();
            vector<float> ratings = net.fwdProp(state).getValues();
            for (int i = 0; i < ratings.size(); ++i) cout << " Move: " << i << " Rating: " << ratings.at(i) << endl;
            //Choose the move with the highest rating
            //Try to play it. if fails, play next highest rated
            float lessThan = 100;
            float highestRating = -100;
            for (int i = 0; i < ratings.size(); ++i) if (ratings.at(i) > highestRating && ratings.at(i) < lessThan) {
                move = i;
                highestRating = ratings.at(i);
            }
            while (!board.playMove(move, Board::AI_TILE)) {
                lessThan = ratings.at(move);
                highestRating = -100;
                for (int i = 0; i < ratings.size(); ++i) if (ratings.at(i) > highestRating && ratings.at(i) < lessThan) {
                    move = i;
                    highestRating = ratings.at(i);
                }
            }
        }
    }
    if (board.evaluate() == winner::player) cout << "Congratulations, you beat the neural network!" << endl;
    else if (board.evaluate() == winner::ai) {
        board.print(cout);
        cout << "The neural net has beaten you!" << endl;
    } else cout << "Tie game!" << endl;
}

int main() {
    srand((unsigned int)time(NULL));

    vector<vector<float>> boardStates;
    vector<vector<float>> moveWeights;
    cout << "How many whole games of tictactoe would you like to train the neural net on?" << endl;
    cout << ">";
    int numGames;
    cin >> numGames;
    cout << "Generating training data..." << endl;
    generateTrainingData(numGames, boardStates, moveWeights);
    cout << "How extra first turns would you like to train the neural net on?" << endl;
    cout << ">";
    cin >> numGames;
    cout << "Generating training data..." << endl;
    generateFirstTurnTrainingData(numGames, boardStates, moveWeights);
    NeuralNet net(9);
    net.addLayer(9);
    net.addLayer(9);
    net.addLayer(9);
    cout << "Training neural net..." << endl;
    cout << "Size of dataset: " << boardStates.size() << endl;
    net.train(0.1, boardStates, moveWeights);

    char play;
    do {
        playNeuralNet(net);
        cout << "Would you like to play again? y/n" << endl;
        cout << ">";
        cin >> play;
    } while (play == 'y');
}
