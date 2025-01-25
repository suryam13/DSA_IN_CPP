#include <bits/stdc++.h>
using namespace std;

int firstocc(vector<int> &nums, int target)
{  
    //alternately an be found out using lower bound,but if arr[lb]!=target || lb==n then there is no occurence retur -1 -1 for both first and last
    int s = 0;
    int e = nums.size() - 1;
    int ans = -1;

    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (nums[mid] == target)
        {
            ans = mid;
            e = mid - 1;
        }

        else if (nums[mid] > target)
        {
            e = mid - 1;
        }

        else
            s = mid + 1;

        mid = s + (e - s) / 2;
    }
    return ans;
}

int lastocc(vector<int> &nums, int target)
{

    //alternately an be found out using upper bound - 1
    int s = 0;
    int e = nums.size() - 1;
    int ans = -1;

    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (nums[mid] == target)
        {
            ans = mid;
            s = mid + 1;
        }

        else if (nums[mid] > target)
        {
            e = mid - 1;
        }

        else
            s = mid + 1;

        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{

    return 0;
}

// int firstocc(vector<int>& nums, int target) {
//     int s = 0;
//     int e = nums.size() - 1;
//     // int ans = -1;

//     int mid = s + (e - s) / 2;

//     while (s <= e) {
//         if (nums[mid] == target) {

//             if ( mid!=0 && nums[mid - 1] == target)
//                 e = mid - 1;

//             else
//                 return mid;

//         }

//         else if (nums[mid] > target) {
//             e = mid - 1;
//         }

//         else
//             s = mid + 1;

//         mid = s + (e - s) / 2;
//     }
//     return -1;
// }