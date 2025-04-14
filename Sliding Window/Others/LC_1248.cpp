#include <bits/stdc++.h>
using namespace std;
int numberOfSubarrays(vector<int> &nums, int k)
{

    int cnt = 0, odd_count = 0, j = 0, i = 0;
    int n = nums.size();
    int left = 0;

    while (j < n)
    {
        if ((nums[j] & 1))
        { // odd
            odd_count++;
            left = 0;
        }

        while (odd_count == k)
        {
            if (nums[i] & 1)
                odd_count--;

            i++;
            left++;
        }

        cnt += left;
        j++;
    }

    return cnt;
}
int main()
{

    return 0;
}