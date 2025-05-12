#include <bits/stdc++.h>
using namespace std;

long long countSubarrays(vector<int> &nums, int k)
{

    int maxi = *max_element(nums.begin(), nums.end());

    int i = 0, j = 0;
    int n = nums.size();
    long long cnt = 0;
    int occ = 0;

    while (j < n)
    {
        if (nums[j] == maxi)
            occ++;

        if (occ == k)
        {
            cnt += n - j;
            while (occ == k)
            {
                if (nums[i] == maxi)
                    occ--;
                i++;
                if (occ == k)
                    cnt += n - j;
            }
        }
        j++;
    }

    return cnt;
}
int main()
{

    return 0;
}