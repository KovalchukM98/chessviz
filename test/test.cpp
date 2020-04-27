#include "board.h"
#include <gtest/gtest.h>
#include <string>

TEST(board, make_default)
{
    char** board = make_default();
    ASSERT_TRUE(board != NULL);
    clear(board);
}

TEST(board, chess_move)
{
    char** board = make_default();
    std::string str = "aaaaaaa";
    ASSERT_FALSE(chess_move(board, str));
    str = "a2-a2";
    ASSERT_FALSE(chess_move(board, str));
    str = "e1-e2";
    ASSERT_FALSE(chess_move(board, str));
    str = "e2 e3";
    ASSERT_FALSE(chess_move(board, str));
    str = "e2-e3-e4";
    ASSERT_FALSE(chess_move(board, str));
    str = "e4-e5";
    ASSERT_FALSE(chess_move(board, str));
    str = "e2-e4";
    ASSERT_TRUE(chess_move(board, str));
    clear(board);
}

TEST(board, is_pawn_move_valid)
{
    char** board = make_default();
    ASSERT_TRUE(is_pawn_move_valid(board, 2, 1, 2, 3));
    ASSERT_TRUE(is_pawn_move_valid(board, 2, 1, 2, 2));
    ASSERT_FALSE(is_pawn_move_valid(board, 2, 1, 2, 4));
    std::string str = "b1-c3";
    chess_move(board, str);
    ASSERT_FALSE(is_pawn_move_valid(board, 2, 1, 2, 2));
    ASSERT_FALSE(is_pawn_move_valid(board, 2, 1, 2, 3));
    clear(board);
}

TEST(board, is_bishop_move_valid)
{
    char** board = make_default();
    ASSERT_FALSE(is_bishop_move_valid(board, 2, 0, 5, 3));
    std::string str = "d2-d4";
    chess_move(board, str);
    ASSERT_TRUE(is_bishop_move_valid(board, 2, 0, 5, 3));
    str = "c1-f4";
    chess_move(board, str);
    ASSERT_TRUE(is_bishop_move_valid(board, 5, 3, 2, 0));
    ASSERT_TRUE(is_bishop_move_valid(board, 5, 3, 6, 2));
    ASSERT_TRUE(is_bishop_move_valid(board, 5, 3, 7, 5));
    ASSERT_TRUE(is_bishop_move_valid(board, 5, 3, 3, 5));
    ASSERT_FALSE(is_bishop_move_valid(board, 5, 3, 4, 3));
    str = "e2-e3";
    chess_move(board, str);
    ASSERT_FALSE(is_bishop_move_valid(board, 5, 3, 2, 0));
    clear(board);
}

TEST(board, is_rook_move_valid)
{
    char** board = make_default();
    ASSERT_FALSE(is_rook_move_valid(board, 0, 0, 0, 1));
    ASSERT_FALSE(is_rook_move_valid(board, 0, 0, 0, 5));
    std::string str = "a2-a4";
    chess_move(board, str);
    ASSERT_FALSE(is_rook_move_valid(board, 0, 0, 0, 5));
    ASSERT_TRUE(is_rook_move_valid(board, 0, 0, 0, 2));
    str = "a1-a3";
    chess_move(board, str);
    ASSERT_TRUE(is_rook_move_valid(board, 0, 2, 7, 2));
    str = "a3-h3";
    chess_move(board, str);
    ASSERT_TRUE(is_rook_move_valid(board, 7, 2, 7, 5));
    str = "e2-e3";
    chess_move(board, str);
    ASSERT_FALSE(is_rook_move_valid(board, 7, 2, 1, 2));
    // show(board);
    clear(board);
}

TEST(board, is_horse_move_valid)
{
    char** board = make_default();
    ASSERT_TRUE(is_horse_move_valid(board, 1, 0, 2, 2));
    ASSERT_FALSE(is_horse_move_valid(board, 1, 0, 2, 3));
    ASSERT_FALSE(is_horse_move_valid(board, 1, 0, 3, 1));
    ASSERT_FALSE(is_horse_move_valid(board, 1, 0, 3, 3));
    ASSERT_FALSE(is_horse_move_valid(board, 1, 0, 1, 3));
    std::string str = "b1-c3";
    chess_move(board, str);
    // show(board);
    ASSERT_TRUE(is_horse_move_valid(board, 2, 2, 0, 3));
    ASSERT_TRUE(is_horse_move_valid(board, 2, 2, 3, 4));
    ASSERT_TRUE(is_horse_move_valid(board, 2, 2, 1, 4));
    ASSERT_TRUE(is_horse_move_valid(board, 2, 2, 4, 3));
    ASSERT_FALSE(is_horse_move_valid(board, 2, 2, 0, 1));
    clear(board);
}

TEST(board, is_queen_move_valid)
{
    char** board = make_default();
    ASSERT_FALSE(is_queen_move_valid(board, 4, 7, 6, 5));
    std::string str = "f7-f6";
    chess_move(board, str);
    ASSERT_TRUE(is_queen_move_valid(board, 4, 7, 6, 5));
    ASSERT_FALSE(is_queen_move_valid(board, 4, 7, 4, 4));
    board[6][4] = ' ';
    ASSERT_TRUE(is_queen_move_valid(board, 4, 7, 4, 4));
    str = "e8-e4";
    chess_move(board, str);
    ASSERT_TRUE(is_queen_move_valid(board, 4, 3, 4, 7));
    ASSERT_TRUE(is_queen_move_valid(board, 4, 3, 4, 2));
    ASSERT_TRUE(is_queen_move_valid(board, 4, 3, 7, 3));
    ASSERT_TRUE(is_queen_move_valid(board, 4, 3, 0, 3));
    ASSERT_TRUE(is_queen_move_valid(board, 4, 3, 6, 5));
    board[4][5] = 'P';
    board[6][4] = 'P';
    // show(board);
    ASSERT_FALSE(is_queen_move_valid(board, 4, 3, 6, 5));
    ASSERT_FALSE(is_queen_move_valid(board, 4, 3, 4, 7));
    clear(board);
}

TEST(board, is_king_move_valid)
{
    char** board = make_default();
    ASSERT_FALSE(is_king_move_valid(board, 3, 7, 6, 5));
    ASSERT_FALSE(is_king_move_valid(board, 3, 7, 3, 5));
    ASSERT_FALSE(is_king_move_valid(board, 3, 7, 3, 6));
    std::string str = "d7-d5";
    chess_move(board, str);
    ASSERT_TRUE(is_king_move_valid(board, 3, 7, 3, 6));
    str = "d8-d7";
    chess_move(board, str);
    // show(board);
    ASSERT_TRUE(is_king_move_valid(board, 3, 6, 2, 5));
    ASSERT_TRUE(is_king_move_valid(board, 3, 6, 3, 7));
    ASSERT_TRUE(is_king_move_valid(board, 3, 6, 4, 5));
    ASSERT_FALSE(is_king_move_valid(board, 3, 6, 1, 4));
    clear(board);
}
