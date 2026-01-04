#include <bits/stdc++.h>
using namespace std;
// LC 209

int minSubArrayLen(int target, vector<int> &nums)
{

    // Sliding window pattern since it includes subarray
    int n = nums.size();

    int i = 0;
    int j = 0;
    long long sum = 0;
    int size = INT_MAX;

    while (i < n)
    {

        sum = sum + nums[i]; // general syntax

        if (sum >= target)
        {
            size = min(size, i - j + 1); // check always because there might be possibility
                                         // that there wont exist size  like this

            while (sum > target)
            { // keep increasing j untill it becomes small
              // than target and check at each step whether
              // it is valid or not and take min
                sum = sum - nums[j];
                j++;

                if (sum >= target)
                    size = min(size, i - j + 1);
            }
        }

        i++; // keep going
    }

    if (size == INT_MAX)
        return 0;

    return size;
}

// Another method same approach
int minSubArrayLen(int target, vector<int> &nums)
{

    // Sliding window pattern since it includes subarray
    int n = nums.size();

    int i = 0;
    int j = 0;
    long long sum = 0;
    int size = INT_MAX;

    while (i < n)
    {

        sum = sum + nums[i]; // general syntax

        // check always because there might be possibility
        // that there wont exist size  like this

        while (sum >= target) // chota kartev jaao check akrte jaao
        {
            size = min(size, i - j + 1); // whether it is valid or not and take min
            sum = sum - nums[j];
            j++;
        }

        i++; // keep going
    }

    if (size == INT_MAX)
        return 0;

    return size;
}
int main()
{

    return 0;
}