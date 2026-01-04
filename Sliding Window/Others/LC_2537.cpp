#include <bits/stdc++.h>
using namespace std;

long long countGood(vector<int> &nums, int k)
{

    // note if we have 3 numbers 1 then 2 pairs are possible for 3rd 1 as it would be making
    // the 1st pair with the 1st 1 and 2nd pair with 2nd 1

    unordered_map<int, int> mapy;
    // for storing the count of numbers if it becomes more than 2 then a good pair

    int i = 0, j = 0;
    int n = nums.size();
    long long pairs = 0, good = 0;

    while (j < n)
    {
        // then a good pair is obtained
        pairs += mapy[nums[j]]; // means that many good pairs
        mapy[nums[j]]++;

        // if we got the right pairs then shrink the window
        long long left = 0;
        while (pairs >= k)
        {
            mapy[nums[i]]--;

            pairs -= mapy[nums[i]];
            // if earlier we had 4 1's then it means it was making three pairs so
            // now subtract 3 good pairs

            left++;
            i++;
        }

        // from right all the remaining ones would be involved in making subarrays
        // count from left how many are there add that,and from right multiply it with
        // number of left

        good += left + (left * (n - j - 1));
        // this would be altered only when we have left > 0

        j++;
    }

    return good;
}
int main()
{

    return 0;
}