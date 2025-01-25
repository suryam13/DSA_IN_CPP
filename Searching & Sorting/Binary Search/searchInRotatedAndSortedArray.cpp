#include <bits/stdc++.h>
using namespace std;
//here pivot index is the one which is maximum
int pivotIndex(vector<int> &arr)
{
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (start == end)
        {
            // single element
            return start;
        }

        else if ((mid + 1 < n) && (arr[mid] > arr[mid + 1]))
        {
            return mid;
        }

        else if ((mid - 1 >= 0) && (arr[mid] < arr[mid - 1]))
        {
            return mid - 1;
        }

        else if (arr[mid] >= arr[start])//arr[0] can also be used same answer would be received
        {
            start = mid +
                    1;
            // if this is to be written at last then no need of =
            // sign write directly in else part,problem arises when
            // there is 1,3 error is generated hence = is used
        }

        else if (arr[mid] < arr[start])
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }
    return mid;
}

int binarySearch(vector<int> &nums, int start, int end, int target)
{

    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (target == nums[mid])
            return mid;

        else if (target > nums[mid])
            start = mid + 1;

        else
            end = mid - 1;

        mid = start + (end - start) / 2;
    }
    return -1;
}

int search(vector<int> &nums, int target)
{

    int ans;

    int pivot = pivotIndex(nums);
    cout << pivot;

    if (target >= nums[0] && target <= nums[pivot])
        ans = binarySearch(nums, 0, pivot, target);

    else
        ans = binarySearch(nums, pivot + 1, nums.size() - 1, target);

    return ans;
}

int main()
{

    return 0;
}