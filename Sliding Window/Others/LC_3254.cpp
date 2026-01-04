#include <bits/stdc++.h>
using namespace std;
vector<int> resultsArray(vector<int> &nums, int k)
{
    // T.C O(N)
    int n = nums.size();
    // through sliding window

    vector<int> ans(n - k + 1, -1);
    int cnt = 1;

    for (int i = 1; i < k; i++)
    {
        if (nums[i - 1] == nums[i] - 1)
            cnt++;

        else
            cnt = 1;
    }
    if (cnt == k)
        ans[0] = nums[k - 1];

    int i = 1;
    int j = k;

    while (j < n)
    {
        if (nums[j] - 1 == nums[j - 1])
            cnt++;

        else
            cnt = 1;

        if (cnt >= k)
            ans[i] = nums[j];

        i++;
        j++;
    }

    return ans;
}
int main()
{

    return 0;
}