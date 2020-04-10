#include <stdio.h>
#include <stdlib.h>
#include "board.h"

char **make_default()
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

bool print(char **board)
{
	FILE* out = fopen("board.txt", "w");
    if (out == NULL) {
        return false;
    }
    for (int i = 0; i < 8; ++i) {
        fprintf(out, "%s" , board[i]);
        fprintf(out, "\n");
    }
    fclose(out);
    return true;
}

void clear(char **board)
{
	for (int i = 0; i < 8; ++i) {
        delete [] board[i];
    }
    delete [] board;
}
