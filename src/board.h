#ifndef BOARD_H
#define BOARD_H

char** make_default();

void clear(char** board);

bool print(char** board);

void chess_move(char** board);

#endif