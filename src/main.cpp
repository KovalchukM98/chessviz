#include <stdio.h>
#include <stdlib.h>
#include "board.h"

int main(int argc, char* argv[])
{
    char **board = make_default();
    chess_move(board);
    print(board);
    clear(board);
    return 0;
}
