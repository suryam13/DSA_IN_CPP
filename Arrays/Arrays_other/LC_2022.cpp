#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
{

    vector<vector<int>> ans(m, vector<int>(n)); //intialisation of 2D vector

    if ((m * n) != original.size())
        return {};

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i][j] = original[(n * i) + j];
        }
    }

    return ans;
}
int main()
{

    return 0;
}