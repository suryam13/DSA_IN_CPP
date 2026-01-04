#include <bits/stdc++.h>
using namespace std;
// brute
void flip(vector<int> &nums, int j)
{
    for (int i = j; i < j + 3; i++)
    {
        if (nums[i] == 0)
            nums[i] = 1;

        else
            nums[i] = 0;
    }
}

int minOperations(vector<int> &nums)
{

    // Approach 1 : greedy + brute takes o(N*3) in worst case s we have to mark 3 consecutive

    int flipCnt = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0) // means needs to be flipped
        {
            flipCnt++;
            if ((i + 3) > nums.size())
                return -1;

            else // flip k elements
                flip(nums, i);
        }
    }

    return flipCnt;
}
int minOperations(vector<int> &nums)
{
    // Refer 995 for intution
    // brute solution is using greedy but takes O(N*3)
    // optimised is keeping a track how many times the current i is been flipped by maintaining a cnt variable
    // within the k range,use a bool array to keep a track of which indices are been flipped

    vector<bool> mark(nums.size(), false);

    int flipCnt = 0; // maintaining the flip cnt variable
    int ans = 0;     // counting the total numbers of flips done

    for (int i = 0; i < nums.size(); i++)
    {
        if (i >= 3) // so start deleting the effect of flips from the out of window indices
        {
            if (mark[i - 3]) // means we have extra flip in the current subarray so delete 1
                flipCnt--;
        }

        if ((flipCnt % 2) == nums[i]) // means needs to be flipped,ex: if cnt is 2 and val is 0 then the resultant effect will make
        // it 0 again which needs to be flipped,ex2: if cnt is 1 and val is 1 then it would make it 0 again so needs to be flipped
        {

            ans++;
            flipCnt++;
            mark[i] = true;

            if ((i + 3) > nums.size()) // means we have to convert 0 into 1 but dont have the forward k subarrays so not possible
                // also we cant go backwards as this is greedy appraoch going back would make it fall in a trap
                return -1;
        }
    }

    return ans;
}
int main()
{

    return 0;
}