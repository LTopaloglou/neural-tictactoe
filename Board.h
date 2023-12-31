#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

#include <vector>
#include <iostream>

using namespace std;

enum winner{incomplete, tie, player, ai};

class Board {
    static inline int NUM_TILES = 9;
    static inline char EMPTY_TILE = ' ';

    vector<char> tiles;

    bool checkRow(int row);
    bool checkColumn(int column);
    bool checkDiagonals();
    bool checkTie();

public:
    static inline char PLAYER_TILE = 'X';
    static inline char AI_TILE = 'O';
    Board();
    Board(const Board& other);
    Board(Board&& other) noexcept;
    Board& operator=(const Board& other);
    vector<int> possibleMoves();
    bool playMove(int spot, char player);
    winner evaluate();
    void print(ostream &out);
    Board playerMove(int spot);
    Board aiMove(int spot);
    std::vector<float> getBoardState();
};


#endif //TICTACTOE_BOARD_H
