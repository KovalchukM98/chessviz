#include "board.h"
#include <gtest/gtest.h>
#include <string>

TEST(board, make_default) {
	char** board = make_default();
	ASSERT_TRUE(board != NULL);
	clear(board);
}

TEST(board, chess_move) {
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

TEST(board, is_pawn_move_valid) {
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

// int main(int argc , char* argv[])
// {
// 	::testing::InitGoogleTest(&argc, argv);
// 	return RUN_ALL_TESTS();
// }