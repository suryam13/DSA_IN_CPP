#include <bits/stdc++.h>
using namespace std;
/*
   T.C. we have n^2 cells and at each cell we are having 4 options so O( 4 raise to n^2 )
   but to be precise we have only 3 choices from where it is standing it cannot go from where it came
   so O(3^n^2) and i fursther asked more so could multiply the n2 with it in worst when suppose all the cells are 1 and i have to push_back s in ans so n^2

   S.C-stack space - O(n^2) maximum depth
   */
int n;
void solve(vector<vector<int>> &mat, vector<string> &ans, string &s, int i, int j)
{

    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(s);
        return;
    }

    if (i < 0 || j < 0 || i >= n || j >= n || mat[i][j] == 0)
        return;

    // marks as visited
    mat[i][j] = 0;

    // explore down
    // no need to mark visited again and unmark again at all the 4 steps
    // because each recursion stack is different so if done once is also ok
    // its mandatory to mark and unmark beacuase at every cell u have 4 choices if u
    // wont mark the place from where u came then it woulg go again over there
    s.push_back('D');
    solve(mat, ans, s, i + 1, j);
    s.pop_back();

    s.push_back('U');
    solve(mat, ans, s, i - 1, j);
    s.pop_back();

    s.push_back('R');
    solve(mat, ans, s, i, j + 1);
    s.pop_back();

    s.push_back('L');
    solve(mat, ans, s, i, j - 1);
    s.pop_back();

    // mark again as unvisited
    mat[i][j] = 1;
}
vector<string> findPath(vector<vector<int>> &mat)
{
    n = mat.size();

    string s = "";
    vector<string> ans;

    if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0)
    {
        ans.push_back("-1");
        return ans;
    }

    solve(mat, ans, s, 0, 0);

    return ans;
}
int main()
{

    return 0;
}