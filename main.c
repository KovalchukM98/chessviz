#include <stdio.h>
#include <stdlib.h>

int size = 64;

void set_default(char* board)
{
    board[0] = 'r';
    board[1] = 'h';
    board[2] = 'e';
    board[3] = 'q';
    board[4] = 'k';
    board[5] = 'e';
    board[6] = 'h';
    board[7] = 'r';
    for (int i = 8; i < 16; ++i) {
        board[i] = 'p';
        board[size - 1 - i] = 'P';
    }
    for (int i = 16; i < 48; ++i) {
        board[i] = ' ';
    }
    board[56] = 'C';
    board[57] = 'H';
    board[58] = 'E';
    board[59] = 'K';
    board[60] = 'Q';
    board[61] = 'E';
    board[62] = 'H';
    board[63] = 'C';
}

int main(int argc, char* argv[])
{
    FILE* out = fopen("board.txt", "w");
    if (out == NULL) {
        return 0;
    }
    char* board = (char*)calloc(sizeof(char), size);
    set_default(board);
    fprintf(out, board);
    fclose(out);
    return 0;
}
