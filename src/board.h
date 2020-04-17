#ifndef BOARD_H
#define BOARD_H
#include <string>

char** make_default();

void clear(char** board);

bool print(char** board);

void chess_move(char** board, std::string str);

#endif