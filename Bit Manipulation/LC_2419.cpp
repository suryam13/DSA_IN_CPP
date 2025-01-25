#include <bits/stdc++.h>
using namespace std;
int longestSubarray(vector<int> &nums)
{
    // T.C O(2N)

    // Note-AND operation between two different numbers would always
    // result into smaller value

    /// over here we found out the maximum value and checked out for its consecutiveness as the max element would have the max and answer
    // int maxi=*max_element(nums.begin(),nums.end());

    // int maxlen=0;
    // int length=0;

    // for(int i =0;i<nums.size();i++)
    // {
    //     if(nums[i]==maxi)
    //     {
    //         length++;
    //         maxlen=max(maxlen,length);
    //     }

    //     else
    //     length=0;
    // }

    // return maxlen;

    // O(N)
    int maxi = 0;
    int maxlen = 0; // maximum possible length
    int streak = 0; // current streak

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > maxi)
        {
            // means the nums[i] is maximum number which can generate maximum AND hence resetting all the previous credentials
            maxi = nums[i];
            maxlen = 0;
            streak = 0;
        }

        if (maxi == nums[i])
            streak++;

        else
            streak = 0;

        maxlen = max(maxlen, streak);
    }
    return maxlen;
}
int main()
{

    return 0;
}