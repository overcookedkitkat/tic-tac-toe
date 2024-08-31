#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define PLAYER1 'X'
#define PLAYER2 'O'

char board[3][3];
int choice;

void resetBoard();
void printBoard();
void playerMove(char);
void computerMove();
void winner(char);
char checkWinner();  
int freeSpace();

int main()
{
    main:
    printf("\n\nChoose game mode:\n");
    printf("1. Player vs Computer\n");
    printf("2. Player vs Player\n");

    scanf("%d", &choice); 
    char Winner = ' ';
    resetBoard();

    switch (choice)
    {
    case 1:
        printf("PLAYER => X\nCOMPUTER => O\n\n");

        while (Winner == ' ' && freeSpace() != 0)
        {
            printBoard();

            playerMove(PLAYER1);
            Winner = checkWinner();
            if (Winner != ' ' || freeSpace() == 0)
            {
                break;
            }

            computerMove();
            Winner = checkWinner();
            if (Winner != ' ' || freeSpace() == 0)
            {
                break;
            }
        }

        break;

    case 2:
        printf("PLAYER 1 => X\nPLAYER 2 => O\n\n");

        while (Winner == ' ' && freeSpace() != 0)
        {
            printBoard();

            playerMove(PLAYER1);
            Winner = checkWinner();
            if (Winner != ' ' || freeSpace() == 0)
            {
                break;
            }

            printBoard();

            playerMove(PLAYER2);
            Winner = checkWinner();
            if (Winner != ' ' || freeSpace() == 0)
            {
                break;
            }
        }

        break;

    default:
        printf("Invalid choice\n");
        return 1;
    }

    printBoard();
    winner(Winner);

    printf("\nDo you want to play again? (Y/N): ");
    char response;
    fflush(stdin);
    scanf("%c",&response);

    if(toupper(response) == 'Y')
    {
        goto main;
    }

    else if(toupper(response) == 'N')
    {
        printf("\nThank you for playing, now exiting the game...");
        return 0;
    }

    else
    {
        printf("Invalid Choice, Exiting the Game");
    }

    return 0;
}

void resetBoard()
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");

    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");

    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}


void playerMove(char playerSymbol)
{
    int i, j;

    printf("Player %c, Make your Move\n", playerSymbol);

    do
    {
        printf("Enter row (1-3): ");
        scanf("%d", &i);
        i--;

        printf("Enter column (1-3): ");
        scanf("%d", &j);
        j--;

        if (board[i][j] != ' ')
        {
            printf("Space already occupied\n");
        }

        else
        {
            board[i][j] = playerSymbol;
            break;
        }
    } while (board[i][j] != ' ');
}


void computerMove()
{
    srand(time(NULL));

    int i;
    int j;

    do
    {
        i = rand() % 3;
        j = rand() % 3;
    } while (board[i][j] != ' ');

    board[i][j] = PLAYER2;
}


void winner(char Winner)
{

    if(choice == 2)
    {

        if (Winner == PLAYER1)
        {
            printf("\nPLAYER X WINS\n");
        }

        else if (Winner == PLAYER2)
        {
            printf("\nPLAYER O WINS\n");
        }

        else
        {
            printf("\nIT IS A DRAW\n");
        }
    }

    else
    {
        if (Winner == PLAYER1)
        {
            printf("YOU WIN\n");
        }

        else if (Winner == PLAYER2)
        {
            printf("YOU LOSE\n");
        }

        else
        {
            printf("IT IS A DRAW\n");
        }
    }

    
}

char checkWinner()
{
    int i;

    for (i = 0; i < 3; i++) //ROW
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }

    for (i = 0; i < 3; i++) //COLUMN
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) //DIAGONAL
    {
        return board[0][0];
    }

    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) //DIAGONAL
    {
        return board[0][2];
    }

    return ' ';
}

int freeSpace()
{
    int freeSpace = 9;
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                freeSpace--;
            }
        }
    }

    return freeSpace;
}
