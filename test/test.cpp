#include "board.h"
#include <gtest/gtest.h>

TEST(board, is_pawn_move_valid) {
	char** board = make_default();
	EXPECT_TRUE(is_pawn_move_valid(board, 0, 1, 0, 3));
	clear(board);
}

int main(int argc , char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}