#include "chess.h"

piece::piece(int row, int col, char type, bool isWhite)
    : m_row(row), m_col(col), m_type(type), m_isWhite(isWhite) {}

    piece::piece(const piece& other)
    : m_row(other.m_row), m_col(other.m_col), m_type(other.m_type), m_isWhite(other.m_isWhite) {}

char piece::getSymbol() const {
    if (m_isWhite) {
        return toupper(m_type); 
    } else {
        return tolower(m_type);
    }
}

bool piece::isWhite() const {
    return m_isWhite;
}

pawn::pawn(int row, int col, bool isWhite)
    : piece(row, col, isWhite ? 'P' : 'p', isWhite) {}

piece* pawn::clone() const {
        return new pawn(*this);
}

bishop::bishop(int row, int col, bool isWhite)
    : piece(row, col, isWhite ? 'B' : 'b', isWhite) {}

piece* bishop::clone() const {
        return new bishop(*this);
}

knight::knight(int row, int col, bool isWhite)
    : piece(row, col, isWhite ? 'N' : 'n', isWhite) {}

piece* knight::clone() const {
        return new knight(*this);
}

rook::rook(int row, int col, bool isWhite)
    : piece(row, col, isWhite ? 'R' : 'r', isWhite) {}

piece* rook::clone() const {
        return new rook(*this);
}

queen::queen(int row, int col, bool isWhite)
    : piece(row, col, isWhite ? 'Q' : 'q', isWhite) {}

piece* queen::clone() const {
        return new queen(*this);
}

king::king(int row, int col, bool isWhite)
    : piece(row, col, isWhite ? 'K' : 'k', isWhite) {}

piece* king::clone() const {
        return new king(*this);
}

bool piece::isvalidmove(int newRow, int newCol, const Matrix<piece*>& board) const {
    if (newRow < 0 || newRow >= board.getSize() ||
        newCol < 0 || newCol >= board.getSize()) {
        
            return false;
    }

    piece* targetPiece = board.getElement(newRow, newCol);

    if (targetPiece) {
        if (targetPiece->isWhite() == m_isWhite) {
            return false;
        }
    }

    return true; 
}

bool pawn::isvalidmove(int newRow, int newCol, const Matrix<piece*>& board) const {
    if (!piece::isvalidmove(newRow, newCol, board)) {
        return false;
    }
    
    int direction = m_isWhite ? -1 : 1; 
    int rowDiff = newRow - m_row;
    int colDiff = abs(newCol - m_col);
    
    piece* target = board.getElement(newRow, newCol);

    if (colDiff == 0) { 
        if (rowDiff == direction) {
            return target == nullptr; 
        }
        
        if (rowDiff == 2 * direction) {
            bool atStartingRow = (m_isWhite && m_row == 6) || (!m_isWhite && m_row == 1);
            
            if (atStartingRow && target == nullptr) {
                return board.getElement(m_row + direction, m_col) == nullptr;
            }
        }
        return false;
    }
    
    if (colDiff == 1 && rowDiff == direction) {
        return target != nullptr && target->isWhite() != m_isWhite;
    }

    return false;
}

bool knight::isvalidmove(int newRow, int newCol, const Matrix<piece*>& board) const {
    if (!piece::isvalidmove(newRow, newCol, board)) {
        return false;
    }

    int rowDiff = abs(newRow - m_row);
    int colDiff = abs(newCol - m_col);

    return (rowDiff == 1 && colDiff == 2) || (rowDiff == 2 && colDiff == 1);
}

bool rook::isvalidmove(int newRow, int newCol, const Matrix<piece*>& board) const {
    if (!piece::isvalidmove(newRow, newCol, board)) {
        return false;
    }

    if (m_row != newRow && m_col != newCol) {
        return false;
    }

    int rowDir = (m_row != newRow) ? (newRow > m_row ? 1 : -1) : 0;
    int colDir = (m_col != newCol) ? (newCol > m_col ? 1 : -1) : 0;

    int r = m_row + rowDir;
    int c = m_col + colDir;

    while (r != newRow || c != newCol) {
        if (board.getElement(r, c) != nullptr) {
            return false;
        }
        r += rowDir;
        c += colDir;
    }

    return true;
}

bool bishop::isvalidmove(int newRow, int newCol, const Matrix<piece*>& board) const {
    if (!piece::isvalidmove(newRow, newCol, board)) {
        return false;
    }

    if (abs(newRow - m_row) != abs(newCol - m_col)) {
        return false;
    }

    int rowDir = (newRow > m_row) ? 1 : -1;
    int colDir = (newCol > m_col) ? 1 : -1;

    int r = m_row + rowDir;
    int c = m_col + colDir;

    while (r != newRow) {
        if (board.getElement(r, c) != nullptr) {
            return false;
        }
        r += rowDir;
        c += colDir;
    }

    return true;
}

bool queen::isvalidmove(int newRow, int newCol, const Matrix<piece*>& board) const {
    if (!piece::isvalidmove(newRow, newCol, board)) {
        return false;
    }

    bool isStraight = (m_row == newRow || m_col == newCol);
    bool isDiagonal = (abs(newRow - m_row) == abs(newCol - m_col));

    if (!isStraight && !isDiagonal) {
        return false;
    }

    int rowDir = 0;
    int colDir = 0;

    if (isStraight) {
        rowDir = (m_row != newRow) ? (newRow > m_row ? 1 : -1) : 0;
        colDir = (m_col != newCol) ? (newCol > m_col ? 1 : -1) : 0;
    } else {
        rowDir = (newRow > m_row) ? 1 : -1;
        colDir = (newCol > m_col) ? 1 : -1;
    }
    
    int r = m_row + rowDir;
    int c = m_col + colDir;

    while (r != newRow || c != newCol) {
        if (board.getElement(r, c) != nullptr) {
            return false;
        }
        r += rowDir;
        c += colDir;
    }

    return true;
}

bool king::isvalidmove(int newRow, int newCol, const Matrix<piece*>& board) const {
    if (!piece::isvalidmove(newRow, newCol, board)) {
        return false;
    }

    int rowDiff = abs(newRow - m_row);
    int colDiff = abs(newCol - m_col);

    bool isOneStep = (rowDiff <= 1) && (colDiff <= 1);
    
    return isOneStep;
}