#include <bits/stdc++.h>
using namespace std;
///SHEET : LC-503
vector<int> nextGreaterElements(vector<int> &nums)
{

    // T.C. O(4N)
    vector<int> ans(nums.size());
    stack<int> st;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        st.push(nums[i]);
    } // O(N)

    // O(2N+N)
    for (int j = nums.size() - 1; j >= 0; j--)
    { // O(N)

        // untill the top is greater pop el's
        while (!st.empty() && st.top() <= nums[j])
        { // O(N) O(N) extra for removal of el which came from first loop
            st.pop();
        }

        if (st.empty())
            ans[j] = -1; // means no greater found

        else
            ans[j] = st.top(); // greater is at top

        st.push(nums[j]); // push the current el to be greater to coming one
    }

    return ans;
}
int main()
{

    return 0;
}