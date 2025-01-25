#include <bits/stdc++.h>
using namespace std;

// without for loop just using backtracking template
// void subsequence(vector<int> nums, vector<vector<int>> &ans, vector<int> v,
//                  int i)
// {

//     if (i == nums.size())
//     {
//         ans.push_back(v);
//         return;
//     }

//     // excluding
//     subsequence(nums, ans, v, i + 1);

//     // including
//     v.push_back(nums[i]);
//     subsequence(nums, ans, v, i + 1);
// }

vector<vector<int>> subsets(vector<int> &nums)
{

    vector<vector<int>> ans;
    vector<int> v;

    subsequence(nums, ans, v, 0);

    return ans;
}

// did using for loop
void subsequence(vector<int> &nums, vector<vector<int>> &ans,
                 vector<int> &v, int i)
{

    ans.push_back(v);

    for (int j = i; j < nums.size(); j++)
    {

        v.push_back(nums[j]);
        subsequence(nums, ans, v, j + 1);
        v.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{

    vector<vector<int>> ans;
    vector<int> v;

    subsequence(nums, ans, v, 0);

    return ans;
}

int main()
{

    return 0;
}