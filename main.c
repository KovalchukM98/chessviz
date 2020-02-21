#include <stdio.h>
#include <stdlib.h>

int size = 64;

void set_default(char* board[])
{
    board[0][0] = 'r';
    board[0][1] = 'h';
    board[0][2] = 'e';
    board[0][3] = 'q';
    board[0][4] = 'k';
    board[0][5] = 'e';
    board[0][6] = 'h';
    board[0][7] = 'r';
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
}

int main(int argc, char* argv[])
{
    FILE* out = fopen("board.txt", "w");
    if (out == NULL) {
        return 0;
    }
    char** board = (char**)calloc(sizeof(char*), 8);
    for (int i = 0; i < 8; ++i) {
        board[i] = (char*)calloc(sizeof(char), 8);
    }
    set_default(board);
    for (int i = 0; i < 8; ++i) {
        fprintf(out, board[i]);
        fprintf(out, "\n");
    }
    fclose(out);
    for (int i = 0; i < 8; ++i) {
        free(board[i]);
    }
    free(board);
    return 0;
}
