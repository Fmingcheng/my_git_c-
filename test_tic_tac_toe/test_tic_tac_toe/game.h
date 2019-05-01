#ifndef  _GAME__H_
#define  _GAME__H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 6
#define COL 6

void InitBoard(char board[ROW][COL],int row,int col);
void DisplayBoard(char board[ROW][COL],int row,int col);
void ComputerMove(char board[ROW][COL],int row,int col);
void PlayerMove(char board[ROW][COL],int row,int col);
char IsWin(char board[ROW][COL],int row,int col);

#endif  // _GAME__H_