#include <bits/stdc++.h>
using namespace std;

int maximumCount(vector<int> &nums)
{

    int countNeg = 0;
    int countPos = 0;

    // BS for neg that is last occurence of neg
    int start = 0;
    int end = nums.size() - 1;
    int mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (nums[mid] < 0) // means go right to find last occurence
            start = mid + 1;

        else // means either 0 or positive so go left
            end = mid - 1;
    }
    countNeg = start;

    start = 0;
    end = nums.size() - 1;

    // find first occurence of positive
    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (nums[mid] <= 0) // means go right to find strict positive
            start = mid + 1;

        else // means positive so go left
            end = mid - 1;
    }
    countPos = nums.size() - end - 1;

    return max(countPos, countNeg);
}
int main()
{

    return 0;
}