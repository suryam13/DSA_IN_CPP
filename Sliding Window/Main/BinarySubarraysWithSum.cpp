#include <bits/stdc++.h>
using namespace std;
int numSubarraysWithSum(vector<int> &nums, int target)
{

    // through prefix sum using the sum occurence in map

    map<int, int> mapy; // key is the sum and the val is the occurence
    mapy[0] = 1;
    int cnt = 0;
    long long sum = 0;

    int i = 0;
    while (i < nums.size())
    {
        sum += nums[i];
        int req = sum - target;
        // prefix sum approach if u want some part to be ur target value
        // then have to search for whether the req is present prior or
        // not...for eg 2 5 2 1 the sum is 10 and u want to achieve the
        // target of 3 so u will have to check whether previously was there
        // any sum equal to 7 if yes then after that sum ur answer lies right after the req

        cnt += mapy[req];
        // there could be multiple sum like this which appears at different
        // indexes so considering that in subarrays

        mapy[sum]++;
        i++;
    }
    return cnt;
}

int main()
{

    return 0;
}