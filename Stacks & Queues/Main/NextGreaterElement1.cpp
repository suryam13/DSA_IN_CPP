#include <bits/stdc++.h>
using namespace std;
///SHEET : LC-496
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{

    // stack approach(Monotonic Stack)
    vector<int> ans;
    stack<int> st;

    unordered_map<int, int> mapy;

    //O(2N) as at max only n elements are popped not everytime they are popped popped just once
    for (int i = nums2.size() - 1; i >= 0; i--)
    {

        // untill the top is greater pop el's
        while (!st.empty() && st.top() <= nums2[i])
        {
            st.pop();
        }

        if (st.empty())
            mapy[nums2[i]] = -1; // means no greater found

        else
            mapy[nums2[i]] = st.top(); // greater is at top

        st.push(nums2[i]); // push the current el to be greater to coming one
    }

    for (auto &el : nums1)
    {
        ans.push_back(mapy[el]);
    }

    return ans;
}
int main()
{

    return 0;
}