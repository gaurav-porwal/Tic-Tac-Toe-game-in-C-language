#include<stdio.h>
#include<stdlib.h>

char board[9]="         ";
int Game=0;
int player=1;
char Mark='X';
int Stop=1;

void Drawboard(void)
{
    printf("\n %c | %c | %c \n",board[0],board[1],board[2]);
    printf("___|___|___\n");
    printf(" %c | %c | %c \n",board[3],board[4],board[5]);
    printf("___|___|___\n");
    printf(" %c | %c | %c \n",board[6],board[7],board[8]);
    printf("   |   |   \n");
}

void CheckWin(void)
{
    if(board[0]==board[1] && board[1]==board[2] && board[0]!=' ')
        Game=1;
    else if(board[3]==board[4] && board[4]==board[5] && board[3]!=' ')
        Game=1;
    else if(board[6]==board[7] && board[7]==board[8] && board[6]!=' ')
        Game=1;
    else if(board[0]==board[3] && board[3]==board[6] && board[0]!=' ')
        Game=1;
    else if(board[1]==board[4] && board[4]==board[7] && board[1]!=' ')
        Game=1;
    else if(board[2]==board[5] && board[5]==board[8] && board[2]!=' ')
        Game=1;
    else if(board[0]==board[4] && board[4]==board[8] && board[4]!=' ')
        Game=1;
    else if(board[2]==board[4] && board[4]==board[6] && board[4]!=' ')
        Game=1;
    else if(board[0]!=' ' && board[1]!=' ' && board[2]!=' '&& board[3]!=' ' && board[4]!=' ' && board[5]!=' ' && board[6]!=' ' && board[7]!=' ' && board[8]!=' ')
        Game=-1;
    else
        Game=0;
}

int CheckPosition(int x)
{
    if(board[x]==' ')
        return 1;
    else
        return 0;
}

int main(void)
{
    int choice=0;
    printf("Tic-Tac-Toe Game Designed by Gaurav\n");
    printf("Player 1 [X] --- Player 2 [O]\n");
    while(Game==0)
    {
        Drawboard();
        if(player%2!=0)
        {
            printf("Player 1's chance\n");
            Mark='X';
        }
        else
        {
            printf("Player 2's chance\n");
            Mark='O';
        }
        printf("Enter the position between 1-9 where you want to mark or 0 to exit: ");
        scanf("%d",&choice);
        if(choice==0)
            exit(0);
        else
        {
            choice=choice-1;
            if(CheckPosition(choice))
            {
                board[choice]=Mark;
                player=player+1;
                CheckWin();
            }
        }
    }
    Drawboard();
    if(Game==-1)
    {
        printf("Game Draw");
        exit(0);
    }
    else
    {
        player=player-1;
        if(player%2!=0)
            printf("Player 1 Won");
        else
            printf("Player 2 Won");
    }
}