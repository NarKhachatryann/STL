#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "matrix.h"

class piece {
public:
    int m_row;
    int m_col;
    char m_type;
    bool m_isWhite;

    piece(int row, int col, char type, bool isWhite);
    piece(const piece& other);
    piece() = default;
    virtual piece* clone() const = 0;
    virtual ~piece() = default;

    virtual bool isvalidmove(int newRow, int newCol, const Matrix<piece*>& board) const;

    char getSymbol() const;
    bool isWhite() const;
};

class pawn : public piece {
public:
    pawn(int row, int col, bool isWhite);
    piece* clone() const override;

    bool isvalidmove(int newRow, int newCol, const Matrix<piece*>& board) const override;
};

class bishop : public piece {
public:
    bishop(int row, int col, bool isWhite);
    piece* clone() const override;

    bool isvalidmove(int newRow, int newCol, const Matrix<piece*>& board) const override;
};

class knight : public piece {
public:
    knight(int row, int col, bool isWhite);
    piece* clone() const override;

    bool isvalidmove(int newRow, int newCol, const Matrix<piece*>& board) const override;
};

class rook : public piece {
public:
    rook(int row, int col, bool isWhite);
    piece* clone() const override;

    bool isvalidmove(int newRow, int newCol, const Matrix<piece*>& board) const override;
};

class queen : public piece {
public:
    queen(int row, int col, bool isWhite);
    piece* clone() const override;

    bool isvalidmove(int newRow, int newCol, const Matrix<piece*>& board) const override;
};

class king : public piece {
public:
    king(int row, int col, bool isWhite);
    piece* clone() const override;

    bool isvalidmove(int newRow, int newCol, const Matrix<piece*>& board) const override;
};

class chessboard : public Matrix<piece*> {
public:
    static constexpr int BOARD_SIZE = 8;

    chessboard();

    chessboard(const chessboard& other);
    chessboard& operator=(const chessboard& other);

    void initChessboard();
    void printChessboard() const;
    char getPiece(int row, int col) const;
    bool isempty(int row, int col) const;

    chessboard(chessboard&& other) noexcept = delete;
    chessboard& operator=(chessboard&& other) noexcept = delete;


    virtual ~chessboard();
};

#endif