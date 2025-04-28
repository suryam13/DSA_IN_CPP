#include <bits/stdc++.h>
using namespace std;
long long countSubarrays(vector<int> &nums, long long k)
{

    long long cnt = 0;
    long long sum = 0;
    int i = 0, j = 0;
    int n = nums.size();

    while (j < n)
    {
        sum += nums[j];
        long long req = sum * (j - i + 1);

        while (req >= k)
        {
            sum -= nums[i];
            i++;
            req = sum * (j - i + 1);
        }

        if (req < k)
            cnt += j - i + 1; // ending at j how many subarrays could be made,because between them also all will
        // be following the condition as the sum  would be smaller and lenght as well

        j++;
    }

    return cnt;
}
int main()
{

    return 0;
}