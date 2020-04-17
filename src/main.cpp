#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

int main(int argc, char* argv[])
{
    char** board = make_default();
    
    for (int i = 0; i < 3; ++i) {
        std::cout << "enter turns" << std::endl;
        std::string str;
        getline(std::cin, str);
        chess_move(board, str);
        show(board);
    }
    print(board);
    clear(board);
    return 0;
}