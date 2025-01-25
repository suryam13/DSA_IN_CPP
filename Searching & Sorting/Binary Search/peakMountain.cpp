#include <bits/stdc++.h>
using namespace std;
int peakIndexInMountainArray(vector<int> &arr)
{

    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if (arr[mid] < arr[mid + 1])
        {
            // a wali line mein hupi
            start = mid + 1;
        }

        else
        {
            // b line pe hu ya toh peak pe hu
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return end;
}
int main()
{

    return 0;
}