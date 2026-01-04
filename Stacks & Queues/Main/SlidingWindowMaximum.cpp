#include <bits/stdc++.h>
using namespace std;
/*
SHEET : LC - 239
CODESTORYWITHMIK
*/
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{

    vector<int> ans;
    deque<int> deq;

    // we are storing the indices of the elements
    //  pop the elements which cannot be the maximum

    for (int i = 0; i < nums.size(); i++)
    {
        while (!deq.empty() && deq.front() <= i - k) // start popping as the index is out of
            // bound for consideration
            deq.pop_front();

        while (!deq.empty() && nums[i] > nums[deq.back()])
            deq.pop_back();

        deq.push_back(i);

        if (i >= k - 1) // keep pushing as after the minimum window is acieved the front would be the max amongst
            // the elements
            ans.push_back(nums[deq.front()]);
    }

    return ans;
}
int main()
{

    return 0;
}