// In Merge sort the concept revloves around divide and merge
#include <bits/stdc++.h>
using namespace std;
// TC-O(NlogN)-->there are logN calls made in total by dividing the array and N is the time required for merging at each dunction call so NLogN
// SC-O(N+LogN)-->O(N)  //logN is the stack space and N is the auxillary array space
void merge(int arr[], int low, int mid, int high)
{
    vector<int> temp; // for storing the values in the temp vec

    int left = low;      // keeping left pointer on the first value
    int right = mid + 1; // keeping right pointer on the first value of right array

    while (left <= mid && right <= high) // assuring that both are in bounds
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }

        else // cases where right would be smaller then left
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // making sure that if any of the elements are left due to out of bound condition in the previous one are handled over here

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {

        temp.push_back(arr[right]);
        right++;
    }

    // now finally after performing all the operations saving the values of temp in the main array
    int dummy = 0;
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[dummy];
        dummy++;
    }
}

void mergeSort(int arr[], int low, int high)
{
    // base case
    if (low == high)
        return; //means only one element is remaining so return

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);      // sort the left half
    mergeSort(arr, mid + 1, high); // sort the right half
    merge(arr, low, mid, high);    // then finally merge
}

int main()
{

    return 0;
}
