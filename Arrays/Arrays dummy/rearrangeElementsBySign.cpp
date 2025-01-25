#include <bits/stdc++.h>
using namespace std;
vector<int> rearrangeArray(vector<int> &nums)
{

    vector<int> ans(nums.size());

    int posi = 0; // positive
    int negi = 1; // negative

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            ans[posi] = nums[i];
            posi = posi + 2;
        }

        else
        {
            ans[negi] = nums[i];
            negi = negi + 2;
        }
    }
    return ans;
}
int main()
{

    return 0;
}