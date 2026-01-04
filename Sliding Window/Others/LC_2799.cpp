#include <bits/stdc++.h>
using namespace std;

    int countCompleteSubarrays(vector<int> &nums)
    {

        // Sliding Window
        // we just have to find the first valid subarray then with respect to that all
        // at the right would also create a valid subarray
        // then move i by one step and if the condition is valid then again consider all
        // the rights

        unordered_set<int> st(nums.begin(), nums.end());
        int size = st.size();
        unordered_map<int, int> mapy;
        int i = 0, j = 0;
        int n = nums.size();
        int cnt = 0;

        while (j < n)
        {
            mapy[nums[j]]++;

            // now move i ahead uptill it is equal to size
            while (mapy.size() == size)
            {
                mapy[nums[i]]--;
                if (mapy[nums[i]] == 0)
                    mapy.erase(nums[i]);
                i++;
                cnt += n - j; // considering all the rights
            }

            j++;
        }

        return cnt;
    }
    
int main()
{

    return 0;
}