#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
// T.C. less than O(2^n) specifically O(C(9, k)) choosing k elements from 9
// S.C-O(k) specifically  O(C(9, k) * k)

void solve(vector<int> &v, int k, int target, int i)
{

    if (target == 0 && v.size() == k)
    {
        ans.push_back(v);
        return;
    }

    if (i > 9) // makin sure that the digit is in bound
        return;

    // including that number
    if (i <= target) // not required but to do a bit optimization avoiding
                     // unnecessary calls
    {
        v.push_back(i);
        solve(v, k, target - i, i + 1);
        v.pop_back();
    }

    // excluding that number
    solve(v, k, target, i + 1);
}

vector<vector<int>> combinationSum3(int k, int n)
{

    vector<int> v;
    solve(v, k, n, 1);
    return ans;
}

// through for loop
vector<vector<int>> ans;
// T.C. less than O(2^n) specifically O(C(9, k)) choosing k elements from 9
// S.C-O(k) specifically  O(C(9, k) * k)

void solve(vector<int> &v, int k, int target, int ind)
{

    if (v.size() == k && target == 0)
    {
        ans.push_back(v);
        return;
    }

    for (int i = ind; i <= 9; i++)
    {
        if (i > target)
            break; // no need of checking as it would always be greater

        v.push_back(i);
        solve(v, k, target - i,
              i + 1); // make tree diagram would understand why
        v.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n)
{

    vector<int> v;
    solve(v, k, n, 1);
    return ans;
}
int main()
{

    return 0;
}