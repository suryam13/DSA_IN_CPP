#include <bits/stdc++.h>
using namespace std;

// LC-286

//a number range is given from 0 to N find which number is missing

int missingNumber(vector<int> &nums)
{
    // approach 1-sort and compare index
    // approach 2-sum approach

    int sum1 = 0;
    for (int i = 0; i <= nums.size(); i++)
    {
        sum1 = sum1 + i;
    }

    int sum2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum2 = sum2 + nums[i];
    }
    return sum1 - sum2;

    // approach-3
    //  //x-oring array elments till end
    //  int ans=0;

    // for(int i=0;i<nums.size();i++)
    // {
    //     ans=ans^nums[i];

    // }

    // //x-oring from 0 to n
    // for(int i=0;i<=nums.size();i++)
    // {
    //     ans=ans^i;
    // }

    // return ans;
}
int main()
{

    return 0;
}