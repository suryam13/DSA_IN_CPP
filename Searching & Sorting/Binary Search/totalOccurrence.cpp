#include <bits/stdc++.h>
using namespace std;

// total occurence=last occ-firstocc+1

int firstocc(int nums[], int n, int target)
{
    int s = 0;
    int e = n - 1;
    // int ans = -1;

    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (nums[mid] == target)
        {

            if (mid != 0 && nums[mid - 1] == target)
                e = mid - 1; // alternate method else follow lastocc method below

            else
                return mid;
        }

        else if (nums[mid] > target)
        {
            e = mid - 1;
        }

        else
            s = mid + 1;

        mid = s + (e - s) / 2;
    }
    return -1;
}

int lastocc(int nums[], int n, int target)
{
    int s = 0;
    int e = n - 1;
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

int count(int arr[], int n, int x)
{
    // code here
    int first = firstocc(arr, n, x);
    int last = lastocc(arr, n, x);
    int totalocc;

    if (first == -1 && last == -1)
        totalocc = 0;

    else
        totalocc = (last - first) + 1;
    return totalocc;
}


int main()
{

    return 0;
}

