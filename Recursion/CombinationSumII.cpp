#include <bits/stdc++.h>
using namespace std;
// brute tle for last 3 test cases
// void solve(vector<int> &candidates, set<vector<int>> &st, vector<int> &temp,
//            int target, int i)

// {
//     if (i == candidates.size())
//     {
//         if (target == 0)
//             st.insert(temp);

//         return;
//     }

//     // including
//     if (candidates[i] <= target)
//     {
//         temp.push_back(candidates[i]);
//         solve(candidates, st, temp, target - candidates[i], i + 1);
//         temp.pop_back();
//     }

//     solve(candidates, st, temp, target, i + 1);
// }
// vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
// {
//     set<vector<int>> st;
//     vector<vector<int>> ans;
//     vector<int> temp;
//     sort(candidates.begin(), candidates.end());

//     solve(candidates, st, temp, target, 0);

//     for (auto &it : st)
//     {
//         ans.push_back(it);
//     }
//     return ans;
// }

// optimised
vector<vector<int>> ans;

void solve(vector<int> &candidates, vector<int> &v, int ind, int target)
{

    if (target == 0)
    {
        ans.push_back(v);
       
    }

    // looping to get rid of duplicates and not using the same
    for (int i = ind; i < candidates.size(); i++)
    {
        if (i > ind &&
            candidates[i - 1] ==
                candidates[i]) // wrote the first condition so that the
                               // first element can always be considered
            continue;

        if (candidates[i] > target)
            break; // no need to check further

        v.push_back(candidates[i]);
        solve(candidates, v, i + 1, target - candidates[i]);
        v.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{

    vector<int> v;

    sort(candidates.begin(), candidates.end());
    solve(candidates, v, 0, target);
    return ans;
}


int main()
{

    return 0;
}