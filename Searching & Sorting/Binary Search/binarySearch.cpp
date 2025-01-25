#include <bits/stdc++.h>
using namespace std;

// LC-704
//  by recursive approach
int search1(vector<int> &nums, int start, int end, int target)
{
    // base condition
    if (start > end)
        return -1;

    int mid = start + (end - start) / 2;
    if (nums[mid] == target)
        return mid;

    else if (nums[mid] > target)

        return search1(nums, start, mid - 1, target);

    else

        return search1(nums, mid + 1, end, target);

    return -1;
}

int search(vector<int> &nums, int target)
{

    return search1(nums, 0, nums.size() - 1, target);
    // int start = 0;
    // int end = nums.size() - 1;
    // int mid = start + (end - start) / 2;

    // while (start <= end) {
    //     if (target == nums[mid])
    //         return mid;

    //     else if (target > nums[mid])
    //         start = mid + 1;

    //     else
    //         end = mid - 1;

    //     mid = start + (end - start) / 2;
    // }
    // return -1;
}

int main()
{

    return 0;
}



