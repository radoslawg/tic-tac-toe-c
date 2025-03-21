#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

char board[3][3];
const char player = 'X';
const char computer = 'O';

int main() {
    char winner = ' ';
    resetBoard();
    while(winner == ' ' && checkFreeSpaces() > 0)
    {
        printBoard();
        playerMove();
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0)
            break;
        computerMove();
        winner = checkWinner();
    }
    printBoard();
    printWinner(winner);
    return 0;
}

void resetBoard()
{
    memset(board, ' ', sizeof(board));
}
void printBoard()
{
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

int checkFreeSpaces()
{
    char* p = (char*)board;
    for (int i = 0; i < sizeof(board); ++i) {
        printf("Checking field %d/%d\n", i, sizeof(board));
        printf("Field: %d\n", *(p + i));
        if (*(p+i) == ' ')
        {
            printf("Free space found\n");
            return 1;
        }
    }
    return 0;
}
void playerMove()
{
    int x, y;
    printf("Enter the row and column (1-3) where you want to place your X: ");
    scanf("%d %d", &x, &y);
    x--;
    y--;
    if (board[x][y] == ' ')
    {
        board[x][y] = player;
    }
    else
    {
        printf("That space is already taken!\n");
        playerMove();
    }
}

void computerMove()
{
    srand(time(NULL));
    int x, y;
    do
    {
        x = rand() % 3;
        y = rand() % 3;
    } while (board[x][y] != ' ');
    board[x][y] = computer;
}

char checkWinner()
{
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];
    return ' ';
}

void printWinner(char winner)
{
    if (winner == player)
        printf("Congratulations! You win!\n");
    else if (winner == computer)
        printf("The computer wins!\n");
    else
        printf("It's a tie!\n");
}


