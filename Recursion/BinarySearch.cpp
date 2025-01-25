#include <bits/stdc++.h>
using namespace std;

// check if array is sorted or not

// bool isSorted(int arr[],int n)
// {
//     if(n==1)
//     return true;
//     //base case

//     if(arr[n-1]<arr[n-2])
//     return false;

//     isSorted(arr,n-1);

// }

int binarySearch(int arr[], int start, int end, int target)
{
    if (start > end)
        return -1;

    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
        return mid;

    else if (arr[mid] > target)
        return binarySearch(arr, start, mid - 1, target);

    else if (arr[mid] < target)
        return binarySearch(arr, mid + 1, end, target);
}

int main()
{
    int arr[6] = {1, 3, 7, 8, 8, 9};

    // cout<<isSorted(arr,6);
    cout << binarySearch(arr, 0, 5, 3);

    return 0;
}