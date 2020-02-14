#include<stdio.h>
#include<stdlib.h>

int size = 64;

void set_default(char *board){
board[0] = 'c';
board[1] = 'h';
board[2] = 'e';
board[3] = 'q';
board[4] = 'k';
board[5] = 'e';
board[6] = 'h';
board[7] = 'c';
for(int i = 8 ; i < 16 ; ++i){
board[i] = 'p';
board[size-1 - i] = 'p';
}
for(int i = 16 ; i < 48 ; ++i){
board[i] = ' ';
}
board[56] = 'c';
board[57] = 'h';
board[58] = 'e';
board[59] = 'k';
board[60] = 'q';
board[61] = 'e';
board[62] = 'h';
board[63] = 'c';
}

int main(int argc , char *argv[])
{
FILE *out = fopen("board.txt" , "w");
if(out == NULL)
{
return 0;
}
char *board = (char*)calloc(sizeof(char), size );
set_default(board);
fprintf(out , board);
fclose(out);
return 0;
}
