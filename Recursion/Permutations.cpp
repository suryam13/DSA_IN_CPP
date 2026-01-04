#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
unordered_set<int> st;

void solve(vector<int> &nums, vector<int> &temp)
{
    if (temp.size() >= nums.size())
    {
        ans.push_back(temp);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (st.find(i) ==
            st.end()) // then only i can take the ith element
        {
            st.insert(i);
            temp.push_back(nums[i]); // do
            solve(nums, temp);       // explore
            temp.pop_back();         // undo
            st.erase(i);
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> temp;
    solve(nums, temp);
    return ans;
}


//Approach 2
  vector<vector<int>> ans;

    void solve(vector<int>& nums, int idx) {
        if (idx >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {

            swap(nums[i], nums[idx]);
            solve(nums, idx + 1);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        solve(nums, 0);
        return ans;
    }

int main()
{

    return 0;
}