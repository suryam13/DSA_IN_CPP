#include <bits/stdc++.h>
using namespace std;
int longestOnes(vector<int> &nums, int k)
{

    int maxCount = 0;

    int i = 0;
    int j = 0;

    while (j < nums.size())
    {
        if (nums[j] == 1)
        {

            maxCount = max(maxCount, j - i + 1);
            j++;
        }

        else if (nums[j] == 0 && k > 0)
        {

            maxCount = max(maxCount, j - i + 1);
            k--;

            j++;
        }

        else
        { // means k==0
            if (nums[i] == 0)
                k++;

            i++;
        }
    }
    return maxCount;
}
int main()
{

    return 0;
}