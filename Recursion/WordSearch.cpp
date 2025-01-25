#include <bits/stdc++.h>
using namespace std;
bool solve(vector<vector<char>> &board, string &word, string &temp, int i,
           int j, int m, int n)
{
    if (temp == word)
    {
        return true;
    }

    if (i >= m || j >= n || i < 0 || j < 0 || board[i][j] == '@' ||
        board[i][j] != word[temp.size()])
        return false;

    char tempy;
    tempy = board[i][j];
    temp.push_back(board[i][j]);
    board[i][j] = '@';
    if ((solve(board, word, temp, i, j + 1, m, n) == true)) // right
        return true;
    if ((solve(board, word, temp, i, j - 1, m, n) == true)) // left
        return true;
    if ((solve(board, word, temp, i - 1, j, m, n) == true)) // up
        return true;
    if ((solve(board, word, temp, i + 1, j, m, n) == true)) // down
        return true;
    temp.pop_back();
    board[i][j] = tempy;

    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    int m = board.size();
    int n = board[0].size();
    string temp = "";

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == word[0] &&
                solve(board, word, temp, i, j, m, n))
                return true;
        }
    }

    return false;
}
int main()
{

    return 0;
}