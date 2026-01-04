#include <bits/stdc++.h>
using namespace std;

// did by own(HARD)
long long countSubarrays(vector<int> &nums, int minK, int maxK)
{

    int i = 0, j = 0;
    int n = nums.size();
    int mini = INT_MAX;
    int maxi = INT_MIN;
    long long cnt = 0;
    unordered_map<int, int> mapy;

    // precomputing falsy index(which violates the condition) for each index
    vector<int> falsy(nums.size());
    int indy = falsy.size();
    for (int j = falsy.size() - 1; j >= 0; j--)
    {
        if (nums[j] > maxK || nums[j] < minK)
            indy = j;

        falsy[j] = indy;
    }

    while (j < n)
    {
        if (nums[j] > maxK || nums[j] < minK) // jump to next and have a fresh start
        {
            i = j + 1;
            j++;
            mapy.clear();
            mini = INT_MAX;
            maxi = INT_MIN;
            continue;
        }

        mapy[nums[j]]++;
        mini = min(mini, nums[j]);
        maxi = max(maxi, nums[j]);

        while (mini == minK && maxi == maxK) // keep counting till feasible
        {
            cnt += falsy[j] - j;
            // increment i by one step
            mapy[nums[i]]--;
            if (mapy[nums[i]] == 0 && mini == nums[i])
                mini = INT_MAX;
            else if (mapy[nums[i]] == 0 && maxi == nums[i])
                maxi = INT_MIN;
            i++;
        }

        j++;
    }
    return cnt;
}
int main()
{

    return 0;
}