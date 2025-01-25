#include <bits/stdc++.h>
using namespace std;
// i am given a vector [1,2,3] print subarrays
//method 1

void solve(vector<int> nums, int idx, vector<int> temp)
{
    for (auto it : temp)
    {
        cout << it << " ";
    }
    cout << endl;

    for (int i = idx; i < nums.size(); i++)
    {   
        if( idx!=i && idx!=0 )
        continue;

        temp.push_back(nums[i]);
        solve(nums, i + 1, temp);
        temp.pop_back();
    }
}

int main()
{
    vector<int> nums = {1, 2, 3,5,6,2};
    vector<int> temp;
    solve(nums, 0, temp);

    return 0;
}

/*
method 2 
#include <bits/stdc++.h>
using namespace std;
// i am given a vector [1,2,3] print subarrays

void solve(vector<int> nums, int idx, vector<int> temp)
{
    if (idx == nums.size())
    {

        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        temp.push_back(nums[i]);
         for (auto it : temp)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    temp.clear();
    solve(nums,idx+1,temp);
}

int main()
{
    vector<int> nums = {1, 2, 3,4,5,6};
    vector<int> temp;
    solve(nums, 0, temp);

    return 0;
} */