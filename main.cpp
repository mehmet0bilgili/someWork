#include <iostream>

using namespace std;

char board[5][5] = {
    {'x','0','1','1','1'},
    {'1','0','0','1','0'},
    {'1','1','1','1','1'},
    {'0','0','1','0','0'},
    {'0','1','1','1','1'},
};

void printBoard()
{
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << board[i][j];
        }
        if (i == 4) cout << "F";
        cout << "\n";
    }
}

int main()
{

    cout << "Finish (F) is right-down corner.\n";
    cout << "w-up, a-left, s-down, d-right\n";

    bool finish = true;
    char mv;
    int a = 0, b = 0;
    while (finish)
    {
        printBoard();
        cin >> mv;
        mv = tolower(mv);
        system("CLS");

        switch(mv) {
        case 'w':
            if (board[a-1][b] == '1') {
                board[a][b] = '1';
                board[a-1][b] = 'x';
                a--;
            }
            break;
        case 'a':
            if (board[a][b-1] == '1') {
                board[a][b] = '1';
                board[a][b-1] = 'x';
                b--;
            }
            break;
        case 's':
            if (board[a+1][b] == '1') {
                board[a][b] = '1';
                board[a+1][b] = 'x';
                a++;
            }
            break;
        case 'd':
            if (board[a][b+1] == '1') {
                board[a][b] = '1';
                board[a][b+1] = 'x';
                b++;
            }
            break;
        default:
            cout << "Press w, a, s, or d.\n";
        }

        if (a == 4 && b == 4) finish = false;
    }
    printBoard();
    cout << "Congrats!\n";

    return 0;
}
