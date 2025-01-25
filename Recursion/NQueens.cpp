#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> ans;

bool isSafe(vector<string> &board, int row, int col, int n)
{
    // check upwards along the column
    for (int i = row; i >= 0; i--)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    // along the right digonal because i am filling right from first row so
    // there is no need to check in back right or back left diagonal
    int tempr = row;
    int tempc = col;
    while (tempr >= 0 && tempc < n)
    {
        if (board[tempr][tempc] == 'Q')
            return false;

        tempc++;
        tempr--;
    }

    // along the left diagonal
    tempr = row;
    tempc = col;
    while (tempr >= 0 && tempc >= 0)
    {
        if (board[tempr][tempc] == 'Q')
            return false;

        tempc--;
        tempr--;
    }
    return true;
}

// main function
// i will be passing row and checking at which column is it possible to
// place,once done then will be calling other row to check whether how can i
// place into that row in accordance with the prior
void solve(vector<string> &board, int row, int n)
{
    // base case
    if (row == n) // means all n-1 placed are been filled
    {
        ans.push_back(board);
        return;
    }

    // looping over every columns in that particular row
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 'Q';    // do
            solve(board, row + 1, n); // explore
            board[row][col] = '.';    // undo
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    // creating a grid/board
    vector<string> board(n, string(n, '.'));
    // means n strings with each n ... value in it
    solve(board, 0, n);
    return ans;
}
int main()
{

    return 0;
}