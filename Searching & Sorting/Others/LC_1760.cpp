#include <bits/stdc++.h>
using namespace std;
bool isValid(vector<int> &nums, int maxOperations, int mid)
{
    int cnt = 0; // for counting the max limit

    // alt approach
    for (auto it : nums)
    {
        cnt = cnt + it / mid;

        if (it % mid == 0)
            cnt--;
    }
    return cnt <= maxOperations;

    // gave tle
    //  for(auto it:nums)
    //  {
    //      int itt=it;
    //      while(itt>mid)
    //      {

    //         itt=itt-mid;
    //         cnt++;

    //         if(itt==mid)
    //         break;

    //     }
    // }

    return cnt <= maxOperations;
}

int minimumSize(vector<int> &nums, int maxOperations)
{

    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    int mid;
    int ans;

    // basically it is a B.S. on answers approach we are checking which num
    // would divide by getting the minimum penalty

    // we are constantly checking can we obtain that num from remaining and
    // constantly subtracting untill we get that num and therby increasing
    // the count of operations,as been done in alt method
    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (isValid(nums, maxOperations, mid))
        {
            ans = mid;
            high = mid - 1;
        }

        else
            low = mid + 1;
    }

    return ans;
}

int main()
{

    return 0;
}