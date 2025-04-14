#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int> &nums)
{
    // equal 0's and equal 1's so just replace the 0 with -1 and if we get the same result which had
    // appeared before means we got equal number of 0's and 1's
    // now this question is been changed to find largest subarray with sum 0

    // just use prefix sum approach with mao and the job would be done

    int n = nums.size();
    int sum = 0;
    unordered_map<int, int> mapy; //{sum,idx}
    int maxLen = 0;
    mapy[0] = -1;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i] == 0 ? -1 : 1; // if 0 then add -1 else 1

        if (mapy.find(sum) != mapy.end()) // means the sum has been repeated so consider the current length
            maxLen = max(maxLen, i - mapy[sum]);

        else
            mapy[sum] = i; // if sum is present then please don't update the idx
    }

    return maxLen;
}

int main()
{

    return 0;
}