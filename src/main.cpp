#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

int main(int argc, char* argv[])
{
    char** board = make_default();
    for (int i = 0; i < 3; ++i) {
        std::cout << "enter turn" << std::endl;
        std::string str;
        getline(std::cin, str);
        if (chess_move(board, str)) {
            show(board);
        }
    }
    print(board);
    clear(board);
    return 0;
}