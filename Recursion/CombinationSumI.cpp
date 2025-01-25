#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &candidates, vector<vector<int>> &ans,
           vector<int> temp, int i, int target)
{
    if (i == candidates.size())
    {
        if (target == 0)
            ans.push_back(temp);

        return;
    }

    // exclude
    solve(candidates, ans, temp, i + 1, target);

    // include
    if (candidates[i] <= target)
    {
        temp.push_back(candidates[i]);
        solve(candidates, ans, temp, i, target - candidates[i]);
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{

    vector<vector<int>> ans;
    vector<int> temp;
    solve(candidates, ans, temp, 0, target);
    return ans;
}
// using for loop
void solve(vector<int> &candidates, vector<vector<int>> &ans,
           vector<int> temp, int ind, int target)
{
    // base case if target==0 return
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }

    for (int i = ind; i < candidates.size(); i++)
    {
        // pick means u can use the element multilpe times untill the sum is
        // possible
        if (candidates[i] <= target)
        {

            temp.push_back(candidates[i]);
            solve(candidates, ans, temp, i, target - candidates[i]);
            temp.pop_back();
        }

        // not pick is by default handled as the index proceeds further to explore
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    int dummy = 0;
    solve(candidates, ans, temp, 0, target);
    return ans;
}
int main()
{

    return 0;
}