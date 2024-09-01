#include <iostream>

using namespace std;

const unsigned int ArraySize = 3;
char board[ArraySize][ArraySize] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char charcter;
unsigned int _Palyer_;

void ShowBoard() 
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

template < typename T>
bool PlayerOne(T Number) 
{
    unsigned int row = (Number - 1) / ArraySize;
    unsigned int col = (Number - 1) % ArraySize;

    if (board[row][col] != 'X' && board[row][col] != 'O') 
    {
        board[row][col] = charcter;
        return true;
    }
    return false;
}

bool Result()
{
    for (int i = 0; i < ArraySize; i++) 
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}

void Player_One_Two() 
{
    if (_Palyer_ == 1) 
    {
        _Palyer_ = 2;
        charcter = 'O';
    }
    else 
    {
        _Palyer_ = 1;
        charcter = 'X';
    }
}

void game() 
{
    cout << "Welcom X-O Gmae\n\n";

    _Palyer_ = 1;
    charcter = 'X';

    unsigned int max = 0;
    while (max < 9) 
    {
        ShowBoard();
        unsigned int number__one;

        cout << "\n\n";
        cout << "Player " << _Palyer_ << ", enter player : ";

        cin >> number__one;
        cout << "\n\n";


        if (number__one < 1 || number__one > 9 || !PlayerOne(number__one)) 
        {
            cout << "Error! / False number ! / Tray again \n";
            continue;
        }

        if (Result()) 
        {
            cout << "=================================" << "\n";
            cout << "\t Result" << "\n\n";

            ShowBoard();

            cout << "\n\n";

            cout << "Player " << _Palyer_ << " is winner\n";

            return;
        }
       Player_One_Two();
        max++;
    }
}

int main() 
{
    game();
    return 0;
}
