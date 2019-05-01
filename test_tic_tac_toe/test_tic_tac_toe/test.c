#include "game.h"

void menu()
{
   printf("**************************************\n");
   printf("*******         1.play        ********\n");
   printf("*******         0.exit        ********\n");
   printf("**************************************\n");
}

void game()
{
	char ret=' ';
	char board[ROW][COL]={0};
	InitBoard(board,ROW,COL);
	DisplayBoard(board,ROW,COL);
	while(ret==' ')
	{
	  	  system("cls");
	  ComputerMove(board,ROW,COL);
	  DisplayBoard(board,ROW,COL);
	  ret=IsWin(board,ROW,COL);
	  if(ret != ' ')
		  break;
	  PlayerMove(board,ROW,COL);
	  DisplayBoard(board,ROW,COL);
	  ret=IsWin(board,ROW,COL);
	}
	if(ret=='O')
		printf("玩家胜利\n");
	if(ret=='X')
		printf("电脑胜利\n");
	if(ret=='Q')
		printf("平局\n");
}

int main()
{
  int input=0;
  do
  {
    menu();
    printf("请输入>:");
    scanf("%d",&input);
	switch(input)
	{
	  case 1:
		 game();
		 break;
	  case 0:
	     printf("退出游戏\n");
		 break;
	  default:
	     printf("输入有误\n");
		 break;
	}
  }while(input);
 return 0;
}