//
// Created by admin on 2/16/2025.
// Tic Tac Toe Game [lynxforge]
//
#include<iostream>
using namespace std;

char page[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int player;
char choice;

void tearpage()
{
    cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << page[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
bool tick(int box)
{
    int row = (box - 1) / 3;
    int col = (box - 1) % 3;

    if (page[row][col] != 'X' && page[row][col] != 'O')
    {
        page[row][col] = choice;
        return true;
    }else
    {
        return false;
    }
}

void turn()
{
    if (choice == 'X')
    {
        choice = 'O';
        player = 2;
    }else
    {
        choice = 'X';
        player = 1;
    }
}

int winner()
{
    if (page[0][0] == page[1][1] && page[1][1] == page[2][2])
        return player;
    if (page[0][2] == page[1][1] && page[1][1] == page[2][0])
        return player;

    for (int i = 0; i < 3; i++)
    {
        if (page[0][i] == page[1][i] && page[1][i] == page[2][i])
            return player;
        if (page[i][0] == page[i][1] && page[i][1] == page[i][2])
            return player;
    }
    return 0;
}

void game()
{
    cout << "Ready Player One?\nX or O: ";
    cin >> choice;

    player = 1;
    tearpage();

    int turncount = 0;

    while (turncount < 9)
    {
        int box;

        cout << "Player" << player <<"'s turn: ";
        cin >> box;

        if (box < 1 || box > 9 || !tick(box))
        {
            cout << "Inavlid move\nTry again\n";
        }

        tearpage();

        if (winner() != 0)
        {
            if (player == 1)
            {
                cout << "Player X wins!\n";
            }else
            {
                cout << "Player O wins!\n";
            }
            return;
        }

        turn();
        turncount++;
    }
    cout << "Tie!\n";
}

int main()
{
    game();
    return 0;
}
