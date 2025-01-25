#include <bits/stdc++.h>
using namespace std;
void funct(vector<int> &nums, int ind, vector<vector<int>> &ans,
           vector<int> &dummy)
{
    ans.push_back(dummy);

    for (int i = ind; i < nums.size(); i++)
    {
        if (i > ind && nums[i - 1] == nums[i])
        {
            continue; // to make sure that if we are starting with it then
                      // thats ok
        }
        dummy.push_back(nums[i]);
        funct(nums, i + 1, ans, dummy);
        dummy.pop_back();
        /*
        over here why did we pass i+1 and not ind+1?
        think like u took 1 and then explored from the next index u took 2 and explored from the next ind so to go to the next obvioulsy u have to pass current iteration+1 to explore from next index if u will give ind means u are again going to the current index+1 not current iteration +1
        */
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> dummy;
    sort(nums.begin(),
         nums.end()); // just to deal with the input array as we had to sort
                      // in order to match test case and to avoid duplicates in sequence
    int i = 0;

    funct(nums, i, ans, dummy);
    return ans;
}
int main()
{

    return 0;
}