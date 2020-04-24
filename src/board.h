#ifndef BOARD_H
#define BOARD_H
#include <string>

char** make_default();

void clear(char** board);

bool print(char** board);

void show(char** board);

bool is_pawn_move_valid(char** board, int i, int j, int k, int l);

bool is_bishop_move_valid(char** board, int i, int j, int k, int l);

bool is_horse_move_valid(char** board, int i, int j, int k, int l);

bool is_rook_move_valid(char** board, int i, int j, int k, int l);

bool is_queen_move_valid(char** board, int i, int j, int k, int l);

bool is_king_move_valid(char** board, int i, int j, int k, int l);

bool is_symbols_valid(int i, int j, int k, int l);

bool chess_move(char** board, std::string str);

int min(int a, int b);

int max(int a, int b);

#endif