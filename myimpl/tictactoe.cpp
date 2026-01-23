#include <iostream>

bool winner(char** matrix, int size, char player) {
    for (int i = 0; i < size; ++i) {
        bool win = true;
        for(int j = 0; j < size; ++j) {
            if(matrix[i][j] != player) {
                win = false;
                break;
            }
        }
        if(win) return true;
    }

    for(int j = 0; j < size; ++j) {
        bool win = true;
        for(int i = 0; i < size; ++i) {
            if(matrix[i][j] != player) {
                win = false;
                break;
            }
        }
        if(win) return true;
    }

    bool win = true;
    for(int i = 0; i < size; ++i) {
        if(matrix[i][i] != player) {
            win = false;
            break;
        }
    }
    if(win) return true;
    
    win = true;
    for(int i = 0; i < size; ++i) {
        if(matrix[i][size - 1 - i] != player) {
            win = false;
        }
    }
    if(win) return true;

    return false;
}

bool matrixchecker(char** matrix, int size) {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            if(matrix[i][j] == ' ') {
                return true;
            }
        }
    }
    return false;
}

void board(char** matrix, int size) {
    std::cout << "\n" << "|---+---+---|" << std::endl;
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            std::cout<< "| " << matrix[i][j] << " ";
        }
        std::cout << "|" << "\n" << "|---+---+---|" << std::endl;
    }
    std::cout << std::endl;

} 

bool check(char** matrix, int size, int row, int col) {
    if(row < 1 || row > size || col < 1 || col > size) {
        return false;
    }
    else if(matrix[row - 1][col - 1] != ' ') {
        return false;
    }
    return true;
}

void game(char** matrix, int size) {
    char playero = 'o';
    char playerx = 'x';
    char player = playerx;
    int row = 0, col = 0;

    board(matrix,size);

    while (true)
    {
        bool checker = false;
        do {
                std::cout << "Enter the row for player " << player << ": ";
                std::cin >> row;
                std::cout << "Enter the column for player " << player << ": ";
                std::cin >> col;
                if(!check(matrix, size, row, col)) {
                    std::cout << "Wrong Row or Column!!" << std::endl << "Try again!" << std::endl;
                } else {
                    checker = true;
                }
            } while(!checker);

        matrix[row - 1][col - 1] = player;

        if(winner(matrix, size, player)) {
            std::cout << "Player " << player << " wins!" << std::endl;
            break;
        }
        if(!matrixchecker(matrix,size)) {
            std::cout << "It is a draw" << std::endl;
            break;
        }
        board(matrix,size);

        if(player == playerx) {
            player = playero;
        } else {
            player = playerx;
        }

    }
}

char** creatematrix(int size) {
    char** matrix = new char*[size];
    for(int  i = 0; i < size; ++i) {
        matrix[i] = new char[size];
    }

    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            matrix[i][j] = ' ';
        }
    }

    return matrix;
}

void deletemat(char** matrix, int size) {
    for(int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int size = 3;
    char** matrix = creatematrix(size);

    game(matrix, size);
    deletemat(matrix, size);

    return 0;
}