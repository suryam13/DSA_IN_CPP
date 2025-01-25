#include <bits/stdc++.h>
using namespace std;

// using lowerbound technique
//LC 35

int searchInsert(vector<int> &nums, int target)
{
    // using lowerbound
    int start = 0;
    int end = nums.size() - 1;
    int mid = start + (end - start) / 2;
    int ans = nums.size();

    while (start <= end)
    {

        if (nums[mid] >= target)
        {
            ans = mid;
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }
    return ans;
}
int main()
{

    return 0;
}