#include<stdio.h>
int  game[9]={0,0,0,0,0,0,0,0,0},flag=1,CPlyr=-1,count=0;int const plr=-1,comp=1;
int Result();
void computerPlay(int []);
int minmax(int [], int);
struct result
{
    int p1,p2,dr;
    char name[20];
};
struct result r;
int CheckWin(int const chgame[9])
{
  int bwp[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    for(int i = 0; i < 8; ++i)
    {      if(chgame[bwp[i][0]] != 0 && chgame[bwp[i][0]] == chgame[bwp[i][1]] && chgame[bwp[i][0]] == chgame[bwp[i][2]])
            return chgame[bwp[i][2]];
    }
 return 0;
}
void clrscr()
{printf("\033c");}
char CheckXorO(int i){
switch(i)
{
case -1: return 'X';
case 1: return 'O';
case 0: return ' ';
}
}
void HowToPlay()
{printf("\n\n\n");
 printf("\t\t-----------------------------------------------------------------------------\n");
 printf("\t\t.............................................................................\n");
 printf("\t\t|                ***** RULES FOR TIC-TAC-TOE ******                         |\n");
 printf("\t\t| 1. The game is played on a grid that's 3 squares by 3 squares.            |\n");
 printf("\t\t| 2. You are X,  the computer in this case is O. Players play first by      |\n");
 printf("\t\t|     entering location i.e(1-9) turns putting the char on game.            |\n");
 printf("\t\t| 3. The  player or Computer to get 3 of her marks in a row (up, down,      |\n");
 printf("\t\t|    across, or diagonally) is the winner.                                  |\n");
 printf("\t\t| 4. When all 9 squares are full, the game is over. If no player has 3 marks|\n");
 printf("\t\t|     in a row, the game ends in a tie.                                     |\n");
 printf("\t\t|                                       -- Vikram Kumar Anthamgari And Team |\n");
 printf("\t\t.............................................................................\n");
 printf("\t\t-----------------------------------------------------------------------------\n");
 printf("\n\n\n");
  printf("\t\t----------------------      Game Starts Here     ---------------------------\n");
}// How To Play
void drawBoard(int dgame[9])// Draw the Board
{
 printf("\n\n\n");
 //printf("\t\t-----------------------------------------------------------------------------\n");
// printf("\t\t.............................................................................\n\n");

    printf("\t\t\t\t\t\t %c | %c | %c\n",CheckXorO(dgame[0]),CheckXorO(dgame[1]),CheckXorO(dgame[2]));
    printf("\t\t\t\t\t\t---+---+---\n");
    printf("\t\t\t\t\t\t %c | %c | %c\n",CheckXorO(dgame[3]),CheckXorO(dgame[4]),CheckXorO(dgame[5]));
    printf("\t\t\t\t\t\t---+---+---\n");
    printf("\t\t\t\t\t\t %c | %c | %c\n\n",CheckXorO(dgame[6]),CheckXorO(dgame[7]),CheckXorO(dgame[8]));
// printf("\t\t-----------------------------------------------------------------------------\n");
// printf("\t\t.............................................................................\n");
}
void play()
{
  HowToPlay();
drawBoard(game);
while(count<9)
 {
  int a;
  printf("Please enter Your Move Location:");
  scanf("%d",&a);
  if(a<0||a>9)
  {
  printf("\aInvalid Location\a\n");
  continue;
  }
  if(game[a-1]!=-1&&game[a-1]!=1)
   { game[a-1]=CPlyr;count++;
     clrscr();
     drawBoard(game);
   }
  else
   {printf("\n\aInvalid Move Already Played!! \n");
   continue;
   }
if(Result())
    {
      break;
    }
if(CPlyr==-1)
{
  computerPlay(game);
  clrscr();
  drawBoard(game);
  count++;
  CPlyr=-1;
  if(Result())
    {
      break;
    }
  }
if(count==8)
{
    printf("\a\a\aGame Draws!\n");
    r.dr=r.dr+1;
    printf("Gamedraws: %d\n",r.dr);
    printf("%s wins: %d\n",r.name,r.p1);
    printf("Computer wins: %d\n",r.p2);
    break;}
 }
}
void computerPlay(int CPgame[9])
{
 int score=-2;
 int bestMove=-1;
 for(int i=0;i<9;i++)
 {
   if(CPgame[i]==0)// Check Legal Move
   {
    CPgame[i]=1;
    int tempScore=-minmax(CPgame,-1);
    if(tempScore>score)
    {
      score=tempScore;
      bestMove=i;
    }
    CPgame[i]=0;// reset the move after try
   }
 }
 CPgame[bestMove]=1;
}
int minmax(int mmgame[9], int cplr)
{
  int win = CheckWin(mmgame);
  if(win!=0) return win*cplr;
  int bestMove=-1;
  int score=-2;
  for(int i=0;i<9;i++)
  {
    if(mmgame[i]==0)
    {
      mmgame[i]=cplr;
      int tempScore=-minmax(mmgame,-cplr);
      if(tempScore>score)
      {
        score=tempScore;
        bestMove=i;
      }
     mmgame[i]=0;
    }
  }
  if(bestMove==-1)
  return 0;
  return score;
}
int Result()
{
       if(CheckWin(game)!=0)
     {
      	if(CheckWin(game)==-1)
        {
            printf("\n%s Is Winner!!!",r.name);
            r.p1=r.p1+1;
            printf("%s wins: %d\n",r.name,r.p1);
            printf("Computer wins: %d\n",r.p2);
            printf("Game draws: %d\n",r.dr);
            return 1;
        }
        else if(CheckWin(game)==1)
         {
             printf("\a\a\a Computer Is Winner!\n");
             r.p2=r.p2+1;
             printf("Computer wins: %d\n",r.p2);
             printf("%s wins: %d\n",r.name,r.p1);
             printf("Game draws: %d\n",r.dr);
             return 1;
         }
      }
      return 0;
}
void main()
{
     printf("Enter your name: ");
    scanf("%s",r.name);
    play();
     while(1)
    {
        int n,a;
        count=0;
        CPlyr=-1;
        for(a=0;a<9;a++)
            game[a]=0;
        printf("\n\
               1. for play\n\
               2. for exit\n");
        printf("Please enter your choice: ");
        scanf("%d",&n);
        switch(n)
        {
            case 1: play();break;
            case 2:exit(1);
            default: printf("Invalide choice.\n");
        }
    }
}
