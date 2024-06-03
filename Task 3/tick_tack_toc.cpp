#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];
char currentPlayer = 'X';

void initializeBoard()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            board[i][j] = ' ';
        }
    }
}

void displayBoard()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            cout << board[i][j];
            if (j < SIZE - 1)
                cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1)
            cout << "--+---+--" << endl;
    }
}

bool isValidMove(int row, int col)
{
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ';
}

void makeMove(int row, int col)
{
    if (isValidMove(row, col))
    {
        board[row][col] = currentPlayer;
    }
}

bool checkWin()
{
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i)
    {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }
    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;

    return false;
}

bool isBoardFull()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playGame()
{
    initializeBoard();
    bool gameWon = false;
    bool draw = false;

    while (!gameWon && !draw)
    {
        displayBoard();
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (isValidMove(row, col))
        {
            makeMove(row, col);
            gameWon = checkWin();
            if (!gameWon)
            {
                draw = isBoardFull();
                if (!draw)
                {
                    switchPlayer();
                }
            }
        }
        else
        {
            cout << "Invalid move. Try again." << endl;
        }
    }

    displayBoard();
    if (gameWon)
    {
        cout << "Player " << currentPlayer << " wins!" << endl;
    }
    else
    {
        cout << "It's a draw!" << endl;
    }
}

int main()
{
    char playAgain;
    do
    {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
