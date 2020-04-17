#include "board.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

int FIRST_NUM_CODE = 49;
int FIRST_LETTER_CODE = 97;

char** make_default()
{
    char** board = new char*[8];
    for (int i = 0; i < 8; ++i) {
        board[i] = new char[8];
    }
    board[0][0] = 'c';
    board[0][1] = 'h';
    board[0][2] = 'e';
    board[0][3] = 'q';
    board[0][4] = 'k';
    board[0][5] = 'e';
    board[0][6] = 'h';
    board[0][7] = 'c';
    for (int i = 0; i < 8; ++i) {
        board[1][i] = 'p';
        board[6][i] = 'P';
    }
    for (int i = 2; i < 6; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = ' ';
        }
    }
    board[7][0] = 'C';
    board[7][1] = 'H';
    board[7][2] = 'E';
    board[7][3] = 'K';
    board[7][4] = 'Q';
    board[7][5] = 'E';
    board[7][6] = 'H';
    board[7][7] = 'C';
    return board;
}

bool print(char** board)
{
    std::fstream out;
    out.open("board.txt", std::fstream::out);
    std::string str;
    str += ' ';
    char c = 'a';
    for (int i = 0; i < 8; ++i) {
        str += c;
        c++;
    }
    out << str << std::endl;
    for (int i = 0; i < 8; ++i) {
        out << i + 1 << board[i] << std::endl;
    }
    out.close();
    return true;
}

void show(char** board)
{
    std::cout << " abcdefgh" << std::endl;
    for (int i = 0; i < 8; ++i) {
        std::cout << i + 1 << board[i] << std::endl;
    }
    std::cout << std::endl;
}

void chess_move(char** board, std::string str)
{
    int i, j, k, l;
    if (str.size() < 5) {
        std::cout << "invalid input" << std::endl;
        return;
    }
    i = str[0] - FIRST_LETTER_CODE;
    j = str[1] - FIRST_NUM_CODE;
    if (i < 0 || i > 7 || j < 0 || j > 7
        || (board[j][i] != 'P' && board[j][i] != 'p')) {
        std::cout << "invalid input" << std::endl;
        return;
    }
    k = str[3] - FIRST_LETTER_CODE;
    l = str[4] - FIRST_NUM_CODE;
    if (k < 0 || k > 7 || l < 0 || l > 7 || board[l][k] != ' ') {
        std::cout << "invalid input" << std::endl;
        return;
    }
    if (k != i) {
        std::cout << "invalid input" << std::endl;
        return;
    }
    if (board[j][i] == 'p') {
        if (j == 1) {
            if (l - j > 2) {
                std::cout << "invalid input" << std::endl;
                return;
            }
        } else {
            if (l - j != 1) {
                std::cout << "invalid input" << std::endl;
                return;
            }
        }
    }
    if (board[j][i] == 'P') {
        if (j == 6) {
            if (j - l > 2) {
                std::cout << "invalid input" << std::endl;
                return;
            }
        } else {
            if (j - l != 1) {
                std::cout << "invalid input" << std::endl;
                return;
            }
        }
    }
    board[l][k] = board[j][i];
    board[j][i] = ' ';
}

void clear(char** board)
{
    for (int i = 0; i < 8; ++i) {
        delete[] board[i];
    }
    delete[] board;
}