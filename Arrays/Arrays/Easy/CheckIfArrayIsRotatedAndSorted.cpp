#include <bits/stdc++.h>
using namespace std;

// LC-1752
// key observations
// the array which has more than one peak element cannot be rotated and sorted
// normal sorted array would have one peak that would be known by comparing first and last element
// rotated and sorted would have 1 peak while traversing somehwere mid in the array,the first element would never be less then the last
bool check(vector<int> &nums)
{

    // O(N)
    int n = nums.size();
    int cnt = 0;

    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
            cnt++; // to check whether how many peak it has
    }

    if (nums[0] < nums[n - 1])
        cnt++; // to check whether it has another peak or not

    if (cnt <= 1)
        return true;

    return false;
}

int main()
{

    return 0;
}