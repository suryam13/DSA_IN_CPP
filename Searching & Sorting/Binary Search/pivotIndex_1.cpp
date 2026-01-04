

//  this problem pivot index is the smallest possible in sorted and rotated array
//  eg 3 8 10 17 1
//  1 is the pivot index

#include <bits/stdc++.h>
using namespace std;
int pivotIndex(vector<int> &arr) //approach 1
{
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    if (arr[end] > arr[start])
        return start;

    while (start <= end)
    {
        if (start == end)
        {
            // single element
            return start;
        }

        else if (arr[end] > arr[start])
            return start;

        else if ((mid + 1 < n) && (arr[mid] > arr[mid + 1]))
        {
            return mid + 1;
        }

        else if ((mid - 1 >= 0) && (arr[mid] < arr[mid - 1]))
        {
            return mid;
        }

        else if (arr[mid] > arr[start]) // arr[0] can also be used same answer would be received
        {
            start = mid +
                    1;
        }

        else if (arr[mid] < arr[start])
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }
    return mid;
}


int findMin(vector<int>& nums) {  //approach 2
        int left = 0, right = nums.size() - 1;

        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return nums[left];
    }  



int findMin(vector<int> &nums)
{

    return nums[pivotIndex(nums)];
}
int main()
{

    return 0;
}