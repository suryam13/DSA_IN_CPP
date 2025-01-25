#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int x, int n)
{

    // upper bound is the element which is just greater than target,smallest index such that arr[i]>target

    // return upper_bound(arr.begin(), arr.end(), x) - arr.begin();  STL

    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int ans = n;

    while (start <= end)
    {
        if (arr[mid] > x)
        {
            ans = mid;
            end = mid - 1;
        }

        else
            start = mid + 1;

        mid = start + (end - start) / 2;
    }
    return ans;
}

int lowerBound(vector<int> arr, int n, int x)
{
    // lower bound is the element which is just greater than or equal to target,smallest index such that arr[i]>=target

    // return lower_bound(arr.begin(), arr.end(), x) - arr.begin();  STL

    int start=0;
    int end=n-1;
    int mid=start+(end-start)/2;
    int ans=n;

    while(start<=end)
    {
    	if(arr[mid]>=x)
    	{
    		ans=mid;
    		end=mid-1;
    	}

    	else
    	start=mid+1;

    	mid=start+(end-start)/2;
    }
    return ans;
}

int main()
{

    return 0;
}