#include <bits/stdc++.h>
using namespace std;

int maxAbsoluteSum(vector<int> &nums)
{
    // did it on my own

    int maxSum = 0;
    int maxMax = 0;
    // max subarray sum
    for (auto &maxi : nums)
    {
        maxSum += maxi;

        maxMax = max(maxMax, maxSum);
        if (maxSum < 0)
            maxSum = 0;
    }

    int minSum = 0;
    int maxMin = 0;
    // min subarray sum
    for (auto &mini : nums)
    {
        minSum += mini;
        maxMin = min(maxMin, minSum);
        if (minSum > 0)
            minSum = 0;
    }

    return max(abs(maxMin), maxMax);
}
int main()
{

    return 0;
}