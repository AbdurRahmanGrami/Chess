#include<iostream>
using namespace std;

void start();
void display(char** board, int size);
int selectPiece(char** board, int size, int turn);
bool possibleMoves(char** board, int size, char piece, int row, int col);
void move(char** board, int size, char piece, int row, int col);
bool isCheck(char** board, int size, int row, int col, char piece);

int main()
{
    start();

    return 0;
}

void start()
{
    char** board = new char* [9];
    for (int i = 0; i < 9; i++)
    {
        board[i] = new char[9];
        for (int j = 0; j < 9; j++)
        {
            if (j == 0 && i > 0)
                board[i][j] = i - 1 + 48;
            else if (i == 0 && j > 0)
                board[i][j] = j - 1 + 48;
            else if (i == 8 && (j == 1 || j == 8))
                board[i][j] = 'R';
            else if (i == 8 && (j == 2 || j == 7))
                board[i][j] = 'N';
            else if (i == 8 && (j == 3 || j == 6))
                board[i][j] = 'B';
            else if (i == 8 && j == 4)
                board[i][j] = 'Q';
            else if (i == 8 && j == 5)
                board[i][j] = 'K';
            else if (i == 1 && (j == 1 || j == 8))
                board[i][j] = 'r';
            else if (i == 1 && (j == 2 || j == 7))
                board[i][j] = 'n';
            else if (i == 1 && (j == 3 || j == 6))
                board[i][j] = 'b';
            else if (i == 1 && j == 4)
                board[i][j] = 'q';
            else if (i == 1 && j == 5)
                board[i][j] = 'k';
            else
                board[i][j] = '_';
        }
    }
    display(board, 9);
    char ask, turn = 1;
    while (1)
    {
        int moves = selectPiece(board, 9, turn);
        if (moves == 0)
            continue;
        else if (moves == 2)
        {
            cout << "\nCheckMate\n\n";
            break;
        }
        cout << "Do you want to end game?)(Y/N): ";
        cin >> ask;
        if (ask == 'Y' || ask == 'y')
            break;
        display(board, 9);
        turn++;
    }
    for (int i = 0; i < 9; i++)
        delete[] board[i];
    delete[] board;
}
void display(char** board, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << board[i][j] << "    ";
        }
        cout << endl << endl;
    }
}
int selectPiece(char** board, int size, int turn)
{
    char piece;
    int row, col;
    bool correctPos = 0;
    if (turn % 2 != 0)
    {
        piece = 'K';
        cout << "~~~~~OPPONENT TURN~~~~~\n\n";
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] == piece)
                {
                    row = i;
                    col = j;
                }
            }
        }
        if (isCheck(board, size, row, col, piece))
        {
            cout << "Check. Change Position of King\n\n";
            int check = possibleMoves(board, size, piece, row, col);
            if (check == 0)
                return 2;
            return 1;
        }
        else {
            while (1)
            {
                cout << "Select the piece you want to move:\n";
                cout << "1) Rook(R)\n2) Knight(N)\n3) Bishop(B)\n4) Queen(Q)\n5) King(K)\n\n";
                cin >> piece;
                if (piece == 'R' || piece == 'B' || piece == 'N' || piece == 'Q' || piece == 'K')
                    break;
                else
                    cout << "Incorrect Piece selected, enter again\n\n";
            }
            while (1)
            {
                cout << "Enter the position of that piece:\n";
                cout << "Col: ";
                cin >> col;
                cout << "Row: ";
                cin >> row;
                if ((row >= 0 && row <= 7) && (col >= 0 && col <= 7))
                    for (int i = 0; i < size; i++)
                    {
                        for (int j = 0; j < size; j++)
                        {
                            if (board[row + 1][col + 1] == piece)
                                correctPos = 1;
                        }
                    }
                if (correctPos == 1)
                    break;
                else
                    cout << "Incorrect Position selected, enter again\n\n";
            }
            return possibleMoves(board, size, piece, row + 1, col + 1);
        }

    }
    else
    {
        piece = 'k';
        cout << "~~~~~YOUR TURN~~~~~\n\n";
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] == piece)
                {
                    row = i;
                    col = j;
                }
            }
        }
        if (isCheck(board, size, row, col, piece))
        {
            cout << "Check. Change Position of King\n\n";
            int check = possibleMoves(board, size, piece, row, col);
            if (check == 0)
                return 2;
            return 1;
        }
        else {
            while (1)
            {
                cout << "Select the piece you want to move:\n";
                cout << "1) Rook(r)\n2) Knight(n)\n3) Bishop(b)\n4) Queen(q)\n5) King(k)\n\n";
                cin >> piece;
                if (piece == 'r' || piece == 'b' || piece == 'n' || piece == 'q' || piece == 'k')
                    break;
                else
                    cout << "Incorrect Piece selected, enter again\n\n";
            }
            while (1)
            {
                cout << "Enter the position of that piece:\n";
                cout << "Col: ";
                cin >> col;
                cout << "Row: ";
                cin >> row;
                if ((row >= 0 && row <= 7) && (col >= 0 && col <= 7))
                    for (int i = 0; i < size; i++)
                    {
                        for (int j = 0; j < size; j++)
                        {
                            if (board[row + 1][col + 1] == piece)
                                correctPos = 1;
                        }
                    }
                if (correctPos == 1)
                    break;
                else
                    cout << "Incorrect Position selected, enter again\n\n";
            }
            return possibleMoves(board, size, piece, row + 1, col + 1);
        }
    }
}
bool possibleMoves(char** board, int size, char piece, int row, int col)
{
    int count = 0;
    if (piece == 'R' || piece == 'r')
    {
        for (int j = col + 1; j < size; j++)//placing x to the right of rook
        {
            if (j >= size)
                break;
            if (board[row][j] == '_')
            {
                count++;
                board[row][j] = 'x';
                cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\n";
            }
            else if (piece == 'R')
            {
                if (board[row][j] == 'r')
                {
                    count++;
                    board[row][j] = '~';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[row][j] == 'n')
                {
                    count++;
                    board[row][j] = '!';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[row][j] == 'b')
                {
                    count++;
                    board[row][j] = '@';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[row][j] == 'q')
                {
                    count++;
                    board[row][j] = '#';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else if (piece == 'r')
            {
                if (board[row][j] == 'R')
                {
                    count++;
                    board[row][j] = '^';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[row][j] == 'N')
                {
                    count++;
                    board[row][j] = '*';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[row][j] == 'B')
                {
                    count++;
                    board[row][j] = '-';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[row][j] == 'Q')
                {
                    count++;
                    board[row][j] = '+';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else
                break;
        }
        for (int j = col - 1; j >= 0; j--)//placing x to the left of rook
        {
            if (j < 0)
                break;
            if (board[row][j] == '_')
            {
                count++;
                board[row][j] = 'x';
                cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\n";
            }
            else if (piece == 'R')
            {
                if (board[row][j] == 'r')
                {
                    count++;
                    board[row][j] = '~';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[row][j] == 'n')
                {
                    count++;
                    board[row][j] = '!';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[row][j] == 'b')
                {
                    count++;
                    board[row][j] = '@';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[row][j] == 'q')
                {
                    count++;
                    board[row][j] = '#';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else if (piece == 'r')
            {
                if (board[row][j] == 'R')
                {
                    count++;
                    board[row][j] = '^';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[row][j] == 'N')
                {
                    count++;
                    board[row][j] = '*';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[row][j] == 'B')
                {
                    count++;
                    board[row][j] = '-';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[row][j] == 'Q')
                {
                    count++;
                    board[row][j] = '+';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else
                break;
        }
        for (int i = row + 1; i < size; i++)//placing x to the bottom of rook
        {
            if (i >= size)
                break;
            if (board[i][col] == '_')
            {
                count++;
                board[i][col] = 'x';
                cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\n";
            }
            else if (piece == 'R')
            {
                if (board[i][col] == 'r')
                {
                    count++;
                    board[i][col] = '~';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[i][col] == 'n')
                {
                    count++;
                    board[i][col] = '!';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[i][col] == 'b')
                {
                    count++;
                    board[i][col] = '@';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[i][col] == 'q')
                {
                    count++;
                    board[i][col] = '#';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else if (piece == 'r')
            {
                if (board[i][col] == 'R')
                {
                    count++;
                    board[i][col] = '^';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[i][col] == 'N')
                {
                    count++;
                    board[i][col] = '*';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[i][col] == 'B')
                {
                    count++;
                    board[i][col] = '-';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[i][col] == 'Q')
                {
                    count++;
                    board[i][col] = '+';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else
                break;
        }
        for (int i = row - 1; i >= 0; i--)//placing x to the above of rook
        {
            if (i < 0)
                break;
            if (board[i][col] == '_')
            {
                count++;
                board[i][col] = 'x';
                cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\n";
            }
            else if (piece == 'R')
            {
                if (board[i][col] == 'r')
                {
                    count++;
                    board[i][col] = '~';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[i][col] == 'n')
                {
                    count++;
                    board[i][col] = '!';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[i][col] == 'b')
                {
                    count++;
                    board[i][col] = '@';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[i][col] == 'q')
                {
                    count++;
                    board[i][col] = '#';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else if (piece == 'r')
            {
                if (board[i][col] == 'R')
                {
                    count++;
                    board[i][col] = '^';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[i][col] == 'N')
                {
                    count++;
                    board[i][col] = '*';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[i][col] == 'B')
                {
                    count++;
                    board[i][col] = '-';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[i][col] == 'Q')
                {
                    count++;
                    board[i][col] = '+';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else
                break;
        }
    }
    if (piece == 'B' || piece == 'b')
    {
        for (int i = row - 1, j = col + 1; i >= 0 || j < size; i--, j++)//placing x on the upper right diagonal of bishop
        {
            if (i >= size || j >= size || i < 0 || j < 0)
                break;
            if (board[i][j] == '_')
            {
                count++;
                board[i][j] = 'x';
                cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\n";
            }
            else if (piece == 'B')
            {
                if (board[i][j] == 'r')
                {
                    count++;
                    board[i][j] = '~';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[i][j] == 'n')
                {
                    count++;
                    board[i][j] = '!';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[i][j] == 'b')
                {
                    count++;
                    board[i][j] = '@';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[i][j] == 'q')
                {
                    count++;
                    board[i][j] = '#';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else if (piece == 'b')
            {
                if (board[i][j] == 'R')
                {
                    count++;
                    board[i][j] = '^';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[i][j] == 'N')
                {
                    count++;
                    board[i][j] = '*';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[i][j] == 'B')
                {
                    count++;
                    board[i][j] = '-';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[i][j] == 'Q')
                {
                    count++;
                    board[i][j] = '+';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else
                break;
        }
        for (int i = row - 1, j = col - 1; i >= 0 || j >= 0; i--, j--)//placing x on the upper left diagonal of bishop
        {
            if (i >= size || j >= size || i < 0 || j < 0)
                break;
            if (board[i][j] == '_')
            {
                count++;
                board[i][j] = 'x';
                cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\n";
            }
            else if (piece == 'B')
            {
                if (board[i][j] == 'r')
                {
                    count++;
                    board[i][j] = '~';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[i][j] == 'n')
                {
                    count++;
                    board[i][j] = '!';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[i][j] == 'b')
                {
                    count++;
                    board[i][j] = '@';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[i][j] == 'q')
                {
                    count++;
                    board[i][j] = '#';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else if (piece == 'b')
            {
                if (board[i][j] == 'R')
                {
                    count++;
                    board[i][j] = '^';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[i][j] == 'N')
                {
                    count++;
                    board[i][j] = '*';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[i][j] == 'B')
                {
                    count++;
                    board[i][j] = '-';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[i][j] == 'Q')
                {
                    count++;
                    board[i][j] = '+';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else
                break;
        }
        for (int i = row + 1, j = col + 1; i < size || j < size; i++, j++)//placing x on the bottom right diagonal of bishop
        {
            if (i >= size || j >= size || i < 0 || j < 0)
                break;
            if (board[i][j] == '_')
            {
                count++;
                board[i][j] = 'x';
                cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\n";
            }
            else if (piece == 'B')
            {
                if (board[i][j] == 'r')
                {
                    count++;
                    board[i][j] = '~';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[i][j] == 'n')
                {
                    count++;
                    board[i][j] = '!';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[i][j] == 'b')
                {
                    count++;
                    board[i][j] = '@';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[i][j] == 'q')
                {
                    count++;
                    board[i][j] = '#';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else if (piece == 'b')
            {
                if (board[i][j] == 'R')
                {
                    count++;
                    board[i][j] = '^';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[i][j] == 'N')
                {
                    count++;
                    board[i][j] = '*';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[i][j] == 'B')
                {
                    count++;
                    board[i][j] = '-';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[i][j] == 'Q')
                {
                    count++;
                    board[i][j] = '+';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else
                break;
        }
        for (int i = row + 1, j = col - 1; i < size || j >= 0; i++, j--)//placing x on the bottom left diagonal of bishop
        {
            if (i >= size || j >= size || i < 0 || j < 0)
                break;
            if (board[i][j] == '_')
            {
                count++;
                board[i][j] = 'x';
                cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\n";
            }
            else if (piece == 'B')
            {
                if (board[i][j] == 'r')
                {
                    count++;
                    board[i][j] = '~';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[i][j] == 'n')
                {
                    count++;
                    board[i][j] = '!';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[i][j] == 'b')
                {
                    count++;
                    board[i][j] = '@';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[i][j] == 'q')
                {
                    count++;
                    board[i][j] = '#';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else if (piece == 'b')
            {
                if (board[i][j] == 'R')
                {
                    count++;
                    board[i][j] = '^';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[i][j] == 'N')
                {
                    count++;
                    board[i][j] = '*';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[i][j] == 'B')
                {
                    count++;
                    board[i][j] = '-';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[i][j] == 'Q')
                {
                    count++;
                    board[i][j] = '+';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else
                break;
        }
    }
    if (piece == 'Q' || piece == 'q')
    {
        for (int i = row - 1, j = col + 1; i >= 0 || j < size; i--, j++)//placing x on the upper right diagonal of Queen
        {
            if (i >= size || j >= size || i < 0 || j < 0)
                break;
            if (board[i][j] == '_')
            {
                count++;
                board[i][j] = 'x';
                cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\n";
            }
            else if (piece == 'Q')
            {
                if (board[i][j] == 'r')
                {
                    count++;
                    board[i][j] = '~';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[i][j] == 'n')
                {
                    count++;
                    board[i][j] = '!';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[i][j] == 'b')
                {
                    count++;
                    board[i][j] = '@';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[i][j] == 'q')
                {
                    count++;
                    board[i][j] = '#';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else if (piece == 'q')
            {
                if (board[i][j] == 'R')
                {
                    count++;
                    board[i][j] = '^';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[i][j] == 'N')
                {
                    count++;
                    board[i][j] = '*';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[i][j] == 'B')
                {
                    count++;
                    board[i][j] = '-';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[i][j] == 'Q')
                {
                    count++;
                    board[i][j] = '+';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else
                break;
        }
        for (int i = row - 1, j = col - 1; i >= 0 || j >= 0; i--, j--)//placing x on the upper left diagonal of Queen
        {
            if (i >= size || j >= size || i < 0 || j < 0)
                break;
            if (board[i][j] == '_')
            {
                count++;
                board[i][j] = 'x';
                cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\n";
            }
            else if (piece == 'Q')
            {
                if (board[i][j] == 'r')
                {
                    count++;
                    board[i][j] = '~';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[i][j] == 'n')
                {
                    count++;
                    board[i][j] = '!';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[i][j] == 'b')
                {
                    count++;
                    board[i][j] = '@';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[i][j] == 'q')
                {
                    count++;
                    board[i][j] = '#';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else if (piece == 'q')
            {
                if (board[i][j] == 'R')
                {
                    count++;
                    board[i][j] = '^';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[i][j] == 'N')
                {
                    count++;
                    board[i][j] = '*';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[i][j] == 'B')
                {
                    count++;
                    board[i][j] = '-';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[i][j] == 'Q')
                {
                    count++;
                    board[i][j] = '+';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else
                break;
        }
        for (int i = row + 1, j = col + 1; i < size || j < size; i++, j++)//placing x on the bottom right diagonal of Queen
        {
            if (i >= size || j >= size || i < 0 || j < 0)
                break;
            if (board[i][j] == '_')
            {
                count++;
                board[i][j] = 'x';
                cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\n";
            }
            else if (piece == 'Q')
            {
                if (board[i][j] == 'r')
                {
                    count++;
                    board[i][j] = '~';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[i][j] == 'n')
                {
                    count++;
                    board[i][j] = '!';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[i][j] == 'b')
                {
                    count++;
                    board[i][j] = '@';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[i][j] == 'q')
                {
                    count++;
                    board[i][j] = '#';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else if (piece == 'q')
            {
                if (board[i][j] == 'R')
                {
                    count++;
                    board[i][j] = '^';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[i][j] == 'N')
                {
                    count++;
                    board[i][j] = '*';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[i][j] == 'B')
                {
                    count++;
                    board[i][j] = '-';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[i][j] == 'Q')
                {
                    count++;
                    board[i][j] = '+';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else
                break;
        }
        for (int i = row + 1, j = col - 1; i < size || j >= 0; i++, j--)//placing x on the bottom left diagonal of Queen
        {
            if (i >= size || j >= size || i < 0 || j < 0)
                break;
            if (board[i][j] == '_')
            {
                count++;
                board[i][j] = 'x';
                cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\n";
            }
            else if (piece == 'Q')
            {
                if (board[i][j] == 'r')
                {
                    count++;
                    board[i][j] = '~';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[i][j] == 'n')
                {
                    count++;
                    board[i][j] = '!';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[i][j] == 'b')
                {
                    count++;
                    board[i][j] = '@';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[i][j] == 'q')
                {
                    count++;
                    board[i][j] = '#';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else if (piece == 'q')
            {
                if (board[i][j] == 'R')
                {
                    count++;
                    board[i][j] = '^';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[i][j] == 'N')
                {
                    count++;
                    board[i][j] = '*';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[i][j] == 'B')
                {
                    count++;
                    board[i][j] = '-';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[i][j] == 'Q')
                {
                    count++;
                    board[i][j] = '+';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << i - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else
                break;
        }
        for (int j = col + 1; j < size; j++)//placing x to the right of Queen
        {
            if (j >= size)
                break;
            if (board[row][j] == '_')
            {
                count++;
                board[row][j] = 'x';
                cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\n";
            }
            else if (piece == 'Q')
            {
                if (board[row][j] == 'r')
                {
                    count++;
                    board[row][j] = '~';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[row][j] == 'n')
                {
                    count++;
                    board[row][j] = '!';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[row][j] == 'b')
                {
                    count++;
                    board[row][j] = '@';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[row][j] == 'q')
                {
                    count++;
                    board[row][j] = '#';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else if (piece == 'q')
            {
                if (board[row][j] == 'R')
                {
                    count++;
                    board[row][j] = '^';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[row][j] == 'N')
                {
                    count++;
                    board[row][j] = '*';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[row][j] == 'B')
                {
                    count++;
                    board[row][j] = '-';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[row][j] == 'Q')
                {
                    count++;
                    board[row][j] = '+';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else
                break;
        }
        for (int j = col - 1; j >= 0; j--)//placing x to the left of Queen
        {
            if (j < 0)
                break;
            if (board[row][j] == '_')
            {
                count++;
                board[row][j] = 'x';
                cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\n";
            }
            else if (piece == 'Q')
            {
                if (board[row][j] == 'r')
                {
                    count++;
                    board[row][j] = '~';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[row][j] == 'n')
                {
                    count++;
                    board[row][j] = '!';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[row][j] == 'b')
                {
                    count++;
                    board[row][j] = '@';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[row][j] == 'q')
                {
                    count++;
                    board[row][j] = '#';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else if (piece == 'q')
            {
                if (board[row][j] == 'R')
                {
                    count++;
                    board[row][j] = '^';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[row][j] == 'N')
                {
                    count++;
                    board[row][j] = '*';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[row][j] == 'B')
                {
                    count++;
                    board[row][j] = '-';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[row][j] == 'Q')
                {
                    count++;
                    board[row][j] = '+';
                    cout << "Possible Move " << count << " (" << j - 1 << "," << row - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else
                break;
        }
        for (int i = row + 1; i < size; i++)//placing x to the bottom of Queen
        {
            if (i >= size)
                break;
            if (board[i][col] == '_')
            {
                count++;
                board[i][col] = 'x';
                cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\n";
            }
            else if (piece == 'Q')
            {
                if (board[i][col] == 'r')
                {
                    count++;
                    board[i][col] = '~';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[i][col] == 'n')
                {
                    count++;
                    board[i][col] = '!';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[i][col] == 'b')
                {
                    count++;
                    board[i][col] = '@';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[i][col] == 'q')
                {
                    count++;
                    board[i][col] = '#';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else if (piece == 'q')
            {
                if (board[i][col] == 'R')
                {
                    count++;
                    board[i][col] = '^';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[i][col] == 'N')
                {
                    count++;
                    board[i][col] = '*';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[i][col] == 'B')
                {
                    count++;
                    board[i][col] = '-';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[i][col] == 'Q')
                {
                    count++;
                    board[i][col] = '+';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else
                break;
        }
        for (int i = row - 1; i >= 0; i--)//placing x to the above of Queen
        {
            if (i < 0)
                break;
            if (board[i][col] == '_')
            {
                count++;
                board[i][col] = 'x';
                cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\n";
            }
            else if (piece == 'Q')
            {
                if (board[i][col] == 'r')
                {
                    count++;
                    board[i][col] = '~';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[i][col] == 'n')
                {
                    count++;
                    board[i][col] = '!';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[i][col] == 'b')
                {
                    count++;
                    board[i][col] = '@';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[i][col] == 'q')
                {
                    count++;
                    board[i][col] = '#';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else if (piece == 'q')
            {
                if (board[i][col] == 'R')
                {
                    count++;
                    board[i][col] = '^';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Rook\n";
                    break;
                }
                if (board[i][col] == 'N')
                {
                    count++;
                    board[i][col] = '*';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Knight\n";
                    break;
                }
                if (board[i][col] == 'B')
                {
                    count++;
                    board[i][col] = '-';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Bishop\n";
                    break;
                }
                if (board[i][col] == 'Q')
                {
                    count++;
                    board[i][col] = '+';
                    cout << "Possible Move " << count << " (" << col - 1 << "," << i - 1 << ")\tTake Queen\n";
                    break;
                }
            }
            else
                break;
        }
    }
    if (piece == 'N' || piece == 'n')
    {
        int dx[] = { 2, 2, 1, 1, -1, -1, -2, -2 };
        int dy[] = { 1, -1, 2, -2, 2, -2, 1, -1 };

        for (int k = 0; k < 8; k++)
        {
            int x = row + dx[k];
            int y = col + dy[k];

            if (x >= 1 && x < size && y >= 1 && y < size)
            {
                if (board[x][y] == '_')
                {
                    count++;
                    board[x][y] = 'x';
                    cout << "Possible Move " << count << ": (" << y - 1 << "," << x - 1 << ")\n";
                }
                else if (piece == 'N')
                {
                    if (board[x][y] == 'r')
                    {
                        count++;
                        board[x][y] = '~';
                        cout << "Possible Move " << count << ": (" << y - 1 << "," << x - 1 << ")\tTake Rook\n";
                        break;
                    }
                    if (board[x][y] == 'n')
                    {
                        count++;
                        board[x][y] = '!';
                        cout << "Possible Move " << count << ": (" << y - 1 << "," << x - 1 << ")\tTake Knight\n";
                        break;
                    }
                    if (board[x][y] == 'b')
                    {
                        count++;
                        board[x][y] = '@';
                        cout << "Possible Move " << count << ": (" << y - 1 << "," << x - 1 << ")\tTake Bishop\n";
                        break;
                    }
                    if (board[x][y] == 'q')
                    {
                        count++;
                        board[x][y] = '#';
                        cout << "Possible Move " << count << ": (" << y - 1 << "," << x - 1 << ")\tTake Queen\n";
                        break;
                    }
                }
                else if (piece == 'n')
                {
                    if (board[x][y] == 'R')
                    {
                        count++;
                        board[x][y] = '^';
                        cout << "Possible Move " << count << ": (" << y - 1 << "," << x - 1 << ")\tTake Rook\n";
                        break;
                    }
                    if (board[x][y] == 'N')
                    {
                        count++;
                        board[x][y] = '*';
                        cout << "Possible Move " << count << ": (" << y - 1 << "," << x - 1 << ")\tTake Knight\n";
                        break;
                    }
                    if (board[x][y] == 'B')
                    {
                        count++;
                        board[x][y] = '-';
                        cout << "Possible Move " << count << ": (" << y - 1 << "," << x - 1 << ")\tTake Bishop\n";
                        break;
                    }
                    if (board[x][y] == 'Q')
                    {
                        count++;
                        board[x][y] = '+';
                        cout << "Possible Move " << count << ": (" << y - 1 << "," << x - 1 << ")\tTake Queen\n";
                        break;
                    }
                }
            }
        }
    }
    if (piece == 'K')
    {
        if ((col + 1) < size) {
            if (board[row][col + 1] == '_')//placing king to the right
            {
                if (isCheck(board, size, row, col + 1, piece) == 0)
                {
                    count++;
                    board[row][col + 1] = 'x';
                    cout << "Possible Move " << count << ": (" << col << "," << row - 1 << ")\n";
                }
            }
            else if (board[row][col + 1] == 'r')//placing king to the right
            {
                if (isCheck(board, size, row, col + 1, piece) == 0)
                {
                    count++;
                    board[row][col + 1] = '~';
                    cout << "Possible Move " << count << ": (" << col << "," << row - 1 << ")\tTake Rook\n";
                }
            }
            else if (board[row][col + 1] == 'n')//placing king to the right
            {
                if (isCheck(board, size, row, col + 1, piece) == 0)
                {
                    count++;
                    board[row][col + 1] = '!';
                    cout << "Possible Move " << count << ": (" << col << "," << row - 1 << ")\tTake Knight\n";
                }
            }
            else if (board[row][col + 1] == 'b')//placing king to the right
            {
                if (isCheck(board, size, row, col + 1, piece) == 0)
                {
                    count++;
                    board[row][col + 1] = '@';
                    cout << "Possible Move " << count << ": (" << col << "," << row - 1 << ")\tTake Bishop\n";
                }
            }
            else if (board[row][col + 1] == 'q')//placing king to the right
            {
                if (isCheck(board, size, row, col + 1, piece) == 0)
                {
                    count++;
                    board[row][col + 1] = '#';
                    cout << "Possible Move " << count << ": (" << col << "," << row - 1 << ")\tTake Queen\n";
                }
            }
        }
        if ((col - 1) >= 0) {
            if (board[row][col - 1] == '_')//placing king to the left
            {
                if (isCheck(board, size, row, col - 1, piece) == 0)
                {
                    count++;
                    board[row][col - 1] = 'x';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row - 1 << ")\n";
                }
            }
            else if (board[row][col - 1] == 'r')//placing king to the left
            {
                if (isCheck(board, size, row, col - 1, piece) == 0)
                {
                    count++;
                    board[row][col - 1] = '~';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row - 1 << ")\n";
                }
            }
            else if (board[row][col - 1] == 'n')//placing king to the left
            {
                if (isCheck(board, size, row, col - 1, piece) == 0)
                {
                    count++;
                    board[row][col - 1] = '!';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row - 1 << ")\n";
                }
            }
            else if (board[row][col - 1] == 'b')//placing king to the left
            {
                if (isCheck(board, size, row, col - 1, piece) == 0)
                {
                    count++;
                    board[row][col - 1] = '@';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row - 1 << ")\n";
                }
            }
            else if (board[row][col - 1] == 'q')//placing king to the left
            {
                if (isCheck(board, size, row, col - 1, piece) == 0)
                {
                    count++;
                    board[row][col - 1] = '#';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row - 1 << ")\n";
                }
            }
        }
        if ((row + 1) < size) {
            if (board[row + 1][col] == '_')//placing king to the bottom
            {
                if (isCheck(board, size, row + 1, col, piece) == 0)
                {
                    count++;
                    board[row + 1][col] = 'x';
                    cout << "Possible Move " << count << ": (" << col - 1 << "," << row << ")\n";
                }
            }
            else if (board[row + 1][col] == 'r')//placing king to the bottom
            {
                if (isCheck(board, size, row + 1, col, piece) == 0)
                {
                    count++;
                    board[row + 1][col] = '~';
                    cout << "Possible Move " << count << ": (" << col - 1 << "," << row << ")\n";
                }
            }
            else if (board[row + 1][col] == 'n')//placing king to the bottom
            {
                if (isCheck(board, size, row + 1, col, piece) == 0)
                {
                    count++;
                    board[row + 1][col] = '!';
                    cout << "Possible Move " << count << ": (" << col - 1 << "," << row << ")\n";
                }
            }
            else if (board[row + 1][col] == 'b')//placing king to the bottom
            {
                if (isCheck(board, size, row + 1, col, piece) == 0)
                {
                    count++;
                    board[row + 1][col] = '@';
                    cout << "Possible Move " << count << ": (" << col - 1 << "," << row << ")\n";
                }
            }
            else if (board[row + 1][col] == 'q')//placing king to the bottom
            {
                if (isCheck(board, size, row + 1, col, piece) == 0)
                {
                    count++;
                    board[row + 1][col] = '#';
                    cout << "Possible Move " << count << ": (" << col - 1 << "," << row << ")\n";
                }
            }
        }
        if ((row - 1) >= 0) {
            if (board[row - 1][col] == '_')//placing king to the above
            {
                if (isCheck(board, size, row - 1, col, piece) == 0)
                {
                    count++;
                    board[row - 1][col] = 'x';
                    cout << "Possible Move " << count << ": (" << col - 1 << "," << row - 2 << ")\n";
                }
            }
            else if (board[row - 1][col] == 'r')//placing king to the above
            {
                if (isCheck(board, size, row - 1, col, piece) == 0)
                {
                    count++;
                    board[row - 1][col] = '~';
                    cout << "Possible Move " << count << ": (" << col - 1 << "," << row - 2 << ")\n";
                }
            }
            else if (board[row - 1][col] == 'n')//placing king to the above
            {
                if (isCheck(board, size, row - 1, col, piece) == 0)
                {
                    count++;
                    board[row - 1][col] = '!';
                    cout << "Possible Move " << count << ": (" << col - 1 << "," << row - 2 << ")\n";
                }
            }
            else if (board[row - 1][col] == 'b')//placing king to the above
            {
                if (isCheck(board, size, row - 1, col, piece) == 0)
                {
                    count++;
                    board[row - 1][col] = '@';
                    cout << "Possible Move " << count << ": (" << col - 1 << "," << row - 2 << ")\n";
                }
            }
            else if (board[row - 1][col] == 'q')//placing king to the above
            {
                if (isCheck(board, size, row - 1, col, piece) == 0)
                {
                    count++;
                    board[row - 1][col] == '#';
                    cout << "Possible Move " << count << ": (" << col - 1 << "," << row - 2 << ")\n";
                }
            }
        }
        if ((row - 1) >= 0 && (col + 1) < size) {
            if (board[row - 1][col + 1] == '_')//placing king to the upper right diagonal
            {
                if (isCheck(board, size, row - 1, col + 1, piece) == 0)
                {
                    count++;
                    board[row - 1][col + 1] = 'x';
                    cout << "Possible Move " << count << ": (" << col << "," << row - 2 << ")\n";
                }
            }
            else if (board[row - 1][col + 1] == 'r')//placing king to the upper right diagonal
            {
                if (isCheck(board, size, row - 1, col + 1, piece) == 0)
                {
                    count++;
                    board[row - 1][col + 1] = '~';
                    cout << "Possible Move " << count << ": (" << col << "," << row - 2 << ")\n";
                }
            }
            else if (board[row - 1][col + 1] == 'n')//placing king to the upper right diagonal
            {
                if (isCheck(board, size, row - 1, col + 1, piece) == 0)
                {
                    count++;
                    board[row - 1][col + 1] = '!';
                    cout << "Possible Move " << count << ": (" << col << "," << row - 2 << ")\n";
                }
            }
            else if (board[row - 1][col + 1] == 'b')//placing king to the upper right diagonal
            {
                if (isCheck(board, size, row - 1, col + 1, piece) == 0)
                {
                    count++;
                    board[row - 1][col + 1] == '@';
                    cout << "Possible Move " << count << ": (" << col << "," << row - 2 << ")\n";
                }
            }
            else if (board[row - 1][col + 1] == 'q')//placing king to the upper right diagonal
            {
                if (isCheck(board, size, row - 1, col + 1, piece) == 0)
                {
                    count++;
                    board[row - 1][col + 1] = '#';
                    cout << "Possible Move " << count << ": (" << col << "," << row - 2 << ")\n";
                }
            }
        }
        if ((row + 1) < size && (col + 1) < size) {
            if (board[row + 1][col + 1] == '_')//placing king to the lower right diagonal
            {
                if (isCheck(board, size, row + 1, col + 1, piece) == 0)
                {
                    count++;
                    board[row + 1][col + 1] = 'x';
                    cout << "Possible Move " << count << ": (" << col << "," << row << ")\n";
                }
            }
            else if (board[row + 1][col + 1] == 'r')//placing king to the lower right diagonal
            {
                if (isCheck(board, size, row + 1, col + 1, piece) == 0)
                {
                    count++;
                    board[row + 1][col + 1] = '~';
                    cout << "Possible Move " << count << ": (" << col << "," << row << ")\n";
                }
            }
            else if (board[row + 1][col + 1] == 'n')//placing king to the lower right diagonal
            {
                if (isCheck(board, size, row + 1, col + 1, piece) == 0)
                {
                    count++;
                    board[row + 1][col + 1] = '!';
                    cout << "Possible Move " << count << ": (" << col << "," << row << ")\n";
                }
            }
            else if (board[row + 1][col + 1] == 'b')//placing king to the lower right diagonal
            {
                if (isCheck(board, size, row + 1, col + 1, piece) == 0)
                {
                    count++;
                    board[row + 1][col + 1] = '@';
                    cout << "Possible Move " << count << ": (" << col << "," << row << ")\n";
                }
            }
            else if (board[row + 1][col + 1] == 'q')//placing king to the lower right diagonal
            {
                if (isCheck(board, size, row + 1, col + 1, piece) == 0)
                {
                    count++;
                    board[row + 1][col + 1] = '#';
                    cout << "Possible Move " << count << ": (" << col << "," << row << ")\n";
                }
            }
        }
        if ((row - 1) >= 0 && (col - 1) >= 0) {
            if (board[row - 1][col - 1] == '_')//placing king to the upper left diagonal
            {
                if (isCheck(board, size, row - 1, col - 1, piece) == 0)
                {
                    count++;
                    board[row - 1][col - 1] = 'x';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row - 2 << ")\n";
                }
            }
            else if (board[row - 1][col - 1] == 'r')//placing king to the upper left diagonal
            {
                if (isCheck(board, size, row - 1, col - 1, piece) == 0)
                {
                    count++;
                    board[row - 1][col - 1] = '~';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row - 2 << ")\n";
                }
            }
            else if (board[row - 1][col - 1] == 'n')//placing king to the upper left diagonal
            {
                if (isCheck(board, size, row - 1, col - 1, piece) == 0)
                {
                    count++;
                    board[row - 1][col - 1] = '!';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row - 2 << ")\n";
                }
            }
            else if (board[row - 1][col - 1] == 'b')//placing king to the upper left diagonal
            {
                if (isCheck(board, size, row - 1, col - 1, piece) == 0)
                {
                    count++;
                    board[row - 1][col - 1] = '@';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row - 2 << ")\n";
                }
            }
            else if (board[row - 1][col - 1] == 'q')//placing king to the upper left diagonal
            {
                if (isCheck(board, size, row - 1, col - 1, piece) == 0)
                {
                    count++;
                    board[row - 1][col - 1] = '#';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row - 2 << ")\n";
                }
            }
        }
        if ((row + 1) < size && (col - 1) >= 0) {
            if (board[row + 1][col - 1] == '_')//placing king to the lower left diagonal
            {
                if (isCheck(board, size, row + 1, col - 1, piece) == 0)
                {
                    count++;
                    board[row + 1][col - 1] = 'x';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row << ")\n";
                }
            }
            else if (board[row + 1][col - 1] == 'r')//placing king to the lower left diagonal
            {
                if (isCheck(board, size, row + 1, col - 1, piece) == 0)
                {
                    count++;
                    board[row + 1][col - 1] = '~';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row << ")\n";
                }
            }
            else if (board[row + 1][col - 1] == 'n')//placing king to the lower left diagonal
            {
                if (isCheck(board, size, row + 1, col - 1, piece) == 0)
                {
                    count++;
                    board[row + 1][col - 1] = '!';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row << ")\n";
                }
            }
            else if (board[row + 1][col - 1] == 'b')//placing king to the lower left diagonal
            {
                if (isCheck(board, size, row + 1, col - 1, piece) == 0)
                {
                    count++;
                    board[row + 1][col - 1] = '@';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row << ")\n";
                }
            }
            else if (board[row + 1][col - 1] == 'q')//placing king to the lower left diagonal
            {
                if (isCheck(board, size, row + 1, col - 1, piece) == 0)
                {
                    count++;
                    board[row + 1][col - 1] = '#';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row << ")\n";
                }
            }
        }
    }
    if (piece == 'k')
    {
        if ((col + 1) < size) {
            if (board[row][col + 1] == '_')//placing king to the right
            {
                if (isCheck(board, size, row, col + 1, piece) == 0)
                {
                    count++;
                    board[row][col + 1] = 'x';
                    cout << "Possible Move " << count << ": (" << col << "," << row - 1 << ")\n";
                }
            }
            else if (board[row][col + 1] == 'R')//placing king to the right
            {
                if (isCheck(board, size, row, col + 1, piece) == 0)
                {
                    count++;
                    board[row][col + 1] = '^';
                    cout << "Possible Move " << count << ": (" << col << "," << row - 1 << ")\tTake Rook\n";
                }
            }
            else if (board[row][col + 1] == 'N')//placing king to the right
            {
                if (isCheck(board, size, row, col + 1, piece) == 0)
                {
                    count++;
                    board[row][col + 1] = '*';
                    cout << "Possible Move " << count << ": (" << col << "," << row - 1 << ")\tTake Knight\n";
                }
            }
            else if (board[row][col + 1] == 'B')//placing king to the right
            {
                if (isCheck(board, size, row, col + 1, piece) == 0)
                {
                    count++;
                    board[row][col + 1] = '-';
                    cout << "Possible Move " << count << ": (" << col << "," << row - 1 << ")\tTake Bishop\n";
                }
            }
            else if (board[row][col + 1] == 'Q')//placing king to the right
            {
                if (isCheck(board, size, row, col + 1, piece) == 0)
                {
                    count++;
                    board[row][col + 1] = '+';
                    cout << "Possible Move " << count << ": (" << col << "," << row - 1 << ")\tTake Queen\n";
                }
            }
        }
        if ((col - 1) >= 0) {
            if (board[row][col - 1] == '_')//placing king to the left
            {
                if (isCheck(board, size, row, col - 1, piece) == 0)
                {
                    count++;
                    board[row][col - 1] = 'x';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row - 1 << ")\n";
                }
            }
            else if (board[row][col - 1] == 'R')//placing king to the left
            {
                if (isCheck(board, size, row, col - 1, piece) == 0)
                {
                    count++;
                    board[row][col - 1] = '^';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row - 1 << ")\n";
                }
            }
            else if (board[row][col - 1] == 'N')//placing king to the left
            {
                if (isCheck(board, size, row, col - 1, piece) == 0)
                {
                    count++;
                    board[row][col - 1] = '*';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row - 1 << ")\n";
                }
            }
            else if (board[row][col - 1] == 'B')//placing king to the left
            {
                if (isCheck(board, size, row, col - 1, piece) == 0)
                {
                    count++;
                    board[row][col - 1] = '-';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row - 1 << ")\n";
                }
            }
            else if (board[row][col - 1] == 'Q')//placing king to the left
            {
                if (isCheck(board, size, row, col - 1, piece) == 0)
                {
                    count++;
                    board[row][col - 1] = '+';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row - 1 << ")\n";
                }
            }
        }
        if ((row + 1) < size) {
            if (board[row + 1][col] == '_')//placing king to the bottom
            {
                if (isCheck(board, size, row + 1, col, piece) == 0)
                {
                    count++;
                    board[row + 1][col] = 'x';
                    cout << "Possible Move " << count << ": (" << col - 1 << "," << row << ")\n";
                }
            }
            else if (board[row + 1][col] == 'R')//placing king to the bottom
            {
                if (isCheck(board, size, row + 1, col, piece) == 0)
                {
                    count++;
                    board[row + 1][col] = '^';
                    cout << "Possible Move " << count << ": (" << col - 1 << "," << row << ")\n";
                }
            }
            else if (board[row + 1][col] == 'N')//placing king to the bottom
            {
                if (isCheck(board, size, row + 1, col, piece) == 0)
                {
                    count++;
                    board[row + 1][col] = '*';
                    cout << "Possible Move " << count << ": (" << col - 1 << "," << row << ")\n";
                }
            }
            else if (board[row + 1][col] == 'B')//placing king to the bottom
            {
                if (isCheck(board, size, row + 1, col, piece) == 0)
                {
                    count++;
                    board[row + 1][col] = '-';
                    cout << "Possible Move " << count << ": (" << col - 1 << "," << row << ")\n";
                }
            }
            else if (board[row + 1][col] == 'Q')//placing king to the bottom
            {
                if (isCheck(board, size, row + 1, col, piece) == 0)
                {
                    count++;
                    board[row + 1][col] = '+';
                    cout << "Possible Move " << count << ": (" << col - 1 << "," << row << ")\n";
                }
            }
        }
        if ((row - 1) >= 0) {
            if (board[row - 1][col] == '_')//placing king to the above
            {
                if (isCheck(board, size, row - 1, col, piece) == 0)
                {
                    count++;
                    board[row - 1][col] = 'x';
                    cout << "Possible Move " << count << ": (" << col - 1 << "," << row - 2 << ")\n";
                }
            }
            else if (board[row - 1][col] == 'R')//placing king to the above
            {
                if (isCheck(board, size, row - 1, col, piece) == 0)
                {
                    count++;
                    board[row - 1][col] = '^';
                    cout << "Possible Move " << count << ": (" << col - 1 << "," << row - 2 << ")\n";
                }
            }
            else if (board[row - 1][col] == 'N')//placing king to the above
            {
                if (isCheck(board, size, row - 1, col, piece) == 0)
                {
                    count++;
                    board[row - 1][col] = '*';
                    cout << "Possible Move " << count << ": (" << col - 1 << "," << row - 2 << ")\n";
                }
            }
            else if (board[row - 1][col] == 'B')//placing king to the above
            {
                if (isCheck(board, size, row - 1, col, piece) == 0)
                {
                    count++;
                    board[row - 1][col] = '-';
                    cout << "Possible Move " << count << ": (" << col - 1 << "," << row - 2 << ")\n";
                }
            }
            else if (board[row - 1][col] == 'Q')//placing king to the above
            {
                if (isCheck(board, size, row - 1, col, piece) == 0)
                {
                    count++;
                    board[row - 1][col] == '+';
                    cout << "Possible Move " << count << ": (" << col - 1 << "," << row - 2 << ")\n";
                }
            }
        }
        if ((row - 1) >= 0 && (col + 1) < size) {
            if (board[row - 1][col + 1] == '_')//placing king to the upper right diagonal
            {
                if (isCheck(board, size, row - 1, col + 1, piece) == 0)
                {
                    count++;
                    board[row - 1][col + 1] = 'x';
                    cout << "Possible Move " << count << ": (" << col << "," << row - 2 << ")\n";
                }
            }
            else if (board[row - 1][col + 1] == 'R')//placing king to the upper right diagonal
            {
                if (isCheck(board, size, row - 1, col + 1, piece) == 0)
                {
                    count++;
                    board[row - 1][col + 1] = '^';
                    cout << "Possible Move " << count << ": (" << col << "," << row - 2 << ")\n";
                }
            }
            else if (board[row - 1][col + 1] == 'N')//placing king to the upper right diagonal
            {
                if (isCheck(board, size, row - 1, col + 1, piece) == 0)
                {
                    count++;
                    board[row - 1][col + 1] = '*';
                    cout << "Possible Move " << count << ": (" << col << "," << row - 2 << ")\n";
                }
            }
            else if (board[row - 1][col + 1] == 'B')//placing king to the upper right diagonal
            {
                if (isCheck(board, size, row - 1, col + 1, piece) == 0)
                {
                    count++;
                    board[row - 1][col + 1] == '-';
                    cout << "Possible Move " << count << ": (" << col << "," << row - 2 << ")\n";
                }
            }
            else if (board[row - 1][col + 1] == 'Q')//placing king to the upper right diagonal
            {
                if (isCheck(board, size, row - 1, col + 1, piece) == 0)
                {
                    count++;
                    board[row - 1][col + 1] = '+';
                    cout << "Possible Move " << count << ": (" << col << "," << row - 2 << ")\n";
                }
            }
        }
        if ((row + 1) < size && (col + 1) < size) {
            if (board[row + 1][col + 1] == '_')//placing king to the lower right diagonal
            {
                if (isCheck(board, size, row + 1, col + 1, piece) == 0)
                {
                    count++;
                    board[row + 1][col + 1] = 'x';
                    cout << "Possible Move " << count << ": (" << col << "," << row << ")\n";
                }
            }
            else if (board[row + 1][col + 1] == 'R')//placing king to the lower right diagonal
            {
                if (isCheck(board, size, row + 1, col + 1, piece) == 0)
                {
                    count++;
                    board[row + 1][col + 1] = '^';
                    cout << "Possible Move " << count << ": (" << col << "," << row << ")\n";
                }
            }
            else if (board[row + 1][col + 1] == 'N')//placing king to the lower right diagonal
            {
                if (isCheck(board, size, row + 1, col + 1, piece) == 0)
                {
                    count++;
                    board[row + 1][col + 1] = '*';
                    cout << "Possible Move " << count << ": (" << col << "," << row << ")\n";
                }
            }
            else if (board[row + 1][col + 1] == 'B')//placing king to the lower right diagonal
            {
                if (isCheck(board, size, row + 1, col + 1, piece) == 0)
                {
                    count++;
                    board[row + 1][col + 1] = '-';
                    cout << "Possible Move " << count << ": (" << col << "," << row << ")\n";
                }
            }
            else if (board[row + 1][col + 1] == 'Q')//placing king to the lower right diagonal
            {
                if (isCheck(board, size, row + 1, col + 1, piece) == 0)
                {
                    count++;
                    board[row + 1][col + 1] = '+';
                    cout << "Possible Move " << count << ": (" << col << "," << row << ")\n";
                }
            }
        }
        if ((row - 1) >= 0 && (col - 1) >= 0) {
            if (board[row - 1][col - 1] == '_')//placing king to the upper left diagonal
            {
                if (isCheck(board, size, row - 1, col - 1, piece) == 0)
                {
                    count++;
                    board[row - 1][col - 1] = 'x';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row - 2 << ")\n";
                }
            }
            else if (board[row - 1][col - 1] == 'R')//placing king to the upper left diagonal
            {
                if (isCheck(board, size, row - 1, col - 1, piece) == 0)
                {
                    count++;
                    board[row - 1][col - 1] = '^';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row - 2 << ")\n";
                }
            }
            else if (board[row - 1][col - 1] == 'N')//placing king to the upper left diagonal
            {
                if (isCheck(board, size, row - 1, col - 1, piece) == 0)
                {
                    count++;
                    board[row - 1][col - 1] = '*';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row - 2 << ")\n";
                }
            }
            else if (board[row - 1][col - 1] == 'B')//placing king to the upper left diagonal
            {
                if (isCheck(board, size, row - 1, col - 1, piece) == 0)
                {
                    count++;
                    board[row - 1][col - 1] = '-';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row - 2 << ")\n";
                }
            }
            else if (board[row - 1][col - 1] == 'Q')//placing king to the upper left diagonal
            {
                if (isCheck(board, size, row - 1, col - 1, piece) == 0)
                {
                    count++;
                    board[row - 1][col - 1] = '+';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row - 2 << ")\n";
                }
            }
        }
        if ((row + 1) < size && (col - 1) >= 0) {
            if (board[row + 1][col - 1] == '_')//placing king to the lower left diagonal
            {
                if (isCheck(board, size, row + 1, col - 1, piece) == 0)
                {
                    count++;
                    board[row + 1][col - 1] = 'x';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row << ")\n";
                }
            }
            else if (board[row + 1][col - 1] == 'R')//placing king to the lower left diagonal
            {
                if (isCheck(board, size, row + 1, col - 1, piece) == 0)
                {
                    count++;
                    board[row + 1][col - 1] = '^';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row << ")\n";
                }
            }
            else if (board[row + 1][col - 1] == 'N')//placing king to the lower left diagonal
            {
                if (isCheck(board, size, row + 1, col - 1, piece) == 0)
                {
                    count++;
                    board[row + 1][col - 1] = '*';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row << ")\n";
                }
            }
            else if (board[row + 1][col - 1] == 'B')//placing king to the lower left diagonal
            {
                if (isCheck(board, size, row + 1, col - 1, piece) == 0)
                {
                    count++;
                    board[row + 1][col - 1] = '-';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row << ")\n";
                }
            }
            else if (board[row + 1][col - 1] == 'Q')//placing king to the lower left diagonal
            {
                if (isCheck(board, size, row + 1, col - 1, piece) == 0)
                {
                    count++;
                    board[row + 1][col - 1] = '+';
                    cout << "Possible Move " << count << ": (" << col - 2 << "," << row << ")\n";
                }
            }
        }
    }

    bool xfind = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] == 'x')
                xfind = 1;
        }
    }
    if (xfind == 0)
    {
        cout << "No moves available\n";
        return xfind;
    }
    display(board, size);
    move(board, size, piece, row, col);
    return xfind;
}
void move(char** board, int size, char piece, int row, int col)
{
    int r, c;
    bool correctMove = 0;
    while (1)
    {
        cout << "Enter the Position that you want to move from the Possible moves available marked as 'x': \n";
        cout << "col: ";
        cin >> c;
        cout << "row: ";
        cin >> r;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (board[r + 1][c + 1] == 'x' || board[r + 1][c + 1] == '~' || board[r + 1][c + 1] == '!' || board[r + 1][c + 1] == '@' || board[r + 1][c + 1] == '#' || board[r + 1][c + 1] == '^' || board[r + 1][c + 1] == '*' || board[r + 1][c + 1] == '-' || board[r + 1][c + 1] == '+')
                {
                    board[r + 1][c + 1] = piece;
                    correctMove = 1;
                    board[row][col] = '_';
                }
            }
        }
        if (correctMove == 1)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (board[i][j] == 'x')
                        board[i][j] = '_';
                    if (board[i][j] == '~')
                        board[i][j] = 'r';
                    if (board[i][j] == '!')
                        board[i][j] = 'n';
                    if (board[i][j] == '@')
                        board[i][j] = 'b';
                    if (board[i][j] == '#')
                        board[i][j] = 'q';
                    if (board[i][j] == '^')
                        board[i][j] = 'R';
                    if (board[i][j] == '*')
                        board[i][j] = 'N';
                    if (board[i][j] == '-')
                        board[i][j] = 'B';
                    if (board[i][j] == '+')
                        board[i][j] = 'Q';
                }
            }
            break;
        }
        else
            cout << "Invalid Position entered, enter again\n";
    }
}
bool isCheck(char** board, int size, int row, int col, char piece)
{
    if (piece == 'k')
    {
        // Check for attacks from opponent knights
        int knightMoves[8][2] = { {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1} };
        for (int i = 0; i < 8; i++)
        {
            int newRow = row + knightMoves[i][0];
            int newCol = col + knightMoves[i][1];
            if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size && board[newRow][newCol] == 'N')
                return true;

        }
        // Check for attacks from opponent bishops, queens, or kings in diagonal directions
        int diagMoves[4][2] = { {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
        for (int i = 0; i < 4; i++)
        {
            int j = 0;
            int newRow = row + diagMoves[i][0];
            int newCol = col + diagMoves[i][1];
            while (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size)
            {
                if (board[newRow][newCol] == 'B' || board[newRow][newCol] == 'Q' || (j == 0 && board[newRow][newCol] == 'K'))
                    return true;
                if (board[newRow][newCol] != '_')
                    break;
                newRow += diagMoves[i][0];
                newCol += diagMoves[i][1];
                j++;
            }
        }
        // Check for attacks from opponent rooks, queens, or kings in straight directions
        int straightMoves[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
        for (int i = 0; i < 4; i++)
        {
            int j = 0;
            int newRow = row + straightMoves[i][0];
            int newCol = col + straightMoves[i][1];
            while (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size)
            {
                if (board[newRow][newCol] == 'R' || board[newRow][newCol] == 'Q' || (j == 0 && board[newRow][newCol] == 'K'))
                    return true;
                if (board[newRow][newCol] != '_')
                    break;
                newRow += straightMoves[i][0];
                newCol += straightMoves[i][1];
                j++;
            }
        }
    }
    else if (piece == 'K')
    {
        // Check for attacks from opponent knights
        int knightMoves[8][2] = { {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1} };
        for (int i = 0; i < 8; i++)
        {
            int newRow = row + knightMoves[i][0];
            int newCol = col + knightMoves[i][1];
            if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size && board[newRow][newCol] == 'n')
                return true;

        }
        // Check for attacks from opponent bishops, queens, or kings in diagonal directions
        int diagMoves[4][2] = { {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
        for (int i = 0; i < 4; i++)
        {
            int newRow = row + diagMoves[i][0];
            int newCol = col + diagMoves[i][1];
            int j = 0;
            while (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size)
            {
                if (board[newRow][newCol] == 'b' || board[newRow][newCol] == 'q' || (j == 0 && board[newRow][newCol] == 'k'))
                    return true;
                if (board[newRow][newCol] != '_')
                    break;
                newRow += diagMoves[i][0];
                newCol += diagMoves[i][1];
                j++;
            }
        }
        // Check for attacks from opponent rooks, queens, or kings in straight directions
        int straightMoves[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
        for (int i = 0; i < 4; i++)
        {
            int j = 0;
            int newRow = row + straightMoves[i][0];
            int newCol = col + straightMoves[i][1];
            while (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size)
            {
                if (board[newRow][newCol] == 'r' || board[newRow][newCol] == 'q' || (j == 0 && board[newRow][newCol] == 'k'))
                    return true;
                if (board[newRow][newCol] != '_')
                    break;
                newRow += straightMoves[i][0];
                newCol += straightMoves[i][1];
                j++;
            }
        }
    }

    return false;
}