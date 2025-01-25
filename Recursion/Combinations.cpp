#include <bits/stdc++.h>
using namespace std;
// over here got to know about the importance of sending by reference passed
// temp by reference and the problem got solved
vector<vector<int>> ans;
void solve(vector<int> &temp, int i, int k, int n)
{

    if (k == 0)
    {
        ans.push_back(temp);
        return;
    }
    if (i > n)
        return;

    // include
    temp.push_back(i);
    solve(temp, i + 1, k - 1, n);
    temp.pop_back();

    // exclude
    solve(temp, i + 1, k, n);
}

vector<vector<int>> combine(int n, int k)
{

    vector<int> temp;

    solve(temp, 1, k, n);

    return ans;
}

// using for loop
//  over here got to know about the importance of sending by reference passed
//  temp by reference and the problem got solved
// T.C-nCk x k for adding the result we have to choose k elements form n

void solve(vector<vector<int>> &ans, vector<int> &temp, int idx, int k,
           int n)
{

    if (temp.size() == k)
    {
        ans.push_back(temp);
        return;
    }

    for (int i = idx; i <= n; i++)
    {
        temp.push_back(i);
        solve(ans, temp, i + 1, k, n);
        temp.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{

    vector<int> temp;
    vector<vector<int>> ans;

    solve(ans, temp, 1, k, n);

    return ans;
}
int main()
{

    return 0;
}