#include <bits/stdc++.h>
using namespace std;
int findShortestSubArray(vector<int> &nums)
{

    // unordered_map<int,int> first occ,last occ,count of each
    unordered_map<int, int> first, last, count;
    // for first occ number and idx are stored
    for (int i = 0; i < nums.size(); i++)
    {
        if (first.find(nums[i]) == first.end())
            first[nums[i]] = i; // such a condition will occur only once for each element

        last[nums[i]] = i; // stores last occ
        count[nums[i]]++;  // stores the count
    }

    int maxi = 0; // checking the max count in count

    for (auto it : count)
    {
        maxi = max(maxi, it.second);
    }

    int ans = INT_MAX;
    // now iterating again on count to determine minimum num having least
    // dist
    for (auto it : count)
    {
        if (it.second == maxi)
        {
            ans = min(ans, last[it.first] - first[it.first] + 1);
        }
    }
    return ans;
}
int main()
{

    return 0;
}