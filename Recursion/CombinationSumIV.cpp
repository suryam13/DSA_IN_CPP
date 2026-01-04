#include <bits/stdc++.h>
using namespace std;

//TLE would have to memoize
//through for loop approach
int cnt = 0;

void solve(vector<int> &nums, int target, int idx)
{
    if (target == 0)
    {
        cnt++;
        return;
    }

    if (target < 0)
        return;

    for (int i = idx; i < nums.size(); i++)
    {
        if (nums[i] <= target)
        {
            solve(nums, target - nums[i], 0);
        }
    }
}
int combinationSum4(vector<int> &nums, int target)
{

    solve(nums, target, 0);
    return cnt;
}
int main()
{

    return 0;
}