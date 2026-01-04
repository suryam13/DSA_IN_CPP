#include <bits/stdc++.h>
using namespace std;
//other approach is in pivotindex_1
int pivotIndex(vector<int> &arr)
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
int findMin(vector<int> &nums)
{

    return nums[pivotIndex(nums)];
}
int main()
{

    return 0;
}