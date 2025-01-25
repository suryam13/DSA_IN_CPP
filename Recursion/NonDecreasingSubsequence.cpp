#include <bits/stdc++.h>
using namespace std;
// didnt understood looping technique so visit again for that
//  LC-491
/*
   T.C-O(2^n x n)+O(2^n x n)+O(2^n x n)=O(2^n x n)
   1st one is at the time of recursion call 2^n for exploration multiplied by n
   as at each step we are inserting some thing in vector that takes O(1) space
   but at last entire vector is been copied and pushed back in ans so O(N
   space) 2nd is for insering into set for removing duplicates insertion takes
   logN so O(2^n.log 2^n) so finally O(2^n x n) 3rd one is for transferring
   back to ans.If there are 2^n subsequences, and copying each one takes
    O(n), then the time complexity for this step is: 𝑂 ( 2 𝑛 ⋅ �


   S.C-
   auxillary space-O(2^n.n)
    stack space-O(N)

   */
vector<vector<int>> ans;

void solve(vector<int> &nums, vector<int> temp, int i)
{
    // base case
    if (i >= nums.size())
    {
        if (temp.size() >= 2)
            ans.push_back(temp);

        return;
    }

    if (temp.empty() || temp.back() <= nums[i])
    {
        // include
        temp.push_back(nums[i]);  // do
        solve(nums, temp, i + 1); // explore
        temp.pop_back();          // undo
    }

    // exclude
    solve(nums, temp, i + 1);
}
vector<vector<int>> findSubsequences(vector<int> &nums)
{
    vector<int> temp;
    solve(nums, temp, 0);

    set<vector<int>> st(ans.begin(), ans.end());
    ans.clear();
    for (auto &it : st)
    {
        ans.push_back(it);
    }
    return ans;
}

// take not take approach
vector<vector<int>> ans;

void solve(vector<int> &nums, vector<int> temp, int i)
{

    if (i >= nums.size())
    {
        if (temp.size() >= 2)
            ans.push_back(temp);

        return;
    }

    // take

    if (temp.size() == 0 || temp.back() <= nums[i])
    {
        temp.push_back(nums[i]);
        solve(nums, temp, i + 1);
        temp.pop_back();
    }

    // not take
    solve(nums, temp, i + 1);
}
vector<vector<int>> findSubsequences(vector<int> &nums)
{
    vector<int> temp;
    solve(nums, temp, 0);

    set<vector<int>> st(ans.begin(), ans.end());
    ans.clear();
    for (auto &it : st)
    {
        ans.push_back(it);
    }
    return ans;
}
int main()
{

    return 0;
}