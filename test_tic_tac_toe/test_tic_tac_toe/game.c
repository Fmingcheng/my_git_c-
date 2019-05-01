#include "game.h"

void InitBoard(char board[ROW][COL],int row,int col)
{
  int i=0;
  for(i=1;i<row;i++)
  {
    int j=0;
    for(j=1;j<col;j++)
	{
	   board[i][j]=' ';
	}
  }
  for(i=0;i<row;i++)
  {
     int j=0;
     for(j=0;j<col;j++)
	 {
	   board[0][j]=48+j;
	 }
	 board[i][0]=48+i;
  }
}

void DisplayBoard(char board[ROW][COL],int row,int col)
{
  int i=0;
  for(i=0;i<row;i++)
  {
     int j=0;
     for(j=0;j<col;j++)
	 {
	   printf(" %c ",board[i][j]);
	   if(j<col-1)
	     printf("|");
	 }
	 printf("\n");
     if(i<row-1)
	 {
	   	for(j=0;j<col;j++)
	   {
	     printf("---");
		 if(j<col-1)
		   printf("|");
	   }
	  printf("\n");
	 }
  }
}

void ComputerMove(char board[ROW][COL],int row,int col)
{
	int x=0;
	int y=0;
	printf("电脑走\n");
	srand((unsigned)time(NULL));
	x=rand()%row;
	y=rand()%col;
	while(board[x][y] != ' ')
	{
	  	x=rand()%row;
	    y=rand()%col;
	}
    board[x][y]='X';
}

void PlayerMove(char board[ROW][COL],int row,int col)
{
    int a=0;
	int b=0;
    printf("玩家走->");
	while(1){
	printf("请输入坐标>:");
	scanf("%d %d",&a,&b);
	if(a>0 && a<row && b>0 && b<col)
	{
	  if(board[a][b] != ' ')
		  printf("输入有误，请重新输入\n");
	  else{
		  board[a][b]='O';
		  break;
	  }
	}
	else
		printf("输入有误，请重新输入\n");
	}
}

char IsWin(char board[ROW][COL],int row,int col)
{
   int i=0;
   int j=0;
   for(i=1;i<row;i++)
   {
      for(j=1;j<col-1;j++)
	  {
	     if(board[i][j] != board[i][j+1])
			 break;
	  }
	  if(j==col-1)
	  {
	     if(board[i][j]=='O')
			 return 'O';
		 if(board[i][j]=='X')
			 return 'X';
	  }
   }
   for(j=1;j<col;j++)
   {
      for(i=1;i<row-1;i++)
	  {
	     if(board[i][j] != board[i+1][j])
			 break;
	  }
	  if(i==row-1)
	  {
	     if(board[i][j]=='O')
			 return 'O';
		 if(board[i][j]=='X')
			 return 'X';
	  }
   }

   i=1;
   j=1;
   while(i<row-1)
   {
     if(board[i][j]!=board[i+1][j+1])
		 break;
	 i++;
	 j++;
   }
   if(i==row-1)
   {
     if(board[i][j]=='O')
		 return 'O';
	 if(board[i][j]=='X')
		 return 'X';
   }
   
   i=row;
   j=1;
   while(j<col)
   {
     if(board[i][j]!=board[i-1][j+1])
		 break;
	 i++;
	 j++;
   }
   if(j==col-1)
   {
     if(board[i][j]=='O')
		 return 'O';
	 if(board[i][j]=='X')
		 return 'X';
   }
   for(i=1;i<row;i++)
   {
      for(j=1;j<col;j++)
	  {
	     if(board[i][j]==' ')
			 return ' ';
	  }
   }
   return 'Q';
}