#include <iostream>
#include "chess.h"

static constexpr int BOARD_SIZE = 8;

chessboard::chessboard() : Matrix<piece*>(BOARD_SIZE) {
    initChessboard();
}

chessboard::chessboard(const chessboard& other)
    : Matrix(other.getSize())
{
    for (int i = 0; i < BOARD_SIZE; ++i)
        for (int j = 0; j < BOARD_SIZE; ++j) {
            piece* p = other.getElement(i, j);
            this->setElement(i, j, p ? p->clone() : nullptr);
        }
}

chessboard& chessboard::operator=(const chessboard& other) {
    if (this != &other) {

        for (int i = 0; i < BOARD_SIZE; ++i)
            for (int j = 0; j < BOARD_SIZE; ++j)
                delete this->getElement(i, j);

        Matrix::operator=(other);

        for (int i = 0; i < BOARD_SIZE; ++i)
            for (int j = 0; j < BOARD_SIZE; ++j) {
                piece* p = other.getElement(i, j);
                this->setElement(i, j, p ? p->clone() : nullptr);
            }
    }
    return *this;
}


chessboard::~chessboard() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            delete this->getElement(i, j);
        }
    }
}

void chessboard::initChessboard() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            this->setElement(i, j, nullptr);
        }
    }

    bool isBlack = false;

    this->setElement(0, 0, new rook(0, 0, isBlack));
    this->setElement(0, 1, new knight(0, 1, isBlack));
    this->setElement(0, 2, new bishop(0, 2, isBlack));
    this->setElement(0, 3, new queen(0, 3, isBlack));
    this->setElement(0, 4, new king(0, 4, isBlack));
    this->setElement(0, 5, new bishop(0, 5, isBlack));
    this->setElement(0, 6, new knight(0, 6, isBlack));
    this->setElement(0, 7, new rook(0, 7, isBlack));

    for (int j = 0; j < BOARD_SIZE; ++j) {
        this->setElement(1, j, new pawn(1, j, isBlack));
    }

    bool isWhite = true;

    this->setElement(7, 0, new rook(7, 0, isWhite));
    this->setElement(7, 1, new knight(7, 1, isWhite));
    this->setElement(7, 2, new bishop(7, 2, isWhite));
    this->setElement(7, 3, new queen(7, 3, isWhite));
    this->setElement(7, 4, new king(7, 4, isWhite));
    this->setElement(7, 5, new bishop(7, 5, isWhite));
    this->setElement(7, 6, new knight(7, 6, isWhite));
    this->setElement(7, 7, new rook(7, 7, isWhite));

    for (int j = 0; j < BOARD_SIZE; ++j) {
        this->setElement(6, j, new pawn(6, j, isWhite));
    }
}

void chessboard::printChessboard() const {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            std::cout << getPiece(i, j) << " ";
        }
        std::cout << std::endl;
    }
}


char chessboard::getPiece(int row, int col) const {
    piece* p = this->getElement(row, col);

    if (p == nullptr) {
        return '.';
    }
    
    return p->getSymbol(); 
}

bool chessboard::isempty(int row, int col) const {
    piece* p = this->getElement(row, col);
    return p == nullptr;
}