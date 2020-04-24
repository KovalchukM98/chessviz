#include "board.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

int main(int argc, char* argv[])
{
    char** board = make_default();
    for (int i = 0; i < 3; ++i) {
        std::cout << "enter turn" << std::endl;
        std::string str;
        getline(std::cin, str);
        if (chess_move(board, str)) {
            show(board);
        } else {
            std::cout << "invalid input" << std::endl;
        }
    }
    print(board);
    clear(board);
    return 0;
}