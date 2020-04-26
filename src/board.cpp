#include "board.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

int FIRST_NUM_CODE = 49;
int FIRST_LETTER_CODE = 97;
int BOARD_SIZE = 8;

int min(int a, int b)
{
    if (a >= b) {
        return b;
    }
    return a;
}

int max(int a, int b)
{
    if (a >= b) {
        return a;
    }
    return b;
}

char** make_default()
{
    char** board = new char*[BOARD_SIZE];
    for (int i = 0; i < 8; ++i) {
        board[i] = new char[BOARD_SIZE];
    }
    board[0][0] = 'r';
    board[0][1] = 'h';
    board[0][2] = 'b';
    board[0][3] = 'q';
    board[0][4] = 'k';
    board[0][5] = 'b';
    board[0][6] = 'h';
    board[0][7] = 'r';
    for (int i = 0; i < BOARD_SIZE; ++i) {
        board[1][i] = 'p';
        board[6][i] = 'P';
    }
    for (int i = 2; i < 6; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
    board[7][0] = 'R';
    board[7][1] = 'H';
    board[7][2] = 'B';
    board[7][3] = 'K';
    board[7][4] = 'Q';
    board[7][5] = 'B';
    board[7][6] = 'H';
    board[7][7] = 'R';
    return board;
}

bool print(char** board)
{
    std::fstream out;
    out.open("board.txt", std::fstream::out);
    std::string str;
    str.push_back(' ');
    char c = 'a';
    for (int i = 0; i < BOARD_SIZE; ++i) {
        str.push_back(c);
        c++;
    }
    out << str << std::endl;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        str.clear();
        for (int j = 0; j < BOARD_SIZE; ++j) {
            str.push_back(board[i][j]);
        }
        out << i + 1 << str << std::endl;
    }
    out.close();
    return true;
}

void show(char** board)
{
    std::cout << " abcdefgh" << std::endl;
    std::string str;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        str.clear();
        for (int j = 0; j < BOARD_SIZE; ++j) {
            str.push_back(board[i][j]);
        }
        std::cout << i + 1 << str << std::endl;
    }
    std::cout << std::endl;
}

bool is_pawn_move_valid(char** board, int i, int j, int k, int l)
{
    if (k != i) {
        return false;
    }
    if (board[j][i] == 'p') {
        if (j == 1) {
            if (l - j > 2) {
                return false;
            }
        } else {
            if (l - j != 1) {
                return false;
            }
        }
    }
    if (board[j][i] == 'P') {
        if (j == 6) {
            if (j - l > 2) {
                return false;
            }
        } else {
            if (j - l != 1) {
                return false;
            }
        }
    }
    for (int n = min(j, l); n <= max(j, l); n++) {
        if (n == j) {
            continue;
        }
        if (board[n][i] != ' ') {
                return false;
        }
    }
    return true;
}

bool is_bishop_move_valid(char** board, int i, int j, int k, int l)
{
    int X_dir = -1;
    int Y_dir = -1;
    int a = i - k;
    int b = j - l;
    if (a < 0) {
        X_dir = 1;
        a *= -1;
    }
    if (b < 0) {
        Y_dir = 1;
        b *= -1;
    }
    if (a != b) {
        return false;
    }
    // std::cout << "let_dir = " << X_dir <<std::endl;
    // std::cout << "num_dir = " << Y_dir <<std::endl;
    i += X_dir;
    j += Y_dir;
    while (i != k && k != l) {
        // std::cout << "b = " << board[j][i] <<std::endl;
        if (board[j][i] != ' ') {
            return false;
        }
        i += X_dir;
        j += Y_dir;
    }
    return true;
}

bool is_horse_move_valid(char** board, int i, int j, int k, int l)
{
    int a = i - k;
    int b = j - l;
    if (a < 0) {
        a *= -1;
    }
    if (b < 0) {
        b *= -1;
    }
    if (a == 2 && b == 1) {
        return true;
    }
    if (a == 1 && b == 2) {
        return true;
    }
    return false;
}

bool is_rook_move_valid(char** board, int i, int j, int k, int l)
{
    if (i != k && j != l) {
        return false;
    }
    if (i == k) {
        for (int n = min(j, l); n < max(j, l); ++n) {
            if (n == j) {
                continue;
            }
            if (board[n][i] != ' ') {
                return false;
            }
        }
    }
    if (j == l) {
        for (int n = min(i, k); n <= max(i, k); ++n) {
            if (n == i) {
                continue;
            }
            if (board[j][n] != ' ') {
                return false;
            }
        }
    }
    return true;
}

bool is_queen_move_valid(char** board, int i, int j, int k, int l)
{
    if (!is_bishop_move_valid(board, i, j, k, l)
        && !is_rook_move_valid(board, i, j, k, l)) {
        return false;
    }
    return true;
}

bool is_king_move_valid(char** board, int i, int j, int k, int l)
{
    int a = i - k;
    int b = j - l;
    if (a < 0) {
        a *= -1;
    }
    if (b < 0) {
        b *= -1;
    }
    if (a > 1 || b > 1) {
        return false;
    }
    return true;
}

bool is_symbols_valid(int i, int j, int k, int l)
{
    if (i < 0 || i > 7 || j < 0 || j > 7) {
        return false;
    }
    if (k < 0 || k > 7 || l < 0 || l > 7) {
        return false;
    }
    return true;
}

bool chess_move(char** board, std::string str)
{
    int i, j, k, l;
    if (str.size() != 5) {
        return false;
    }
    if (str[2] != '-') {
        return false;
    }
    i = str[0] - FIRST_LETTER_CODE;
    j = str[1] - FIRST_NUM_CODE;
    k = str[3] - FIRST_LETTER_CODE;
    l = str[4] - FIRST_NUM_CODE;
    if (!is_symbols_valid(i, j, k, l) || board[l][k] != ' ') {
        return false;
    }
    if (i == j && k == l) {
        return false;
    }
    bool is_valid = false;
    switch (board[j][i]) {
    case 'P':
    case 'p':
        is_valid = is_pawn_move_valid(board, i, j, k, l);
        break;

    case 'R':
    case 'r':
        is_valid = is_rook_move_valid(board, i, j, k, l);
        break;

    case 'B':
    case 'b':
        is_valid = is_bishop_move_valid(board, i, j, k, l);
        break;

    case 'H':
    case 'h':
        is_valid = is_horse_move_valid(board, i, j, k, l);
        break;

    case 'K':
    case 'k':
        is_valid = is_king_move_valid(board, i, j, k, l);
        break;

    case 'Q':
    case 'q':
        is_valid = is_queen_move_valid(board, i, j, k, l);
        break;

    default:
        return false;
    }
    if (!is_valid) {
        return false;
    }
    board[l][k] = board[j][i];
    board[j][i] = ' ';
    return true;
}

void clear(char** board)
{
    for (int i = 0; i < BOARD_SIZE; ++i) {
        delete[] board[i];
    }
    delete[] board;
}