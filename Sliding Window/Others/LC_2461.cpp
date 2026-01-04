#include <bits/stdc++.h>
using namespace std;
long long maximumSubarraySum(vector<int> &nums, int k)
{

    long long sum = 0;
    unordered_map<int, int> mapy;

    for (int i = 0; i < k; i++)
    {
        mapy[nums[i]]++;
        sum = sum + nums[i];
    }

    long long ans = 0;

    int i = 0;
    int j = k - 1;

    while (j < nums.size())
    {
        if (mapy.size() == k)
            ans = max(sum, ans);

        sum = sum - nums[i];
        mapy[nums[i]]--;
        if (mapy[nums[i]] == 0)
            mapy.erase(nums[i]);
        i++;

        j++;
        if (j < nums.size())
        {
            sum = sum + nums[j];
            mapy[nums[j]]++;
        }
    }

    return ans;
}
int main()
{

    return 0;
}