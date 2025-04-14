#include <bits/stdc++.h>
using namespace std;

// Approach 1 - Mine
//LC 1248 too falls under this category
int subarraysWithKDistinct(vector<int> &nums, int k)
{

    int n = nums.size();
    int cnt = 0, dummy = 0;
    int i = 0, j = 0;

    unordered_map<int, int> mapy;

    while (j < n)
    {
        mapy[nums[j]]++;

        // if greater than k then adjust i by moving forward
        while (mapy.size() > k)
        {
            mapy[nums[i]]--;

            if (mapy[nums[i]] == 0)
                mapy.erase(nums[i]);

            i++;
            dummy = 0; // new sequence starts,reset dummy
        }

        if (mapy.size() == k)
            cnt++; // one valid pair

        // check how many pairs from left could be made by moving i
        while (mapy.size() == k)
        {
            mapy[nums[i]]--;

            if (mapy[nums[i]] == 0)
                mapy.erase(nums[i]);

            if (mapy.size() < k) // means break as the condition is violated,restore the count
            {
                mapy[nums[i]]++;
                break;
            }

            dummy++; // means these can be considered from left
            i++;
        }

        cnt += dummy;
        j++;
    }

    return cnt;
}

// Approach 2
int helper(vector<int> &nums, int k)
{
    int n = nums.size();
    int cnt = 0;
    int i = 0, j = 0;

    unordered_map<int, int> mapy;
    // will be counting all the subarrays which can be generated at index j that is j-i+1 but this would
    // not be necessarily of k distinct integers it can range from 1 to k

    while (j < n)
    {
        mapy[nums[j]]++;

        // if more than k then shrink
        while (mapy.size() > k)
        {
            mapy[nums[i]]--;

            if (mapy[nums[i]] == 0)
                mapy.erase(nums[i]);

            i++;
        }

        // count number of subarrays ending at j
        cnt += j - i + 1;
        j++;
    }

    return cnt;
}
int subarraysWithKDistinct(vector<int> &nums, int k)
{

    // this is another approach lets suppose we find the number of subarrays with <=k and then find <=k-1
    // then the resultant on subtraction would be exactly of k integers
    // ex k=3 find all the subarrays <=3 which would be of 1,2,3 unique elements
    // find all subarrays <=2 which would be containing 1,2 unique elements
    // now (3,2,1)-(2,1) => 3 which is exactly what we want

    return helper(nums, k) - helper(nums, k - 1);
}
int main()
{

    return 0;
}