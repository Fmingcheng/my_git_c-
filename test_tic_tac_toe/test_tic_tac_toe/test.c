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
		printf("���ʤ��\n");
	if(ret=='X')
		printf("����ʤ��\n");
	if(ret=='Q')
		printf("ƽ��\n");
}

int main()
{
  int input=0;
  do
  {
    menu();
    printf("������>:");
    scanf("%d",&input);
	switch(input)
	{
	  case 1:
		 game();
		 break;
	  case 0:
	     printf("�˳���Ϸ\n");
		 break;
	  default:
	     printf("��������\n");
		 break;
	}
  }while(input);
 return 0;
}