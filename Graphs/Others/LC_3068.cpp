#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        long long sum = 0;
        int cnt = 0, mini = INT_MAX;

        // whether there exists any edge or not between the nodes we can reach to them as they are connected

        for (int i = 0; i < nums.size(); i++)
        {
            if ((nums[i] ^ k) > nums[i])
            {
                sum += nums[i] ^ k; // taking the larger value
                cnt++;
            }

            else
                sum += nums[i];

            mini = min(mini, abs((nums[i] ^ k) - nums[i]));
            // tracking the minimum loss,if not taken as we want to maximise the sum the mini will be deducted from
            //  the sum if the cnt is odd
        }

        return cnt & 1 ? sum -= mini : sum;
    }
};

int main()
{

    return 0;
}