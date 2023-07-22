#include "Board.h"

Board::Board(): tiles{vector<char>(NUM_TILES, EMPTY_TILE)} {}

Board::Board(const Board& other): tiles{other.tiles} {}

Board::Board(Board&& other) noexcept: tiles{other.tiles} {}

Board &Board::operator=(const Board& other) {
    this->tiles = other.tiles;
    return *this;
}

vector<int> Board::possibleMoves() {
    vector<int> moves;
    for (int i = 0; i < NUM_TILES; ++i) {
        if (tiles.at(i) == EMPTY_TILE) moves.emplace_back(i);
    }
    return moves;
}

bool Board::playMove(int spot, char player) {
    if (spot >= 0 && spot < 9 && tiles.at(spot) == EMPTY_TILE) {
        tiles.at(spot) = player;
        return true;
    }
    return false;
}

bool Board::checkRow(int row) {
    int offset = 3*row;
    return (tiles[0+offset] == tiles[1+offset] && tiles[0+offset] == tiles[2+offset]);
}

bool Board::checkColumn(int column) {
    return (tiles[0+column] == tiles[3+column] && tiles[0+column] == tiles[6+column]);
}

bool Board::checkDiagonals() {
    return (tiles[0] == tiles[4] && tiles[0] == tiles[8])
    || (tiles[2] == tiles[4] && tiles[2] == tiles[6]);
}

bool Board::checkTie() {
    for (char c : tiles) {
        if (c == EMPTY_TILE) return false;
    }
    return true;
}

winner Board::evaluate() {
    for (int i = 0; i < 3; ++i) {
        if (checkRow(i)) {
            if (tiles[3*i] == PLAYER_TILE) return winner::player;
            if (tiles[3*i] == AI_TILE) return winner::player;
        }
        if (checkColumn(i)) {
            if (tiles[i] == PLAYER_TILE) return winner::player;
            if (tiles[i] == AI_TILE) return winner::player;
        }
    }
    if (checkDiagonals()) {
        if (tiles[4] == PLAYER_TILE) return winner::player;
        if (tiles[4] == AI_TILE) return winner::player;
    }
    return (checkTie()) ? winner::tie : winner::incomplete;
}

void Board::print(ostream &out) {
    out << "_______" << endl;
    out << "|" << tiles[0] << "|" << tiles[1] << "|" << tiles[2] << "|" << endl;
    out << "|_|_|_|" << endl;
    out << "|" << tiles[3] << "|" << tiles[4] << "|" << tiles[5] << "|" << endl;
    out << "|_|_|_|" << endl;
    out << "|" << tiles[6] << "|" << tiles[7] << "|" << tiles[8] << "|" << endl;
    out << "|_|_|_|" << endl;
}

//This method aiMove should only be used by compute, and spot should be chosen from
//the list of possibleMoves(), but there is some error throwing here for redeundancy
Board Board::playerMove(int spot) {
    Board copy(*this);
    if (!copy.playMove(spot, PLAYER_TILE)) throw "Invalid Move";
    return copy;
}

Board Board::aiMove(int spot) {
    Board copy(*this);
    if (!copy.playMove(spot, AI_TILE)) throw "Invalid Move";
    return copy;
}
