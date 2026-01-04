#include <bits/stdc++.h>
using namespace std;

// L.C-31
/*
brute approach is through recursion which would have a lot of time complexity

*/
// next permutation would be always greater than the previous one
// T.C. -O(3N)-->O(N)
// S.C -O(N) as we are modifying the array,but if not considering the modification then it would be O(1)

vector<int> nextGreaterPermutation(vector<int> &nums)
{

    // using stl this can be done through this two lines of code
    //  next_permutation(A.begin(),A.end());
    //  return A;

    // considering the example 2 1 5 4 3 0 0
    //  implementation of the in-built function
    int index = -1;
    int n = nums.size();

    // Step-1 Finding the breakpoint where i<i+1,it is breaking at the index 1,basically u have to search for longest prefix match
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            index = i;
            break;
        }
    }

    if (index == -1) // it means that there was no breakpoint so we would just reverse the vec to get the very first permutation as the current one is the greatest
    {
        reverse(nums.begin(), nums.end());
        return nums;
    }

    // Step-2 Checking the closest greater element of nums[i] which would
    // obviously start from backside because if some other number would have
    // been after the considered closest greater that would have been filtered out
    // during the intial comparisons made in step 1.

    else
    {
        for (int i = n - 1; i > index; i--)
        {
            if (nums[i] > nums[index])
            {
                swap(nums[i], nums[index]);
                break;
            }
        }
        // 2 3 5 4 1 0 0

        // Step-3 now reversing the array right from +1 of the index to the
        // end as we want the minimum number to be formed in the next
        // permutation that could be obtained with sorting in ascending order,but we got the pattern that it would be in decreasing number order so just reversed it

        reverse(nums.begin() + index + 1, nums.end());
        // 2 3 0 0 1 4 5
        // this is the next greater permutation which can be obtained

        return nums;
    }
}

int main()
{

    return 0;
}