#include <bits/stdc++.h>
using namespace std;
// LC-136
//everything appears twice except one element which appears once

int singleNumber(vector<int> &nums)
{

    // x-oring all the elements in the array
    //  int ans=0;
    //  for(int i=0;i<nums.size();i++)
    //  {
    //          ans=ans^nums[i];
    //  }
    //  return ans;

    map<int, int> mapy;
    for (int i = 0; i < nums.size(); i++)
    {
        mapy[nums[i]]++;
    }

    for (auto it : mapy)
    {
        if (it.second == 1)
            return it.first;
    }
    return -1;
}

int main()
{

    return 0;
}